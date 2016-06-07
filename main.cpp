#include "graphicwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
   {
   QApplication a(argc, argv);
   GraphicWindow w;
   w.show();

   return a.exec();
   }
