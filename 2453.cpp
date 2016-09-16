#include <stdio.h>

int make_t(int n);
int check_in(int n, int i);
int is_that_beautiful(int n);

int N, K;
int t[10]; //어짜피 8자리만 쓸 거
int answer;
int v[40]; //계산한 거 자장해 둘 배열 - 8자리일 때 36개가 전부
int flag;

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int testcase = 1; testcase <= T; testcase++) {
		//입력
		scanf("%d %d", &N, &K);

		flag = 0;
		answer = 0;

		if (1 < N && N < 9) {
			make_t(1); //N만큼의 재귀를 통해 많은 숫자들을 만들어 내야함
		}
		//각 자리수는 0이나 1은 안되고 서로 달라야 하는 것이 원칙
		//아름다운 문자열이 나올 수 있는 최대 문자열 개수는

		//9개부터는 절대 아름다운 문자열이 나올 수가 없다.
		//검사는 2개부터 하면 됨 - 1자리수는 같을 거 안나오도록 미리 제한 셈

		if (N == 1) {
			if (K == 1) printf("0\n");
			else if (K == 2) printf("1\n");
			else if (K == 3) printf("2\n");
			else if (K == 4) printf("3\n");
			else if (K == 5) printf("4\n");
			else if (K == 6) printf("5\n");
			else if (K == 7) printf("6\n");
			else if (K == 8) printf("7\n");
			else if (K == 9) printf("8\n");
			else if (K == 10) printf("9\n");
			else printf("NONE\n");
		}
		else if (flag == 1) {
			for (int i = 1; i <= N; i++) {
				printf("%d", t[i]);
			}
			printf("\n");
		}
		else {
			printf("NONE\n");
		}
	}
}

int make_t(int n) {

	if (n > N) { //다 채웠으면 검사
		if (is_that_beautiful(N) == 1) {
			answer++;
		}
		if (answer == K) {
			flag = 1;
			return 1;
		}
		return 0;
	}
	else { //조건에 맞춰 채워 넣음
		for (int i = 2; i <= 9; i++) {
			//1 ~ n-1까지 해당 숫자가 없을 때만 넣을 수 있음
			if (check_in(n, i) == 1) {
				t[n] = i;
				if (make_t(n + 1) == 1) {
					return 1;
				}
				t[n] = 0;
			}
		}
	}

	return 0;
}

int check_in(int n, int i) {

	for (int j = 1; j < n; j++) {
		if (t[j] == i) {
			return 0;
		}
	}
	//반복문 나오면 같은 숫자 없었다는 소리

	return 1;
}

int is_that_beautiful(int n) {
	int count = 0;

	//검사하다가 같은거 나오면 못생긴 문자열
	for (int a = 1; a <= n; a++) { //문자열 2개면 2개 곱한거 1번만 하면 됨
								   //a개 곱한 결과들 저장시키면서 검사
		for (int b = 1; b <= n - a + 1; b++) {
			int temp = 1;
			//a개 만큼 곱함
			for (int c = 0; c < a; c++) {
				temp *= t[b + c];
			}
			//곱한 결과 체크
			for (int i = 0; i < count; i++) {
				if (v[i] == temp) {
					//못생긴 문자열, 함수 중단
					return 0;
				}
			}

			//이전에랑 같은애 없으면 일단 저장
			v[count++] = temp;
		}
	}
	//누구도 같은애 없으면 이쁜애임

	return 1;
}