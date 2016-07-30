#include <stdio.h>

char arr1[1100];
char arr2[1100];
int arr1_len;
int arr2_len;

int DT[1100][1100];

int mystrlen(char *arr);

int main(void)
{
	scanf("%s", &arr1);
	scanf("%s", &arr2);

	arr1_len = mystrlen(arr1);
	arr2_len = mystrlen(arr2);

	for (int i = 1; i <= arr1_len; i++)
	{
		for (int j = 1; j <= arr2_len; j++)
		{
			if (arr1[i - 1] == arr2[j - 1])
				DT[i][j] = DT[i - 1][j - 1] + 1;
			else
				DT[i][j] = DT[i - 1][j] > DT[i][j - 1] ? DT[i - 1][j] : DT[i][j - 1];
		} //for j
	} //for i

	printf("%d\n", DT[arr1_len][arr2_len]);

	return 0;
}

int mystrlen(char *arr)
{
	int i;

	for (i = 0; arr[i] != '\0'; i++);

	return i;
}