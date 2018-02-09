#include<stdlib.h>
#include <stdio.h>

void Search(pNote head, int key);
void addFirst(pNote *head); //Note **head 
void printList(pNote head);
void addLast(pNote *head);
void FreeList(pNote *head);
void Del(int key);

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

static int key = 0;

int main(void)
{
	pNote head = NULL;
	
	int n = 0;
	for (n = 0; n < 6; n++)
	{
		addFirst(&head);		
	}

	printList(head);
	Search(head, 2);

	getch();
	return 0;
}

void addLast(pNote *head)
{
	pNote tmp = *head;
	pNote newS;

	if (tmp == NULL)
	{
		addFirst(head);
	}
	else
	{
		//find last
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}

		newS = malloc(sizeof(Note));
		key++;
		newS->key = key;
		newS->next = NULL;
		tmp->next = newS;
	}
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

	while (current != NULL)
	{
		printf("%d", current->key);
		current = current->next;
	}
}

void Search(pNote head, int key)
{
	pNote current;
	pNote prev;
	current = head;

	if (head->key == key)
	{
		printf(" \n Searched number: %d", current->key);
	}

	if (head->next != NULL)
	{
		current = head->next;
		prev = head;
	}

	while (current != NULL)
	{
		if (current->key == key)
		{
			printf(" \n Searched number: %d", current->key);
		}
		current = current->next;
		prev = prev->next;
	}
}