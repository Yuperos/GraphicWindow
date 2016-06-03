#include "traindraw.h"


void TrainDraw::findBorders()
   {
   if(trains->isEmpty() || trains->at(0).isEmpty()) return;
   bounds[0]=bounds[1]=trains->at(0).at(0);
   for(auto a : *trains){
      for(auto b : a){
         if(bounds[0]>b) bounds[0]=b;
         if(bounds[1]<b) bounds[1]=b;
         }
      }
   }

QColor TrainDraw::valueColor(int value, ValueColorType VCT)
   {
   qreal range = bounds[1] - bounds[0];
   int rgb[3];
   switch(VCT){
      case VCT_Colored:
         {
         int colorVal=((256*7)/range)*(value-bounds[0]);
         int j = colorVal/256 + 1;
         for(int i=0; i<3; i++){
            rgb[i]=128+(fColor[i][j-1])*128;
            if(fColor[i][j-1]!=fColor[i][j])
               rgb[i]+=fColor[i][j]*(colorVal%256);
            }
         } break;
      case VCT_BlackAndWhite:
         {
         int colorVal = (256/range)*(value-bounds[0]);
         rgb[0]=rgb[1]=rgb[2]=colorVal;
         } break;
      default: rgb[0]=rgb[1]=rgb[2]=-1;
      }
   return QColor(rgb[0],rgb[1],rgb[2]);
   }

void TrainDraw::draw()
   {
   QBrush     brush = QBrush(QColor(0,153,255));
   QPen       pen = QPen(QColor(0,153,255),0);
   findBorders();
   gs->clear();

   QPointF scale((qreal)gs->width()/trains->at(0).count(), (qreal)gs->height()/trains->count());
   for(int i=0; i<trains->count(); i++){
      for(int j=0; j<trains->at(i).count(); j++){
         pen.setColor(valueColor(trains->at(i).at(j)));
         brush.setColor(pen.color());
         qreal a[4];
         a[0]=scale.rx()*pow(2,i)*j;
         a[1]=scale.ry()*i;
         a[2]=scale.rx()*pow(2.,i);
         a[3]=scale.ry();
         gs->addPolygon(QPolygonF(QRectF(a[0], a[1], a[2], a[3])), pen,brush);
         }
      }
   }

TrainDraw::TrainDraw()
   {

   }

void TrainDraw::init()
   {

   }

