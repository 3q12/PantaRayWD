#include <stdio.h>
#include <stdlib.h> //192.168.123.102
#include <string.h>
#include <time.h>
typedef struct sensor
{
	float humi;
	float temp;
}sensor;
int main(){
	sensor save; //struct(I don't use array)
	int i, j;
	char *result;
	char a[30];
	char b;
	int tmp;
	FILE *stor = fopen("stor2.ino", "wt");; //save imformation to stor.
	while(1){
		result='\0';
		system("rm S2.html");
		system("wget -O S2.html 192.168.123.100");
		FILE *test = fopen("S2.html", "rt");
		if(test==NULL)
			return -1;
		for(i=0; (b=fgetc(test))!='\n'; i++)
			a[i]=b;
		result=strtok(a,",");
		for(i=0; result != NULL; i++)
		{
			if(i==0){
				save.humi=atof(result);
				printf("humidity : %.1f ", save.humi);
				fprintf(stor, "humidity : %.1f ", save.humi);
				fflush(stor);
				result = strtok(NULL, ",");}
			else {
				save.temp=atof(result);
				printf("temperature : %.1f\n", save.temp);
				fprintf(stor, "temperature : %.1f\n", save.temp);
				fflush(stor);
				result = strtok(NULL, ",");}
		}
		fclose(test);
		sleep(1);
	}
	fclose(stor);
	return 0;
} 
