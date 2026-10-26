#include <stdio.h>
int m,n;
//无向图最短路径用bfs，而有权有向图则用disjktra。
//不过对于本题难道每个点都bfs一次么
int queue[1010];
int front=0,rear=0;
int gra[1010][1010];
int dis[1010][1010];
void bfs(int a){
    int vis[1010];
    for(int i=1;i<=n;i++) vis[i]=0;
    front=0,rear=0;
    queue[++rear]=a;
    vis[a]=1;
    dis[a][a]=0;
    while(front<rear){
        //int len=1;
        int t=queue[front+1];
        front++;
        for(int i=1;i<=n;i++){
            //dis[a][i]=len++;
            if(!vis[i] && gra[t][i]){
            dis[a][i]=dis[a][t]+1;
            vis[i]=1;
            queue[++rear]=i;
            }
        }
    }
    return;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            gra[i][j]=0;
            dis[i][j]=-1;
        }
    }
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        gra[a][b]=1;gra[b][a]=1;
    }
    
    
    for(int i=1;i<=n;i++){
        bfs(i);
        double f1=0;double f2=n;
        for(int j=1;j<=n;j++){
            if(dis[i][j]<=6&&dis[i][j]>=0) f1++;
        }
        double percent=f1/f2*100;
        printf("%d: %.2f%%\n",i,percent);
        
    }
    
}
