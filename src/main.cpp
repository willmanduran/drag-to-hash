#include <QApplication>
#include <QIcon>
#include "DropWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/resources/icon.png"));

    DropWidget w;
    w.show();
    return app.exec();
}
