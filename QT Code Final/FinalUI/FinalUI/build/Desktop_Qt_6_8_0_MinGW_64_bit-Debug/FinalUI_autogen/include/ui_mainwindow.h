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
    QLabel *ChooseOption;
    QPushButton *AddPlayer;
    QPushButton *ReportMatch;
    QPushButton *FindPlayer;
    QPushButton *Exit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ChooseOption = new QLabel(centralwidget);
        ChooseOption->setObjectName("ChooseOption");
        ChooseOption->setGeometry(QRect(60, 40, 111, 20));
        AddPlayer = new QPushButton(centralwidget);
        AddPlayer->setObjectName("AddPlayer");
        AddPlayer->setGeometry(QRect(190, 40, 81, 24));
        ReportMatch = new QPushButton(centralwidget);
        ReportMatch->setObjectName("ReportMatch");
        ReportMatch->setGeometry(QRect(190, 60, 81, 24));
        FindPlayer = new QPushButton(centralwidget);
        FindPlayer->setObjectName("FindPlayer");
        FindPlayer->setGeometry(QRect(190, 80, 81, 24));
        Exit = new QPushButton(centralwidget);
        Exit->setObjectName("Exit");
        Exit->setGeometry(QRect(190, 100, 81, 24));
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
        ChooseOption->setText(QCoreApplication::translate("MainWindow", "Choose Option", nullptr));
        AddPlayer->setText(QCoreApplication::translate("MainWindow", "Add Player", nullptr));
        ReportMatch->setText(QCoreApplication::translate("MainWindow", "Report Match", nullptr));
        FindPlayer->setText(QCoreApplication::translate("MainWindow", "Find Player", nullptr));
        Exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
