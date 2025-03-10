#include "CreateWidget.h"
#include "../EditMedia/EditItem.h"

#include <QVBoxLayout>

namespace view{
namespace create{

CreateWidget::CreateWidget(media::storage::JsonStorage* repo, QWidget* parent): QWidget(parent){
    QVBoxLayout* vbox = new QVBoxLayout(this);
    stacked = new QStackedWidget();

    edit::EditItem* editWidget = new edit::EditItem(repo);

    type = new QComboBox();
    type->addItem("Album");
    type->addItem("Article");
    type->addItem("Book");
    type->addItem("Film");
    type->addItem("Song");

    vbox->addWidget(type);
    vbox->addWidget(stacked);

    connect(type, &QComboBox::currentTextChanged, this, std::bind(&CreateWidget::renderCreateWidget, this, repo));
   

    renderCreateWidget(repo);
}


void CreateWidget::renderCreateWidget(media::storage::JsonStorage* repo){
    if(stacked->count() > 0){
        QWidget* tmp = stacked->widget(0);
        stacked->removeWidget(tmp);
        delete tmp;
    }
    edit::EditItem* editWidget = new edit::EditItem(repo);
    editWidget->renderForCreate(type->currentText().toStdString());

    stacked->addWidget(editWidget);

    connect(editWidget, &edit::EditItem::modifiedMedia, this, &CreateWidget::createdMedia);
}

}
}


