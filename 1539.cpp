#include <stdio.h>

typedef struct brick {
	int nuby;
	int height;
	int weight;

	int max_height;
	int idx_; //이전
	int idx; //이후

	int num; //개수

} BRICK;

int n;

int result, r_idx, result_n;

BRICK b[110];

void quick(BRICK *arr, int n);

int main(void)
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &b[i].nuby, &b[i].height, &b[i].weight);

		b[i].idx_ = i; //인덱스값을 미리 설정해준다.
	}

	quick(b, n);

	for (int i = 0; i < n; i++)
	{
		b[i].idx = i; //이후 인덱스값도 설정해준다.
	}


	for (int i = 0; i < n; i++)
	{
		b[i].max_height = b[i].height;
		b[i].num = 1;

		for (int j = 0; j < i; j++)
		{
			if ((b[j].max_height + b[i].height > b[i].max_height) && (b[j].weight > b[i].weight)) {

				b[i].max_height = b[j].max_height + b[i].height;
				b[i].idx = j;
				b[i].num = b[j].num + 1;
			} //if
		}

		if (b[i].max_height > result)
		{
			result = b[i].max_height;

			result_n = b[i].num;

			r_idx = i; //결과 인덱스 저장
		}
	} //for i
	  /*
	  for (int i = 0; i < n; i++)
	  {
	  printf("! %d %d %d %d %d\n", b[i].nuby, b[i].height, b[i].weight, b[i].idx_, b[i].idx);
	  }
	  */

	printf("%d\n", result_n);

	while (1)
	{
		printf("%d\n", b[r_idx].idx_ + 1);

		if (r_idx == b[r_idx].idx)
			break;

		r_idx = b[r_idx].idx;
	}

	return 0;
}

void quick(BRICK *arr, int n)
{

	if (n > 1)
	{
		int i = -1;
		int j = n - 1;
		int mid = arr[n - 1].nuby;
		BRICK temp;

		while (1)
		{
			while (arr[++i].nuby > mid);
			while (arr[--j].nuby < mid);

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

}