#include <stdio.h>

int N;

int arr[110][110];

int garo[110];
int saero[110];

int fail_flag;

void check(void);

int main(void)
{
	scanf("%d", &N); //input N

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]); //input i, j;
		}
	}

	//1. 첫번째 검사

	check();

	if (fail_flag == 0) {
		printf("OK\n");
		goto EXIT;
	}
	else //1단계 실패일 경우,
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] == 0)
					arr[i][j] = 1;
				else
					arr[i][j] = 0;

				check();
				if (fail_flag == 0)
				{
					printf("Change bit (%d,%d)\n", i + 1, j + 1);
					goto EXIT;
				}

				if (arr[i][j] == 0)
					arr[i][j] = 1;
				else
					arr[i][j] = 0;

			}
		}

	}

	printf("Corrupt\n");

EXIT:

	return 0;
}

void check(void)
{
	fail_flag = 0; //init fail_flag;
	for (int i = 0; i < N; i++)
	{
		garo[i] = saero[i] = 0; //init garo, saero;
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 1) {
				garo[i]++;
				saero[j]++; //garo, saero plus
			}
		} //for j
	} //for i
	for (int i = 0; i < N; i++)
	{
		if (garo[i] % 2 != 0 || saero[i] % 2 != 0) {
			fail_flag = 1;
			break;
		}
	}

}