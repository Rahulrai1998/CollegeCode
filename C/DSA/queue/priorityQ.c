//PRIORITY QUEUE WITH LINKEDLIST

#include<stdio.h>
#include<stdlib.h>

typedef struct priorQ{
	int info , prn; 
	struct priorQ * next ; 
}pq;

void insert(pq ** , int , int);
int delete(pq**);

int main()
{
	pq *head = NULL ;
	int choice,inf,prt , deleted; 
	while(1)
	{
		printf("This is PRIORITY QUEUE\nList:-\n1 . Insert a node\n2 . Delete\n0 . Exit\n\nEnter your choice = ");
		scanf("%d" , &choice);
		
		switch(choice)
		{
			case 0 :
				exit(0);
			case 1 :
				printf("Enter the the info and priotity of the node = ");
				scanf("%d%d" , &inf , &prt);
				insert(&head , inf , prt);
				break;
			case 2 :
				deleted = delete(&head) ; 
				if(deleted != -9999)
					printf("%d is deleted .\n",deleted);
				break ; 
			default : 
				printf("%d is not in the list .\n" , choice);
		}
		
	}
	
}
void insert(pq **head , int item , int n)
{
	pq *loc = (*head);
	pq *locp ; 
	
	while(loc != NULL && (loc -> prn)<= n)
	{
		locp = loc ; 
		loc = loc -> next ; 	
	}

	pq * newnode = (pq *)malloc(sizeof(pq));
	newnode -> info = item ; 
	newnode -> prn = n ; 
	
	if((*head)==loc)
	{
		newnode->next = (*head);
		(*head) = newnode ; 
	}
	else
	{
		newnode->next = locp->next ; 
		locp->next = newnode ; 
	}
	
	return ; 
}

int delete(pq **head)
{
	if((*head)==NULL)
	{
		printf("UNDERFLOW\n");
		return -9999 ; 
	}
	int item = (*head)->info ; 
	pq * temp = (*head);
	(*head) = (*head)->next ; 
	(temp)->next = NULL;
	free(temp);
	
	return(item);
	
}