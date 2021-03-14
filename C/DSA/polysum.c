#include<stdio.h>
#include<stdlib.h>

typedef struct polySum
{
	float coeff ; 
	int expo ; 
	struct polySum * next ; 
}poly;

void polyCreate(poly ** head , int n);
void polySum(poly * h1 , poly * h2 , poly * h3);
void polyInsert(poly ** head , int ex , int cf);
int main()
{
	poly * h1 , h2 , h3 ; 
	h1 = h2 = h3 = NULL ; 
	
	while(1)
	{
		printf("List:-\n1 . Create list\n2 . ");
	}

}