#include <stdio.h>

int fahrcels(int l, int u, int s);

int main()
{
	fahrcels(0, 300, 20);
	return 0;
}

int fahrcels(int lower, int upper, int step)
{
	int fahr, celsius;

	for( fahr = lower; fahr <= upper ; fahr = fahr + step)
		printf("%d\t%d\n", fahr, (5 * (fahr-32) / 9));
	return 1;	
	
	

}
