#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    char c;
    unsigned lineas =0;
    unsigned palabras =0;
    unsigned caracteres = 0;
    char buffer[250];
    unsigned i =0;

    while(read(STDIN_FILENO,&c,1) !=0){
         
        i++;
        buffer[i] = c;
        if (c!='\n'){
            caracteres++;
        }
        if(c==' '){
            if (buffer[i-1]!='\n' && buffer[i-1]!=' ' && i>1){
                palabras ++;
            }  
        } 
        else if (c=='\n'){
            lineas ++;
            if (buffer[i-1]!=' ' && i>1){
                palabras++;
            }
            i=0;
        }  
    }
    caracteres = caracteres + ((lineas));
    printf("lineas: %d \n",lineas);
    printf("palabras: %d \n",palabras);
    printf("caracteres: %d \n",caracteres);

    return 0;
}