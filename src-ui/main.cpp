#include "lib_mw.h"
#include "Library.h"
#include "Console.h"
#include "Menu.h"
#include <QApplication>
#include <QMessageBox>

Console con;
Library lib;
Menu m(&lib);
std::string loginID = "-1";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lib.init();
    QT_REQUIRE_VERSION(argc, argv, "5.10.1");
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);//解决Qt在Retina屏幕上图片模糊问题
    Lib_MW w;
    w.show();

    return a.exec();
}
