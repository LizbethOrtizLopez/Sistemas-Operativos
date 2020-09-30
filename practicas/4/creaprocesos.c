#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void signalHandler(int signum){
    int status;
    wait(&status);
    printf("Mi hijo termino con status %d \n",status);
}

int main(int argc, char **argv){
    
    signal(17, signalHandler);
    unsigned pid = fork();
    if (pid==0){
        sleep(3);
        printf("Soy el proceso hijo\n");
        //execv(argv[1],&argv[1]);
        return 10;
    }
    else{
        int status;
        sleep(2);
        printf("Soy el proceso padre y mi hijo es %u\n",pid);
        while(1){
            sleep(2);
            printf("trabajando \n");
        }
    }
    printf("Hola mundo\n");
    return 0;
}