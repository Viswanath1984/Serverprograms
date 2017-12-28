#include<iostream>
#include<map>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
struct Node* createNewNode(int data)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	if(newnode)
	{
		newnode->data = data;
		newnode->next = NULL;
	}
	return newnode;

}

void display(struct Node* head)
{
	printf("\n Elements in linked list are as follows: ");
	struct Node* current;
	current = head;
	while(current)
	{
		if(current->next !=NULL)
			printf("%d,",current->data);
		else
			printf("%d ",current->data);
		current = current->next;
	}
}

void removeduplicates(struct Node* head)
{
	// Declare a map to store the values in the list	
	map<int,int> map1;
	struct Node* current,*previous,*temp;
	current = head;
	int value;
	while(current)
	{
		// We are able to find a value corresponding to map1.
		value = current->data;
		if(map1.find(value)!= map1.end())
		{
			temp = current;
			previous->next = current->next;
			printf("\n Freeing element with value %d", temp->data);
			free(temp);
		}
		else
		{
			printf("\n Entering else block:");
			map1[value] = 1;
			previous = current;
		}
		current = current->next;
	}
}

int main()
{
	struct Node* head = createNewNode(1);
	head->next = createNewNode(1);
	head->next->next = createNewNode(1);
	head->next->next = createNewNode(1);
	head->next->next->next = createNewNode(5);
	head->next->next->next->next = createNewNode(4);
	head->next->next->next->next->next = createNewNode(5);
	printf("\n Original list:");	
	display(head);
	
	removeduplicates(head);
	printf("\n List after removing duplicates");
	display(head);

}

