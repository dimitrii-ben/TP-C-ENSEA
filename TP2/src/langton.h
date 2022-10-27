#include <stdlib.h>
#include <stdio.h>

#define DIMX 5
#define DIMY 5

//Creation des constantes de directions
#define NORD 0
#define EST 1
#define SUD 2
#define OUEST 3


typedef struct etat
{
    int direction;
    int tableau[DIMX][DIMY]
}ETAT;

typedef ETAT* ptETAT;
ptETAT createFisrtState(int direction,int x,int y);

//Creation de la variable type
typedef struct liste{
    int val;
    struct liste * suivant;
}Liste;

