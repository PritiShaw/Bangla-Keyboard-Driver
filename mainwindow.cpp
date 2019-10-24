#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPlainTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->text->setPlaceholderText(QString::fromUtf8("\u098F\u0996\u09BE\u09A8\u09C7 \u09B2\u09BF\u0996\u09C1\u09A8..."));
    createMap();
    ui->text->installEventFilter(this);
//    ui->menuBar->setStyleSheet("QMenu::item {"
//                                  "padding: 2px 5px 2px 2px;"
//                                  "}"
//                                  "QMenu::item:selected {"
//                                  "background-color: rgb(0, 85, 127);"
//                                  "color: rgb(255, 255, 255);"
//                                  "}");

}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if(unimap.find(keyEvent->text())!=unimap.end()/* && (keyEvent->modifiers() & Qt::ShiftModifier)*/){
            ui->text->insertPlainText(unimap[keyEvent->text()].toUtf8());
            return true;
        }
        else
            return false;
    } else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}

void MainWindow::createMap(){
    unimap["."]="\u09F7";
    unimap["-"]="\u0983";
    unimap[","]="\u09B7";
    unimap[";"]="\u099A";
    unimap[";"]="\u099B";
    unimap["'"]="\u099F";
    unimap["'"]="\u09A0";
    unimap["["]="\u09A1";
    unimap["["]="\u09A2";
    unimap["]"]="\u09BC";
    unimap["]"]="\u099E";
    unimap["/"]="\u09DF";
    unimap["/"]="\u09AF";
    unimap["="]="\u09C3";
    unimap["="]="\u098B";
    unimap["a"]="\u09CB";
    unimap["A"]="\u0993";
    unimap["b"]="\u09AC";
    unimap["c"]="\u09AE";
    unimap["C"]="\u09A3";
    unimap["d"]="\u09CD";
    unimap["D"]="\u0985";
    unimap["e"]="\u09BE";
    unimap["E"]="\u0986";
    unimap["f"]="\u09BF";
    unimap["F"]="\u0987";
    unimap["g"]="\u09C1";
    unimap["G"]="\u0989";
    unimap["h"]="\u09AA";
    unimap["H"]="\u09AB";
    unimap["i"]="\u0997";
    unimap["I"]="\u0998";
    unimap["j"]="\u09B0";
    unimap["k"]="\u0995";
    unimap["K"]="\u0996";
    unimap["l"]="\u09A4";
    unimap["L"]="\u09A5";
    unimap["m"]="\u09B8";
    unimap["M"]="\u09B6";
    unimap["n"]="\u09B2";
    unimap["o"]="\u09A6";
    unimap["O"]="\u09A7";
    unimap["p"]="\u099C";
    unimap["P"]="\u099D";
    unimap["q"]="\u09CC";
    unimap["Q"]="\u0994";
    unimap["r"]="\u09C0";
    unimap["R"]="\u0988";
    unimap["s"]="\u09C7";
    unimap["S"]="\u098F";
    unimap["t"]="\u09C2";
    unimap["T"]="\u098A";
    unimap["u"]="\u09B9";
    unimap["U"]="\u0999";
    unimap["v"]="\u09A8";
    unimap["w"]="\u09C8";
    unimap["W"]="\u0990";
    unimap["x"]="\u0982";
    unimap["X"]="\u0981";
    unimap["y"]="\u09AC";
    unimap["Y"]="\u09AD";
}

MainWindow::~MainWindow()
{
    delete ui;
}
