#include <stdio.h>

#define MAX 1000

/* This is meant to be  a crude synthax check for C programs, (['"*/
char sm[MAX];

void copy(char out[], char sm[]);
int parenbrack(int i, char sm[], int y, char st[]);
int controller(int i, char sm[], char out[], int c);

int main()
	/* Both the main() and the copy function is the base copy of the program */
{
	char out[MAX], sm[MAX];
	int i, c, par, ch;
       	ch = 0;
      	for(i=0; (c = getchar()) != EOF && ch < 1; ++i){
		sm[i] = c;
		if(controller(i, sm, out, c) > 0)
			++ch;
	}
	if(ch == 0){
		copy(out, sm);
		printf("%s", out);		
	}
	return 0;
}

void copy(char out[], char sm[])
	/* The very simple copy func */
{

	int i; 
	i = 0;
	while((out[i] = sm[i]) != '\0')
		++i;	
}













int controller(int i, char sm[], char out[], int c)
	/* dispatches the work to diff func, parenbrack(), ... . Futur funcs are to be controlled through here !*/ 
{
	int ch, y; 
	char st[8];
	st[0] = '(';
	st[1] = '[';
	st[2] = ')';
	st[3] = ']';
	ch = 0;

	if(c == '\n')
		for(y = 0; y < 2; ++y)
		   	if(parenbrack(i, sm, y, st) != 0){
				++ch; 
				copy(out, sm);
				printf("%s", out);
				printf("\nCheck previous line for unbalanceness !");
		}
	return ch;
}

int parenbrack(int i, char sm[], int y, char st[])
	/* Checks for unbanceness line by line ([)]*/
{
	int e, op, cl;
	op = cl = 0; 

	for(e = (i-1); e != '\n'&& e != 0; --e){
		if(sm[e] == st[y])
			++op;
		if(sm[e] == st[y+2])
			++cl;
	}
	return cl-op;
	op = cl = 0;

}
