#include <stdio.h>

main() 
{
	int c, nl, tbs, ws;

	nl = 0;
	tbs = 0;
	ws = 0;

	while((c= getchar())!= EOF){
		if (c == '\n' )
			++nl;
		if (c == '\t' )
			++tbs;
		if (c == ' ' )
		       ++ws;
	}	
	printf("\n   nl  tbs ws \n", "nl", "tbs", "ws");
	printf("\n %3d %3d %3d \n", nl, tbs, ws);
}
