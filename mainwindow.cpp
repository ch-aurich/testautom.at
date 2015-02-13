#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "childwindow.h"

#include <QMdiSubWindow>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <vitrek.h>

//MainWindow::MainWindow(QWidget *parent, QSqlDatabase *db) :
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(openChildWindow()));

//    QSqlQuery query("SELECT * FROM device_type", *db);

//    QMessageBox::critical(0,"count columns", QString("%1").arg(query.record().count()));
//    QMessageBox::critical(0,"count columns", QString("%1").arg(query.size()));
    Vitrek *v = new Vitrek("/dev/ttyUSB0");
    v->sequence_set_name("test");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openChildWindow()
{
    QString filename = QFileDialog::getOpenFileName(this,
         tr("Open Test"), "", tr("Test Files (*.js)"));



    QMdiSubWindow* sw = new QMdiSubWindow( ui->mdiArea );
    sw->setWidget( new childwindow( sw, &filename ) );
    sw->setAttribute( Qt::WA_DeleteOnClose );
    ui->mdiArea->addSubWindow( sw );
    sw->showMaximized();
}
