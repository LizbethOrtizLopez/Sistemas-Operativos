
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signum){

    printf("Jajaja xd no me matas\n");
}

int main(){
    signal(2, signalHandler);
    while(1){
        sleep(2);
        printf("Trabajando amigos \n");
    }
    return 0;
}