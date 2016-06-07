#ifndef GRAPHICWINDOW_H
#define GRAPHICWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QGraphicsScene>
#include <random>
#include <QTime>

#include "traindraw.h"

namespace Ui {
   class GraphicWindow;
   }

class GraphicWindow : public QMainWindow
   {
   Q_OBJECT

   TrainDraw td;
   QList<QList<int> > *list;
   QGraphicsScene *gs;
   QGraphicsView *gv;


public:
   explicit GraphicWindow(QWidget *parent = 0);
   ~GraphicWindow();

public slots:
   void start();

signals:
   void painted();

private:
   Ui::GraphicWindow *ui;
   };

#endif // GRAPHICWINDOW_H
