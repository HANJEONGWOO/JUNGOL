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
	if (dh == 0 || du[dh - 1] >= x) { //ó���̰ų�, �������� ���簪���� Ŭ ���� ���� ���Խ�Ų��.
		du[dh++] = x;
		return;
	}

	int s, e;
	s = 0, e = dh - 1; //s�� 0, e�� dh-1�� �ʱ�ȭ��Ų��.

	while (s <= e) { //s�� Ŀ�������� �ݺ�,
		int m = (s + e) / 2; //mid�� ���� �߶� ����
		if (du[m] >= x) //���� �̵�迭 ���� x���� ũ�ٸ�
			s = m + 1; //s�� �ű��.
		else
			e = m - 1; //�װ� �ƴϸ� e�� �ű��.
	}

	du[e + 1] = x; //ã�� e���� 1 ���� �迭�� x���� �ִ´�.
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
	} //�� �� ��ġ�� ���� �����ϴ� ����

	dh = 0;
	for (i = 0; i < m; i++) {
		ins_du(se[i].e);
	}

	printf("%d\n", dh);

	return 0;
}