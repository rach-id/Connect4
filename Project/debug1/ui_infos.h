/********************************************************************************
** Form generated from reading UI file 'infos.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOS_H
#define UI_INFOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Infos
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *Infos)
    {
        if (Infos->objectName().isEmpty())
            Infos->setObjectName(QStringLiteral("Infos"));
        Infos->setEnabled(true);
        Infos->resize(515, 190);
        Infos->setMaximumSize(QSize(597, 295));
        Infos->setStyleSheet(QLatin1String("\n"
"background-image: url(:/rec/rec/dialogue.jpg);"));
        label = new QLabel(Infos);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 90, 151, 31));
        label->setStyleSheet(QLatin1String("background-image: url(:/rec/rec/blue1.jpg);\n"
"font: 22pt \"Source Code Pro\";"));
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Sunken);
        label->setLineWidth(-1);
        label_2 = new QLabel(Infos);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(false);
        label_2->setGeometry(QRect(160, 90, 351, 101));
        label_2->setStyleSheet(QLatin1String("background-image: url(:/rec/rec/blue1.jpg);\n"
"font: 22pt \"Source Code Pro\";"));
        label_2->setFrameShape(QFrame::WinPanel);
        label_3 = new QLabel(Infos);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(400, 50, 101, 31));
        label_3->setStyleSheet(QLatin1String("background-image: url(:/rec/rec/blue1.jpg);\n"
"font: 15pt \"Source Code Pro\";"));
        label_4 = new QLabel(Infos);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 50, 371, 31));
        label_4->setStyleSheet(QLatin1String("background-image: url(:/rec/rec/blue1.jpg);\n"
"font: 11pt \"Source Code Pro\";"));
        label_5 = new QLabel(Infos);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 10, 371, 31));
        label_5->setStyleSheet(QLatin1String("background-image: url(:/rec/rec/blue1.jpg);\n"
"font: 11pt \"Source Code Pro\";"));
        label_6 = new QLabel(Infos);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(400, 10, 101, 31));
        label_6->setStyleSheet(QLatin1String("background-image: url(:/rec/rec/blue1.jpg);\n"
"font: 15pt \"Source Code Pro\";"));

        retranslateUi(Infos);

        QMetaObject::connectSlotsByName(Infos);
    } // setupUi

    void retranslateUi(QDialog *Infos)
    {
        Infos->setWindowTitle(QApplication::translate("Infos", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Infos", "Joueur :", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Infos: public Ui_Infos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOS_H
