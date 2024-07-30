#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "facade/facade.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loadButton_clicked();
    void on_addCameraButton_clicked();
    void on_setCameraButton_clicked();
    void on_removeButton_clicked();
    void on_compositeButton_clicked();
    void on_moveButton_clicked();
    void on_scaleButton_clicked();
    void on_rotateButton_clicked();

private:
    void drawScene();
    void updateCameraList();
    void updateObjectList();
    std::vector<size_t> getSelectedObjectIds();
    std::vector<size_t> getSelectedCameraIds();

private:
    Ui::MainWindow *ui;
    Facade _facade;
};

#endif // MAINWINDOW_H
