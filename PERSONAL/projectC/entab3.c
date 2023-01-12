#include <stdio.h>

#define TAB 8
#define MAX 500
#define MAX2 1000

void copy( char out[], char sm[]);
int count(int i, int c, char sm[]);

main(){
	while(getlines() > 1)
		getlines();
}

int getlines()
{
	int c, i, b;
	char sm[MAX2], outm[MAX2];
	

	for (i = 0; i < (MAX) && (c = getchar()) != EOF && c != '\n' ; ++i){
		if (c == ' ' && c == '\t')
			sm[i] = count(i, c, sm) ;

		else{
			sm[i] = c;
		        		}
	}
	if (c == '\n'){
		++i;
		sm[i] = c;
	}
	++i;	 
	sm[i] = '\0';
	copy(outm, sm);
	printf("\n%s\n", outm);
	return i;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

int count(int i, int c, char sm[])
{
	int v, y, nc, ws;
	char sc[MAX];
	
	nc = i;
	ws = 0;
	while( c == ' ' && c == '\t'){
		if (c == '\t'){
			ws = ws + (TAB-nc%TAB);
			nc = nc + (TAB-nc%TAB);
			}
		else if (c == ' '){
			++nc;
			++ws;
		}
	}
	for(y = 0; ws > 0 ; ++y){
		if (ws >= TAB){
			sc[y] = '\t';
			ws = ws-(TAB-nc%TAB);
		}
		else { 
			sc[y] = ' ';
			--ws;
		}
	ws =0;
	}
	for(v = 0; v < y; ++v) { 	
		return sc[v];
		

	}
	

		
}	

