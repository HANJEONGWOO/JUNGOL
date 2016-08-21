#include <stdio.h>

int N;
int S[10];
int B[10];

int min = 987654321;

int myabs(int value);
void func(int s, int b, int c, int n);

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &S[i], &B[i]); //input S, B
	}

	func(1, 0, 0, 0);

	printf("%d\n", min);

	return 0;
}

void func(int s, int b, int c, int n)
{
	if (n == N) {
		if (c >= 1)
		{
			if (myabs(s - b) < min)
				min = myabs(s - b);
		}
		return;
	}
	else
	{
		func(s * S[n], b + B[n], c + 1, n + 1);

		func(s, b, c, n + 1);
	}
}

int myabs(int value)
{
	if (value > 0)
		return value;
	else
		return -value;
}