#include <stdio.h>
 
int main()
{
    int a = 10, b = 20;
	int res;

	res = a > 0 && b > 0;

    printf("when a && b are true res = %d \n", res);
	res = a < 0 && b < 0;

    printf("when a && b are false res = %d \n", res);
    return 0;
}
