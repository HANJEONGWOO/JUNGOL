#include <stdio.h>

int N, S;

typedef struct mat {
	int H;
	int C;
} MAT;

MAT mat[330000];

int idx[330000];

int d[330000];
int max[330000];

void quick(MAT *arr, int n);

int main(void)
{
	scanf("%d %d", &N, &S);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &mat[i].H, &mat[i].C);
	}

	quick(mat, N + 1);

	for (int i = 1; i <= N; i++)
	{
		for (idx[i] = idx[i - 1] + 1; idx[i] < i; idx[i]++)
		{
			if (mat[i].H - mat[idx[i]].H < S)
				break;
		}
		idx[i]--; //최대 인덱스를 구해놓음
	}

	for (int i = 1; i <= N; i++)
	{
		d[i] = max[idx[i]] + mat[i].C;
		max[i] = max[i - 1] > d[i] ? max[i - 1] : d[i];
	}

	printf("%d\n", max[N]);

	return 0;
}


void quick(MAT *arr, int n)
{
	int i, j;
	int mid;
	MAT temp;

	if (n > 1)
	{
		i = -1;
		j = n - 1;
		mid = arr[n - 1].H;

		while (1)
		{
			//set i, j;
			while (arr[++i].H < mid);
			while (arr[--j].H > mid);

			if (i >= j)
				break;

			//swap two value
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		//swap pivot value
		temp = arr[i];
		arr[i] = arr[n - 1];
		arr[n - 1] = temp;

		//re-quick
		quick(arr, i);
		quick(arr + i + 1, n - i - 1);
	} //if

} //quick