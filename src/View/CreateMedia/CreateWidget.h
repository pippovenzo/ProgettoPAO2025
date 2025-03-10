#ifndef CREATE_WIDGET_H
#define CREATE_WIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QStackedWidget>

#include "../../Media/Storage/JsonStorage.h"


namespace view{
namespace create{
    class CreateWidget: public QWidget{
        Q_OBJECT
        public:
            explicit CreateWidget(media::storage::JsonStorage* repo, QWidget* parent = 0);
        private:
            QComboBox* type;
            QStackedWidget* stacked;

        public slots:
            void renderCreateWidget(media::storage::JsonStorage* repo);

        signals:
            void createdMedia();
    };
}
}

#endif