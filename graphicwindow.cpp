#include "graphicwindow.h"
#include "ui_graphicwindow.h"

GraphicWindow::GraphicWindow(QWidget *parent)
   : QGraphicsView(parent)
{
   this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   this->setAlignment(Qt::AlignCenter);
   this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
   this->setMinimumHeight(100);
   this->setMinimumWidth(100);


   gs=new QGraphicsScene();
   this->setScene(gs);
   this->maxColumns = this->size().width();
   group = new QGraphicsItemGroup();
   group->setCacheMode(QGraphicsItem::ItemCoordinateCache);
   gs->addItem(group);

   currX=0;
   timer = new QTimer();
   list = new QList<qreal>();

   for(int i=0; i<this->minimumHeight();++i){
      list->append(1);
      }

   //connect(gs, &QGraphicsScene::changed, this, &GraphicWindow::start);

   connect(this, &GraphicWindow::generated, this, &GraphicWindow::updateGraph);
   connect(this, &GraphicWindow::updated, this, &GraphicWindow::generate);
   }

GraphicWindow::~GraphicWindow() { }

void GraphicWindow::updateGraph()
   {
   QPen pen(QColor(0,153,255),0);
   if (td.canImproveBounds()) td.findBorders(list);
   for(int i =0; i<list->count(); ++i){
      pen.setColor(td.valueColor(list->at(i)));
      group->addToGroup(gs->addLine(currX,i,currX,i+1,pen));
      }
   ++currX;
   if (currX>=maxColumns) moveAndChop();
   emit updated();
   }

void GraphicWindow::moveAndChop()
   {
   QTransform xform = group->deviceTransform(this->viewportTransform());
   QRect deviceRect = xform.mapRect(this->rect());
   this->viewport()->scroll(-1, 0, deviceRect);
   --currX;
   }

void GraphicWindow::resizeEvent(QResizeEvent *event)
   {
   this->maxColumns = this->size().width();
   int d= this->size().height() - this->maxRows;
   if (d>0)
      for(int i=0; i<d; ++i){
         list->append(1);
         }
   this->maxRows = this->size().height();
   QGraphicsView::resizeEvent(event);
   }

void GraphicWindow::generate()
   {
   for(int i=0; i<maxRows; ++i){
      qreal val = 0.8*list->at(i) + 0.2*(rand()%2000);
      list->insert(i,val);
      }
   emit generated();
   }
