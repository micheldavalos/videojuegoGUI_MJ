#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QTableWidgetItem>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->crear, SIGNAL(clicked()),
            this, SLOT(click_inicializar()));
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

void MainWindow::click_inicializar()
{
    qDebug() << "inicializar";

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

    int n = ui->n->value();

    v.inicializar(p, size_t(n));
}






void MainWindow::on_mostrar_tabla_clicked()
{
    qDebug() << "mostrar tabla";
    vector<Personaje> personajes;
    for (size_t i = 0; i < v.size(); i++) {
        personajes.push_back(v[i]);
    }
    mostrar_tabla(personajes);

}

void MainWindow::mostrar_tabla(vector<Personaje> &per)
{
    ui->tabla->clear();
    ui->tabla->setColumnCount(4);
    ui->tabla->setRowCount(per.size());

    QStringList headers;
    headers << "Nombre" << "Tipo" << "Fuerza" << "Salud";

    ui->tabla->setHorizontalHeaderLabels(headers);

    size_t row = 0;
    for (size_t i = 0; i < per.size(); i++) {
        Personaje &p = per[i];
        QString nombre =
                QString::fromStdString(p.getNombre());
        QString tipo = QString::fromStdString(p.getTipo());
        QString fuerza = QString::number(p.getFuerza());
        QString salud = QString::number(p.getSalud());

        ui->tabla->setItem(row, 0,
                           new QTableWidgetItem(nombre));
        ui->tabla->setItem(row, 1,
                           new QTableWidgetItem(tipo));
        ui->tabla->setItem(row, 2,
                           new QTableWidgetItem(fuerza));
        ui->tabla->setItem(row, 3,
                           new QTableWidgetItem(salud));
        row++;
    }
}

void MainWindow::on_actionNombre_triggered()
{
    v.sort();
}

void MainWindow::on_actionSalud_triggered()
{
    v.sort_salud();
}

void MainWindow::on_buscar_clicked()
{
    QString texto = ui->lineEdit_buscar->text();
    qDebug() << texto;

    Personaje p;
    p.setNombre(texto.toStdString());

    Personaje *ptr = v.buscar(p);

    if (ptr == nullptr) {
        QMessageBox::warning(this, "Buscar", "No encontrado");
    }
    else {
        vector<Personaje> personajes;
        personajes.push_back(*ptr);

        mostrar_tabla(personajes);
    }

}










