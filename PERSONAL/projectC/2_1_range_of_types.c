#include <stdio.h>
#include <math.h>
void signed_char(void);
void unsigned_char(void);
void signed_short(void);
void unsigned_short(void);
void my_float(void);
void my_dblfloat(void);


int main(void)
{
	signed_char();
	unsigned_char();
	signed_short();
	unsigned_short();
	my_float();
	my_dblfloat();


}

void unsigned_short(void)
{
	unsigned short sh = 1;

	while (sh > 0)
		sh++;
	sh--;
	printf("An unsigned short has a range of: %d min: %d max: %d.\n", sh + 1, 0, sh + 1);
}

void signed_short(void)
{
	signed short nsh = 0, psh = 0;

	while (nsh >= 0)
		nsh++;
	while (psh <= 0)	
		psh--;
	printf("A signed short has a range of: %d min: %d max: %d.\n", psh - nsh + 1, nsh, psh);
}	

void unsigned_char(void)
{
	unsigned char cp = 1;
	
	while (cp > 0)
		cp++;
	cp--;
	printf("An unsigned char has a range of: %d min: %d max: %d.\n", cp + 1, 0, cp + 1);
}

void signed_char(void)
{ signed char	cn = 0, cp = 0;

	while (cn >= 0)
		cn++;
	while (cp <= 0)
		cp--; 				// This acctually decrements one further than -128 ie 127.
	printf("A signed char has a range of: %d min: %d max: %d.\n", (cp - cn + 1), cn, cp);
}

void my_float(void)
{
	float flm = 0.1, flz = 1e0f;
	
	while (flm < INFINITY)
	{
		if (flm * 1e1f < INFINITY)
			flm = flm * 1e1f;
		else 
			break;
	}	
	while (flm < INFINITY)
	{
		if (flm + (flm / 1000) < INFINITY)
		{
			flm = flm + flm / 1000;
		}
		else 
			break;
	}
	while (flm < INFINITY)
	{
		if ((flm + 0.000001e38f) < INFINITY)
		{
			flm = flm + 0.000001e38f;
		}
		else 
			break;
	}
	while (flz >= 0)
	{
		if (flz * 1e-1f > 0.000000e0f)
		{
			flz = flz * 1e-1f; 
		}
		else
			break;
	}
	printf("A float has a max absolute value: %e and a min abs value: %e\n", flm, flz);
}

void my_dblfloat(void)
{
	double flm = 0.1, flz = 1e0;
	
	while (flm < INFINITY)
	{
		if (flm * 1e1 < INFINITY)
			flm = flm * 1e1;
		else 
			break;
	}	
	while (flm < INFINITY)
	{
		if (flm + (flm / 1000) < INFINITY)
		{
			flm = flm + flm / 1000;
		}
		else 
			break;
	}
	while (flm < INFINITY)
	{
		if ((flm + 0.000001e308) < INFINITY)
		{
			flm = flm + 0.000001e308;
		}
		else 
			break;
	}
	while (flz >= 0)
	{
		if (flz * 1e-1 > 0.000000e0)
		{
			flz = flz * 1e-1; 
		}
		else
			break;
	}
	printf("A double has a max absolute value: %e and a min abs value: %e\n", flm, flz);
}


