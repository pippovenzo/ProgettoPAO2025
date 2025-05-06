#include "MainWindow.h"
#include "Layout/FlowLayout.h"
#include "EditMedia/EditItem.h"
#include "EditMedia/EditVisitor.h"
#include "CreateMedia/CreateWidget.h"
#include "LookupMedia/LookupWidget.h"
#include "LookupMedia/LookupVisitor.h"

#include <QToolBar>
#include <QAction>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QMenuBar>

/*

QT += core widgets
RESOURCES = application.qrc
RESOURCES += application.qrc
*/


namespace view{

MainWindow::MainWindow(): QMainWindow(), repo(""){
    
    QString path = QDir().absolutePath() + "/src/Media/Storage/repository.json";
    repo.setFilePath(path.toStdString());
    
    //repo.setFilePath(QFileDialog::getOpenFileName(this, "Select a json file", "./", "Json (*.json)").toStdString());

    QScrollArea* scrollArea = new QScrollArea(this);
    cardView = new CardView(repo.fetchFromFile());

    scrollArea->setWidget(cardView);
    scrollArea->setWidgetResizable(true);

    QAction* create = new QAction(QIcon(QPixmap((":/src/assets/icons/new.svg"))), "New Media");
    create->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_T));

    QAction* previosPage = new QAction(QIcon(QPixmap((":/src/assets/icons/previous.svg"))), "Previos page");
    previosPage->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_B));
    
    QAction* loadFile = new QAction(QIcon(QPixmap((":/src/assets/icons/load.svg"))), "Load repository");
    loadFile->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT |Qt::Key_T));

    QAction* createRepo = new QAction(QIcon(QPixmap((":/src/assets/icons/load.svg"))), "Create new repository");

    searchBar = new QLineEdit();
    searchBar->setPlaceholderText("Search");

    QMenu* fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(loadFile);
    fileMenu->addAction(createRepo);

    QMenu* mediaMenu = menuBar()->addMenu("&Media");
    mediaMenu->addAction(create);
    //Toolbar creation
    QToolBar* toolbar = addToolBar("");
    toolbar->setFloatable(false);
    toolbar->setMovable(false);

    toolbar->addAction(previosPage);
    toolbar->addSeparator();

    toolbar->addAction(loadFile);
    toolbar->addAction(create);

    QWidget* spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    toolbar->addWidget(spacer);

    toolbar->addWidget(searchBar);
    toolbar->addSeparator();

    QString styleSheet(QString("QToolBar "
        "{background-color: #aeaeae; "
        "border-radius: 1px;"
        "opacity: 0.5;"
        "border: 0px;}"));

    toolbar->setStyleSheet(styleSheet);

    stacked = new QStackedWidget();
    stacked->addWidget(scrollArea);

    connect(cardView, &CardView::editMedia, this, &MainWindow::editMedia);
    connect(cardView, &CardView::lookupMedia, this, &MainWindow::lookupMedia);

    connect(previosPage, &QAction::triggered, this, &MainWindow::goPreviousPage);
    connect(create, &QAction::triggered, this, &MainWindow::createNewMedia);
    connect(loadFile, &QAction::triggered, this, &MainWindow::loadRepository);
    connect(createRepo, &QAction::triggered, this, &MainWindow::createRepository);

    connect(searchBar, &QLineEdit::textChanged, this, std::bind(&MainWindow::search, this, searchBar));

    setCentralWidget(stacked);
}

void MainWindow::editMedia(const media::AbstractMedia* media){
    edit::EditVisitor editVisitor(&repo);
    media->accept(editVisitor);
    
    edit::EditItem* editWidget = editVisitor.getEditWidget();

    connect(editWidget, &edit::EditItem::modifiedMedia, this, &MainWindow::goPreviousPage);

    stacked->addWidget(editWidget);
    stacked->setCurrentIndex(1);
}

void MainWindow::lookupMedia(const media::AbstractMedia* media){
    lookup::LookupVisitor lookupVisitor(&repo);
    media->accept(lookupVisitor);

    lookup::LookupWidget* lookupWidget = lookupVisitor.getLookupWidget();

    stacked->addWidget(lookupWidget);
    stacked->setCurrentIndex(1);

}

void MainWindow::goPreviousPage(){
    if(stacked->count() > 1){
        QWidget* tmp = stacked->widget(1);
        stacked->removeWidget(tmp);
        delete tmp;

        stacked->setCurrentIndex(stacked->currentIndex()-1);
    }

    if(stacked->currentIndex() == 0) updateCardView();
}

void MainWindow::updateCardView(){
    cardView->renderCardView(repo.fetchFromFile());
}

void MainWindow::createNewMedia(){
    create::CreateWidget* createWidget = new create::CreateWidget(&repo.fetchFromFile());

    connect(createWidget, &create::CreateWidget::createdMedia, this, &MainWindow::goPreviousPage);

    stacked->addWidget(createWidget);
    stacked->setCurrentIndex(1);
}

void MainWindow::search(QLineEdit* query){
    std::string filter = query->text().toStdString();
    cardView->renderStringMatching(repo, filter);
}

void MainWindow::loadRepository(){
    std::string newPath = QFileDialog::getOpenFileName(this, "Select a json file", "./", "Json (*.json)").toStdString();

    if(newPath != ""){
        repo.setFilePath(newPath);
    }
    emit updateCardView();
}

void MainWindow::createRepository(){
    std::string filename = "";

    filename = QFileDialog::getSaveFileName(this,  "Create New Repository", QDir().absolutePath(), "Json (*.json)").toStdString();

    QFile newRepo(QString::fromStdString(filename));
    newRepo.open(QIODevice::WriteOnly);
    newRepo.close();

    repo.setFilePath(filename);

    emit updateCardView();
    
}


}
