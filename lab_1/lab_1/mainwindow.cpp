#include <QFileDialog>
#include <QFile>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "manager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->transferButton->hide();
    ui->scaleButton->hide();
    ui->rotateButton->hide();
    request_t req;
    req.type = INIT;
    (void)request_proc(req);
}

MainWindow::~MainWindow()
{
    request_t req;
    req.type = FREE;
    (void)request_proc(req);
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 2));
    request_t req;
    req.type = DRAW;
    req.drawer.painter = &painter;
    (void)request_proc(req);
}

void MainWindow::on_transferButton_clicked()
{
    QString dx = ui->transferX->text();
    QString dy = ui->transferY->text();
    QString dz = ui->transferZ->text();

    if (dx.size() == 0 || dy.size() == 0 || dz.size() == 0)
        throw_error(ERR_UI_FORMS);
    else
    {
        bool ok_dx = false, ok_dy = false, ok_dz = false;
        double x_dx = dx.toDouble(&ok_dx);
        if (!ok_dx)
            throw_error(ERR_UI_FORMS);

        double y_dy = dy.toDouble(&ok_dy);
        if (!ok_dy)
            throw_error(ERR_UI_FORMS);

        double z_dz = dz.toDouble(&ok_dz);
        if (!ok_dz)
            throw_error(ERR_UI_FORMS);

        if (ok_dx && ok_dy && ok_dz)
        {
            request_t req;
            req.type = TRANSFER;
            req.transfer = transfer_init(x_dx, y_dy, z_dz);
            proc_err_t rc = request_proc(req);
            throw_error(rc);
        }
    }

    repaint();
}

void MainWindow::on_scaleButton_clicked()
{
    QString kx = ui->scaleX->text();
    QString ky = ui->scaleY->text();
    QString kz = ui->scaleZ->text();
    QString x_cent = ui->scaleCenterX->text();
    QString y_cent = ui->scaleCenterY->text();
    QString z_cent = ui->scaleCenterZ->text();

    if (kx.size() == 0 || ky.size() == 0 || kz.size() == 0 || x_cent.size() == 0 || y_cent.size() == 0 || z_cent.size() == 0)
        throw_error(ERR_UI_FORMS);
    else
    {
        bool ok_kx = false, ok_ky = false, ok_kz = false, ok_x_cent = false, ok_y_cent = false, ok_z_cent = false;
        double x_kx = kx.toDouble(&ok_kx);
        if (!ok_kx)
            throw_error(ERR_UI_FORMS);

        double y_ky = ky.toDouble(&ok_ky);
        if (!ok_ky)
            throw_error(ERR_UI_FORMS);

        double z_kz = kz.toDouble(&ok_kz);
        if (!ok_kz)
            throw_error(ERR_UI_FORMS);

        double x_x_cent = x_cent.toDouble(&ok_x_cent);
        if (!ok_x_cent)
            throw_error(ERR_UI_FORMS);

        double y_y_cent = y_cent.toDouble(&ok_y_cent);
        if (!ok_y_cent)
            throw_error(ERR_UI_FORMS);

        double z_z_cent = z_cent.toDouble(&ok_z_cent);
        if (!ok_z_cent)
            throw_error(ERR_UI_FORMS);

        if (ok_kx && ok_ky && ok_kz && ok_x_cent && ok_y_cent && ok_z_cent)
        {
            request_t req;
            req.type = SCALE;
            req.scale.center = vertex_init(x_x_cent, y_y_cent, z_z_cent);
            req.scale = scale_init(x_kx, y_ky, z_kz);
            proc_err_t rc = request_proc(req);
            throw_error(rc);
        }
    }

    repaint();
}

void MainWindow::on_rotateButton_clicked()
{
    QString x_angle = ui->rotateX->text();
    QString y_angle = ui->rotateY->text();
    QString z_angle = ui->rotateZ->text();
    QString x_cent = ui->rotateCenterX->text();
    QString y_cent = ui->rotateCenterY->text();
    QString z_cent = ui->rotateCenterZ->text();

    if (x_angle.size() == 0 || y_angle.size() == 0 || z_angle.size() == 0 || x_cent.size() == 0 || y_cent.size() == 0 || z_cent.size() == 0)
        throw_error(ERR_UI_FORMS);
    else
    {
        bool ok_x_angle = false, ok_y_angle = false, ok_z_angle = false, ok_x_cent = false, ok_y_cent = false, ok_z_cent = false;
        double x_x_angle = x_angle.toDouble(&ok_x_angle);
        if (!ok_x_angle)
            throw_error(ERR_UI_FORMS);

        double y_y_angle = y_angle.toDouble(&ok_y_angle);
        if (!ok_y_angle)
            throw_error(ERR_UI_FORMS);

        double z_z_angle = z_angle.toDouble(&ok_z_angle);
        if (!ok_z_angle)
            throw_error(ERR_UI_FORMS);

        double x_x_cent = x_cent.toDouble(&ok_x_cent);
        if (!ok_x_cent)
            throw_error(ERR_UI_FORMS);

        double y_y_cent = y_cent.toDouble(&ok_y_cent);
        if (!ok_y_cent)
            throw_error(ERR_UI_FORMS);

        double z_z_cent = z_cent.toDouble(&ok_z_cent);
        if (!ok_z_cent)
            throw_error(ERR_UI_FORMS);

        if (ok_x_angle && ok_y_angle && ok_z_angle && ok_x_cent && ok_y_cent && ok_z_cent)
        {
            request_t req;
            req.type = ROTATE;
            req.rotate.center = vertex_init(x_x_cent, y_y_cent, z_z_cent);
            req.rotate = rotate_init(x_x_angle, y_y_angle, z_z_angle);
            proc_err_t rc = request_proc(req);
            throw_error(rc);
        }
    }

    repaint();
}

void MainWindow::on_downloadFromFileButton_clicked()
{
    QString path = QFileDialog::getOpenFileName();
    QByteArray bytearray = path.toUtf8();
    const char *filename = bytearray.constData();
    request_t req;
    req.type = FREE;
    request_proc(req);
    req.type = INIT;
    request_proc(req);
    req.type = LOAD_FILE;
    req.filename = filename;
    proc_err_t rc = request_proc(req);
    if (!rc)
    {
        ui->transferButton->show();
        ui->scaleButton->show();
        ui->rotateButton->show();
    }

    throw_error(rc);
}

void MainWindow::on_uploadInFileButton_clicked()
{
    QString path = QFileDialog::getSaveFileName();
    QByteArray bytearray = path.toUtf8();
    const char *filename = bytearray.constData();
    request_t req;
    req.type = UPLOAD_FILE;
    req.filename = filename;
    proc_err_t rc = request_proc(req);
    throw_error(rc);
}
