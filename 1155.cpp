#include <stdio.h>

int K;
short DT[1001][1001][1001];

int element[4]; //a, c, g, t

char arr[600001];
int arr_len;

int cur, result;

int mystrlen(char *arr);

int main(void)
{
	scanf("%d", &K);

	scanf("%s", &arr);
	arr_len = mystrlen(arr);

	for (int i = 0; i < K; i++)
	{
		if (arr[i] == 'A')
			element[0]++;
		else if (arr[i] == 'C')
			element[1]++;
		else if (arr[i] == 'G')
			element[2]++;
		else if (arr[i] == 'T')
			element[3]++;
	} //for i

	DT[element[1]][element[2]][element[3]]++;

	for (int i = 1; i < arr_len - K; i++)
	{
		switch (arr[i])
		{
		case 'A':
			element[0]--;
		case 'C':
			element[1]--;
		case 'G':
			element[2]--;
		case 'T':
			element[3]--;
		} //switch

		switch (arr[K - 1 + i])
		{
		case 'A':
			element[0]++;
		case 'C':
			element[1]++;
		case 'G':
			element[2]++;
		case 'T':
			element[3]++;
		}

		DT[element[1]][element[2]][element[3]]++;

		if (DT[element[1]][element[2]][element[3]] > result)
			result = DT[element[1]][element[2]][element[3]];
	}

	printf("%d\n", result);

	return 0;
}

int mystrlen(char *arr)
{
	int i;

	for (int i = 0; arr[i] != NULL; i++);

	return i;
}