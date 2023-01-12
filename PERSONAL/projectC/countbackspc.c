#include <stdio.h> 

main()

{
	int c; 
	while((c = getchar()) != EOF){
		if(c == '\b')
			printf("\\b");
		if(c != '\b')
			putchar(c);
	}
}
