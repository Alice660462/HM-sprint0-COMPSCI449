#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void drawLineDDA(int x1, int y1, int x2, int y2);
    void plotPoint(int x, int y);
private slots:
    void on_clearbutton_clicked();

    void on_okbutton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
