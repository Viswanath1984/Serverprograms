#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
//Let us initialize a structure to store treenode
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

// Let us have a function to create a new node

struct Node* newNode(int data)
{
	// Allocate memory using new
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	//printf("\n Created new node with value %d",data);	
	return temp;
}

// Let us have a function to push a new node into a tree
struct Node* sortedarraytobst(int *arr,int start,int end)
{
	if(start> end)
		return NULL;
	// Here we create nodes in pre-order 
	int middle = (start + end)/2;
	struct Node* temp = newNode(arr[middle]);
	temp->left = sortedarraytobst(arr,start,middle-1);
	temp->right = sortedarraytobst(arr,middle+1,end);
	return temp;
}
void inordertraversal(struct Node* head)
{
	if(head==NULL)
		return;
	inordertraversal(head->left);
	printf("%d ",head->data);
	inordertraversal(head->right);
}

int main()
{
    // Given a sorted array let us convert into a balanced binary search tree
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);	
    struct Node* head = NULL;
    //head = sortedarraytobst(arr,0,n-1);
    printf("\n Inorder traversal is as follows"); 
    //inordertraversal(head);
}
