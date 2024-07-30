#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_transferButton_clicked();

    void on_scaleButton_clicked();

    void on_rotateButton_clicked();

    void on_downloadFromFileButton_clicked();

    void on_uploadInFileButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
