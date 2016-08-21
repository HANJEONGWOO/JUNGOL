#include <stdio.h>

int TC, N;
int DT[100];

int main(void)
{
	DT[1] = 1, DT[2] = 2;
	for (int i = 3; i < 100; i++) {
		if (i & 1)
			DT[i] = DT[i - 1];
		else
			DT[i] = (DT[i - 1] + DT[i / 2]);
	}

	scanf("%d", &TC);

	while (TC--)
	{
		scanf("%d", &N);

		printf("%d\n", DT[N]);
	}

	return 0;
}