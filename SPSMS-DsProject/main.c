#include <stdio.h>
#include <stdlib.h>
#include "LinkedListType.h"
#include <string.h>

int main()
{

    LinkedList list;
    creatList(&list);

    EntryType course1;
    strcpy(course1.courseName,"cs20");
    strcpy(course1.coursePre[0],"one");
    strcpy(course1.coursePre[1],"two");
    strcpy(course1.coursePre[2],"three");
    insertItem(&list,course1,0);

    EntryType course3;
    strcpy(course3.courseName,"pl20");
    strcpy(course3.coursePre[0],"one");
    strcpy(course3.coursePre[1],"two");
    strcpy(course3.coursePre[2],"three");
    insertItem(&list,course3,1);


    EntryType course2 = showItem(&list,0);
    printf("%s",course2.courseName);
    printf("%s",course2.coursePre[0]);
    printf("%s",course2.coursePre[1]);
    printf("%s",course2.coursePre[2]);

    EntryType course4 = showItem(&list,1);
    printf("%s",course4.courseName);
    printf("%s",course4.coursePre[0]);
    printf("%s",course4.coursePre[1]);
    printf("%s",course4.coursePre[2]);
    return 0;
}
