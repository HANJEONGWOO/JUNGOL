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
	ret = mymax(solve(i + 1, j), solve(i + 1, j + 1)); //���� ī�常 ���� ������, �� ī�� ��� ���� ������ �����Ѵ�.

	if (player[i] > enemy[j]) //���� �÷��̾� ī�尡 �� ũ�ٸ� enemy[j]ī�带 ���ϰ� �ٽ� jī�� ��� ȣ���Ѵ�.
		ret = mymax(ret, enemy[j] + solve(i, j + 1));

	d[i][j] = ret; //�޸������̼� ������� ���� �ذ�

	return ret;
}