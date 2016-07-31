#include <stdio.h>

int N;
int M;

int result;

int prev_sheet;
int sheet;

int fibo[44];
int main(void)
{

	fibo[0] = 1;
	fibo[1] = 1;
	for (int i = 2; i <= 40; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2]; //get fibonacci
	}

	scanf("%d", &N);
	scanf("%d", &M);

	result = 1;
	prev_sheet = 0;
	for (int i = 0; i < M; i++) {
		scanf("%d", &sheet);

		result *= (fibo[sheet - prev_sheet - 1]);

		//printf("!%d\n", fibo[sheet - prev_sheet - 1]);

		prev_sheet = sheet;
	}

	result *= (fibo[(N + 1) - prev_sheet - 1]);
	//printf("!%d\n", fibo[(N + 1) - prev_sheet - 1] );

	printf("%d\n", result);

	return 0;
}