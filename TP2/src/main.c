#include "langton.h"
/* argv[]
 * 0: Frame Per Second
 * 1: Nb d'iterations
*/
int main(int argc,char* argv[]){
    ETAT* head = createFirstState(NORD,25,25);
    ETAT* current_pt = head;
    for(int i =0;i<10000;i++){
        createNextState(head);
    }
    for (int i =0;i<10000;i++){
        displayState(current_pt);
        current_pt = current_pt->next;
        printf("\e[1;1H\e[2J");

    }
    freeAll(head);
    /*for (int i =0;i<atoi(argv[1]);i++){
        createNextState(head);
    }
    ETAT* current_pt= head;
    for (int i =0;i<atoi(argv[1]);i++){

        displayState(current_pt);
        current_pt = current_pt->next;
    }*/
}