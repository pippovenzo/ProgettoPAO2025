#include "MainWindow.h"
#include <QToolBar>
#include <QAction>
#include <QHBoxLayout>

/*

QT += core widgets
RESOURCES = application.qrc
*/


namespace view{

MainWindow::MainWindow(): QMainWindow(){
    cardView = new CardView(repo);
    setCentralWidget(cardView);


    QAction* file = new QAction("File");
    QAction* edit = new QAction("Edit");
    QAction* view = new QAction("View");

    QToolBar* toolbar = addToolBar(" ");
    toolbar->setFloatable(false);
    toolbar->setMovable(false);
    toolbar->addAction(file);
    toolbar->addAction(edit);
    toolbar->addAction(view);

}
}