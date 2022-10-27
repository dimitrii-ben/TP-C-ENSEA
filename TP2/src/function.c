#include "langton.h"

//Fonction ajoutant un nouvel element au debut de la liste courante tout en modifiant le pointeur du premier element
void push(Liste ** head, int val) {
    Liste* new_node;
    new_node = (Liste *) malloc(sizeof(Liste));

    new_node->val = val;
    new_node->suivant = *head;
    *head = new_node;
}
// Fonction ajouant un nouvel element a la fin de la liste courante
void push(Liste * head, int val) {
    Liste * current = head;
    //Boucler jusqu'au dernier element
    while (current->suivant != NULL) {
        current = current->suivant;
    }
    //Creation et allocation du nouvel element dans la liste
    current->suivant = (Liste *) malloc(sizeof(Liste));
    current->suivant->val = val;
    current->suivant->suivant = NULL;
}
// Fonction retirant le premier element de la liste courante et retourne la valeur enleve
int pop(Liste ** head) {
    int retval = -1;
    Liste * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->suivant;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_last(Liste * head) {
    int retval = 0;
    // Si la liste contient un element retirer celui ci
    if (head->suivant == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }

    // Va chercher l'avant dernier element de la liste (d'ou le double decalage)
    Liste * current = head;
    while (current->suivant->suivant != NULL) {
        current = current->suivant;
    }

    //Supprimer et librer l'espace du dernier element de la liste
    //Et transformer cette element en l'element NULL
    retval = current->suivant->val;
    free(current->suivant);
    current->suivant = NULL;
    return retval;

}



