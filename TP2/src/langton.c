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
    nouveau->next = NULL;
}

ptETAT createNextState(ETAT* head){
    ptETAT current_pt = head;
    //Go to the end of the list
    while(current_pt->next!=NULL){
        current_pt = current_pt->next;
    }
    //--------------    Creation de l'Etat suivant
    ptETAT nouveau = malloc(sizeof(ETAT));
    int direction,x,y;
    for (int i = 0; i<DIMY;i++){
        for (int j =0;j<DIMX;j++){
            nouveau->tableau[i][j] = current_pt->tableau[i][j];
        }
    }
    nouveau->next = NULL;

    //On defini la direction du prochain etat
    if(current_pt->tableau[current_pt->x_fourmi][current_pt->y_fourmi] == BLANC){
        nouveau->direction = current_pt->direction++;
    }
    else{
        if(!current_pt->direction){
            nouveau->direction = OUEST;
        }
        else{
            nouveau->direction = current_pt->direction--;
        }
        
    }
    //On modifi l'etat du tableau et les coordonees de la fourmi
    /*  0 ----> x
     *  |
     *  |
     *  \/ y
     * 
    */
    switch (nouveau->direction)
    {
    case NORD:
        nouveau->x_fourmi = current_pt->y_fourmi--;
        break;
    case EST:
        nouveau->x_fourmi = current_pt->x_fourmi++;
        break;
    case SUD:
        nouveau->x_fourmi = current_pt->y_fourmi++;
        break;
    case OUEST:
        nouveau->x_fourmi = current_pt->x_fourmi--;
        break;

    
    default:
        break;
    }
    current_pt->next = createFisrtState(direction,x,y);
    

}