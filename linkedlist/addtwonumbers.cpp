#include<iostream>
#include<cstdlib>
#include<map>
using namespace std;
// Data structure for storing node information
struct Node
{
	int data;
	struct Node* next;
};
typedef struct Node* Nodeptr;

struct Node* createnewNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode)
	{
		newNode->data = data;
		newNode->next = NULL;
	}
}
void display(struct Node* head)
{
	printf("\n Elements in the list are as follows: ");
	struct Node* current = head;
	while(current)
	{
		if(current->next!=NULL)
			printf("%d, ",current->data);			
		else
			printf("%d",current->data);
		current = current->next;
	}

}
void insertfront(struct Node** head,int numzeroes)
{
	while(numzeroes>0)
	{
		struct Node* newnode = createnewNode(0);	
		newnode->next = *head;
		*head = newnode;
		numzeroes--;
	}
}
struct Node* insertelements(struct Node** head, int *arr,int size)
{	
	struct Node* current = *head;
	struct Node* temp;
	for(int i=0;i<size;i++)
	{
		if((*head)==NULL)
		{
			current = createnewNode(arr[i]);
			*head = current;
		}
		else
		{
			temp = *head;
			while(temp->next!=NULL)
				temp= temp->next;
			temp->next = createnewNode(arr[i]);
			printf("\n Created new element with val %d",arr[i]);
		}
	}
	return *head;
}

void reverselist(Nodeptr *head)
{
	Nodeptr nextNode,previous=NULL,current;
	current = *head;
	while(current!=NULL)
	{
		nextNode = current->next;
		current->next = previous;
		previous = current;
		current = nextNode;
	}
	*head = previous;
}

struct Node* addlists(Nodeptr *list1head,Nodeptr *list2head)
{
	Nodeptr p = *list1head;
	Nodeptr q = *list2head;
	struct Node* newlist=NULL,*temp;
	int addval,remainder,carry=0;
	int count = 0,quotient;
	while(p && q)
	{
		addval = (p)->data + (q)->data;
		quotient = (addval + carry)/10;
		if(quotient !=0)
		{	
			remainder = (addval+carry)%10;	
			carry = quotient;
		}	
		else
		{
			remainder = (addval+carry)%10;
			carry = 0;
			printf("\n carry for count %d is %d",count,carry);
		}
		count++;
		if(newlist==NULL)
		{
                        newlist = createnewNode(remainder);
                }
		else
		{
			temp = newlist;
			while(temp->next!=NULL)
				temp= temp->next;
			temp->next = createnewNode(remainder);
		}
		p = (p)->next;
		q = (q)->next;
	}
	if(carry==1)
	{
		temp = newlist;
		while(temp->next!=NULL)
			temp = temp->next;
		temp->next = createnewNode(1);	
	}
	return newlist;
}

int main()
{
	struct Node* list1head = NULL;
	struct Node* list2head = NULL;

	int arr1[] = {9,9,9,4,5};
	int arr2[] = {3,6,9};

	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	int size2 = sizeof(arr2)/sizeof(arr2[0]);
	//createnewNode(1);
	/*head->next = createnewNode(1);
	head->next->next = createnewNode(1);
	head->next->next->next = createnewNode(1);
	head->next->next->next->next = createnewNode(1);
	head->next->next->next->next->next = createnewNode(5);
	head->next->next->next->next->next->next  = createnewNode(4);
	head->next->next->next->next->next->next->next = createnewNode(5);
	*/
	list1head = insertelements(&list1head,arr1,size1);
	list2head = insertelements(&list2head,arr2,size2);
	int diff;
	if(size1>size2)
	{
		// Insert (size1-size2) zeroes at start of 2nd linked list
		diff = size1 - size2;
		insertfront(&list2head,diff);
	}

	printf("\n Elements in first list are as follows: ");
	display(list1head);
	printf("\n Elements in second list are as follows: ");
	display(list2head);

	// Now let us reverse both these linked lists
	reverselist(&list1head);
	reverselist(&list2head); 

	printf("\n Elements in first list after reversal are as follows: ");
	display(list1head);
	printf("\n Elements in second list after reversal are as follows: ");
	display(list2head);

	// Now let us add the elements present in both the lists
	struct Node* newlist1 = addlists(&list1head,&list2head);
	display(newlist1);
	printf("\n Elements in the new list after reversal are as follows:");
	reverselist(&newlist1);
	display(newlist1);

}
