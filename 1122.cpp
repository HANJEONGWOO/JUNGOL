#include <stdio.h>

int N;
char chess[5][5];
int max;

int fail_flag = 0;

void f(int y, int x, int n);
int check(int y, int x);

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i<N; i++)
		scanf("%s", &chess[i]);

	f(0, 0, 0);

	printf("%d\n", max);

	return 0;
}

void f(int y, int x, int n)
{
	//printf("!%d %d\n", y, x);

	if (y == N)
	{
		if (max < n)
			max = n;
		return;
	}

	if (x != N - 1)
	{
		f(y, x + 1, n);

		fail_flag = 0;
		fail_flag = check(y, x);
		if (fail_flag == 0)
		{
			//printf("!!%d %d\n", y, x);
			chess[y][x] = '1';
			f(y, x + 1, n + 1);
			chess[y][x] = '.';
		}
	}
	else
	{
		f(y + 1, 0, n);

		fail_flag = 0;
		fail_flag = check(y, x);
		if (fail_flag == 0)
		{
			//printf("!!!%d %d\n", y, x);
			chess[y][x] = '1';
			f(y + 1, 0, n + 1);
			chess[y][x] = '.';
		}
	}

}

int check(int y, int x)
{

	//자기자신이 X인지 조사
	if (chess[y][x] == 'X')
		return 1;

	for (int i = y - 1; i >= 0; i--)
	{
		if (chess[i][x] == 'X')
			break;
		else if (chess[i][x] == '1')
		{
			return 1;
		}
	}
	for (int i = y + 1; i < N; i++)
	{
		if (chess[i][x] == 'X')
			break;
		else if (chess[i][x] == '1')
		{
			return 1;
		}
	}
	for (int i = x - 1; i >= 0; i--)
	{
		if (chess[y][i] == 'X')
			break;
		else if (chess[y][i] == '1')
		{
			return 1;
		}
	}
	for (int i = x + 1; i < N; i++)
	{
		if (chess[y][i] == 'X')
			break;
		else if (chess[y][i] == '1')
		{
			return 1;
		}
	}

	return 0;
}