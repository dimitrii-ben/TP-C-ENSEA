#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#define DIMX 5
#define DIMY 5

//Creation des constantes de directions
#define NORD 0
#define EST 1
#define SUD 2
#define OUEST 3
#define FOURMI 4
#define NOIR 0
#define BLANC 1
typedef struct etat
{
    int direction;
    int tableau[DIMY][DIMX];
    int x_fourmi;
    int y_fourmi;
    struct etat* next;
}ETAT;

typedef ETAT* ptETAT;
ptETAT createFisrtState(int direction,int x,int y);



