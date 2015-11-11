/**
	Problem : Given notes of different denominations ( 1,2,5,10) , WAP to find in how many ways can you make an amount ‘x’ ?
**/
#include <iostream>
using namespace std;

int denominations[] = {1, 2, 5, 10 }; 	// Possible Denominations
int size = 4;


int howmanyways(int x) {
	if(x == 0)	return 1;
	if( x < 0)	return 0;
	int no_of_ways = 0;
	for(int i = 0; i < size; i++)
		no_of_ways += howmanyways(x - denominations[i]);
	return no_of_ways;

}


int main() {
	cout << howmanyways(3) << endl;
	return 0;
}
