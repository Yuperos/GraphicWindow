#include "graphicwindow.h"
#include "ui_graphicwindow.h"


GraphicWindow::GraphicWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::GraphicWindow)
   {
   ui->setupUi(this);

   ui->centralWidget->setGeometry(0,0,640, 480);



   gs=new QGraphicsScene(this);
   gs->setSceneRect(0, 0, 640, 480);
   ui->graphicsView->setScene(gs);
   gv= ui->graphicsView;
   gv->setFixedHeight(gs->height());
   gv->setFixedWidth(gs->width());

   list = new QList<QList<int> >();
   td.setGS(gs);
   td.setTrains(list);

   connect(ui->pushButton, &QPushButton::clicked, this, &GraphicWindow::start );

   }

GraphicWindow::~GraphicWindow()
   {
   delete ui;
   }

void GraphicWindow::start()
   {
   list->clear();
   int maxCount=pow(2,9);
   int i=1;
   while(maxCount>=pow(2,i)){
      list->append(QList<int>());
      for(int j =0; j<maxCount/pow(2,i); j++)
         (*list)[i-1].append(rand()%2000);
      i++;
      }
   td.draw();

   }
