#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_agregar_clicked()
{
    qDebug() << "Hola";
    QString nombre = ui->nombre->text();
    QString tipo = ui->tipo->text();
    int salud = ui->salud->value();
    int fuerza = ui->fuerza->value();

    qDebug() << nombre << tipo << salud << fuerza;

    Personaje p;

    p.setNombre(nombre.toStdString());
    p.setTipo(tipo.toStdString());
    p.setSalud(salud);
    p.setFuerza(fuerza);

    v.agregar(p);
}

void MainWindow::on_mostrar_clicked()
{
    qDebug() << "mostrar";
    // v.mostrar();
    ui->salida->clear();
    for (size_t i = 0; i < v.size(); i++) {
        Personaje &p = v[i];

        ui->salida->insertPlainText(
                    "Nombre: "
                    + QString::fromStdString(p.getNombre())
                    + "\n");
        ui->salida->insertPlainText(
                    "Tipo: "
                    + QString::fromStdString(p.getTipo())
                    +"\n");
        ui->salida->insertPlainText(
                    "Salud: "
                    + QString::number(p.getSalud())
                    + "\n");
        ui->salida->insertPlainText(
                    "Fuerza: "
                    + QString::number(p.getFuerza())
                    + "\n");
    }
}

void MainWindow::on_actionGuardar_triggered()
{
    qDebug() << "guardar";

    QString ubicacion = QFileDialog::getSaveFileName(this,
                                 "Guardar personajes",
                                 "C:\\",
                                 "TXT (*.txt)");
    qDebug() << ubicacion;

    v.respaldar(ubicacion.toStdString());


}

void MainWindow::on_actionAbrir_triggered()
{
    qDebug() << "abrir";

    QString ubicacion =
            QFileDialog::getOpenFileName(this,
                                         "Abrir archivo",
                                         "C:\\",
                                         "TXT (*.txt)");

    qDebug() << ubicacion;

    v.recuperar(ubicacion.toStdString());
}





