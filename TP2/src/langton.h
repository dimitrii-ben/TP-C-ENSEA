#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define DIMX 50
#define DIMY 50

//Creation des constantes de directions
#define NORD 0
#define EST 1
#define SUD 2
#define OUEST 3
#define FOURMI 4
#define NOIR 1
#define BLANC 0
typedef struct etat
{
    int direction;
    int tableau[DIMY][DIMX];
    int x_fourmi;
    int y_fourmi;
    struct etat* next;
}ETAT;


ETAT* createFirstState(int direction,int x,int y);
ETAT* createNextState(ETAT* head);
char getChar(ETAT* e,int y,int x);
void displayState(ETAT* e);
void freeAll(ETAT* head);



