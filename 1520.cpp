#include <stdio.h>

int N;

int stair[330];

int DT[330][3];

int my_max(int a, int b);

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &stair[i]); //input

	DT[0][1] = DT[0][2] = stair[0];

	for (int i = 1; i < N; i++)
	{
		DT[i][1] = DT[i - 1][2] + stair[i];
		DT[i][2] = my_max(DT[i - 2][1], DT[i - 2][2]) + stair[i];
	}

	printf("%d\n", my_max(DT[N - 1][1], DT[N - 1][2]));

	return 0;
}

int my_max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}