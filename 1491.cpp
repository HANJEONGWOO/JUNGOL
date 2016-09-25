#include <stdio.h>

typedef struct jungbi {
	int p;
	int t;
} JUNGBI;

JUNGBI jungbi[105];
int M, N;
int answer;
int cnt;

int D[105];
int P[105];

int Print_Path(int idx) {
	if (idx <= 0) {
		printf("%d\n", cnt);
		return 0;
	}
	cnt++;
	Print_Path(P[idx]);
	printf("%d ", idx);
}

int do_dynamic() {

	//D[i]에는 현재 정비소를 마지막으로 정비하게 될 때의 최소값(D[i] = MIN(D[j]) + jungbi[i].t)
	//P[i]에는 D[i]를 계산하기 위한 최소값의 index를 P[i]에 저장(if find "MIN(D[j])" P[i] = j)
	//          [1] [2] [3] [4] [5] [6]
	//J[i] :    100 130 230 270 320 380
	//            5  10   4  11   7   0
	//D[i] :      5  10   9  20  16  16
	//P[i] :      0   0   1   3   3   5

	for (int i = 1; i <= (N + 1); i++) {
		int min = 0x7fffffff;
		int pre;
		for (int j = i - 1; j >= 0; j--) {
			if (jungbi[i].p - jungbi[j].p <= M) {
				if (min > D[j]) {
					min = D[j];
					pre = j;
				}
			}
			else {
				break;
			}
		} //for j
		D[i] = min + jungbi[i].t;
		P[i] = pre;
	} //for i

	printf("%d\n", D[N + 1]);
	if (D[N + 1] != 0)
		Print_Path(P[N + 1]);

	return D[N + 1];
}

int main(void)
{
	//입력파트 - 시작
	scanf("%d", &M);
	scanf("%d", &N);

	int temp;
	int cur = 0;
	for (int i = 1; i <= (N + 1); i++) {
		scanf("%d", &temp);

		cur += temp;
		jungbi[i].p = cur;
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &jungbi[i].t);
	}

	answer = do_dynamic();

	return 0;
}