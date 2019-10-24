#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMap>
#include <QEvent>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_actionShow_Layout_triggered();

    void on_actionShow_Documentation_triggered();

    void on_actionSystems_Lab_JU_BCSE_III_triggered();

private:
    Ui::MainWindow *ui;
    QMap<QString, QString> unimap_shift;
    QMap<QString, QString> unimap_unshift;
    void createMap();

protected:
    bool eventFilter(QObject *obj, QEvent *event);
//    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
