
// PWM stands fo Pulse Width Modulation.
void setup() {
pinMode (9, OUTPUT);
}

void loop() {
	int i = 0;

	while (i <= 255)
	{
		analogWrite(9, i);
		delay(255 - i);
		i++;
	}
}
