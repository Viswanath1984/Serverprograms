#include<iostream>
#include<cstdlib>
using namespace std;
// Data structure to store list node
struct Node
{
	char ch;
	struct Node* next;
};

typedef struct Node* Nodeptr;
bool comparelists(Nodeptr head,Nodeptr head1);
struct Node* createnewNode(char ch)
{
	Nodeptr newnode = (Nodeptr)malloc(sizeof(struct Node));
	newnode->ch = ch;
	newnode->next = NULL;
	return newnode;
}

void insert(Nodeptr *head,char str[])
{
  	Nodeptr temp;
	for(int i=0;i<strlen(str);i++)
	{
		if(*head==NULL)
			*head = createnewNode(str[i]);
		else
		{
			temp = *head;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = createnewNode(str[i]);
		}
	}

}
void reverse(Nodeptr *head)
{
	Nodeptr nextnode;
	Nodeptr current = *head;
	Nodeptr previous = NULL;
	while(current!=NULL)
	{		
		nextnode = current->next;
		current->next = previous;
		previous = current;
		current = nextnode;
	}
	*head = previous;
}


bool checkpalindrome(Nodeptr head)
{
	struct Node* slowptr;
	struct Node* fastptr;
	struct Node* previous_slowptr;
	struct Node* midnode = NULL;
	struct Node* second_half;

	slowptr = head;
	fastptr = head;
	previous_slowptr = head;
	bool res = true;// return result = true

	if(head!=NULL && head->next!=NULL)
	{	
		while(fastptr !=NULL && fastptr->next!=NULL)
		{
			// Move fast pointer by 2 places
			fastptr = fastptr->next->next;
			previous_slowptr = slowptr;
			slowptr = slowptr->next; 
		}	
	

	// If the number of elements in list is odd then we have fastptr->next!=NUll
	if(fastptr!=NULL)
	{
		// Skip middle element				
		midnode = slowptr;
		slowptr= slowptr->next;
	}
	// Now reverse the second half in this case
	second_half = slowptr;
	previous_slowptr->next = NULL;// terminate the first half;
	// Reverse the second half
	reverse(&second_half);

	if(comparelists(head,second_half))
		return true;
	else
		return false;
	
	}
	return res;

}
bool comparelists(Nodeptr head,Nodeptr head1)
{
	Nodeptr temp,temp1;
	temp = head;
	temp1 = head1;
	while(temp && temp1)
	{
		if(temp->ch == temp1->ch)
		{
			temp = temp->next;
			temp1 = temp1->next;
		}
		else
			return 0;

	}
	if(temp ==NULL && temp1==NULL)
		return 1;

	return 0;


}


void display(struct Node* head)
{
	Nodeptr temp;
	temp = head;
	while(temp!=NULL)
	{
		if(temp->next != NULL)
			printf("%c,",temp->ch);
		else
			printf("%c",temp->ch);

		temp = temp->next;
	}

}

int main()
{
	char str1[] = "abcba";
	char str2[] = "abcddcba";
	
	int size1 = strlen(str1);
	int size2 = strlen(str2);

	struct Node *list1 = NULL;
	struct Node *list2 = NULL;

	insert(&list1,str1);
	insert(&list2,str2);

	printf("\n Elements in list1 are as follows: ");
	display(list1);
	printf("\n Elements in list2 are as follows: ");
	display(list2);
	
	if(checkpalindrome(list1))
		printf("\n Entered string %s is palindrome",str1);
	else
		printf("\n Entered string %s isnt palindrome",str1);

}
