#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tournamentClass.h"
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
    Tournament tourney;
    QString filename;

private slots:
    void on_exit_clicked();
    void on_reportMatch_clicked();
    void on_findPlayer_clicked();
    void on_addPlayer_clicked();
    void on_display_clicked();
    void on_importButton_clicked();
    void on_exportButton_clicked();
    void update_findPlayerOutput(const QString text);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
