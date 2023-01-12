#include <stdio.h>

#define PROD 1000000 
main()
{ 
	int x, y, z;

	for(x = 1; x <=PROD ; ++x)
		if(PROD%x == 0)
			for(y =1; y<= PROD ; ++y)
				if(PROD%y == 0)
					for(z = 1; z <= PROD ; ++z)
						if(PROD%z == 0)
							if((x*y*z) == PROD)
								printf("%d:%d:%d\n", x, y, z);
}	
