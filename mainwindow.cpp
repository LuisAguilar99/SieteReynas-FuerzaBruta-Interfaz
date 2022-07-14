#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>


bool cambiar = false;
int reinas[6];
int acc1 = 1,acc2 = 0,acc3 = 0,acc4 = 0,acc5 = 0,acc6 = 0;
bool cam1 = true,cam2 = true,cam3 = true,cam4 = true,cam5 = true,cam6 = true;

//C//F
int tabla[6][6] = {
     {1, 2, 3, 4, 5, 6}
    ,{7, 8, 9,10,11,12}
    ,{13,14,15,16,17,18}
    ,{19,20,21,22,23,24}
    ,{25,26,27,28,29,30}
    ,{31,32,33,34,35,36}
    };


void MainWindow::funcionActivacionTimer(){

    if(cambiar==true){
        QPixmap pm1(":/dama.png");
        if(acc2<6){
    reinas[acc2]=acc1;
    switch (acc2) {
    case 0:
        reset1();
        break;
    case 1:
        reset2();
        break;
    case 2:
        reset3();
        break;
    case 3:
        reset4();
        break;
    case 4:
        reset5();
        break;
    case 5:
        reset6();
        break;
    }
        acc4++;
    if(comprobar(acc2,reinas)){
        acc2++;
        acc3=0;
    }else {
    acc1++;
        }


        for (int i=0; i<6; i++)
        {
                    switch (tabla[i][reinas[i]]) {
                            case 1:
                                ui->reina1_1->setPixmap(pm1);
                                break;
                            case 2:
                                ui->reina1_2->setPixmap(pm1);
                                break;
                            case 3:
                                ui->reina1_3->setPixmap(pm1);
                                break;
                            case 4:
                                ui->reina1_4->setPixmap(pm1);
                                break;
                            case 5:
                                ui->reina1_5->setPixmap(pm1);
                                break;
                            case 6:
                                                ui->reina1_6->setPixmap(pm1);
                                                break;
                                            case 7:
                                                ui->reina2_1->setPixmap(pm1);
                                                break;
                                            case 8:
                                                ui->reina2_2->setPixmap(pm1);
                                                break;
                                            case 9:
                                                ui->reina2_3->setPixmap(pm1);
                                                break;
                                            case 10:
                                                ui->reina2_4->setPixmap(pm1);
                                                break;
                                            case 11:
                                                ui->reina2_5->setPixmap(pm1);
                                                break;
                                            case 12:
                                                ui->reina2_6->setPixmap(pm1);
                                                break;
                                            case 13:
                                                ui->reina3_1->setPixmap(pm1);
                                                break;
                                            case 14:
                                                ui->reina3_2->setPixmap(pm1);
                                                break;
                                            case 15:
                                                ui->reina3_3->setPixmap(pm1);
                                                break;
                                            case 16:
                                                ui->reina3_4->setPixmap(pm1);
                                                break;
                                            case 17:
                                                ui->reina3_5->setPixmap(pm1);
                                                break;
                                            case 18:
                                                ui->reina3_6->setPixmap(pm1);
                                                break;
                                            case 19:
                                                ui->reina4_1->setPixmap(pm1);
                                                break;
                                            case 20:
                                                ui->reina4_2->setPixmap(pm1);
                                                break;
                                            case 21:
                                                ui->reina4_3->setPixmap(pm1);
                                                break;
                                            case 22:
                                                ui->reina4_4->setPixmap(pm1);
                                                break;
                                            case 23:
                                                ui->reina4_5->setPixmap(pm1);
                                                break;
                                            case 24:
                                                ui->reina4_6->setPixmap(pm1);
                                                break;
                                            case 25:
                                                ui->reina5_1->setPixmap(pm1);
                                                break;
                                            case 26:
                                                ui->reina5_2->setPixmap(pm1);
                                                break;
                                            case 27:
                                                ui->reina5_3->setPixmap(pm1);
                                                break;
                                            case 28:
                                                ui->reina5_4->setPixmap(pm1);
                                                break;
                                            case 29:
                                                ui->reina5_5->setPixmap(pm1);
                                                break;
                                            case 30:
                                                ui->reina5_6->setPixmap(pm1);
                                                break;
                                            case 31:
                                                ui->reina6_1->setPixmap(pm1);
                                                break;
                                            case 32:
                                                ui->reina6_2->setPixmap(pm1);
                                                break;
                                            case 33:
                                                ui->reina6_3->setPixmap(pm1);
                                                break;
                                            case 34:
                                                ui->reina6_4->setPixmap(pm1);
                                                break;
                                            case 35:
                                                ui->reina6_5->setPixmap(pm1);
                                                break;
                            case 36:
                               ui->reina6_6->setPixmap(pm1);
                                break;
                            }
        }


        if(acc3>1){
            acc1=reinas[0]+1;
            acc2=0;
        }
    if(acc1>5){
        acc1=0;
        acc3++;
    }


}else {
 ui->label->setText(QString::number(acc4)+"\nFIN");
 cambiar=false; 
}
        //ui->label->setText(QString::number(acc3));

    }

   }

bool MainWindow::comprobar (int fila, int reinas[])
{
    for (int i=0; i<fila; i++)
        if (  ( reinas[i]==reinas[fila] )                      // Misma columna
        || ( abs(fila-i) == abs(reinas[fila]-reinas[i]) ) ) // Misma diagonal
            return false;
    return true;
}


void MainWindow::colocarReina (int fila, int reinas[])
{
QPixmap pm1(":/dama.png");
    if (fila<6)
    {
        for (reinas[fila]=0; reinas[fila]<6; reinas[fila]++)
        {
            if (comprobar(fila,reinas))
            {
                // Si es así, intentamos colocar
                // las reinas restantes
                colocarReina (fila+1, reinas);
            }

        }
    }
    else
    {

        reset1();
        reset2();
        reset3();
        reset4();
        reset5();
        reset6();
        // No quedan reinas por colocar (solución)
    for (int i=0; i<6; i++)
    {
                switch (tabla[i][reinas[i]]) {
                        case 1:
                            ui->reina1_1->setPixmap(pm1);
                            break;
                        case 2:
                            ui->reina1_2->setPixmap(pm1);
                            break;
                        case 3:
                            ui->reina1_3->setPixmap(pm1);
                            break;
                        case 4:
                            ui->reina1_4->setPixmap(pm1);
                            break;
                        case 5:
                            ui->reina1_5->setPixmap(pm1);
                            break;
                        case 6:
                                            ui->reina1_6->setPixmap(pm1);
                                            break;
                                        case 7:
                                            ui->reina2_1->setPixmap(pm1);
                                            break;
                                        case 8:
                                            ui->reina2_2->setPixmap(pm1);
                                            break;
                                        case 9:
                                            ui->reina2_3->setPixmap(pm1);
                                            break;
                                        case 10:
                                            ui->reina2_4->setPixmap(pm1);
                                            break;
                                        case 11:
                                            ui->reina2_5->setPixmap(pm1);
                                            break;
                                        case 12:
                                            ui->reina2_6->setPixmap(pm1);
                                            break;
                                        case 13:
                                            ui->reina3_1->setPixmap(pm1);
                                            break;
                                        case 14:
                                            ui->reina3_2->setPixmap(pm1);
                                            break;
                                        case 15:
                                            ui->reina3_3->setPixmap(pm1);
                                            break;
                                        case 16:
                                            ui->reina3_4->setPixmap(pm1);
                                            break;
                                        case 17:
                                            ui->reina3_5->setPixmap(pm1);
                                            break;
                                        case 18:
                                            ui->reina3_6->setPixmap(pm1);
                                            break;
                                        case 19:
                                            ui->reina4_1->setPixmap(pm1);
                                            break;
                                        case 20:
                                            ui->reina4_2->setPixmap(pm1);
                                            break;
                                        case 21:
                                            ui->reina4_3->setPixmap(pm1);
                                            break;
                                        case 22:
                                            ui->reina4_4->setPixmap(pm1);
                                            break;
                                        case 23:
                                            ui->reina4_5->setPixmap(pm1);
                                            break;
                                        case 24:
                                            ui->reina4_6->setPixmap(pm1);
                                            break;
                                        case 25:
                                            ui->reina5_1->setPixmap(pm1);
                                            break;
                                        case 26:
                                            ui->reina5_2->setPixmap(pm1);
                                            break;
                                        case 27:
                                            ui->reina5_3->setPixmap(pm1);
                                            break;
                                        case 28:
                                            ui->reina5_4->setPixmap(pm1);
                                            break;
                                        case 29:
                                            ui->reina5_5->setPixmap(pm1);
                                            break;
                                        case 30:
                                            ui->reina5_6->setPixmap(pm1);
                                            break;
                                        case 31:
                                            ui->reina6_1->setPixmap(pm1);
                                            break;
                                        case 32:
                                            ui->reina6_2->setPixmap(pm1);
                                            break;
                                        case 33:
                                            ui->reina6_3->setPixmap(pm1);
                                            break;
                                        case 34:
                                            ui->reina6_4->setPixmap(pm1);
                                            break;
                                        case 35:
                                            ui->reina6_5->setPixmap(pm1);
                                            break;
                        case 36:
                           ui->reina6_6->setPixmap(pm1);
                            break;
                        }
    }
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *cronometro=new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
    cronometro->start(200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonJugar_clicked()
{

acc2=0;
acc1=reinas[0]+1;
if(acc1>5){
    acc1=0;
}
  cambiar=true; 
  //colocarReina(0,reinas);
}

void MainWindow::reset1(){
    QPixmap pm2(":/blanco.png");
    ui->reina1_1->setPixmap(pm2);
    ui->reina1_2->setPixmap(pm2);
    ui->reina1_3->setPixmap(pm2);
    ui->reina1_4->setPixmap(pm2);
    ui->reina1_5->setPixmap(pm2);
    ui->reina1_6->setPixmap(pm2);

}
void MainWindow::reset2(){
    QPixmap pm2(":/blanco.png");

    ui->reina2_1->setPixmap(pm2);
    ui->reina2_2->setPixmap(pm2);
    ui->reina2_3->setPixmap(pm2);
    ui->reina2_4->setPixmap(pm2);
    ui->reina2_5->setPixmap(pm2);
    ui->reina2_6->setPixmap(pm2);

}
void MainWindow::reset3(){
    QPixmap pm2(":/blanco.png");

    ui->reina3_1->setPixmap(pm2);
    ui->reina3_2->setPixmap(pm2);
    ui->reina3_3->setPixmap(pm2);
    ui->reina3_4->setPixmap(pm2);
    ui->reina3_5->setPixmap(pm2);
    ui->reina3_6->setPixmap(pm2);

}
void MainWindow::reset4(){
    QPixmap pm2(":/blanco.png");

    ui->reina4_1->setPixmap(pm2);
    ui->reina4_2->setPixmap(pm2);
    ui->reina4_3->setPixmap(pm2);
    ui->reina4_4->setPixmap(pm2);
    ui->reina4_5->setPixmap(pm2);
    ui->reina4_6->setPixmap(pm2);

}
void MainWindow::reset5(){
    QPixmap pm2(":/blanco.png");

    ui->reina5_1->setPixmap(pm2);
    ui->reina5_2->setPixmap(pm2);
    ui->reina5_3->setPixmap(pm2);
    ui->reina5_4->setPixmap(pm2);
    ui->reina5_5->setPixmap(pm2);
    ui->reina5_6->setPixmap(pm2);

}
void MainWindow::reset6(){
    QPixmap pm2(":/blanco.png");

    ui->reina6_1->setPixmap(pm2);
    ui->reina6_2->setPixmap(pm2);
    ui->reina6_3->setPixmap(pm2);
    ui->reina6_4->setPixmap(pm2);
    ui->reina6_5->setPixmap(pm2);
    ui->reina6_6->setPixmap(pm2);
}


