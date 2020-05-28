#include<stdlib.h>
#include "Global.h"

typedef struct listnode{
    EntryType entry ;
    struct listnode *next;

}ListNode;

typedef struct linkedList{
int size ;
ListNode *head;
}LinkedList;

void creatList(LinkedList *pl);

int listSize(LinkedList *pl);

int listEmpty(LinkedList *pl);

int listFull(LinkedList *pl);

void insertItem(LinkedList *pl, EntryType e, int pos);

EntryType showItem(LinkedList *pl , int pos);

void deleteItem(LinkedList *pl, EntryType *pe, int pos );

void replaceItem(LinkedList *pl , EntryType newItem , int pos  );

void destroyList(LinkedList *pl);

void TraverseList(LinkedList* pl, void(*Visit)(EntryType));
