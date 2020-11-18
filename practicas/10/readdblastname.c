#include "./student.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    unsigned index;
    Student myStudent;
    char lastName[20];

    printf("lastName: ");
    scanf("%s", lastName);
    int fd = open(dbName, O_RDONLY, 0);
    int offset = index * sizeof(Student);
    
    while(read(fd, &myStudent, sizeof(Student))){
        if (strcmp(myStudent.lastName,lastName) == 0){
             printf("id %d, first name %s, last name %s, semester %c"
                    ,myStudent.id, myStudent.firstName,myStudent.lastName,myStudent.semester);
        }
    }
    close(fd);
    return 0;
}