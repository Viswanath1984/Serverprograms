#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};

// Let this function return the address of node where slow/fast pointers meet
struct Node* detectcycle(struct Node* head)
{
	struct Node* slow, *fast;
	slow = fast = head;
	while(slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
		{
			printf("\n Cycle is present in the linked list");
			return slow;
		}
	}
	printf("\n Cycle is not present in linked list:");
	return NULL;
}

struct Node* removeloop(struct Node* loopnode, struct Node* head)
{
	// Put loopnode into a pointer ptr2.
	struct Node* fast,*slow;
	slow = head; // 
	fast = loopnode;
	while(slow->next != fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	// At the point where these
	fast->next = NULL;
	printf("\n Removed loop at node with value %d",fast->data);
}

struct Node* createNewNode(int data)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	if(newnode)
	{
		newnode->data = data;
		newnode->next = NULL;	
	}
}
int main()
{
	// 1->2-3->4->5-
	struct Node* head = createNewNode(1);
	head->next = createNewNode(2);
	head->next->next = createNewNode(3);
	head->next->next->next = createNewNode(4);
	head->next->next->next->next = createNewNode(5);
	head->next->next->next->next->next = createNewNode(6);
	
	// Create a a loop between 5th node's next to 3
	head->next->next->next->next->next->next = head->next->next->next; 			
	struct Node* temp =  detectcycle(head);
	if(temp)
	{
		printf("\n Slow and fast pointers meet at Node with value %d",temp->data);
		removeloop(temp,head);
	}
}
