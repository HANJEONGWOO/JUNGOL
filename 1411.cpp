#include <stdio.h>

int N;

long long int arr[110000];

long long int f2(int n);

int main(void)
{
	scanf("%d", &N);

	printf("%d\n", f2(N) % 20100529);

	return 0;
}

long long int f2(int n)
{
	if (n == 0 || n == 1)
		return arr[n] = 1 % 20100529;
	else if (n == 2)
		return arr[n] = 3 % 20100529;
	else
	{
		if (arr[n] != 0)
			return arr[n] % 20100529;
		else if (n % 2 == 0) //¦
			return arr[n] = ((f2(n / 2) % 20100529) * (f2(n / 2) % 20100529) + 2 * ((f2(n / 2 - 1) % 20100529) * (f2(n / 2 - 1) % 20100529)) % 20100529);
		else
			return arr[n] = ((f2(n / 2 + 1) % 20100529) * (f2(n / 2) % 20100529) + 2 * ((f2(n / 2) % 20100529) * (f2(n / 2 - 1) % 20100529)) % 20100529);
	}
}


int myabs(int n)
{
	if (n >= 0)
		return n;
	else
		return -n;
}