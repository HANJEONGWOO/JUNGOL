#include <stdio.h>
#include <string.h>

#define mymin(a, b) ( ( (a) < (b) ) ? (a) : (b) )

int a[16][16];
int d[16][1<<16];

int ans;

int main(void)
{
	int i, j, k;
	int n;

	scanf("%d", &n);

	for(i=0; i<n; i++)	{
		for(j=0; j<n; j++)	{
			scanf("%d", &a[i][j]);
		}
	}
	//printf("%d\n", 1<<16);
	for(i=0; i<n; i++)	{
		for(j=0; j< 1<<n; j++)	{	//1�� n�� �������� ����Ʈ�Ѵ�.
			d[i][j] = 100000000;
		}
	}

	d[0][1] = 0;

	for(i=0; i < (1<<n); i++)	//1<<n�� �ݺ�
	{
		for(j=0; j<n; j++)	//n�� �ݺ�
		{
			if(i & (1<<j) )	{	//���� (i & (1<<j))�� 0�� �ƴ϶��
				for(k=0; k< n; k++)	{	//k�ݺ�, k�� n������ �ݺ���
					if( !(i&(1<<k) ) )	{
						if(a[j][k] && d[k][i+(1<<k)] > d[j][i] + a[j][k])
							d[k][i+(1<<k)] = d[j][i] + a[j][k];
					}
				}
			}
		}
	}
	
	ans = 1000000000;
	for(i=1; i<n; i++)
		ans = mymin(ans, d[i][(1<<n)-1] + a[i][0]);
	printf("%d\n", ans);

	return 0;
}

