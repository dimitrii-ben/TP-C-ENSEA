#include <stdlib.h>
#include <stdio.h>

#define DIMX 5
#define DIMY 5
struct ETAT
{
    int direction;
    int tableau[DIMX][DIMY]
};

typedef struct ETAT * ptETAT;
ptETAT createFisrtState(int direction,int x,int y);
