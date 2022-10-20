#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef int boolean;
#define TRUE 1
#define FALSE 0
char * toUppserCase(char * entree);
char * backwardString(char* entree);
char * stripSpace(char* entree);
char * readFile(char * fileName);
int wordCount (char* s,char* to_be_find);
//char* getWordFromStringUntilSpace(char* string);

boolean isPalindrome(char* entree);