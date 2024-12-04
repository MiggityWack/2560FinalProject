#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <Qstring>
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
void MainWindow::update_findPlayerOutput(const QString text)
{
    ui->findPlayerOutput->setText(text);
}
void MainWindow::on_exit_clicked(){
    MainWindow::~MainWindow();
}
void MainWindow::on_reportMatch_clicked(){
    tourney.reportMatch(tourney.playerSearch(ui->reportMatchTag1->text().QString::toStdString()), tourney.playerSearch(ui->reportMatchTag2->text().QString::toStdString()), ui->P1Wins->text().toInt(), ui->P2Wins->text().toInt(), false);
}
void MainWindow::on_findPlayer_clicked(){
    Tournament::Player* player = tourney.searchPlayerCaseInsensitive(ui->findPlayerTag->text().QString::toStdString());
    if (player) {
        ui->findPlayerOutput->setText(QString::fromStdString(player->Tournament::Player::stringifyReport()));
    } else {
        ui->findPlayerOutput->setText("No Player Found");
    }
}
void MainWindow::on_addPlayer_clicked(){
    string tag = ui->addPlayerTag->text().QString::toStdString();
    int score = ui->addPlayerScore->text().toInt();
    tourney.addPlayer(tag, score, 0);
    ui->addPlayerTag->setText("Tag");
    ui->addPlayerScore->setText("Score");
}
void MainWindow::on_display_clicked(){

}
void MainWindow::on_importButton_clicked(){
    tourney.importPlayers(ui->importFile->text().QString::toStdString());
}
void MainWindow::on_exportButton_clicked(){
    tourney.savePlayers(ui->exportFile->text().QString::toStdString());
}
