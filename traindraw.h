#ifndef TRAINDRAW_H
#define TRAINDRAW_H

#include <QColor>
#include <QList>

enum ValueColorType
   {
   VCT_BlackAndWhite,
   VCT_Colored
   };

class TrainDraw
   {
   int fColor[3][8]={{-1,-1,1,1,1,-1,-1,1},
                     {-1,-1,-1,-1,1,1,1,1},
                     {-1,1,1,-1,-1,-1,1,1}};
   qreal bounds[3];

public:
   TrainDraw();

   void init();
   void findBorders(QList<qreal> *li);
   bool canImproveBounds();
   QColor valueColor(int value, ValueColorType VCT = VCT_BlackAndWhite);
   };

#endif // TRAINDRAW_H
