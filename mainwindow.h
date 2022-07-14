#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void funcionActivacionTimer();
    void reset1();
    void reset2();
    void reset3();
    void reset4();
    void reset5();
    void reset6();
bool comprobar (int fila, int reinas[]);
void colocarReina (int fila, int reinas[]);
private slots:
    void on_pushButtonJugar_clicked(); 

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
