#include "functions.h"
// Transforme la chaine en entree en masjucule
char* toUppserCase(char * entree){
    char * sortie = calloc(strlen(entree)+1,1);
    char * index = sortie;
    int i = 0;
    while (*(entree+i)!= '\0'){
        if('a'<= *(entree+i) && *(entree+i)<= 'z'){
            *index = *(entree+i) - 32;
        }
        else{
            
            *index = *(entree+i);
        }
        index++; 
        i++;  
    }
    *index = '\0';
    return sortie;
}
char* backwardString(char* entree){
    char* sortie = calloc (strlen(entree)+1,1);
    char* index = sortie+strlen(entree);
    *(index--) = '\0';
    int i = 0;
    while(*(entree+i) != '\0'){
        *index = *(entree+i);
        index--;
        i++;
    }
    return sortie;
    
}
/*
 * Fonction enlevant tout les caracteres speciaux de la chaine passe en argument et la renvoie
 */
char* stripSpace(char* entree){
    //Verifions le nombre d'octet a enlever pour reserver l'espace memoire de sortie
    int i = 0;
    int diacritique =0;
    while(*(entree+i) != '\0'){
        if(32 <=*(entree+i) && *(entree+i)<= 47|| 58 <=*(entree+i) && *(entree+i)<= 64 || 
        91 <=*(entree+i) && *(entree+i)<= 96 || 123 <=*(entree+i) && *(entree+i)<= 126){
            diacritique++;
        }
        i++;
    }
    char* sortie = calloc (strlen(entree)+1-diacritique,1);
    char* index = sortie;

    i = 0;
    while(*(entree+i) != '\0'){
        //Si n'est pas un char diacritique
        if(!(32 <=*(entree+i) && *(entree+i)<= 47|| 58 <=*(entree+i) && *(entree+i)<= 64 || 
        91 <=*(entree+i) && *(entree+i)<= 96 || 123 <=*(entree+i) && *(entree+i)<= 126)){
            *index = *(entree+i); 
            index++;
        }
        i++;
        
    }
    *index = '\0';
    return sortie;

}
/*
 * Fonction verifiant si la chaine passee en argument est un palindrome
 */
boolean isPalindrome(char* entree){
    char* entree_bis = toUppserCase((stripSpace(entree)));
    char* reverse_entree_bis = backwardString(entree_bis);
    boolean est_palindrome= FALSE;
    printf("%i",strcmp(entree_bis,reverse_entree_bis));
    if(strcmp(entree_bis,reverse_entree_bis) == 0){
        est_palindrome = TRUE;
    }
    free(entree_bis);
    free(reverse_entree_bis);
    return est_palindrome;
}
/*
 * fonction qui renvoie en chaine de char un fichier lu
 */
char* readFile(char* fileName){
    int count;
    FILE* filePtr;
    char *s = calloc(512*1024,sizeof(char));
    filePtr=fopen(fileName,"r");
    count=fread(s,1,512*1024,filePtr);
    s = realloc(s,count*sizeof(char));
    fclose(filePtr);
    return s;
}
/*
 * Fonction comptant le nombre de repetition de to_be_find dans le text fourni en premier arguement
*/

int wordCount (char* s,char* to_be_find){
    int nb_repetitions = 0 ;
    char* to_find = to_be_find;
    //Tant qu'on arrive pas a la fin de la chaine principale
    while(*s!='\0'){

        //Tant que les lettres coincides
        while (*s==*to_be_find){
            //Si on arrive a la fin de la chaine a comparer la remettre au debut et incrementer le compteur
            if(*(to_be_find+1)=='\0'){
            
                nb_repetitions++;
                to_be_find = to_find;
                
            }
            else{  
                to_be_find++;
            }
            s++;
            
        }
        
        if(*s !='\0'){
            to_be_find = to_find;
            s++;
        }
        
        
        
    } 
    printf("\n");
    return nb_repetitions;
}

