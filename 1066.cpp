#include <stdio.h>
#define TEST 0

int g_n;
double g_a_arr[2];
double g_i_arr[3002];

double result;
double c_minus;

int main(void)
{
	scanf("%d", &g_n);
	scanf("%lf", &g_a_arr[0]);
	scanf("%lf", &g_a_arr[1]);
	for (int i = 1; i <= g_n; i++) {
		scanf("%lf", &g_i_arr[i]); //input ai
	}

	result = g_n * g_a_arr[0] + g_a_arr[1];

	for (int i = 1; i <= g_n; i++) {
		c_minus = 0;
		for (int j = 1; j <= i; j++) {
			c_minus = c_minus + g_i_arr[j];
		}
		c_minus = c_minus * 2.0;
		result = result - c_minus;
		if (TEST)
			printf("C%d : %lf\n", i, c_minus);
	}
	if (TEST)
		printf("%lf\n", result);

	result = result * (double)(1 / ((double)g_n + 1));

	printf("%.2lf\n", result);

	return 0;
}