#include <stdio.h>

int T, K;	//지폐금액, 동전가지수

int coin[110];
int count[110];

int dp[110][11000];


int main(void)
{
	int i, j, k;

	scanf("%d %d", &T, &K);	//지폐금액과 동전가지수 입력

	dp[0][0] = 1;

	for(i=1; i<=K; i++)	{
		dp[i][0] = 1;
		scanf("%d %d", &coin[i], &count[i]);
	}

	for(i=1; i<=K; i++)	{
		for(j=1; j<=T; j++)	{

			for(k=0; k<=count[i]; k++)	{
				if(coin[i] * k > j)
					break;
				dp[i][j] += dp[i-1][j - coin[i] * k];
			}	//for k
		}	//for j
	}	//for i

	printf("%d\n", dp[K][T]);

	return 0;
}
