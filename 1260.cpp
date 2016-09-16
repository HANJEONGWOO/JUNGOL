#include <stdio.h>

int N;

int num1[1100], num2[1100];

int calc_val;

int result;
int result_num1 = 987654321;

int main(void)
{
	scanf("%d", &N); //input N

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num1[i]);

		num2[i] = num1[i];

		while (num2[i] >= 10)
		{
			calc_val = 0;
			while (num2[i] != 0)
			{
				calc_val += num2[i] % 10; //modular it

				num2[i] = num2[i] / 10; //divide it
			} //while loop

			num2[i] = calc_val; //daeip
		} //while loop

		if (num2[i] > result) {
			result = num2[i];
			result_num1 = num1[i];
		}
		else if (num2[i] == result) {
			if (result_num1 > num1[i]) {
				result_num1 = num1[i];
			}
		}
	}

	printf("%d\n", result_num1);

	return 0;
}