#include "childwindow.h"
#include "ui_childwindow.h"


#include <QApplication>
#include <QTextStream>
#include <QTranslator>
#include <QtScript>

#include <QFile>

childwindow::childwindow(QWidget *parent, QString *filename) :
    QWidget(parent),
    ui(new Ui::childwindow)
{
    QFile file;
    file.setFileName(*filename);
    file.open(QIODevice::ReadOnly);

    ui->setupUi(this);

    QString script = file.readAll();

    QScriptEngine engine;

    QScriptValue appContext = engine.newQObject(ui->textEdit);
    engine.globalObject().setProperty("app", appContext);


    QScriptValue result = engine.evaluate(script);

    if (engine.hasUncaughtException())
      {
          int line = engine.uncaughtExceptionLineNumber();
          QString err = result.toString();
          QString msg = QString("Error at line %1: %2")
              .arg(line).arg(err);

          ui->txtDebug->setPlainText(msg);
      }

    this->showMaximized();
}

childwindow::~childwindow()
{
    delete ui;
}
