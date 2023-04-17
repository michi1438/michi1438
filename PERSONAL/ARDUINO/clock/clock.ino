/***
 *         ___/\/\/\/\/\_     _/\/\_______     ___/\/\/\/\___     ___/\/\/\/\/\_     _/\/\____/\/\_
 *        _/\/\_________     _/\/\_______     _/\/\____/\/\_     _/\/\_________     _/\/\__/\/\___ 
 *       _/\/\_________     _/\/\_______     _/\/\____/\/\_     _/\/\_________     _/\/\/\/\_____  
 *      _/\/\_________     _/\/\_______     _/\/\____/\/\_     _/\/\_________     _/\/\__/\/\___   
 *     ___/\/\/\/\/\_     _/\/\/\/\/\_     ___/\/\/\/\___     ___/\/\/\/\/\_     _/\/\____/\/\_    
 *    ______________     ____________     ______________     ______________     ______________     
 */

void reset_all(void);

void setup() {

pinMode (1, OUTPUT);
pinMode (2, OUTPUT);
pinMode (3, OUTPUT);
pinMode (4, OUTPUT);
pinMode (5, OUTPUT);
pinMode (6, OUTPUT);
}

void loop()	
{
	int	i = 0;

	while (i <= 60)
	{
		if (i >> 0 & 1 == 1) 
			digitalWrite(1, HIGH);
		if (i >> 1 & 1 == 1) 
			digitalWrite(2, HIGH);
		if (i >> 2 & 1 == 1) 
			digitalWrite(3, HIGH);
		if (i >> 3 & 1 == 1) 
			digitalWrite(4, HIGH);
		if (i >> 4 & 1 == 1) 
			digitalWrite(5, HIGH);
		if (i >> 5 & 1 == 1) 
			digitalWrite(6, HIGH);
		delay(1000);
		reset_all();
		i++;
	}
}

void reset_all(void)
{
	digitalWrite(1, LOW);
	digitalWrite(2, LOW);
	digitalWrite(3, LOW);
	digitalWrite(4, LOW);
	digitalWrite(5, LOW);
	digitalWrite(6, LOW);
}
