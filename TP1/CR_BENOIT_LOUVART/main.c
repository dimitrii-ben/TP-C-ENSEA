#include "functions.h"


int main(){
    char* exercice1_2 = "HelLo.!;; WoRlD!:,";
    //Exercice 1
    char* a;char*b;char*c;
    printf("Exercice 1:\nChaine de base:[%s]\nChaine modifie:[%s]\n",exercice1_2,a = toUppserCase(exercice1_2));
    //Exercice 2
    printf("Exercice 2:\nChaine de base:[%s]\nChaine modifie:[%s]\n",exercice1_2,b = backwardString(exercice1_2));
    //Exercice 3
    printf("Exercice 3:\nChaine de base:[%s]\nChaine modifie:[%s]\n",exercice1_2,c = stripSpace(exercice1_2));
    //Exercice 4
    char* exercice4 ="Engage le jeu que je le gagne!";
    printf("La chaine:[%s] est un palindrome:[%i]\n",exercice4,isPalindrome(exercice4));
    //Exercice 5
    char* contenu_fichier = readFile("document.txt");
    printf("Le contenu du fichier est\n%s",contenu_fichier);
    //Exercice 6 : Word count
    char* exercice6= "Dimitrii";
    printf("Le mot [%s] apparait [%i] fois dans la chaine\n",exercice6,wordCount(contenu_fichier,exercice6));
    free(a);
    free(b);
    free(c);
    return EXIT_SUCCESS;
}

