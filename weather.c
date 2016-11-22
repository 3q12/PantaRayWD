#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	float temp;
	int pop;
	char weath[10];
	float windspd;
	float humid;
}weather;
void RESET_RSS()
{
	system("rm ./queryDFSRSS.jsp@zone=1159068000");

	system("wget http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=1159068000");
}
int main()
{

	RESET_RSS();

	weather saved[4];
	char tmp;
	int cnt = 0;
	int line = 0;
	char arrtmp[5];

	FILE *ifp, *ofp;

	ifp = fopen("queryDFSRSS.jsp@zone=1159068000", "r");

	while((fscanf(ifp, "%c", &tmp) != EOF) && cnt < 4){//cnt가 4를 넘으면 이상한 공간이 형성 되므로 4 전에 강제 종료 시켜버림
		if(tmp == '<')
		{
			line = 0;
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
			line = 0;
			if(strcmp(arrtmp, "temp") == 0)
			{
				printf(" ===================== %d ========================\n", cnt);
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
				saved[cnt].temp=atof(arrtmp);
				printf("temp : %.1f\n", saved[cnt].temp);
			}g
			else if(strcmp(arrtmp, "wfKor") == 0)
			{
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
				strcpy(saved[cnt].weath, arrtmp);
				printf("weath : %s\n", saved[cnt].weath);
			}
			else if(strcmp(arrtmp, "pop") == 0)
			{
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
				saved[cnt].pop=atof(arrtmp);
				printf("pop : %d\n", saved[cnt].pop);
			}
			else if(strcmp(arrtmp, "ws") == 0)
			{
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
				saved[cnt].windspd=atof(arrtmp);
				printf("windspd : %.1f\n", saved[cnt].windspd);
			}
			else if(strcmp(arrtmp, "reh") == 0)
			{
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
				saved[cnt].humid=atof(arrtmp);
				printf("humid : %.1f\n", saved[cnt].humid);
				cnt++;
			}
		}
	}


	if((ifp = fopen("queryDFSRSS.jsp@zone=1159068000", "r")) == NULL)
		printf("file couldn't be opened");

	return 0;
}
