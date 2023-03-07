#include <stdio.h>

#define TAB 8

/* detab.c replaces tabs in input for the proper number of ws, assume a fixed set of tab stop 8.
 */

void	main()
{
	int c, i, nc, rep; 
	nc = 0;
	while(( c = getchar()) != EOF){
		if (c == '\n')
			nc = -1;
		if( c == '\t')
			for( i = (TAB - (nc % 8)) ; i > 0; --i){
				printf(" ");
				++nc;}
		else{
			putchar(c);
			++nc;
		}
	}
	

	return 0;


}

