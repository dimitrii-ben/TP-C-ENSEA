#include "langton.h"
/* argv[]
 * 0: temps d'attendte entre chaque frame en seconde
 * 1: Nb d'iterations
*/
int main(int argc,char* argv[]){
    if(argc!=3){
        printf("Exit failure\n");
        return EXIT_FAILURE;
    }
    ETAT* head = createFirstState(NORD,25,25);
    ETAT* current_pt;
    int iteration = 0;
    int limite = 0;
    while(!limite && iteration <atoi(argv[2])){
        current_pt = createNextState(head);
        if(current_pt->x_fourmi > DIMX || current_pt->x_fourmi <0 || current_pt->y_fourmi <0 || current_pt->y_fourmi>DIMY){
            limite =1;
            printf("LIMITE : %i",iteration);
            
        }
        else{
            iteration++;
        }
        

    }
    
    
    current_pt = head;
    for (int i =0;i<=iteration;i++){
        displayState(current_pt);
        current_pt = current_pt->next;
        printf("\e[1;1H\e[2J");        
        usleep(atoi(argv[1])); 
        
        

    }
    freeAll(head);
    return EXIT_SUCCESS;
}