#include<stdlib.h>
#include <stdio.h>

int key = 0;

typedef struct List 
{
	int key;
	struct List *next;
	void *Data;
}Note, *pNote;

typedef struct StuDate
{
	char name[20];
	
}*pDate;
void Search(pNote head, int key);
void addFirst( pNote *head); //Note **head 
void printList(pNote head);
void addLast(pNote *head);
int main(void) 
{
	Note *head = NULL;
	int n=0;
	while (n != 6) {
		addFirst(&head);
		n++;
	}
	
	printList(head);
	Search(head, 2);
	
	getchar();
	return 0;
}
void addLast(pNote *head)
{
	pNote tmp = *head;
	
	if (tmp == NULL)
	{
		tmp = malloc(sizeof(Note));
		key++;
		tmp->key = key;
		tmp->next = *head;
		*head = tmp;
    }
	tmp->next = malloc(sizeof(Note));
	key++;
	tmp->next->key = key;
	tmp->next->next = NULL;
}

void addFirst(pNote *head)
{
	pNote tmp;
	tmp = malloc(sizeof(Note));

		key++;
		tmp->key = key;
		tmp->next = *head;
		*head = tmp;
}


void printList(pNote head)
{
	pNote current;
	current = head;
	
	while (current !=NULL)
	{
		printf("%d", current->key);
		current = current -> next;
	}

}

void Search(pNote head,int key)
{
	pNote current;
	current = head;

	while (current != NULL)
	{
		if (current->key == key) 
		{
			printf(" \n Searched number: %d", current->key);
		}
		current = current->next;
	}
}