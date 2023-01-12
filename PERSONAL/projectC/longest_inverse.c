#include <stdio.h>
# define MAXLINE 10000 

int getline(char line[], int maxline); 
void copy(char to[], char from[], int len);

int main()
{
	int len;
	int max; 
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0; 
	while((len = getline(line, MAXLINE)) > 0){
		if (len >= max) 
			copy(longest, line, len); 
		
		if (len > 0){
			printf("\n%d", len);
			printf("\n%s\n", longest);
		}
	}
	return 0; 
}


int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] =  '\0';
	return i; 
}


void copy(char to[], char from[], int len)
{
	int i, v; 
	i = 0;
	for(v = (len - 1); (to[i] = from[v]) != '\0'; ++i && --v) 
		;
}
