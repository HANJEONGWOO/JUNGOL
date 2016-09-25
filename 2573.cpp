#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_N 500000
#define MAX_S 1000000000

struct SE {
	int s, e;
	int num;
} se[MAX_N];
int n;

int du[MAX_N], dh;

int cmp(const void *a, const void *b) {
	SE A = *(SE *)a;
	SE B = *(SE *)b;

	if (A.s == B.s) return B.e - A.e;

	return A.s - B.s;
}

void ins_du(int x) {
	if (dh == 0 || du[dh - 1] >= x) { //처음이거나, 이전값이 현재값보다 클 때는 값을 삽입시킨다.
		du[dh++] = x;
		return;
	}

	int s, e;
	s = 0, e = dh - 1; //s는 0, e는 dh-1로 초기화시킨다.

	while (s <= e) { //s가 커질때까지 반복,
		int m = (s + e) / 2; //mid는 반을 잘라서 정함
		if (du[m] >= x) //만약 미드배열 값이 x보다 크다면
			s = m + 1; //s를 옮긴다.
		else
			e = m - 1; //그게 아니면 e를 옮긴다.
	}

	du[e + 1] = x; //찾은 e에서 1 더한 배열에 x값을 넣는다.
}

int main(void)
{
	scanf("%d", &n);
	//assert(1 <= n && n <= MAX_N);

	int i;
	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &se[i].num, &se[i].s, &se[i].e);
		//assert(1 <= se[i].s && se[i].s < se[i].e && se[i].e <= MAX_S);
	}
	qsort(se, n, sizeof(SE), cmp);

	int m = 1;
	for (i = 1; i < n; i++) {
		if (se[i].s != se[i - 1].s || se[i].e != se[i - 1].e) {
			se[m] = se[i];
			m++;
		}
	} //둘 다 겹치는 것을 방지하는 문장

	dh = 0;
	for (i = 0; i < m; i++) {
		ins_du(se[i].e);
	}

	printf("%d\n", dh);

	return 0;
}