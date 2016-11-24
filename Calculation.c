#include <stdio.h>

typedef struct Sensor1
{
	double UV;
	double humid;
	double temp;
}Sensor1;

typedef struct Sensor2
{
	double humid;
	double temp;
}Sensor2;

void Calculation
{
	double DR;
	int select;
	scanf("%d", &select);

	switch(select)
	{
		case '1' :
			DR = k * (Sensor1.humid - Sensor2.humid);
			break;
		case '2' :
			DR = H / m * (Sensor1.temp - Sensor2.temp);
			break;
	}
}
