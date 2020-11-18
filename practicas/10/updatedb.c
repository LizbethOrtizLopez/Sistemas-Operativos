#include "./student.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    unsigned index;
    Student myStudent;

    printf("index: ");
    scanf("%d", &index);
    int fd = open(dbName, O_RDONLY, 0);
    int offset = index * sizeof(Student);
    lseek(fd,offset,SEEK_SET);
    read(fd,&myStudent, sizeof(Student));
    close(fd);

    //printf("index %d, id %d, first name %s, last name %s, semester %c"
    //,index,myStudent.id, myStudent.firstName,myStudent.lastName,myStudent.semester);

    printf("attribute: ");
    char attributeName[20];
    scanf("%s",attributeName);

    if(strcmp(attributeName,"id")==0){
        printf("current id %d, new id: ",myStudent.id);
        scanf("%d",&myStudent.id);
    }
    if(strcmp(attributeName,"firstName")==0){
        printf("current first name %s, new first name: ", myStudent.firstName);
        scanf("%s",myStudent.firstName);
    }
    if(strcmp(attributeName,"lastName")==0){
        printf("current last name %s, new last name: ", myStudent.lastName);
        scanf("%s",myStudent.lastName);
    }
    if(strcmp(attributeName,"semester")==0){
        printf("current semester %c, new semester: ", myStudent.semester);
        scanf("\n%c",&myStudent.semester);
    }
    fd = open(dbName,O_WRONLY, 0);
    lseek(fd, offset, SEEK_SET);
    write(fd, &myStudent, sizeof(Student));
    close(fd);
    return 0;

}