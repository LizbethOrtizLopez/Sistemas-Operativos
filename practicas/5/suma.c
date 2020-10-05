#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    char c;
    char buffer[20];
    unsigned suma=0;
    unsigned i=0;
    while(read(STDIN_FILENO,&c,1) !=0){
        if(c!=' '){
            buffer[i] = c;
            i++;
        }
        else if(c==' '){
            buffer[i] = '\0';
            suma+=atoi(buffer);
            i = 0;
        }   
    }
    buffer[i]= '\0';
    suma+=atoi(buffer);
    printf("La suma es %u \n:",suma);
    return 0;
}