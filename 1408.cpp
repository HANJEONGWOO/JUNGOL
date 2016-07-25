#include <stdio.h>

struct Line {
	int a;
	int b;
};

int N;

Line line[110];

int flow;

int longest[110];
int max;

int result;

void quick(Line *arr, int n);

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &line[i].a, &line[i].b);
	}

	quick(line, N);


	for (int i = 0; i < N; i++)
	{
		longest[i] = 1; //init value
		for (int j = 0; j < i; j++)
		{
			if ((line[j].a < line[i].a) && (longest[j] + 1 > longest[i]))
				longest[i] = longest[j] + 1;
		}
		if (longest[i] > result)
			result = longest[i]; //set longest value

	}

	printf("%d\n", N - result);

	return 0;
}

void quick(Line *arr, int n)
{
	int i, j;
	int mid;
	Line temp;

	if (n > 1)
	{
		i = -1;
		j = n - 1;
		mid = arr[n - 1].b;

		while (1)
		{
			while (arr[++i].b < mid);
			while (arr[--j].b > mid);

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
