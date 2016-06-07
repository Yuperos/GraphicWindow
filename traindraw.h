#ifndef TRAINDRAW_H
#define TRAINDRAW_H

#include <QtCore>
#include <QGraphicsScene>

enum ValueColorType
   {
   VCT_BlackAndWhite,
   VCT_Colored
   };

class TrainDraw : public QObject
   {
   Q_OBJECT

   int fColor[3][8]={{-1,-1,1,1,1,-1,-1,1},
                     {-1,-1,-1,-1,1,1,1,1},
                     {-1,1,1,-1,-1,-1,1,1}};
   qreal bounds[2];
   QList<QList<int> > *trains;
   QGraphicsScene *gs;
public:
   TrainDraw();

   void init();
   void setGS(QGraphicsScene *value){ gs = value; }
   void setTrains(QList<QList<int> > *value){ trains = value; }
   void findBorders();
   QColor valueColor(int value, ValueColorType VCT = VCT_Colored);

public slots:
   void draw();
   };

#endif // TRAINDRAW_H
