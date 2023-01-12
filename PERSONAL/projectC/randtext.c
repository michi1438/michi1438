#include <time.h>
#include <stdlib.h>

srand(time(NULL));   
int r = rand(); 

main()
{
	extern int r; 
	printf("%d", r);
}
