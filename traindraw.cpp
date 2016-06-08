#include "traindraw.h"


void TrainDraw::findBorders(QList<qreal> *li)
   {
   qreal temp[2] ={li->at(0), li->at(0)};

   for(auto a : *li){
      if(temp[0]>a) temp[0]=a;
      if(temp[1]<a) temp[1]=a;
      }
   bounds[0]=bounds[0]*(1.-bounds[2])+temp[0]*bounds[2];
   bounds[1]=bounds[1]*(1.-bounds[2])+temp[1]*bounds[2];
   bounds[2]*=0.9;
   }

bool TrainDraw::canImproveBounds()
   {
   return bounds[2]>0.00001;
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
            rgb[i]=127.5*(fColor[i][j-1]+1);
            if (fColor[i][j-1]!=fColor[i][j])
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


TrainDraw::TrainDraw()
   {
   init();
   }

void TrainDraw::init()
   {
   bounds[0]=bounds[1]=bounds[2]=1;
   }

