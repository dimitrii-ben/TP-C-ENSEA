#include "langton.h"
//Creation de la variable type
typedef struct liste{
    ETAT state;
    struct liste * suivant;
}Liste;
//Fonction ajoutant un nouvel element au debut de la liste courante tout en modifiant le pointeur du premier element
void push(Liste ** head, ETAT state) {
    Liste* new_node;
    new_node = (Liste *) malloc(sizeof(Liste));

    new_node->state = state;
    new_node->suivant = *head;
    *head = new_node;
}
// Fonction ajouant un nouvel element a la fin de la liste courante
void push(Liste * head, ETAT state) {
    Liste * current = head;
    //Boucler jusqu'au dernier element
    while (current->suivant != NULL) {
        current = current->suivant;
    }
    //Creation et allocation du nouvel element dans la liste
    current->suivant = (Liste *) malloc(sizeof(Liste));
    current->suivant->state = state;
    current->suivant->suivant = NULL;
}
// Fonction retirant le premier element de la liste courante 
int pop(Liste ** head) {
    ETAT retstate;
    Liste * next_node = NULL;

    if (*head == NULL) {
        return NULL;
    }

    next_node = (*head)->suivant;
    free(*head);
    *head = next_node;

    return 1;
}

ETAT remove_last(Liste * head) {
    ETAT retstate;
    // Si la liste contient un element retirer celui ci
    if (head->suivant == NULL) {
        retstate = head->state;
        free(head);
        return retstate;
    }

    // Va chercher l'avant dernier element de la liste (d'ou le double decalage)
    Liste * current = head;
    while (current->suivant->suivant != NULL) {
        current = current->suivant;
    }

    //Supprimer et librer l'espace du dernier element de la liste
    //Et transformer cette element en l'element NULL
    retstate = current->suivant->state;
    free(current->suivant);
    current->suivant = NULL;
    return retstate;

}



