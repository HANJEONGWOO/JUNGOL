#include <stdio.h>

int stone_n;
int stone[330]; //input stone

int find_n;
int find;

int arr[44000];
int idx_cnt = 1;

int main(void)
{
	//input stone_n;
	scanf("%d", &stone_n);


	for (int i = 0; i < stone_n; i++)
	{
		scanf("%d", &stone[i]); //input stone[i];

		if (arr[stone[i]] == 0)
			arr[stone[i]] = idx_cnt;

		for (int j = 40000; j >= 0; j--)
		{
			if (arr[j] < idx_cnt && arr[j] != 0)
			{
				if (arr[j + stone[i]] == 0)
					arr[j + stone[i]] = idx_cnt;

				if (j - stone[i] > 0 && arr[j - stone[i]] == 0) //if
					arr[j - stone[i]] = idx_cnt;

				if (stone[i] - j > 0 && arr[stone[i] - j] == 0)
					arr[stone[i] - j] = idx_cnt;
			} //if
		} //for j

		idx_cnt++;
	} //for i

	scanf("%d", &find_n);

	for (int i = 0; i < find_n; i++)
	{
		scanf("%d", &find);

		if (arr[find] > 0)
			printf("Y "); //Y
		else
			printf("N "); //N
	}


	return 0;
}