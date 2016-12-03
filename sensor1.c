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
        FILE *stor = fopen("stor1", "wt");; //save imformation to stor.
       // while(1){
                result='\0';
     //   system("rm S1.html");
     //   system("wget -O S1.html 192.168.123.101");
        FILE *test = fopen("power", "rt");
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
        fclose(test);
struct tm *clock;
time_t current;
        time(& current);
        clock=localtime(& current);
                fprintf(stor, "%d:%d:%d\n",clock->tm_hour%24,clock->tm_min,clock->tm_sec);
        sleep(1);
       // }
        fclose(stor);
        return 0;
} 
