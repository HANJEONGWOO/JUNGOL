#include<stdio.h>
 
int M,N;
bool S[110][110];
int Check[110][110][5];
 
struct data{
    int x,y,w;
};
data St,Fi;
 
data Bfs[40010];
int Count;
 
int Gox[5]={0,0,0,1,-1};
int Goy[5]={0,1,-1,0,0};
 
int Turn[5][3]={{0,0,0},{0,3,4},{0,3,4},{0,1,2},{0,1,2}};
 
int reset_check()
{
    int i,j,k;
    for(i=1;i<=M;i++){
        for(j=1;j<=N;j++){
            for(k=1;k<=4;k++){
                Check[i][j][k]=999999999;
            }
        }
    }
    return 0;
}
 
int Output()
{
    printf("%d",Check[Fi.x][Fi.y][Fi.w]);
    return 0;
}
 
int Process()
{
    Bfs[1]=St;
    Check[Bfs[1].x][Bfs[1].y][Bfs[1].w]=0;
    Count=1;
 
    int i,j;
    for(i=1;;i++){
        if(Count<i) break;
 
        for(j=1;j<=3;j++){
            if(Bfs[i].x+Gox[Bfs[i].w]*j<1 || Bfs[i].x+Gox[Bfs[i].w]*j>M) break;
            if(Bfs[i].y+Goy[Bfs[i].w]*j<1 || Bfs[i].y+Goy[Bfs[i].w]*j>N) break;
             
            if(S[Bfs[i].x+Gox[Bfs[i].w]*j][Bfs[i].y+Goy[Bfs[i].w]*j]==true) break;
            if(Check[Bfs[i].x+Gox[Bfs[i].w]*j][Bfs[i].y+Goy[Bfs[i].w]*j][Bfs[i].w]!=999999999) continue;
 
            Check[Bfs[i].x+Gox[Bfs[i].w]*j][Bfs[i].y+Goy[Bfs[i].w]*j][Bfs[i].w]=Check[Bfs[i].x][Bfs[i].y][Bfs[i].w]+1;
            Count++;
            Bfs[Count].x=Bfs[i].x+Gox[Bfs[i].w]*j;
            Bfs[Count].y=Bfs[i].y+Goy[Bfs[i].w]*j;
            Bfs[Count].w=Bfs[i].w;
        }
 
        for(j=1;j<=2;j++){
            if(Check[Bfs[i].x][Bfs[i].y][Turn[Bfs[i].w][j]]!=999999999) continue;
 
            Check[Bfs[i].x][Bfs[i].y][Turn[Bfs[i].w][j]]=Check[Bfs[i].x][Bfs[i].y][Bfs[i].w]+1;
            Count++;
            Bfs[Count].x=Bfs[i].x;
            Bfs[Count].y=Bfs[i].y;
            Bfs[Count].w=Turn[Bfs[i].w][j];
        }
    }
    return 0;
}
 
int Input()
{
    scanf("%d %d",&M,&N);
    reset_check();
 
    int i,j;
    int a;
    for(i=1;i<=M;i++){
        for(j=1;j<=N;j++){
            scanf("%d",&a);
 
            if(a==1) S[i][j]=true;
        }
    }
 
    scanf("%d %d %d",&St.x,&St.y,&St.w);
    scanf("%d %d %d",&Fi.x,&Fi.y,&Fi.w);
    return 0;
}
 
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 
    Input();
    Process();
    Output();
    return 0;
}