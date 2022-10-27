#include "langton.h"

ETAT* createFirstState(int direction,int x,int y){
    ETAT* nouveau = malloc(sizeof(ETAT));
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



ETAT* createNextState(ETAT* head){
    ETAT* current_pt = head;
    //Go to the end of the list
    while(current_pt->next!=NULL){
        current_pt = current_pt->next;
    }
    
    /*---------------------------------------------
     *
     *      CREATION NOUVELLE ETAT (ETAT SUIVANT) 
     * 
     *--------------------------------------------*/
    ETAT* nouveau = malloc(sizeof(ETAT));
    
    //Recopie des deux tableaux
    for (int i = 0; i<DIMY;i++){
        for (int j =0;j<DIMX;j++){
            nouveau->tableau[i][j] = current_pt->tableau[i][j];
        }
    }
    /*
     * Changement d'etat de l'ancien element 
    */
    if(nouveau->tableau[current_pt->y_fourmi][current_pt->x_fourmi] == BLANC){
        nouveau->tableau[current_pt->y_fourmi][current_pt->x_fourmi]=NOIR;
    }
    else{
        nouveau->tableau[current_pt->y_fourmi][current_pt->x_fourmi]=BLANC;
    }
    //On defini la direction du prochain etat
    if(current_pt->tableau[current_pt->y_fourmi][current_pt->x_fourmi] == BLANC){
        if(current_pt->direction == OUEST){
            nouveau->direction =NORD;
        }
        else{
            nouveau->direction = current_pt->direction +1;
        }
    }
    else{
        if(current_pt->direction == NORD){
            nouveau->direction = OUEST;
        }
        else{
            nouveau->direction = current_pt->direction -1;
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
        nouveau->y_fourmi = current_pt->y_fourmi-1;
        nouveau->x_fourmi = current_pt->x_fourmi;
        break;
    case EST:
        nouveau->y_fourmi = current_pt->y_fourmi;
        nouveau->x_fourmi = current_pt->x_fourmi+1;
        break;
    case SUD:
        nouveau->y_fourmi = current_pt->y_fourmi+1;
        nouveau->x_fourmi = current_pt->x_fourmi;
        break;
    case OUEST:
        nouveau->y_fourmi = current_pt->y_fourmi;
        nouveau->x_fourmi = current_pt->x_fourmi-1;
        break;
    }
    nouveau->next = NULL;
    /*---------------------------------------------
     *
     *      FIN CREATION NOUVELLE ETAT (ETAT SUIVANT) 
     * 
     *--------------------------------------------*/
    current_pt->next=nouveau;
    return nouveau;
    

}
char getChar(ETAT* e,int y,int x){
    if(e->y_fourmi == y && e->x_fourmi== x){
        switch (e->direction)
        {
        case NORD:
            return '^';
        case OUEST:
            return '<';
        case SUD:
            return 'v';
        case EST:
            return '>';
        }
    }
    else{
        if(e->tableau[y][x] == BLANC){
            return ' ';
        }
        return '#';
    }
    
}

void displayState(ETAT* e){
    //ligne
    for (int i =0;i<DIMY;i++){
        //colonne
        for(int j=0;j<DIMX;j++){
            printf("%c",getChar(e,i,j));
        }
        printf("\n");
    }

}
void freeAll(ETAT* head){
    ETAT* old_pt;
    while(head->next!=NULL){
        old_pt =head;
        head = head->next;
        free(old_pt);
    }
}
