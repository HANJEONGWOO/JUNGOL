#include <stdio.h>

int N;
char neck[400];

int cur;
int result;

int before;
int after;

char b_color;
char a_color;

int w_count;

int main(void)
{
	scanf("%d", &N); //input N;

	scanf("%s", &neck); //input neck

	for (int i = 0; i < N; i++)
	{
		if (neck[i] == 'w')
			w_count++;
	}
	if (w_count == N) { //if, terminal statement
		printf("%d\n", N);
		return 0;
	}

	for (int i = 0; i < N; i++)
	{
		cur = 0; //set cur zero;

		before = i - 1;
		if (before < 0)
			before = N - before;

		if (neck[before] == 'w')
		{
			for (int j = before - 1; ; j--)
			{
				if (j < 0)
					j = N - j;
				if (neck[j] != 'w') {
					b_color = neck[j]; break;
				}
			}
		}
		else
			b_color = neck[before];

		after = i;
		if (after >= N)
			after = after - N;

		if (neck[after] == 'w')
		{
			for (int j = after + 1; ; j++)
			{
				if (j >= N)
					j = j - N;
				if (neck[j] != 'w') {
					a_color = neck[j]; break;
				}
			}
		}
		else
			a_color = neck[after];


		for (int j = before; ; j--)
		{
			if (before < 0)
				before = N - before; //set before

			if (neck[before] == b_color || neck[before] == 'w')
				cur++;
			else
				break;

			if (cur >= N)
				break;

			before--; //minus;
		}

		for (int j = after; ; j++)
		{
			if (after >= N)
				after = after - N;

			if (neck[after] == a_color || neck[after] == 'w')
				cur++;
			else
				break;

			if (cur >= N)
				break;

			after++; //plus;
		}

		if (cur >= N)
			result = N;
		else
		{
			if (result < cur)
				result = cur;
		} //set result;;;

	}

	printf("%d\n", result);

	return 0;
}
