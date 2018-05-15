/********************************************************************************
** Form generated from reading UI file 'secondmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDMENU_H
#define UI_SECONDMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_secondMenu
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *secondMenu)
    {
        if (secondMenu->objectName().isEmpty())
            secondMenu->setObjectName(QStringLiteral("secondMenu"));
        secondMenu->resize(800, 566);
        secondMenu->setMinimumSize(QSize(800, 566));
        secondMenu->setMaximumSize(QSize(800, 566));
        secondMenu->setStyleSheet(QStringLiteral("background-image: url(:/rec/rec/secondMenu.png);"));
        pushButton = new QPushButton(secondMenu);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(440, 210, 161, 31));
        pushButton->setAcceptDrops(false);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QStringLiteral("background-image: url(:/rec/rec/simulation.png);"));
        pushButton_2 = new QPushButton(secondMenu);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(true);
        pushButton_2->setGeometry(QRect(440, 270, 161, 31));
        pushButton_2->setAcceptDrops(false);
        pushButton_2->setAutoFillBackground(false);
        pushButton_2->setStyleSheet(QStringLiteral("background-image: url(:/rec/rec/game.png);"));
        pushButton_3 = new QPushButton(secondMenu);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(true);
        pushButton_3->setGeometry(QRect(460, 400, 121, 51));
        pushButton_3->setAcceptDrops(false);
        pushButton_3->setAutoFillBackground(false);
        pushButton_3->setStyleSheet(QStringLiteral("background-image: url(:/rec/rec/out.png);"));

        retranslateUi(secondMenu);

        QMetaObject::connectSlotsByName(secondMenu);
    } // setupUi

    void retranslateUi(QDialog *secondMenu)
    {
        secondMenu->setWindowTitle(QApplication::translate("secondMenu", "Dialog", Q_NULLPTR));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class secondMenu: public Ui_secondMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDMENU_H
