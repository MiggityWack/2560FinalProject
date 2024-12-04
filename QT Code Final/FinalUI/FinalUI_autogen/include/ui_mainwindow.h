/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *addPlayer;
    QPushButton *reportMatch;
    QPushButton *findPlayer;
    QPushButton *exit;
    QLineEdit *addPlayerTag;
    QLineEdit *reportMatchTag1;
    QLineEdit *findPlayerTag;
    QLineEdit *addPlayerScore;
    QLineEdit *reportMatchTag2;
    QLineEdit *P1Wins;
    QLineEdit *P2Wins;
    QPushButton *importButton;
    QPushButton *exportButton;
    QLineEdit *importFile;
    QLineEdit *exportFile;
    QPushButton *display;
    QLabel *findPlayerOutput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        addPlayer = new QPushButton(centralwidget);
        addPlayer->setObjectName("addPlayer");
        addPlayer->setGeometry(QRect(50, 30, 101, 24));
        reportMatch = new QPushButton(centralwidget);
        reportMatch->setObjectName("reportMatch");
        reportMatch->setGeometry(QRect(50, 50, 101, 24));
        findPlayer = new QPushButton(centralwidget);
        findPlayer->setObjectName("findPlayer");
        findPlayer->setGeometry(QRect(50, 70, 101, 24));
        exit = new QPushButton(centralwidget);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(50, 130, 101, 24));
        addPlayerTag = new QLineEdit(centralwidget);
        addPlayerTag->setObjectName("addPlayerTag");
        addPlayerTag->setGeometry(QRect(160, 30, 113, 22));
        reportMatchTag1 = new QLineEdit(centralwidget);
        reportMatchTag1->setObjectName("reportMatchTag1");
        reportMatchTag1->setGeometry(QRect(160, 50, 113, 22));
        findPlayerTag = new QLineEdit(centralwidget);
        findPlayerTag->setObjectName("findPlayerTag");
        findPlayerTag->setGeometry(QRect(160, 70, 113, 22));
        addPlayerScore = new QLineEdit(centralwidget);
        addPlayerScore->setObjectName("addPlayerScore");
        addPlayerScore->setGeometry(QRect(280, 30, 113, 22));
        reportMatchTag2 = new QLineEdit(centralwidget);
        reportMatchTag2->setObjectName("reportMatchTag2");
        reportMatchTag2->setGeometry(QRect(280, 50, 113, 22));
        P1Wins = new QLineEdit(centralwidget);
        P1Wins->setObjectName("P1Wins");
        P1Wins->setGeometry(QRect(400, 50, 51, 22));
        P2Wins = new QLineEdit(centralwidget);
        P2Wins->setObjectName("P2Wins");
        P2Wins->setGeometry(QRect(460, 50, 51, 22));
        importButton = new QPushButton(centralwidget);
        importButton->setObjectName("importButton");
        importButton->setGeometry(QRect(50, 10, 101, 24));
        exportButton = new QPushButton(centralwidget);
        exportButton->setObjectName("exportButton");
        exportButton->setGeometry(QRect(50, 110, 101, 24));
        importFile = new QLineEdit(centralwidget);
        importFile->setObjectName("importFile");
        importFile->setGeometry(QRect(160, 10, 113, 22));
        exportFile = new QLineEdit(centralwidget);
        exportFile->setObjectName("exportFile");
        exportFile->setGeometry(QRect(160, 110, 113, 22));
        display = new QPushButton(centralwidget);
        display->setObjectName("display");
        display->setGeometry(QRect(50, 90, 101, 24));
        findPlayerOutput = new QLabel(centralwidget);
        findPlayerOutput->setObjectName("findPlayerOutput");
        findPlayerOutput->setGeometry(QRect(280, 75, 291, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addPlayer->setText(QCoreApplication::translate("MainWindow", "Add Player", nullptr));
        reportMatch->setText(QCoreApplication::translate("MainWindow", "Report Match", nullptr));
        findPlayer->setText(QCoreApplication::translate("MainWindow", "Find Player", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        addPlayerTag->setText(QCoreApplication::translate("MainWindow", "Tag", nullptr));
        reportMatchTag1->setText(QCoreApplication::translate("MainWindow", "Player 1", nullptr));
        findPlayerTag->setText(QCoreApplication::translate("MainWindow", "Tag", nullptr));
        addPlayerScore->setText(QCoreApplication::translate("MainWindow", "Score", nullptr));
        reportMatchTag2->setText(QCoreApplication::translate("MainWindow", "Player 2", nullptr));
        P1Wins->setText(QCoreApplication::translate("MainWindow", "P1Wins", nullptr));
        P2Wins->setText(QCoreApplication::translate("MainWindow", "P2Wins", nullptr));
        importButton->setText(QCoreApplication::translate("MainWindow", "Import", nullptr));
        exportButton->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        importFile->setText(QCoreApplication::translate("MainWindow", "File Name", nullptr));
        exportFile->setText(QCoreApplication::translate("MainWindow", "File Name", nullptr));
        display->setText(QCoreApplication::translate("MainWindow", "Display Bracket", nullptr));
        findPlayerOutput->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
