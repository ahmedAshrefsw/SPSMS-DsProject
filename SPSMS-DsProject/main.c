#include <stdio.h>
#include <stdlib.h>
#include "LinkedListType.h"
#include <string.h>
#include <ctype.h>

// use scanCourse to scan the coure and save it on enntryType
void scanCourse (EntryType *course);
void scanPrereq (EntryType *course);// sub fun

void printCourse (EntryType course);// debug fun

void scanStudentData(studentData *student);

int main()
{
    int sizeOfPrereq;
    int DataEntryFlag=1;
    LinkedList list;

    creatList(&list);
    printf("Here is the start of our program 'now you will enter the data'\n");
    do{
        EntryType c1;
        c1.preSize=0;
        // to scan all the course data and save it in a struct
        scanCourse(&c1);
        insertItem(&list,c1,listSize(&list));// to add the course at the last of the linked list
        printf("To add more subject press 1 to terminate press 0 ");
        scanf("%d",&DataEntryFlag);

    }while(DataEntryFlag);

    // to print all the linked list
    TraverseList(&list,&printCourse);

    studentData student;
    scanStudentData(&student);

    printf("student ID : \n",student.ID);
    for(int i =0; i<student.regsize;i++)
        printf("student reg : %s \n",student.coursesReg[i]);

    return 0;
}


void scanPrereq (EntryType *course){
    char str [MAX_STRING_SIZE];
    printf("Enter the subject prereq: \n");
    scanf("%s",&str);
    printf("%d",course->preSize);
    strcpy(course->coursePre[course->preSize],strlwr(str));
    printf("here \n");
    course->preSize ++;

}

void scanCourse (EntryType *course){

    char cName [MAX_STRING_SIZE];
    int numberOfPre ;

    printf("enter number of pre : \n");
    scanf("%d",&numberOfPre);

    printf("Enter the subject name: \n");
    scanf("%s",&cName);

    strcpy(course->courseName,strlwr(cName));
    for(int i = 0 ; i<numberOfPre;i++){
        scanPrereq(course);
    }

}

void printCourse (EntryType course){
    printf("Course Name : %s \n",course.courseName);
    printf("Course Number Of pre : %d \n",course.preSize);
    for(int i = 0 ; i < course.preSize;i++)
        printf("Course pre req : %s \n",course.coursePre[i]);

}

void scanStudentData(studentData *student){
    char studentCourse [MAX_STRING_SIZE];
    int enterCourse =1;
    student->regsize =0 ;
    printf("enter student ID : \n");
    scanf("%d",&student->ID);

    do{

        printf("enter student course : \n");
        scanf("%s",&studentCourse);

        strcpy(student->coursesReg[student->regsize],strlwr(studentCourse));
        student->regsize++;
        printf("if you want to enter more course 1 to terminate 0");
        scanf("%d",&enterCourse);
    }while(enterCourse);


}
