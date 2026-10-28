#include <bits/stdc++.h>
using namespace std;
int m, n;
int tx[8]={0,0,1,1,1,-1,-1,-1};
int ty[8]={1,-1,1,0,-1,0,1,-1};
int sum=0;
int vis[110][110];
void dfs(int x,int y);
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char temp;
            cin>>temp;
            if(temp=='W') vis[i][j]=1;
            else vis[i][j]=0;
        }
    }
     
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vis[i][j]==1){
                sum+=1;
                dfs(j,i);
            }
        }
    }
    cout<<sum;   
 
}
 
// 64 位输出请用 printf("%lld")
void dfs(int x,int y)
{
    vis[y][x]=0;
    if(x>m||x<0||y>n||y<0) return;
 
    for(int i=0;i<8;i++){
        int x0=x+tx[i];
        int y0=y+ty[i];
        if(x0>m||x0<1||y0>n||y0<1) continue;
        if(vis[y0][x0]==1){
            vis[y0][x0]=0;
            dfs(x0,y0);
            
        }
    }
    return;
}
