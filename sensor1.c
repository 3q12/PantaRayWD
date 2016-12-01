#include <stdio.h>
#include <stdlib.h> //192.168.123.102
#include <string.h>
#include <time.h>
typedef struct sensor
{
	float humi;
	float temp;
	float form;
}sensor;

int main(){
	sensor save; //struct(I don't use array)
	int i, j;
	char *result;
	char a[30];
	char b;
	int tmp;
	FILE *stor = fopen("stor1.ino", "wt");; //save imformation to stor.
	while(1){
		result='\0';
		system("rm S1.html");
		system("wget -O S1.html 192.168.123.101");
		FILE *test = fopen("S1.html", "rt");
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
			else if(i==1){
				save.temp=atof(result);
				printf("temperature : %.1f\n", save.temp);
				fprintf(stor, "temperature : %.1f ", save.temp);
				fflush(stor);
				result = strtok(NULL, ",");}
			else {
				save.temp=atof(result);
				printf("formaldehyde : %.1f\n", save.temp);
				fprintf(stor, "formaldehyde : %.1f\n", save.temp);
				fflush(stor);
				result = strtok(NULL, ",");}
		}
		fclose(test);
		sleep(1);
	}
	fclose(stor);
	return 0;
} 