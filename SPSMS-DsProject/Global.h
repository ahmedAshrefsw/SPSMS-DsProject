
#define NUMBER_OF_STRINGS 3
#define MAX_STRING_SIZE 50
#define MAX_NAME_SIZE 100
#define MAX_REG_COURSES_SIZE 50

typedef struct courseFullData{

    char courseName[MAX_STRING_SIZE];
    char coursePre[NUMBER_OF_STRINGS][MAX_STRING_SIZE];
    int preSize;

}EntryType;

typedef struct {

    char studentName[MAX_NAME_SIZE];
    char coursesReg[MAX_REG_COURSES_SIZE];
    int regsize;

}studentData;
