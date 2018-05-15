/********************************************************************************
** Form generated from reading UI file 'gameplay.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPLAY_H
#define UI_GAMEPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_GamePLay
{
public:

    void setupUi(QDialog *GamePLay)
    {
        if (GamePLay->objectName().isEmpty())
            GamePLay->setObjectName(QStringLiteral("GamePLay"));
        GamePLay->resize(400, 300);

        retranslateUi(GamePLay);

        QMetaObject::connectSlotsByName(GamePLay);
    } // setupUi

    void retranslateUi(QDialog *GamePLay)
    {
        GamePLay->setWindowTitle(QApplication::translate("GamePLay", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GamePLay: public Ui_GamePLay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPLAY_H
