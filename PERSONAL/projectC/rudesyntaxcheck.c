#include <stdio.h>

#define MAX 1000

/* This is a program to check the balance in special character like parentheses ...*/

void copy(char sm[], char out[]);
int parenbrackets(int i, char sm[], int y);
/*void stest(char st[]);*/
int quotesdoubl(int i, char sm[], int y);

int main() 
{
	int i, c, nl, y, single, doubl, cumparen, cumbrack;
	char sm[MAX], out[MAX];
	
	doubl = single = cumparen = cumbrack = 0;
	
	for(i = 0; (c = getchar()) != EOF ; ++i){
		sm[i] = c;
		if(sm[i] == '\n'){
			++nl;
			for( y = 2; y < 4; ++y){
				if(y == 2)
					cumparen = parenbrackets(i, sm, y);
				else if(y == 3)
					cumbrack = parenbrackets(i, sm, y);
			}
		}	
	}
	sm[i] = '\0';
	copy(sm, out);
       	printf("%s\n", out);
	printf("\nNewlines : %d\n", nl);	
	printf("\nUnbalanced parentheses : %d (They are signaled inline with a \"*\")", cumparen);
	printf("\nUnbalanced brackets : %d (They are signaled inline with a \"#\")", cumbrack);
	printf("\nUnbalanced singlequotes :  %d && doublequotes : %d signaled inline with a \"@\")", single, doubl);
	printf("\n\n");
	return i;
}

void copy(char from[], char to[])
{
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0')
		++i; 

}

int parenbrackets(int i, char sm[], int y)
	/*Returns the diff in values of one char compared to another taking char in an array list*/
{ 
	char st[4];
	st[2] = '(';
	st[3] = '[';
	st[4] = ')';
	st[5] = ']';

	int v, p, e; 
	v = p = 0;

	for(e = (i-1); sm[e] != '\n' && e > 0; --e){
		if(sm[e] == st[y])
			++v; 
		if(sm[e] == st[y+2])
			++p; 
	}
	if((p-v) != 0)
		return 1 ;

	

	
	v = p = 0;

}

/*void stest(char st[])
	manually created list to serve as general comparators
{
	
		
}
*/

int quotesdoubl(int i, char sm[], int y)
	/*counts the occurence of a char and returns rather it is odd or even */
{
	char st[2];
	st[0] = '\'';
       	st[1] = '"';

	int v, e;
	v = 0;

	for(e = (i-1); sm[e] != '\n' && e > 0; --e)
		if(sm[e] == st[y])			
			++v;

	return v%2;

	v = 0;
}
