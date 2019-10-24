#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>

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
        if((keyEvent->modifiers() & Qt::ShiftModifier)){
            if(unimap_shift.find(keyEvent->text())!=unimap_shift.end()){
                ui->text->insertPlainText(unimap_shift[keyEvent->text()].toUtf8());
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(unimap_unshift.find(keyEvent->text())!=unimap_unshift.end()){
                ui->text->insertPlainText(unimap_unshift[keyEvent->text()].toUtf8());
                return true;
            }
            else{
                return false;
            }
        }
    } else {
        return QObject::eventFilter(obj, event);
    }
}

void MainWindow::createMap(){
    // compile and run ./map/mapCodeGen.cpp file and paste output below
    unimap_shift["_"]="\u0983";
    unimap_shift["<"]="\u09B7";
    unimap_shift[":"]="\u099B";
    unimap_shift["\""]="\u09A0";
    unimap_shift["{"]="\u09A2";
    unimap_shift["}"]="\u099E";
    unimap_shift["?"]="\u09AF";
    unimap_shift["+"]="\u098B";
    unimap_shift["$"]="\u09B0\u09CD";
    unimap_shift["%"]="\u099C\u09CD\u099E";
    unimap_shift["^"]="\u09A4\u09CD\u09B0";
    unimap_shift["&"]="\u0995\u09CD\u09B7";
    unimap_shift["*"]="\u09B6\u09CD\u09B0";
    unimap_shift["A"]="\u0993";
    unimap_shift["C"]="\u09A3";
    unimap_shift["D"]="\u0985";
    unimap_shift["E"]="\u0986";
    unimap_shift["F"]="\u0987";
    unimap_shift["G"]="\u0989";
    unimap_shift["H"]="\u09AB";
    unimap_shift["I"]="\u0998";
    unimap_shift["K"]="\u0996";
    unimap_shift["L"]="\u09A5";
    unimap_shift["M"]="\u09B6";
    unimap_shift["O"]="\u09A7";
    unimap_shift["P"]="\u099D";
    unimap_shift["Q"]="\u0994";
    unimap_shift["R"]="\u0988";
    unimap_shift["S"]="\u098F";
    unimap_shift["T"]="\u098A";
    unimap_shift["U"]="\u0999";
    unimap_shift["W"]="\u0990";
    unimap_shift["X"]="\u0981";
    unimap_shift["Y"]="\u09AD";
    unimap_unshift[";"]="\u099A";
    unimap_unshift["'"]="\u099F";
    unimap_unshift["["]="\u09A1";
    unimap_unshift["]"]="\u09BC";
    unimap_unshift["/"]="\u09DF";
    unimap_unshift["="]="\u09C3";
    unimap_unshift["0"]="\u09E6";
    unimap_unshift["1"]="\u09E7";
    unimap_unshift["2"]="\u09E8";
    unimap_unshift["3"]="\u09E9";
    unimap_unshift["4"]="\u09EA";
    unimap_unshift["5"]="\u09EB";
    unimap_unshift["6"]="\u09EC";
    unimap_unshift["7"]="\u09ED";
    unimap_unshift["8"]="\u09EE";
    unimap_unshift["9"]="\u09EF";
    unimap_unshift["a"]="\u09CB";
    unimap_unshift["b"]="\u09AC";
    unimap_unshift["c"]="\u09AE";
    unimap_unshift["d"]="\u09CD";
    unimap_unshift["e"]="\u09BE";
    unimap_unshift["f"]="\u09BF";
    unimap_unshift["g"]="\u09C1";
    unimap_unshift["h"]="\u09AA";
    unimap_unshift["i"]="\u0997";
    unimap_unshift["j"]="\u09B0";
    unimap_unshift["k"]="\u0995";
    unimap_unshift["l"]="\u09A4";
    unimap_unshift["m"]="\u09B8";
    unimap_unshift["n"]="\u09B2";
    unimap_unshift["o"]="\u09A6";
    unimap_unshift["p"]="\u099C";
    unimap_unshift["q"]="\u09CC";
    unimap_unshift["r"]="\u09C0";
    unimap_unshift["s"]="\u09C7";
    unimap_unshift["t"]="\u09C2";
    unimap_unshift["u"]="\u09B9";
    unimap_unshift["v"]="\u09A8";
    unimap_unshift["w"]="\u09C8";
    unimap_unshift["x"]="\u0982";
    unimap_unshift["y"]="\u09AC";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionShow_Layout_triggered()
{
    QDesktopServices::openUrl(QUrl("https://i.imgur.com/cSqsENx.png", QUrl::TolerantMode));
}

void MainWindow::on_actionShow_Documentation_triggered()
{
    QDesktopServices::openUrl(QUrl("https://help.keyman.com/keyboard/bengali_inscript/1.0/chart.pdf", QUrl::TolerantMode));
}

void MainWindow::on_actionSystems_Lab_JU_BCSE_III_triggered()
{
    QDesktopServices::openUrl(QUrl("http://jaduniv.edu.in", QUrl::TolerantMode));
}
