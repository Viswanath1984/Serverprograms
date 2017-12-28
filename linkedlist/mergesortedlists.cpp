#include<iostream>
using namespace std;
// let us first create a data structure Linked List
struct Node
{
	int data;
	struct Node* next;
};
struct Node* createnewNode(int data)
{
	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
void display(struct Node* head)
{
	struct Node* current;
	current = head;
	while(current)
	{
		printf("%d,",current->data);
		current = current->next;
	}	
}
// Function merge which returns struct Node* and accepts the head node of 2 linked lists
struct Node* merge(struct Node* p,struct Node* q,struct Node* s)
{
	struct Node* new_head = NULL;
	if(p==NULL)
		return q;
	if(q==NULL)
		return p;

	if(p && q)
	{
		//Check if P->Data <= Q->Data.	
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
	new_head = s; // This should be return value from this function
	while(p && q)
	{	
		if(p->data <= q->data)
		{	
			// Now make s->next = P as p is less than Q.
			// Make s point to P.
			// P is made to point to s->next
			s->next = p;
			s = p;
			p = s->next;	
		}
		else
		{
			// Point s->next to Q as q is less than p
			// Then make s point to Q
		// q is made to point to s->next 
			s->next = q;
			s = q;
			q = s->next;
		}
	}
	if(q==NULL && p!=NULL)
		s->next = p;
	else if(p==NULL && q!=NULL)
		s->next = q;
	return new_head;
}
int main()
{
	// Create a header node.
	struct Node* list1head = createnewNode(10);
	list1head->next = createnewNode(50);
	list1head->next->next = createnewNode(70);
	list1head->next->next->next = createnewNode(90);
	list1head->next->next->next->next = createnewNode(100);
	
	struct Node* list2head = createnewNode(20);

	list2head->next = createnewNode(30);
	list2head->next->next = createnewNode(40);
	list2head->next->next->next = createnewNode(60);
	list2head->next->next->next->next = createnewNode(80);

	printf("\n The elements in list1 before merge are as follows: ");
	display(list1head);
	printf("\n The elements in list2 before merge are as follows: ");
	display(list2head);
	struct Node* mergedlist = NULL;
	mergedlist = merge(list1head,list2head,mergedlist);
	printf("\n The elements in merged list are as follows: ");
	display(mergedlist);
}
