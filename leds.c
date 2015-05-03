#include <wiringPi.h>
#include <stdio.h>
#include <string.h>


//Constante waardes
const int CLK = 22; //Clock
const int SDI = 23; //Data
long hexwaarde; //Kleur
int aantalleds; //Aantal leds

int main(int argc, char *argv[])
{	
	//printf("test %d\n", argc);	

	if(argc == 3)//Eerst kijken of er 3 argumenten meegegeven
	{
		//printf(argv[1]);
		aantalleds = (int)strtol(argv[1], NULL, 10);
		//printf(argv[2]);
		hexwaarde = strtol(argv[2], NULL, 0);
	}
	
	wiringPiSetupGpio();
	
	//pinModes klaarzetten
	pinMode(CLK, OUTPUT); //Clock
	pinMode(SDI, OUTPUT); //Data
	
	//printf("Pinmodes SET\n");


	int y;
	for(y = 0; y < aantalleds; y++) //alle leds overlopen
	{
		int i;
		for (i = 23; i >= 0; i--) //24 bits doorsturen voor iedere led
		{
			digitalWrite(CLK, LOW); //clock LOW	

			long bitMask = 1 << i;
			
			if(bitMask & hexwaarde)
				digitalWrite(SDI, HIGH);
			else			
				digitalWrite(SDI, LOW);
								
			digitalWrite(CLK, HIGH); //clock HIGH
		}
	}
	
	digitalWrite(CLK, LOW);
	delayMicroseconds(1000);
	
	//printf("\nEND OF PROGRAM\n");
	
	return 0;
}
