#include <stdio.h>

void main(){
     
    char *words = NULL;
    size_t lengthOfLine = 0, currentLocation = 0;
    int c = EOF;


    while (c){

        printf("\n Enter in a Line: ");
        c = getc(stdin);

        if (c == '\n'){
            c = 0;
            break;
        }

        
    }  

    printf("%s",c);



}