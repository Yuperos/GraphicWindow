#ifndef GRAPHICWINDOW_H
#define GRAPHICWINDOW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QRectF>
#include <QTimer>
#include <random>

#include "traindraw.h"


class GraphicWindow : public QGraphicsView
   {
   Q_OBJECT

   int currX;
   int maxColumns,maxRows;
   TrainDraw td;
   QList<qreal> *list;
   QGraphicsScene *gs;
   QGraphicsItemGroup  *group;
   QTimer *timer;

   void moveAndChop();

public:
   explicit GraphicWindow(QWidget *parent = 0);
   ~GraphicWindow();


   void setList(QList<qreal> *value){ list = value; }
   void setMaxColumns(int value){ maxColumns = value; }


public slots:
   void generate();
   void updateGraph();

signals:
   void generated();
   void updated();

private:
   void resizeEvent(QResizeEvent *event);
   void deleteItemsFromGroup(QGraphicsItemGroup *group);
   };

#endif // GRAPHICWINDOW_H
