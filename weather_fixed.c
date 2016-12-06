#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	float temp;
	int pop;
	char weath[20];
	float windspd;
	float humid;
}weather;
weather saved[4];
void RESET_RSS()
{
	system("rm ./queryDFSRSS.jsp@zone=1159068000");

	system("wget http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=1159068000");
}
void CHECK_INFO(FILE *ifp, char *arrtmp)
{
	int line = 0;	
	while(1)
	{
		fscanf(ifp, "%c", &arrtmp[line]);
		if(arrtmp[line] == '>')
		{
			arrtmp[line] = '\0';
			break;
		}
		line++;
	}
}
void CLOSE_INFO(FILE *ifp, char *arrtmp)
{	
	int line = 0;
	while(1)
	{
		fscanf(ifp, "%c", &arrtmp[line]);
		if(arrtmp[line] == '<')
		{
			arrtmp[line] = '\0';
			break;
		}
		line++;
	}

}
void OUTPUT(weather *saved)
{
	int cnt;
	for(cnt = 0; cnt < 4; cnt ++)
	{
		printf("==============================%d================================\n",cnt);
		printf("temp : %.1f\n", saved[cnt].temp);
		printf("pop : %d\n", saved[cnt].pop);
		printf("weath : %s\n", saved[cnt].weath);
		printf("windspd : %.1f\n", saved[cnt].windspd);
		printf("humid : %.1f\n", saved[cnt].humid);
	}
}
FILE *OPENFILE(void)
{
	FILE *ifp;

	ifp = fopen("queryDFSRSS.jsp@zone=1159068000", "r");
	if((ifp = fopen("queryDFSRSS.jsp@zone=1159068000", "r")) == NULL)
		printf("file couldn't be opened");

	return ifp;
}
void PARCE_DATA(FILE *ifp, weather *saved, char *arrtmp)
{
	char tmp;
	int cnt = 0;

	while((fscanf(ifp, "%c", &tmp) != EOF) && cnt < 4){//cnt가 4를 넘으면 이상한 공간이 형성 되므로 4 전에 강제 종료 시켜버림
		if(tmp == '<')
		{
			CHECK_INFO(ifp, arrtmp);
			if(strcmp(arrtmp, "temp") == 0)
			{
				CLOSE_INFO(ifp, arrtmp);

				saved[cnt].temp=atof(arrtmp);
			}
			else if(strcmp(arrtmp, "wfKor") == 0)
			{
				CLOSE_INFO(ifp, arrtmp);

				strcpy(saved[cnt].weath, arrtmp);
			}
			else if(strcmp(arrtmp, "pop") == 0)
			{
				CLOSE_INFO(ifp, arrtmp);

				saved[cnt].pop=atof(arrtmp);
			}
			else if(strcmp(arrtmp, "ws") == 0)
			{
				CLOSE_INFO(ifp, arrtmp);

				saved[cnt].windspd=atof(arrtmp);
			}
			else if(strcmp(arrtmp, "reh") == 0)
			{
				CLOSE_INFO(ifp, arrtmp);

				saved[cnt].humid=atof(arrtmp);
				cnt++;
			}
		}
	}
}
void MAKE_RSS_FUNCTION()
{
	RESET_RSS();

	char arrtmp[10];

	PARCE_DATA(OPENFILE(), saved, arrtmp);

	OUTPUT(saved);
}
int main()
{

	MAKE_RSS_FUNCTION();

	return 0;
}
