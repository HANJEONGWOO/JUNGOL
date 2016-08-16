#include <stdio.h>

int N;
int pos[15];

int fail_flag;
int result;

void queen(int n);

int main(void)
{
	scanf("%d", &N);

	queen(1);

	printf("%d\n", result);

	return 0;
}

void queen(int n)
{
	int i, j;

	for (i = 1; i <= N; i++) //���� ���� ���� �����Ѵ�.
	{
		fail_flag = 0;
		for (j = n - 1; j >= 1; j--) //������ �迭�� �ִ� ���� ��ġ���� ����
		{
			if ((i == pos[j]) || (i == (pos[j] + (n - j))) || (i == (pos[j] + (j - n)))) {
				fail_flag = 1;
				break;
			}
		} //for j
		if (fail_flag == 0)
		{
			pos[n] = i;

			if (n == N) {
				result++;
				return;
			}
			else
				queen(n + 1);

			pos[n] = 0;
		}
	} //for i

}