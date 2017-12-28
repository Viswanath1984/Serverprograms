#include<iostream>
#include<cstdlib>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
typedef struct Node* Nodeptr;
Nodeptr head = NULL;
void insert(Node** head, int data)
{
	Nodeptr current;
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->next = NULL;
	if(!newnode)
	{
		printf("\n Memory allocation failure");
		exit(1);
	}
	if(*head==NULL)
	{
		*head = newnode;
	}
	else
	{	
		current = *head;
		while(current->next!=NULL)
		{
			current = current->next;
		}
		current->next = newnode;
	}

}
void display(Nodeptr head)
{
	printf("\n The elements in the list are as follows:");
	Nodeptr current;
	current = head;
	while(current!=NULL)
	{
		printf("%d\t",current->data);
		current = current->next;
	}
}
Nodeptr reversealternate(Nodeptr *head,int k)
{
	// Initialize the required pointers
	// When function terminates *head must contain previous - new Head
	Nodeptr previousnode = NULL;
	Nodeptr nextnode;
	Nodeptr currentNode;
	int count = 0; // Initialize a counter to hold number of nodes traversed
	currentNode = *head;

	// Reverse the first k nodes in the Linked List.
	while(currentNode!=NULL && count<k)
	{
		nextnode = currentNode->next; 
		currentNode->next = previousnode;
		previousnode = currentNode;
		currentNode = nextnode;
		count++;
	}
	// At the end of this function curretnode is pointing to next node
	if(*head!=NULL)
		(*head)->next = currentNode;
	// Now we shouldn't be reversing the next three nodes
	count = 0;
	while(count<k-1 && currentNode!=NULL)
	{
		currentNode = currentNode->next;
		count++;
	}
	if(currentNode!=NULL)
		currentNode->next = reversealternate(&(currentNode->next),k);
	
	return previousnode;

}

// Reverse - iterative function
void reverse(Nodeptr *head)
{
	// When this function returns it will modify the head's address
	Nodeptr previousnode = NULL; // Current head node's next pointer is NULL.
	Nodeptr nextnode;
	Nodeptr currentnode = *head; // Initialize head to current
	while(currentnode!=NULL)
	{
		// Save the current's next pointer from being overwritten
		nextnode = currentnode->next;
		currentnode->next = previousnode; // Make current's next point to previous node
		// Make previous node point to 
		previousnode = currentnode;
		currentnode = nextnode;		
	}
	*head = previousnode;
}
int main()
{
	char ch;
	int value,n,i,insertval;
	do
	{
		printf("\n 1. Insert 2. Display 3. Reverse 4.ReverseAlternate");
		scanf("%d",&value);
		switch(value)
		{
			case 1:
				printf("\n Enter the number of elements to be inserted");
				scanf("%d",&n);
				for(int i=0;i<n;i++)
				{
					printf("\n Enter value %d: ", i+1);
					scanf("%d",&insertval);
					insert(&head,insertval);
				}
				break;
			case 2:
				display(head);
				break;
			case 3:
				reverse(&head);
				break;	
			case 4:
				head = reversealternate(&head,3);
				break;
		}	
		printf("\n Do you want to continue(y/n)");
		scanf(" %c",&ch);
	}while(ch=='y');	
}
