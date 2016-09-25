/*
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
*/

//좀 쉽게 풀어쓴 버전

#include <stdio.h>

#define MOD 10000001
typedef struct picture {
	int h;
	int c;
} PICTURE;

PICTURE p[300000];
PICTURE p_[300000];

int DT[10000001];

int N, S;

void quick(PICTURE *arr, int n);

int cur;
int past;
int highest;

int main(void)
{
	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &p_[i].h, &p_[i].c); //input p[i].h and p[i].c
	}
	quick(p_, N); //quick sorting

	int m = 0;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			p[m].h = p_[0].h, p[m].c = p_[0].c;
			m++; //plus m;;;
		}
		else if (p_[i].h == p[m - 1].h) {
			if (p_[i].c > p[m - 1].c) {
				p[m - 1].c = p_[i].c;
			}
		} //else if
		else {
			p[m].h = p_[i].h, p[m].c = p_[i].c; //set normal case
			m++;
		} //else
	}



	highest = p[m - 1].h; //set highest;;;

						  /*
						  for (int i = 0; i < N; i++)
						  {
						  DT[p[i].h] = p[i].c; //set DT
						  }
						  */

	past = 0;
	cur = 0;
	for (int i = 1; i <= highest; i++)
	{
		if (p[cur].h != i)
			DT[i % MOD] = past;
		else {
			if (i - S > 0)
				DT[i % MOD] = DT[(i - S) % MOD] + p[cur].c > DT[(i - 1) % MOD] ? DT[(i - S) % MOD] + p[cur].c : DT[(i - 1) % MOD]; //set
			else
				DT[i % MOD] = DT[0] + p[cur].c > DT[(i - 1) % MOD] ? DT[0] + p[cur].c : DT[(i - 1) % MOD];


			past = DT[i % MOD];

			cur++;
		}
	}

	printf("%d\n", DT[highest % MOD]);

	return 0;
}

void quick(PICTURE *arr, int n)
{
	int i, j;
	int mid;
	PICTURE temp;

	if (n > 1)
	{
		i = -1;
		j = n - 1;
		mid = arr[n - 1].h;

		while (1)
		{
			while (arr[++i].h < mid);
			while (arr[--j].h > mid);

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
	}
}