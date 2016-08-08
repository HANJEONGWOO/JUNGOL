#include <stdio.h>

int N;
int player[2200];
int enemy[2200];

int d[2200][2200];

int mymax(int a, int b);
int solve(int i, int j);

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &player[i]);
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &enemy[i]);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			d[i][j] = -1;
		}
	}

	printf("%d\n", solve(0, 0));

	return 0;
}

int mymax(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int solve(int i, int j) {
	if (i >= N || j >= N)
		return 0;

	if (d[i][j] != -1)
		return d[i][j];

	int ret = 0;
	//ret = mymax(ret, solve(i + 1, j));
	ret = mymax(solve(i + 1, j), solve(i + 1, j + 1)); //왼쪽 카드만 버릴 것인지, 두 카드 모두 버릴 것인지 선택한다.

	if (player[i] > enemy[j]) //만약 플레이어 카드가 더 크다면 enemy[j]카드를 더하고 다시 j카드 재귀 호출한다.
		ret = mymax(ret, enemy[j] + solve(i, j + 1));

	d[i][j] = ret; //메모이제이션 방법으로 문제 해결

	return ret;
}