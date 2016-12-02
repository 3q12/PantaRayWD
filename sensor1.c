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
typedef struct sensor2
{
        float humi2;
        float temp2;
}sensor2;
int main(){
        sensor save; //struct(I don't use array)
        sensor2 save2;
        int i, j;
        char *result;
        char *result2;
        char a[30];
        char a2[30];
        char b;
        char b2;
        FILE *stor = fopen("stor1", "wt");; //save imformation to stor.
        FILE *stor2 = fopen("stor2", "wt");; //save imformation to stor.
        while(1){
                result='\0';
                result2='\0';
     //   system("rm S1.html");
     //   system("rm S2.html");
     //   system("wget -O S1.html 192.168.123.101");
     //   system("wget -O S2.html 192.168.123.100");
        FILE *test = fopen("power", "rt");
        FILE *test2 = fopen("power2", "rt");
        if(test==NULL)
                return -1;
        if(test2==NULL)
                return -1;
        for(i=0; (b=fgetc(test))!='\n'; i++)
                a[i]=b;
        for(i=0; (b2=fgetc(test2))!='\n'; i++)
                a2[i]=b2;
        printf("df");
        result=strtok(a,",");
        result2=strtok(a2,",");
        /*
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
                        printf("temperature : %.1f ", save.temp);
                        fprintf(stor, "temperature : %.1f ", save.temp);
                        fflush(stor);
                        result = strtok(NULL, ",");}
                else {
                        save.form=atof(result);
                        printf("formaldehyde : %.2f\n", save.form);
                        fprintf(stor, "formaldehyde : %.2f ", save.form);
                        fflush(stor);
                        result = strtok(NULL, ",");}
        }
        */
        for(i=0; result2 != NULL; i++)
        {
                if(i==0){
                        save2.humi2=atof(result2);
                        printf("humidity2 : %.1f ", save2.humi2);
                        fprintf(stor2, "humidity2 : %.1f ", save2.humi2);
                        fflush(stor2);
                        result2 = strtok(NULL, ",");}
                else {
                        save2.temp2=atof(result);
                        printf("temperature2 : %.1f ", save2.temp2);
                        fprintf(stor2, "temperature2 : %.1f ", save2.temp2);
                        fflush(stor2);
                        result2 = strtok(NULL, ",");}
        }
        fclose(test);
        fclose(test2);
struct tm *clock;
time_t current;
        time(& current);
        clock=localtime(& current);
                fprintf(stor, "%d:%d:%d\n",clock->tm_hour%24,clock->tm_min,clock->tm_sec);
                fprintf(stor2, "%d:%d:%d\n",clock->tm_hour%24,clock->tm_min,clock->tm_sec);
        sleep(1);
        }
        fclose(stor);
        fclose(stor2);
        return 0;
} 
