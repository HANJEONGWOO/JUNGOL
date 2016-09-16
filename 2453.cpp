#include <stdio.h>

int make_t(int n);
int check_in(int n, int i);
int is_that_beautiful(int n);

int N, K;
int t[10]; //��¥�� 8�ڸ��� �� ��
int answer;
int v[40]; //����� �� ������ �� �迭 - 8�ڸ��� �� 36���� ����
int flag;

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int testcase = 1; testcase <= T; testcase++) {
		//�Է�
		scanf("%d %d", &N, &K);

		flag = 0;
		answer = 0;

		if (1 < N && N < 9) {
			make_t(1); //N��ŭ�� ��͸� ���� ���� ���ڵ��� ����� ������
		}
		//�� �ڸ����� 0�̳� 1�� �ȵǰ� ���� �޶�� �ϴ� ���� ��Ģ
		//�Ƹ��ٿ� ���ڿ��� ���� �� �ִ� �ִ� ���ڿ� ������

		//9�����ʹ� ���� �Ƹ��ٿ� ���ڿ��� ���� ���� ����.
		//�˻�� 2������ �ϸ� �� - 1�ڸ����� ���� �� �ȳ������� �̸� ���� ��

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

	if (n > N) { //�� ä������ �˻�
		if (is_that_beautiful(N) == 1) {
			answer++;
		}
		if (answer == K) {
			flag = 1;
			return 1;
		}
		return 0;
	}
	else { //���ǿ� ���� ä�� ����
		for (int i = 2; i <= 9; i++) {
			//1 ~ n-1���� �ش� ���ڰ� ���� ���� ���� �� ����
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
	//�ݺ��� ������ ���� ���� �����ٴ� �Ҹ�

	return 1;
}

int is_that_beautiful(int n) {
	int count = 0;

	//�˻��ϴٰ� ������ ������ ������ ���ڿ�
	for (int a = 1; a <= n; a++) { //���ڿ� 2���� 2�� ���Ѱ� 1���� �ϸ� ��
								   //a�� ���� ����� �����Ű�鼭 �˻�
		for (int b = 1; b <= n - a + 1; b++) {
			int temp = 1;
			//a�� ��ŭ ����
			for (int c = 0; c < a; c++) {
				temp *= t[b + c];
			}
			//���� ��� üũ
			for (int i = 0; i < count; i++) {
				if (v[i] == temp) {
					//������ ���ڿ�, �Լ� �ߴ�
					return 0;
				}
			}

			//�������� ������ ������ �ϴ� ����
			v[count++] = temp;
		}
	}
	//������ ������ ������ �̻۾���

	return 1;
}