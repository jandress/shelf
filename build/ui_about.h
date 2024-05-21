/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *imageLabel;
    QSpacerItem *verticalSpacer;
    QPushButton *closeButton;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *versionBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QGroupBox *creditsBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->resize(675, 324);
        horizontalLayout = new QHBoxLayout(About);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame_3 = new QFrame(About);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMinimumSize(QSize(200, 300));
        frame_3->setMaximumSize(QSize(200, 300));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        imageLabel = new QLabel(frame_3);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy1);
        imageLabel->setMinimumSize(QSize(185, 185));
        imageLabel->setMaximumSize(QSize(185, 185));
        imageLabel->setScaledContents(true);
        imageLabel->setWordWrap(true);

        verticalLayout_5->addWidget(imageLabel);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_5->addItem(verticalSpacer);

        closeButton = new QPushButton(frame_3);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        verticalLayout_5->addWidget(closeButton);

        imageLabel->raise();
        closeButton->raise();

        horizontalLayout->addWidget(frame_3);

        frame_2 = new QFrame(About);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        versionBox = new QGroupBox(frame_2);
        versionBox->setObjectName(QString::fromUtf8("versionBox"));
        verticalLayout_2 = new QVBoxLayout(versionBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(versionBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);


        verticalLayout->addWidget(versionBox);

        creditsBox = new QGroupBox(frame_2);
        creditsBox->setObjectName(QString::fromUtf8("creditsBox"));
        verticalLayout_3 = new QVBoxLayout(creditsBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(creditsBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);


        verticalLayout->addWidget(creditsBox);

        groupBox = new QGroupBox(frame_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);


        verticalLayout->addWidget(groupBox);


        horizontalLayout->addWidget(frame_2);


        retranslateUi(About);
        QObject::connect(closeButton, SIGNAL(clicked()), About, SLOT(close()));

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QCoreApplication::translate("About", "Dialog", nullptr));
        imageLabel->setText(QString());
        closeButton->setText(QCoreApplication::translate("About", "Close", nullptr));
        versionBox->setTitle(QCoreApplication::translate("About", "Version", nullptr));
        label->setText(QCoreApplication::translate("About", "<html><head/><body><p><span style=\" font-weight:600;\">Version</span>: 1.4.0<br/><span style=\" font-weight:600;\">License: </span><a href=\"https://creativecommons.org/licenses/by-nc-sa/3.0/us/\"><span style=\" text-decoration: underline; color:#0000ff;\">CC BY-NC-SA 3.0 US</span></a><br/><span style=\" font-weight:600;\">Release Date:</span> November 2, 2014<br/><span style=\" font-weight:600;\">Copyright: </span>2014 Jacob Baines<br/><span style=\" font-weight:600;\">Website: </span><a href=\"http://www.elfparser.com\"><span style=\" text-decoration: underline; color:#0000ff;\">www.elfparser.com</span></a></p></body></html>", nullptr));
        creditsBox->setTitle(QCoreApplication::translate("About", "Attribution", nullptr));
        label_2->setText(QCoreApplication::translate("About", "<html><head/><body><span style=\" font-weight:600;\">Icon:</span> by iconsmind.com licensed using the <a href=\"http://creativecommons.org/licenses/by/3.0/us/\"><span style=\" text-decoration: underline; color:#0000ff;\">CC BY 3.0</span></a> license<br><span style=\" font-weight:600;\">Hashing:</span> by Stephan Brumme licensed using the zlib license<br><span style=\" font-weight:600;\">UI:</span> Qt is licensed using the LGPL</body></html>", nullptr));
        groupBox->setTitle(QCoreApplication::translate("About", "Report Bugs", nullptr));
        label_3->setText(QCoreApplication::translate("About", "<html><head/><body><p>Please report bugs to <a href=\"admin@elfparser.com\"><span style=\" text-decoration: underline; color:#0000ff;\">admin@elfparser.com</span></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
