//boost free
void on_aboutButton_clicked();
#ifdef QT_GUI
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


//#include <boost/scoped_ptr.hpp>
#include <memory>

//#include <boost/ptr_container/ptr_vector.hpp>
#include <vector>

namespace Ui {
    class MainWindow;
}
class ELFParser;
class QTableWidgetItem;
class QTreeWidgetItem;

class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void reset();
    void openFile();
    void closeAbout();
    void overviewToClipboard();
    void on_aboutButton_clicked();
    void sectionSelected(QTableWidgetItem*, QTableWidgetItem*);
    void programSelected(QTableWidgetItem*, QTableWidgetItem*);

// private:
//     //! The main window that is created by mainwindow.ui
//     Ui::MainWindow* m_ui;

//     //! The dialog window
//     boost::scoped_ptr<QDialog> m_dialog;

//     //! All the allocated Table values
//     boost::ptr_vector<QTableWidgetItem> m_tableItems;

//     //! All the allocated Tree values
//     boost::ptr_vector<QTreeWidgetItem> m_treeItems;

//     //! The reusable copy action
//     boost::scoped_ptr<QAction> m_copyAction;

//     //! The reusable ELF parser
//     boost::scoped_ptr<ELFParser> m_parser;
// };
private:
    //! The main window that is created by mainwindow.ui
    Ui::MainWindow* m_ui;

    //! The dialog window
    std::unique_ptr<QDialog> m_dialog;

    //! All the allocated Table values
    std::vector<std::unique_ptr<QTableWidgetItem>> m_tableItems;

    //! All the allocated Tree values
    std::vector<std::unique_ptr<QTreeWidgetItem>> m_treeItems;

    //! The reusable copy action
    std::unique_ptr<QAction> m_copyAction;

    //! The reusable ELF parser
    std::unique_ptr<ELFParser> m_parser;
};

#endif // MAINWINDOW_H
#endif
