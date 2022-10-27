#include <stdlib.h>
#include <stdio.h>

#define DIMX 5
#define DIMY 5

//Creation des constantes de directions
#define NORD 0
#define EST 1
#define SUD 2
#define OUEST 3
#define FOURMI 4

typedef struct etat
{
    int direction;
    int tableau[DIMX][DIMY];
    int x_fourmi;
    int y_fourmi;
}ETAT;

typedef ETAT* ptETAT;
ptETAT createFisrtState(int direction,int x,int y);



