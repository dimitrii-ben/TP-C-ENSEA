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

void changeState(int*** tableau,int x,int y){
    if(*tableau[y][x] == BLANC){
        *tableau[y][x]=NOIR;
    }
    else{
        *tableau[y][x]=BLANC;
    }
    
}
void copyArrayState(int*** tableau_nouveau,int*** tableau_ancien){
    for (int i = 0; i<DIMY;i++){
        for (int j =0;j<DIMX;j++){
            *tableau_nouveau[i][j] = *tableau_ancien[i][j];
        }
    }
}

ptETAT createNextState(ETAT* head){
    ptETAT current_pt = head;
    //Go to the end of the list
    while(current_pt->next!=NULL){
        current_pt = current_pt->next;
    }
    /*
     * Changement d'etat du dernier element courant
    */
    changeState(&current_pt->tableau,current_pt->x_fourmi,current_pt->y_fourmi);
    /*---------------------------------------------
     *
     *      CREATION NOUVELLE ETAT (ETAT SUIVANT) 
     * 
     *--------------------------------------------*/
    ptETAT nouveau = malloc(sizeof(ETAT));
    //Recopie des deux tableaux
    copyArrayState(&nouveau->tableau,&current_pt->tableau);
    
    //On defini la direction du prochain etat
    if(current_pt->tableau[current_pt->x_fourmi][current_pt->y_fourmi] == BLANC){
        if(current_pt->direction == OUEST){
            nouveau->direction =NORD;
        }
        else{
            nouveau->direction = current_pt->direction++;
        }
    }
    else{
        if(current_pt->direction == NORD){
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
    }
    nouveau->next = NULL;
    return nouveau;
    

}
char getChar(ptETAT e,int y,int x){
    if(e->y_fourmi == y && e->x_fourmi== x){
        switch (e->direction)
        {
        case NORD:
            return "^";
        case OUEST:
            return "<";
        case SUD:
            return "|";
        case EST:
            return ">";
        }
    }
    else{
        if(e->tableau[y][x] == BLANC){
            return "B";
        }
        return "N";
    }
    
}

void displayState(ptETAT e){
    char* etat_case;
    for (int i =0;i<DIMY;i++){
        for(int j=0;j<DIMX;j++){
            
            printf("%s",getChar(e,i,j));
        }
        printf("\n");
    }

}