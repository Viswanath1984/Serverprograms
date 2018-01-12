#include<iostream>
using namespace std;
int main()
{
	int x=10,y=10;
	printf("\n Before swap values of x and y:  %d, %d",x,y);
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
	printf("\n After swap values of x and y are: %d, %d",x,y);
}
