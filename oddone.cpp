#include<iostream>
using namespace std;
int findoddnumber(int *arr,int n);
int findoddnumber(int *arr,int n)
{
	// Do an XOR Of all elements in the array
	// Initialize result equal to 0. Keep XORing all elements in array
	int result = 0;
	for(int i=0;i<n;i++)
	{
		result ^= arr[i]; 
	}
	printf("\n The odd number in list is %d",result);
	return result;
}
int main()
{
	int arr[] = {12,12,14,14,90,12,12};
	int size = sizeof(arr)/sizeof(arr[0]);
	findoddnumber(arr,size);
}
