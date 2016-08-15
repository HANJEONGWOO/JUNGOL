#include <stdio.h>


typedef struct post {
	int s;
	int e;
	int box;
	int sort;
} POST;

int N, C; //vill, capacity
int M; //box info.

POST p[11000];

int result;
int DT[2200]; //dynamic table

int min; //get min value;

void quick(POST *arr, int n);

int main(void)
{
	scanf("%d %d", &N, &C); //input n and c

	scanf("%d", &M); //box info

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &p[i].s, &p[i].e, &p[i].box);

		p[i].sort = p[i].e * 10000 - p[i].s;
	}

	quick(p, M); //quick sorting

	for (int i = 0; i < M; i++)
	{
		min = p[i].box; //capacity
		for (int j = p[i].s; j < p[i].e; j++)
		{
			if ((C - DT[j]) < min)
				min = (C - DT[j]);
		} //for j

		for (int j = p[i].s; j < p[i].e; j++)
			DT[j] += min;

		result += min; //plus min value;
	} //for i

	printf("%d\n", result);

	return 0;
}


void quick(POST *arr, int n)
{
	int i, j, idx;
	POST temp;

	if (n > 1)
	{
		i = -1;
		j = n - 1;
		idx = arr[n - 1].sort;

		while (1)
		{
			while (arr[++i].sort < idx);
			while (arr[--j].sort > idx);

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

