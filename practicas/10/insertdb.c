#include "./student.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    unsigned index;
    Student myStudent;

    printf("index: ");
    scanf("%d",&index);
    printf("id: ");
    scanf("%d",&myStudent.id);
    printf("First name: ");
    scanf("%s",myStudent.firstName);
    printf("Last name: ");
    scanf("%s",myStudent.lastName);
    printf("Semester: ");
    scanf("\n%c",&myStudent.semester);

    //printf("index %d, id %d, first name %s, last name %s, semester %c"
    //,index,myStudent.id, myStudent.firstName,myStudent.lastName,myStudent.semester);

    int fd = open(dbName,O_WRONLY, 0);
    int offset = index * sizeof(Student);
    lseek(fd, offset, SEEK_SET);
    write(fd, &myStudent, sizeof(Student));
    close(fd);

    return 0;
}