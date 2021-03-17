// Singly Linkedlist

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{	
	int info ; 
	struct node * next ; 
}nod;

void create(nod**, int);
void traverse(nod*);
void insert_first(nod** , int);
void insert_last(nod** , int);
void insert_atPosition(nod** , int , int);
int delete_first(nod**);
int delete_last(nod**);
int delete_element(nod** , int);
void reverse_list(nod*);

int main()
{
	nod * head = NULL ;
	int choice , data , nodeCount,del; 
	while(1)
	{
		printf("List :-\n1 . Create List\n2 . Traverse List\n3 . Insert at first\n4 . Insert at last\n5 . Insert at position\n6 . Delete first\n7 . Delete last\n8 . Delete the element\n9 . Reverse list\n0 . Exit\n\nChoose any option = ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0 :
				printf("We felt great serving you :)\n\n");
				exit(1); 
			case 1 :
				printf("Enter the number of nodes you want = ");
				scanf("%d",&nodeCount);
				create(&head , nodeCount);
				break ;
			case 2 :
				printf("Your list  = ");
				traverse(head);
				break ; 
			case 3 :
				printf("Insert at first\n");
				printf("Enter the item to insert  = ");
				scanf("%d" , &data);
				insert_first(&head,data);
				printf("Your item inserted\n");
				break ; 
			case 4 :
				printf("Insert at last\n");
				printf("Enter the item to insert = ");
				scanf("%d",&data);
				insert_last(&head,data);
				break ; 
			case 5 :
				break ; 
			case 6 :
				break ; 
			case 7 :
				printf("Delete Last\n");
				del = delete_last(&head);
				break ; 
			case 8 :
				break ;
			case 9 :
				break ; 
			default :
				printf("%d is not in the list\n\n" , choice);
		}
	}
}

void create(nod** head , int n)
{
	if((*head != NULL))
	{
		printf("List is already created\n");
		return ; 
	}
	int item , i , count; 
	count = 1 ; 
	nod * temp ; 
	for(i=1;i<=n;i++)
	{
		printf("Enter the data to insert in node %d = ",count);
		scanf("%d" , &item);
		nod * newnode = (nod*)malloc(sizeof(nod));
		newnode -> info = item ; 
		newnode -> next =NULL ;
		if((*head == NULL))
			(*head) = newnode ; 
		else
			temp -> next = newnode ; 
		temp = newnode ; 
		count++ ; 
	}
	return ; 
}

void traverse(nod * head)
{
	if(head == NULL)
	{
		printf("List is Empty\n");
		return ; 
	}
	nod * temp = head ; 
	while(temp != NULL)
	{
		printf("%d " , temp->info);
		temp = temp->next ; 
	}
	printf("\n");
	return ; 
}
void insert_first(nod** head , int item)
{
	if((*head)==NULL)
	{
		printf("Empty List\n");
		return ; 
	}
	nod * newnode = (nod*)malloc(sizeof(nod));
	newnode -> info = item;
	newnode -> next = (*head);
	*head = newnode;
	return;
}
void insert_last(nod**head , int item)
{
	if((*head) == NULL)
	{
		printf("Empty List\n");
		return ; 
	}
	nod* newnode = (nod*)malloc(sizeof(nod));
	newnode -> info = item;
	newnode -> next = NULL;
	nod * temp = (*head);
	while(temp->next !=NULL)
	{
		temp = temp->next;
	}
	
	temp -> next = newnode ; 
	return ; 
	
}
int delete_last(nod**head)
{
	if((*head) == NULL)
	{
		printf("Empty List\n");
		return -9999; 
	}
	nod *loc , *locp ; 
	locp = *head;
	loc = (*head) -> next ; 
	while(loc->next!=NULL)
	{
		loc = loc->next;
		locp = locp->next;
	}
	int item = loc->info;
	locp->next = NULL;
	free(loc);
	return(item);
	
}