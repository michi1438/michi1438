#include <stdio.h>


int power(int m, int n);

/* test the power func/ */
int main()
{
	int i; 

	for (i = 0; i < 10; ++i)
		printf( "\n %d %d %d \n", i, power(5,i), power(10,i));
       	return 0;
}


/* power : raise base to n-th power ; n >= 0 */

int power(int base, int n) 
{
	int i, p; 

	p = 1;
	for(i = 1 ; i <= n ; ++i)
		p = p * base; 
	return p;
}

