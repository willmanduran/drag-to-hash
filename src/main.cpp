#include <QApplication>
#include "DropWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    DropWidget w;
    w.show();
    return app.exec();
}
