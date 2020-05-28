
#define NUMBER_OF_STRINGS 3
#define MAX_STRING_SIZE 50
#define MAX_NAME_SIZE 100
#define NUMBER_OF_COURSES 50

typedef struct courseFullData{

    char courseName[MAX_STRING_SIZE];
    char coursePre[NUMBER_OF_STRINGS][MAX_STRING_SIZE];
    int preSize;

}EntryType;

typedef struct {

    int ID;
    char coursesReg[NUMBER_OF_COURSES][MAX_STRING_SIZE];
    int regsize;

}studentData;
