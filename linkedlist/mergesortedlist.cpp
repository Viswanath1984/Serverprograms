#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;

};
typedef struct Node* Nodeptr;

void display(Nodeptr head)
{
	Nodeptr current;
	current = head;

	while(current)
	{
		if(current->next!=NULL)
			printf("%d,",current->data);
		else
			printf("%d",current->data);
	
		current = current->next;
	}
}
struct Node* createnewNode(int data)
{
	Nodeptr newnode = (Nodeptr)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
void insertelements(Nodeptr *head,int *arr,int n)
{
	Nodeptr temp;
	for(int i=0;i<n;i++)
	{
		if(*head == NULL)
		{
			*head = createnewNode(arr[i]);
		}
		else
		{
			temp = *head;
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = createnewNode(arr[i]);
		}
	}
}

struct Node* mergesorted(Nodeptr p, Nodeptr q, Nodeptr s)
{
	// P - Pointer to 1st list 
	// Q - Pointer to 2nd list
	// s - Moving pointer which points to lesser among p and q nodes
	struct Node *newhead = NULL;
	if(p==NULL)
		return q;
	if(q==NULL)
		return p;

	if(p && q)
	{
		if(p->data <= q->data)
		{
			s = p;
			p = s->next;			
		}		
		else
		{
			s = q;
			q = s->next;

		}
	}	
	newhead = s;

	while(p && q)
	{
		if(p->data<=q->data)
		{
			s->next = p;
			s = p;
			p = s->next;
		}
		else if(q->data<=p->data)
		{
			s->next = q;
			s = q;
			q = s->next;
		}
	}		
	if(q==NULL && p!=NULL)
	{
		s->next = p;	
	}
	else if(p==NULL && q!=NULL)
	{
		s->next = q;
	}
	
	return newhead;
		
}
int main()
{
	Nodeptr temp;
	 
	struct Node* list1head = NULL;
        struct Node* list2head = NULL;
	struct Node* mergedlist = NULL;

	int arr1[] = {10,50,70,90,100};
	int arr2[] = {20,30,40,60,80};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	int n2 = sizeof(arr2)/sizeof(arr2[0]);

	insertelements(&list1head,arr1,n1);
	insertelements(&list2head,arr2,n2);

	printf("\n Elements in the first list are as follows: ");
	display(list1head);	

	printf("\n Elements in the first list are as follows: ");
	display(list2head);	

	mergedlist = mergesorted(list1head,list2head,mergedlist);			
	printf("\n Elements of merged sorted list are as follows: ");
	display(mergedlist);
	
}
