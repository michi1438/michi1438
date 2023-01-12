#include <stdio.h>

#define FIZZ	3
#define BUZZ	5
#define LIMI	100


int main(void)
{
	int i;
	for(i = 1; i < LIMI; ++i){
		if ((i%FIZZ)==0)
			write(1, "FIZZ", 4);
		if ((i%BUZZ)==0)
			write(1, "BUZZ", 4);
		else 
			putnbr i;
		printf(", ");
	}
}

