#include <stdio.h>

int N, D, K, C;

int bowl[33000];
int rice[3300];

int result, cur;
int main(void)
{
	scanf("%d %d %d %d", &N, &D, &K, &C);

	for (int i = 0; i < N; i++)
		scanf("%d", (bowl + i));

	for (int i = 0; i < K; i++)
	{
		rice[bowl[i]]++;
	}
	rice[C] = 987654321; //���� ���Ѵ��� ���� ���������ν� �Ź� ī�����ϰԵȴ�.

	for (int i = 1; i <= D; i++)
	{
		if (rice[i] >= 1)
			cur++; //������� ���س��´�.
	}

	if (cur > result)
		result = cur; //replace

	for (int i = 0; i < N; i++)
	{
		rice[bowl[i]] --;

		if (rice[bowl[i]] == 0)
			cur--;

		rice[bowl[(K + i) % N]]++;

		if (rice[bowl[(K + i) % N]] == 1)
			cur++;

		if (cur > result)
			result = cur;
	}

	printf("%d\n", result);

	return 0;
}