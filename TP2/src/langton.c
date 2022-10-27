#include "langton.h"

ptETAT createFisrtState(int direction,int x,int y){
    ptETAT nouveau = malloc(sizeof(ETAT));
    for (int i =0;i<DIMY;i++){
        for(int j=0;j<DIMX;j++){
            nouveau->tableau[i][j] =0;
        }
    }
    nouveau->direction = direction;
    nouveau->x_fourmi = x;
    nouveau->y_fourmi = y;
}