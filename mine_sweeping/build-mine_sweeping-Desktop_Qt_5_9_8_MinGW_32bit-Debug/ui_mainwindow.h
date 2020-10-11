/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRestart;
    QAction *actionExit;
    QAction *actionprimary;
    QAction *actionmedium;
    QAction *actionexpert;
    QAction *actionVersion;
    QAction *actionAuthor;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuOption;
    QMenu *menuLevel;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionRestart = new QAction(MainWindow);
        actionRestart->setObjectName(QStringLiteral("actionRestart"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionprimary = new QAction(MainWindow);
        actionprimary->setObjectName(QStringLiteral("actionprimary"));
        actionmedium = new QAction(MainWindow);
        actionmedium->setObjectName(QStringLiteral("actionmedium"));
        actionexpert = new QAction(MainWindow);
        actionexpert->setObjectName(QStringLiteral("actionexpert"));
        actionVersion = new QAction(MainWindow);
        actionVersion->setObjectName(QStringLiteral("actionVersion"));
        actionAuthor = new QAction(MainWindow);
        actionAuthor->setObjectName(QStringLiteral("actionAuthor"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuOption = new QMenu(menuBar);
        menuOption->setObjectName(QStringLiteral("menuOption"));
        menuLevel = new QMenu(menuOption);
        menuLevel->setObjectName(QStringLiteral("menuLevel"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuOption->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuOption->addAction(actionRestart);
        menuOption->addAction(menuLevel->menuAction());
        menuOption->addAction(actionExit);
        menuLevel->addAction(actionprimary);
        menuLevel->addAction(actionmedium);
        menuLevel->addAction(actionexpert);
        menuAbout->addAction(actionVersion);
        menuAbout->addAction(actionAuthor);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionRestart->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionRestart->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionprimary->setText(QApplication::translate("MainWindow", "primary", Q_NULLPTR));
        actionmedium->setText(QApplication::translate("MainWindow", "medium", Q_NULLPTR));
        actionexpert->setText(QApplication::translate("MainWindow", "expert", Q_NULLPTR));
        actionVersion->setText(QApplication::translate("MainWindow", "Version", Q_NULLPTR));
        actionAuthor->setText(QApplication::translate("MainWindow", "Author", Q_NULLPTR));
        menuOption->setTitle(QApplication::translate("MainWindow", "Option", Q_NULLPTR));
        menuLevel->setTitle(QApplication::translate("MainWindow", "Level", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
