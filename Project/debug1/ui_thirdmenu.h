/********************************************************************************
** Form generated from reading UI file 'thirdmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIRDMENU_H
#define UI_THIRDMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ThirdMenu
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *ThirdMenu)
    {
        if (ThirdMenu->objectName().isEmpty())
            ThirdMenu->setObjectName(QStringLiteral("ThirdMenu"));
        ThirdMenu->resize(800, 566);
        ThirdMenu->setMinimumSize(QSize(800, 566));
        ThirdMenu->setMaximumSize(QSize(800, 566));
        ThirdMenu->setStyleSheet(QStringLiteral("background-image: url(:/rec/rec/thirdMenu.png);"));
        pushButton = new QPushButton(ThirdMenu);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(450, 400, 141, 51));
        pushButton->setStyleSheet(QStringLiteral("background-image: url(:/rec/rec/out.png);"));
        pushButton_2 = new QPushButton(ThirdMenu);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(450, 330, 141, 31));
        pushButton_2->setStyleSheet(QStringLiteral("background-image: url(:/rec/rec/hard.png);"));
        pushButton_3 = new QPushButton(ThirdMenu);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(450, 260, 141, 31));
        pushButton_3->setStyleSheet(QStringLiteral("background-image: url(:/rec/rec/medium.png);"));
        pushButton_4 = new QPushButton(ThirdMenu);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(450, 190, 141, 31));
        pushButton_4->setStyleSheet(QStringLiteral("background-image: url(:/rec/rec/easy.png);"));

        retranslateUi(ThirdMenu);

        QMetaObject::connectSlotsByName(ThirdMenu);
    } // setupUi

    void retranslateUi(QDialog *ThirdMenu)
    {
        ThirdMenu->setWindowTitle(QApplication::translate("ThirdMenu", "Dialog", Q_NULLPTR));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ThirdMenu: public Ui_ThirdMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIRDMENU_H
