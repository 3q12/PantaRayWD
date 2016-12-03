#include <stdio.h>
int main(){
        int i;
        char a[30];
        char b;
        FILE *Save1 = fopen("Save1", "wt");
        FILE *Save2 = fopen("Save2", "wt");
        system("gcc -o sensor1 sensor11.c");
        system("gcc -o sensor2 sensor2.c");
        while(1){
        a[0]='\0';
        system("./sensor1");
        FILE *final1 = fopen("stor1", "rt");
        for(i=0; (b=fgetc(final1))!='\n'; i++)
                a[i]=b;
        fprintf(Save1, "%s\n", a);
        fflush(Save1);
        fclose(final1);
        system("./sensor2");
        FILE *final2 = fopen("stor2", "rt");
        a[0]='\0';
        for(i=0; (b=fgetc(final2))!='\n'; i++)
                a[i]=b;
        fprintf(Save2, "%s\n", a);
        fflush(Save2);
        fclose(final2);
        }
        return 0;
}
