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
void removeduplicates(struct Node* head)
{
	struct Node* temp;
	struct Node* previous;
	struct Node* current;
	map<int,int> map1;
	int key;
	current = head;
	while(current!=NULL)
	{
		key = current->data;
		// If we find this value already in map, then do following
		if(map1.find(key)!=map1.end())
		{
			// Store the current element in temp
			temp = current;
			previous->next = current->next;
			free(temp);
		}
		else
		{
			// if the current element isn't present in map already then add against key, value of 1.
			map1[key] = 1;
			previous = current;
		}
		current = current->next;
	}
}
int main()
{
	struct Node* head = createnewNode(1);
	head->next = createnewNode(1);
	head->next->next = createnewNode(1);
	head->next->next->next = createnewNode(1);
	head->next->next->next->next = createnewNode(1);
	head->next->next->next->next->next = createnewNode(5);
	head->next->next->next->next->next->next  = createnewNode(4);
	head->next->next->next->next->next->next->next = createnewNode(5);
	display(head);
	removeduplicates(head);
	display(head);

}
