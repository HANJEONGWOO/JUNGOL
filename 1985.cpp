#include <stdio.h>

typedef struct bunsu {
	int ja;
	int mo;
	double v;
} BUNSU;

BUNSU b[13000 + 10];
int N;
int cnt;

void get_in_b(int n);
int check_in(int a, int b);
void quick(BUNSU *arr, int n);

int main(void)
{
	scanf("%d", &N);

	//1은 넣었다고 생각하고 출발
	b[0].ja = 0; b[0].mo = 1; b[0].v = b[0].ja / b[0].mo;
	b[1].ja = 1; b[1].mo = 1; b[1].v = b[1].ja / b[1].mo;

	cnt = 2;
	for (int i = 2; i <= N; i++) {
		get_in_b(i); //i번째에서 들어갈만한거 넣음
	}

	//다 넣고 소수값으로 정렬
	quick(b, cnt);

	//출력
	for (int i = 0; i < cnt; i++)
		printf("%d/%d\n", b[i].ja, b[i].mo);

	return 0;
}

void get_in_b(int n) {
	for (int i = 1; i < n; i++) {
		//이전에 들어간 적 없는 분수만 들어가야 하므로
		//분자, 분모의 최대공약수가 1이어야 함
		if (check_in(i, n)) {
			b[cnt].ja = i; b[cnt].mo = n; b[cnt].v = (double)i / n;
			cnt++;
		}
	}
}

int check_in(int a, int b) {
	for (int i = 2; i <= a; i++) {
		//1이외에 나눠지는 수가 없어야함 - 있다면 못 넣음
		if (a % i == 0 && b % i == 0)
			return 0;
	}

	return 1;
}

void quick(BUNSU *arr, int n)
{
	int i, j;
	double mid;
	BUNSU temp;

	if (n > 1)
	{
		i = -1;
		j = n - 1;
		mid = arr[n - 1].v;

		while (1)
		{
			while (arr[++i].v < mid);
			while (arr[--j].v > mid);

			if (i >= j)
				break;

			//swap two value;
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