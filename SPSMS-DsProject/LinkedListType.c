#include "LinkedListType.h"

void creatList(LinkedList *pl){
    pl->head = NULL;
    pl->size=0;
}

int listSize(LinkedList *pl){
    return pl->size;
}

int listEmpty(LinkedList *pl){
 return pl->size ==0;
}

int listFull(LinkedList *pl){
    return 0;
}

void insertItem(LinkedList *pl, EntryType e, int pos){

    ListNode *newNode , *temp;
    int i;

    newNode = (ListNode *) malloc(sizeof(ListNode));
    newNode->entry = e;
    newNode->next = NULL;

    if (pos == 0){
            newNode->next = pl->head;
            pl->head = newNode;
    }else{
        for(temp=pl->head ,i=0; i<pos-1;i++)
                temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }
    pl->size++;
}

EntryType showItem(LinkedList *pl , int pos){
    ListNode *temp;
    int i ;

    for(temp = pl->head,i=0;i<pos;i++)
        temp = temp->next;
    return temp->entry;
}

void TraverseList(LinkedList* pl, void(*Visit)(EntryType)){
	ListNode *p=pl->head;
	while(p){
		(*Visit)(p->entry);
		p=p->next;
	}
}
