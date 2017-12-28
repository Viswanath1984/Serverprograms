#include<iostream>
using namespace std;
struct Node
{
	char ch;
	struct Node* next;
};
typedef struct Node* Nodeptr;
struct Node* createnewNode(char ch)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->ch = ch;
	newnode->next = NULL;
	return newnode;
}


void insertnodes(Nodeptr *listhead,char list[],int size)
{
	struct Node* temp;
	for(int i=0;i<strlen(list);i++)
	{
		if(*listhead==NULL)
		{
			*listhead = createnewNode(list[i]);
		}
		else
		{
			temp = *listhead;
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = createnewNode(list[i]);
		}
	}
	//return *listhead;
}
void display(struct Node* listhead)
{
	while(listhead)
	{
		if(listhead->next!=NULL)
			printf("%c,",listhead->ch);
		else
			printf("%c",listhead->ch);
		
		listhead = listhead->next;
	}

}
int comparelists(Nodeptr list1,Nodeptr list2)
{

	// First iterate through the lists
	
	while(list1 && list2 && (list1->ch == list2->ch))
	{
		list1 = list1->next;
		list2 = list2->next;
	} 

	// We exit when either one of the two lists run out of elements, or if we find a character mismatch.
	// We could have also exhausted both lists and all characters could have matched
	
	// If both lists have the same length then find the greatest among the first mismatching character
	if(list1 && list2)
	{
		printf("\n List1's character is %c",list1->ch);
		printf("\n List2's character is %c",list2->ch);
		bool result = (list1->ch > list2->ch);
		printf("\n The value of result is %d",result);
		return ( list1->ch > list2->ch ? 1 : -1);
	}

	// If list1 still has elements and list2 doesn't have any 
	if(list1 && !list2)
	{
		return 1;
	}
	if(!list1 && list2)
	{	
		return -1; // First list is lesser than second list
	}
	// Else both the strings must have been equal.
	return 0;
}


int main()
{
	// Initialize the 2 character strings
	struct Node *list1head = NULL;
	struct Node *list2head = NULL;
	
	//char list1[] = {'g','e','e','k','s','b'};
	//char list2[] = {'g','e','e','k','s','a'};

	char list1[] = {'a','e','e','k','s','b'};
	char list2[] = {'g','e','e','k','s','a'};

	
	int size1 = strlen(list1);
	int size2 = strlen(list2);
	printf("\n Size of 1st list is %d",size1);
	printf("\n Size of 2nd list is %d",size2);

	insertnodes(&list1head,list1,size1);
	insertnodes(&list2head,list2,size1);
	
	printf("\n Elements in first list are as follows: ");
	display(list1head);
	
	printf("\n Elements in second list are as follows: ");
	display(list2head);

	int retval = comparelists(list1head,list2head);
	switch(retval)
	{
		case 1:
			printf("\nstring %s is lexicographically greater than %s",list1,list2);
			break;
		case -1:
			printf("\nstring %s is lexicographically greater than %s",list2,list1);
			break;
		default:
			printf("\n String %s is same as string %s",list1,list2);
			break;
	}

}
