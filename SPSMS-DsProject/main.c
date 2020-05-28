#include <stdio.h>
#include <stdlib.h>
#include "LinkedListType.h"
#include <string.h>

// use scanCourse to scan the coure and save it on enntryType
void scanCourse (EntryType *course,int sizeOfPrereq);
void scanPrereq (EntryType *course);// sub fun





int main()
{

    LinkedList list;
    creatList(&list);

    EntryType c1;
    scanCourse(&c1,2);
    insertItem(&list,c1,listSize(&list));

    EntryType c1s = showItem(&list,0);
    printf("%s",c1s.courseName);
    printf("%s",c1s.coursePre[0]);
    printf("%s",c1s.coursePre[1]);
    printf("%s",c1s.coursePre[2]);

    /**EntryType course3;
    strcpy(course3.courseName,"pl20");
    strcpy(course3.coursePre[0],"one");
    strcpy(course3.coursePre[1],"two");
    strcpy(course3.coursePre[2],"three");
    insertItem(&list,course3,1);




    EntryType course4 = showItem(&list,1);
    printf("%s",course4.courseName);
    printf("%s",course4.coursePre[0]);
    printf("%s",course4.coursePre[1]);
    printf("%s",course4.coursePre[2]);**/
    return 0;
}

void scanCourse (EntryType *course, int sizeOfPrereq){
    char cName [MAX_STRING_SIZE];
    printf("Enter the subject name: \n");
    fgets(cName,MAX_STRING_SIZE,stdin);
    strcpy(course->courseName,cName);


    printf("Enter the number of prerequist 'UP to 3 ': \n ");
    for(int i = 0 ; i<sizeOfPrereq;i++){
        scanPrereq(course);
    }

}


void scanPrereq (EntryType *course){
    char str [MAX_STRING_SIZE];
    printf("Enter the subject prereq: \n");
    fgets(str,MAX_STRING_SIZE,stdin);
    strcpy(course->coursePre[course->preSize],str);
    course->preSize ++;
}
