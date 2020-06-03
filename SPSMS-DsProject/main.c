#include <stdio.h>
#include <stdlib.h>
#include "LinkedListType.h"
#include <string.h>
#include <ctype.h>

// use scanCourse to scan the course and save it on enntryType
void scanCourse (EntryType *course);
void scanPrereq (EntryType *course);// sub fun

void printCourse (EntryType course);// debug fun

void scanStudentData(studentData *student);
int coursePreCheack (studentData *student, EntryType * targetedCourse);

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

    int checkOtherStudent =1 ;
do{
    studentData student;
    scanStudentData(&student);

    printf("\n this is list of the avilable cources \n\n");
    // to print all the linked list


    int checkOtherCourse =1;
    do{

    TraverseList(&list,&printCourse);
    int coursePos ;
    printf("Enter number of the course you want to register : \n");
    scanf("%d",&coursePos);

    EntryType targetedCourse = showItem(&list,coursePos);

    int result = coursePreCheack(&student,&targetedCourse);
    if(result)
        printf("you can register the course \n");
    else
        printf("you can't register the course  \n");

    printf("if you want to check for another course press 1 /to add another student or exit 0");
    scanf("%d",&checkOtherCourse);

    }while(checkOtherCourse);

    printf("\n if you want to enter another student 1 \ to exit the program 0");
    scanf("%d",&checkOtherStudent);
}while(checkOtherStudent);

    return 0;
}

void scanPrereq (EntryType *course){

    char str [MAX_STRING_SIZE];

    printf("Enter the subject prereq: \n");
    scanf("%s",&str);

    strcpy(course->coursePre[course->preSize],strlwr(str));
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

    printf("Course Name : %s  || prereq : %d \n",course.courseName,course.preSize);

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

int coursePreCheack (studentData *student, EntryType * targetedCourse){
        int check = 0;
    for( int preIndex = 0 ; preIndex<targetedCourse->preSize;preIndex++){

        for(int regesterdCourseIndex =0; regesterdCourseIndex<student->regsize; regesterdCourseIndex++){
            if( (strcmp(student->coursesReg[regesterdCourseIndex],targetedCourse->coursePre[preIndex])) == 0 ){
                    check ++;
                    break;
            }
        }
    }
    return check == targetedCourse->preSize;

}
