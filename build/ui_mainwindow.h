/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *leftFrame;
    QVBoxLayout *verticalLayout;
    QGroupBox *scoreBox;
    QVBoxLayout *verticalLayout_2;
    QLCDNumber *scoreDisplay;
    QGroupBox *controlsBox;
    QGridLayout *gridLayout;
    QPushButton *openButton;
    QPushButton *closeButton;
    QPushButton *resetButton;
    QPushButton *aboutButton;
    QSpacerItem *leftFrameSpacer;
    QTabWidget *mainTabs;
    QWidget *overviewTab;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *overviewTable;
    QWidget *headerTab;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *headerTable;
    QWidget *sectionsTab;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *sectionsGrou;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *sectionsTable;
    QGroupBox *sectionDetails;
    QVBoxLayout *verticalLayout_4;
    QPlainTextEdit *sectionInfo;
    QWidget *programsTab;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *programsGroup;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *programsTable;
    QGroupBox *detailsGroup;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *programsInfo;
    QWidget *symbolsTab;
    QHBoxLayout *horizontalLayout_7;
    QTableWidget *symbolsTable;
    QWidget *capabilitiesTab;
    QHBoxLayout *horizontalLayout_8;
    QTreeWidget *capabilitiesTree;
    QWidget *scoringTab;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *scoringTable;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(1000, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/locked"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leftFrame = new QFrame(centralwidget);
        leftFrame->setObjectName(QString::fromUtf8("leftFrame"));
        leftFrame->setMinimumSize(QSize(300, 0));
        leftFrame->setFrameShape(QFrame::StyledPanel);
        leftFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(leftFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scoreBox = new QGroupBox(leftFrame);
        scoreBox->setObjectName(QString::fromUtf8("scoreBox"));
        verticalLayout_2 = new QVBoxLayout(scoreBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scoreDisplay = new QLCDNumber(scoreBox);
        scoreDisplay->setObjectName(QString::fromUtf8("scoreDisplay"));
        scoreDisplay->setMinimumSize(QSize(0, 60));

        verticalLayout_2->addWidget(scoreDisplay);


        verticalLayout->addWidget(scoreBox);

        controlsBox = new QGroupBox(leftFrame);
        controlsBox->setObjectName(QString::fromUtf8("controlsBox"));
        gridLayout = new QGridLayout(controlsBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        openButton = new QPushButton(controlsBox);
        openButton->setObjectName(QString::fromUtf8("openButton"));

        gridLayout->addWidget(openButton, 0, 0, 1, 1);

        closeButton = new QPushButton(controlsBox);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        gridLayout->addWidget(closeButton, 1, 1, 1, 1);

        resetButton = new QPushButton(controlsBox);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        gridLayout->addWidget(resetButton, 0, 1, 1, 1);

        aboutButton = new QPushButton(controlsBox);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));

        gridLayout->addWidget(aboutButton, 1, 0, 1, 1);


        verticalLayout->addWidget(controlsBox);

        leftFrameSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(leftFrameSpacer);


        horizontalLayout->addWidget(leftFrame);

        mainTabs = new QTabWidget(centralwidget);
        mainTabs->setObjectName(QString::fromUtf8("mainTabs"));
        mainTabs->setEnabled(true);
        mainTabs->setTabPosition(QTabWidget::North);
        overviewTab = new QWidget();
        overviewTab->setObjectName(QString::fromUtf8("overviewTab"));
        sizePolicy.setHeightForWidth(overviewTab->sizePolicy().hasHeightForWidth());
        overviewTab->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(overviewTab);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        overviewTable = new QTableWidget(overviewTab);
        if (overviewTable->columnCount() < 1)
            overviewTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        overviewTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (overviewTable->rowCount() < 6)
            overviewTable->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        overviewTable->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        overviewTable->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        overviewTable->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        overviewTable->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        overviewTable->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        overviewTable->setVerticalHeaderItem(5, __qtablewidgetitem6);
        overviewTable->setObjectName(QString::fromUtf8("overviewTable"));
        overviewTable->setContextMenuPolicy(Qt::ActionsContextMenu);
        overviewTable->setAutoFillBackground(false);
        overviewTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        overviewTable->setProperty("showDropIndicator", QVariant(false));
        overviewTable->setDragDropOverwriteMode(false);
        overviewTable->setAlternatingRowColors(true);
        overviewTable->setSelectionMode(QAbstractItemView::SingleSelection);
        overviewTable->setColumnCount(1);
        overviewTable->horizontalHeader()->setVisible(false);
        overviewTable->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_3->addWidget(overviewTable);

        mainTabs->addTab(overviewTab, QString());
        headerTab = new QWidget();
        headerTab->setObjectName(QString::fromUtf8("headerTab"));
        sizePolicy.setHeightForWidth(headerTab->sizePolicy().hasHeightForWidth());
        headerTab->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(headerTab);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        headerTable = new QTableWidget(headerTab);
        if (headerTable->columnCount() < 1)
            headerTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        headerTable->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        if (headerTable->rowCount() < 19)
            headerTable->setRowCount(19);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(6, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(7, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(8, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(9, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(10, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(11, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(12, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(13, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(14, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(15, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(16, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(17, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        headerTable->setVerticalHeaderItem(18, __qtablewidgetitem26);
        headerTable->setObjectName(QString::fromUtf8("headerTable"));
        headerTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        headerTable->setProperty("showDropIndicator", QVariant(false));
        headerTable->setAlternatingRowColors(true);
        headerTable->setSelectionMode(QAbstractItemView::SingleSelection);
        headerTable->horizontalHeader()->setVisible(false);
        headerTable->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_2->addWidget(headerTable);

        mainTabs->addTab(headerTab, QString());
        sectionsTab = new QWidget();
        sectionsTab->setObjectName(QString::fromUtf8("sectionsTab"));
        verticalLayout_5 = new QVBoxLayout(sectionsTab);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        sectionsGrou = new QGroupBox(sectionsTab);
        sectionsGrou->setObjectName(QString::fromUtf8("sectionsGrou"));
        verticalLayout_8 = new QVBoxLayout(sectionsGrou);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        sectionsTable = new QTableWidget(sectionsGrou);
        if (sectionsTable->columnCount() < 8)
            sectionsTable->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        sectionsTable->setHorizontalHeaderItem(0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        sectionsTable->setHorizontalHeaderItem(1, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        sectionsTable->setHorizontalHeaderItem(2, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        sectionsTable->setHorizontalHeaderItem(3, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        sectionsTable->setHorizontalHeaderItem(4, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        sectionsTable->setHorizontalHeaderItem(5, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        sectionsTable->setHorizontalHeaderItem(6, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        sectionsTable->setHorizontalHeaderItem(7, __qtablewidgetitem34);
        sectionsTable->setObjectName(QString::fromUtf8("sectionsTable"));
        sectionsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        sectionsTable->setProperty("showDropIndicator", QVariant(false));
        sectionsTable->setAlternatingRowColors(true);
        sectionsTable->setSelectionMode(QAbstractItemView::SingleSelection);
        sectionsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        sectionsTable->setSortingEnabled(true);
        sectionsTable->horizontalHeader()->setCascadingSectionResizes(false);
        sectionsTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        sectionsTable->horizontalHeader()->setStretchLastSection(false);
        sectionsTable->verticalHeader()->setVisible(false);

        verticalLayout_8->addWidget(sectionsTable);


        verticalLayout_5->addWidget(sectionsGrou);

        sectionDetails = new QGroupBox(sectionsTab);
        sectionDetails->setObjectName(QString::fromUtf8("sectionDetails"));
        sizePolicy.setHeightForWidth(sectionDetails->sizePolicy().hasHeightForWidth());
        sectionDetails->setSizePolicy(sizePolicy);
        sectionDetails->setMinimumSize(QSize(0, 0));
        verticalLayout_4 = new QVBoxLayout(sectionDetails);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        sectionInfo = new QPlainTextEdit(sectionDetails);
        sectionInfo->setObjectName(QString::fromUtf8("sectionInfo"));
        sectionInfo->setReadOnly(true);

        verticalLayout_4->addWidget(sectionInfo);


        verticalLayout_5->addWidget(sectionDetails);

        mainTabs->addTab(sectionsTab, QString());
        programsTab = new QWidget();
        programsTab->setObjectName(QString::fromUtf8("programsTab"));
        verticalLayout_6 = new QVBoxLayout(programsTab);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        programsGroup = new QGroupBox(programsTab);
        programsGroup->setObjectName(QString::fromUtf8("programsGroup"));
        verticalLayout_7 = new QVBoxLayout(programsGroup);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        programsTable = new QTableWidget(programsGroup);
        if (programsTable->columnCount() < 7)
            programsTable->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        programsTable->setHorizontalHeaderItem(0, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        programsTable->setHorizontalHeaderItem(1, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        programsTable->setHorizontalHeaderItem(2, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        programsTable->setHorizontalHeaderItem(3, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        programsTable->setHorizontalHeaderItem(4, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        programsTable->setHorizontalHeaderItem(5, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        programsTable->setHorizontalHeaderItem(6, __qtablewidgetitem41);
        programsTable->setObjectName(QString::fromUtf8("programsTable"));
        programsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        programsTable->setAlternatingRowColors(true);
        programsTable->setSelectionMode(QAbstractItemView::SingleSelection);
        programsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        programsTable->setSortingEnabled(true);
        programsTable->verticalHeader()->setVisible(false);

        verticalLayout_7->addWidget(programsTable);


        verticalLayout_6->addWidget(programsGroup);

        detailsGroup = new QGroupBox(programsTab);
        detailsGroup->setObjectName(QString::fromUtf8("detailsGroup"));
        sizePolicy.setHeightForWidth(detailsGroup->sizePolicy().hasHeightForWidth());
        detailsGroup->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(detailsGroup);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        programsInfo = new QPlainTextEdit(detailsGroup);
        programsInfo->setObjectName(QString::fromUtf8("programsInfo"));
        programsInfo->setReadOnly(true);

        verticalLayout_3->addWidget(programsInfo);


        verticalLayout_6->addWidget(detailsGroup);

        mainTabs->addTab(programsTab, QString());
        symbolsTab = new QWidget();
        symbolsTab->setObjectName(QString::fromUtf8("symbolsTab"));
        horizontalLayout_7 = new QHBoxLayout(symbolsTab);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        symbolsTable = new QTableWidget(symbolsTab);
        if (symbolsTable->columnCount() < 3)
            symbolsTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        symbolsTable->setHorizontalHeaderItem(0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        symbolsTable->setHorizontalHeaderItem(1, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        symbolsTable->setHorizontalHeaderItem(2, __qtablewidgetitem44);
        symbolsTable->setObjectName(QString::fromUtf8("symbolsTable"));
        symbolsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        symbolsTable->setAlternatingRowColors(true);
        symbolsTable->setSelectionMode(QAbstractItemView::SingleSelection);
        symbolsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        symbolsTable->setSortingEnabled(true);

        horizontalLayout_7->addWidget(symbolsTable);

        mainTabs->addTab(symbolsTab, QString());
        capabilitiesTab = new QWidget();
        capabilitiesTab->setObjectName(QString::fromUtf8("capabilitiesTab"));
        horizontalLayout_8 = new QHBoxLayout(capabilitiesTab);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        capabilitiesTree = new QTreeWidget(capabilitiesTab);
        capabilitiesTree->setObjectName(QString::fromUtf8("capabilitiesTree"));
        capabilitiesTree->setEditTriggers(QAbstractItemView::NoEditTriggers);
        capabilitiesTree->setProperty("showDropIndicator", QVariant(false));
        capabilitiesTree->setAlternatingRowColors(true);
        capabilitiesTree->setUniformRowHeights(false);
        capabilitiesTree->setSortingEnabled(true);
        capabilitiesTree->setWordWrap(true);

        horizontalLayout_8->addWidget(capabilitiesTree);

        mainTabs->addTab(capabilitiesTab, QString());
        scoringTab = new QWidget();
        scoringTab->setObjectName(QString::fromUtf8("scoringTab"));
        horizontalLayout_4 = new QHBoxLayout(scoringTab);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        scoringTable = new QTableWidget(scoringTab);
        if (scoringTable->columnCount() < 2)
            scoringTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        scoringTable->setHorizontalHeaderItem(0, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        scoringTable->setHorizontalHeaderItem(1, __qtablewidgetitem46);
        scoringTable->setObjectName(QString::fromUtf8("scoringTable"));
        scoringTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        scoringTable->setProperty("showDropIndicator", QVariant(false));
        scoringTable->setDragDropOverwriteMode(false);
        scoringTable->setAlternatingRowColors(true);
        scoringTable->setSelectionMode(QAbstractItemView::SingleSelection);
        scoringTable->setSortingEnabled(false);
        scoringTable->setColumnCount(2);
        scoringTable->verticalHeader()->setVisible(false);

        horizontalLayout_4->addWidget(scoringTable);

        mainTabs->addTab(scoringTab, QString());

        horizontalLayout->addWidget(mainTabs);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(openButton, SIGNAL(clicked()), MainWindow, SLOT(openFile()));
        QObject::connect(sectionsTable, SIGNAL(currentItemChanged(QTableWidgetItem*,QTableWidgetItem*)), MainWindow, SLOT(sectionSelected(QTableWidgetItem*,QTableWidgetItem*)));
        QObject::connect(programsTable, SIGNAL(currentItemChanged(QTableWidgetItem*,QTableWidgetItem*)), MainWindow, SLOT(programSelected(QTableWidgetItem*,QTableWidgetItem*)));
        QObject::connect(resetButton, SIGNAL(clicked()), MainWindow, SLOT(reset()));
        QObject::connect(closeButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        mainTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ELF Parser", nullptr));
        scoreBox->setTitle(QCoreApplication::translate("MainWindow", "Score", nullptr));
        controlsBox->setTitle(QCoreApplication::translate("MainWindow", "Controls", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        aboutButton->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        QTableWidgetItem *___qtablewidgetitem = overviewTable->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Filename", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = overviewTable->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = overviewTable->verticalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "md5", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = overviewTable->verticalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "sha1", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = overviewTable->verticalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "sha256", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = overviewTable->verticalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Family", nullptr));
        mainTabs->setTabText(mainTabs->indexOf(overviewTab), QCoreApplication::translate("MainWindow", "Overview", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = headerTable->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Magic", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = headerTable->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Class", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = headerTable->verticalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Encoding", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = headerTable->verticalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "ELF Version", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = headerTable->verticalHeaderItem(4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "OS ABI", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = headerTable->verticalHeaderItem(5);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "ABI Version", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = headerTable->verticalHeaderItem(6);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = headerTable->verticalHeaderItem(7);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Machine", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = headerTable->verticalHeaderItem(8);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Version", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = headerTable->verticalHeaderItem(9);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "Entry Point", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = headerTable->verticalHeaderItem(10);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "PH Offset", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = headerTable->verticalHeaderItem(11);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "SH Offset", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = headerTable->verticalHeaderItem(12);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "Flags", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = headerTable->verticalHeaderItem(13);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "Header Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = headerTable->verticalHeaderItem(14);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "PH Entry Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = headerTable->verticalHeaderItem(15);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "PH Entries", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = headerTable->verticalHeaderItem(16);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "SH Entry Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = headerTable->verticalHeaderItem(17);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "SH Entries", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = headerTable->verticalHeaderItem(18);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "String Index", nullptr));
        mainTabs->setTabText(mainTabs->indexOf(headerTab), QCoreApplication::translate("MainWindow", "ELF Header", nullptr));
        sectionsGrou->setTitle(QCoreApplication::translate("MainWindow", "Section Headers", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = sectionsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "Index", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = sectionsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = sectionsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = sectionsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "Flags", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = sectionsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "Virtual Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = sectionsTable->horizontalHeaderItem(5);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "Offset", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = sectionsTable->horizontalHeaderItem(6);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = sectionsTable->horizontalHeaderItem(7);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "Link", nullptr));
        sectionDetails->setTitle(QCoreApplication::translate("MainWindow", "Details", nullptr));
        mainTabs->setTabText(mainTabs->indexOf(sectionsTab), QCoreApplication::translate("MainWindow", "SHeaders", nullptr));
        programsGroup->setTitle(QCoreApplication::translate("MainWindow", "Program Headers", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = programsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = programsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "Offset", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = programsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "Virtual Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = programsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("MainWindow", "Physical Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = programsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("MainWindow", "File Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = programsTable->horizontalHeaderItem(5);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("MainWindow", "Memory Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = programsTable->horizontalHeaderItem(6);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("MainWindow", "Flags", nullptr));
        detailsGroup->setTitle(QCoreApplication::translate("MainWindow", "Details", nullptr));
        mainTabs->setTabText(mainTabs->indexOf(programsTab), QCoreApplication::translate("MainWindow", "PHeaders", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = symbolsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = symbolsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("MainWindow", "Binding", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = symbolsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        mainTabs->setTabText(mainTabs->indexOf(symbolsTab), QCoreApplication::translate("MainWindow", "Symbols", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = capabilitiesTree->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "Details", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Category", nullptr));
        mainTabs->setTabText(mainTabs->indexOf(capabilitiesTab), QCoreApplication::translate("MainWindow", "Capabilities", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = scoringTable->horizontalHeaderItem(0);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("MainWindow", "Score", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = scoringTable->horizontalHeaderItem(1);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("MainWindow", "Reason", nullptr));
        mainTabs->setTabText(mainTabs->indexOf(scoringTab), QCoreApplication::translate("MainWindow", "Scoring", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
