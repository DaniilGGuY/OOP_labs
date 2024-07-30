#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <cmath>

#include "commands/load/matrixloadcommand.h"
#include "commands/load/listloadcommand.h"
#include "commands/load/txtloadcommanddecorator.h"
#include "commands/draw/drawsceneqtcommand.h"
#include "commands/scene/getcameraidsscenecommand.h"
#include "commands/scene/getobjectidsscenecommand.h"
#include "commands/camera/addcameracommand.h"
#include "commands/camera/setcameracommand.h"
#include "commands/camera/removecameracommand.h"
#include "commands/object/scaleobjectcommand.h"
#include "commands/object/rotateobjectcommand.h"
#include "commands/object/shiftobjectcommand.h"
#include "commands/object/compositeobjectcommand.h"
#include "commands/object/removeobjectcommand.h"
#include "objects/point.h"

double DegToRad(double angle) { return angle / 180.0 * M_PI; }

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(new QGraphicsScene);
    ui->graphicsView->scene()->setSceneRect(ui->graphicsView->sceneRect());
    ui->graphicsView->setBackgroundBrush(Qt::white);
    ui->viewCombo->addItem("Список", 0);
    ui->viewCombo->addItem("Матрица", 1);
    ui->objectsList->setSelectionMode(QAbstractItemView::MultiSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadButton_clicked()
{
    QString path = QFileDialog::getOpenFileName();
    QByteArray bytearray = path.toUtf8();
    const char *filename = bytearray.constData();
    std::shared_ptr<BaseLoadCommand> command;

    if (ui->viewCombo->currentText() == "Список")
        command = std::make_shared<ListLoadCommand>();
    else
        command = std::make_shared<MatrixLoadCommand>();

    std::shared_ptr<BaseCommand> decorator = std::make_shared<TxtLoadCommandDecorator>(*command, filename);

    _facade.execute(*decorator);

    drawScene();
    updateObjectList();
}

void MainWindow::on_addCameraButton_clicked()
{
    double x = ui->cameraXSpin->value();
    double y = ui->cameraYSpin->value();
    double z = ui->cameraZSpin->value();
    Point pos(x, y, z);
    AddCameraCommand command(pos);
    _facade.execute(command);
    updateCameraList();
    updateObjectList();
}

void MainWindow::on_setCameraButton_clicked()
{
    auto cams = getSelectedCameraIds();
    if (cams.size() != 1)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать ровно одну камеру.");
        return;
    }
    SetCameraCommand command(cams[0]);
    _facade.execute(command);
    drawScene();
}

void MainWindow::on_removeButton_clicked()
{
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    for (auto &id : objs)
    {
        RemoveCameraCommand command1(id);
        _facade.execute(command1);
        RemoveObjectCommand command2(id);
        _facade.execute(command2);
    }

    drawScene();
    updateObjectList();
    updateCameraList();
}

void MainWindow::on_compositeButton_clicked()
{
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    CompositeObjectCommand command(objs);
    _facade.execute(command);

    drawScene();
    updateObjectList();
    updateCameraList();
}

void MainWindow::on_moveButton_clicked()
{
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    double x = ui->moveXSpin->value();
    double y = ui->moveYSpin->value();
    double z = ui->moveZSpin->value();
    for (auto &id : objs)
    {
        ShiftObjectCommand command(id, x, y, z);
        _facade.execute(command);
    }

    drawScene();
}

void MainWindow::on_scaleButton_clicked()
{
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    double x = ui->scaleXSpin->value();
    double y = ui->scaleYSpin->value();
    double z = ui->scaleZSpin->value();
    for (auto &id : objs)
    {
        ScaleObjectCommand command(id, x, y, z);
        _facade.execute(command);
    }

    drawScene();
}

void MainWindow::on_rotateButton_clicked()
{
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    double x = DegToRad(ui->rotateXSpin->value());
    double y = DegToRad(ui->rotateYSpin->value());
    double z = DegToRad(ui->rotateZSpin->value());
    for (auto &id : objs)
    {
        RotateObjectCommand command(id, x, y, z);
        _facade.execute(command);
    }

    drawScene();
}

void MainWindow::updateCameraList()
{
    ui->camerasList->clear();
    GetCameraIdsSceneCommand ids;
    _facade.execute(ids);
    std::vector<size_t> cameraIds = ids.getIds();
    for (size_t id : cameraIds)
        ui->camerasList->addItem(QString::number(id));
}

void MainWindow::updateObjectList()
{
    ui->objectsList->clear();
    GetObjectIdsSceneCommand ids;
    _facade.execute(ids);
    std::vector<size_t> objectIds = ids.getIds();
    for (size_t id : objectIds)
        ui->objectsList->addItem(QString::number(id));
}

std::vector<size_t> MainWindow::getSelectedObjectIds()
{
    std::vector<size_t> ids;
    for (int i = 0; i < ui->objectsList->count(); ++i)
        if (ui->objectsList->item(i)->isSelected())
            ids.push_back(ui->objectsList->item(i)->text().toInt());

    return ids;
}

std::vector<size_t> MainWindow::getSelectedCameraIds()
{
    std::vector<size_t> ids;
    for (int i = 0; i < ui->camerasList->count(); ++i)
        if (ui->camerasList->item(i)->isSelected())
            ids.push_back(ui->camerasList->item(i)->text().toInt());

    return ids;
}

void MainWindow::drawScene()
{
    ui->graphicsView->scene()->clear();
    ui->graphicsView->scene()->setSceneRect(ui->graphicsView->sceneRect());
    DrawSceneQtCommand drawcommand(ui->graphicsView->scene());
    _facade.execute(drawcommand);
}
