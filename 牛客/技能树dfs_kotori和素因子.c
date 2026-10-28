#include <stdio.h>
//嘶.....大脑空空
//首先对于最小可能和这种最优解问题，我的第一反应会是局部贪心得到最优解。
//犹豫迟疑的点在于如果发现后面的数的素因子被占了难道是回溯到前一个重新找吗？
//经过ai教导大概明白回溯的办法就是dfs的核心，利用dfs遍历所有可能。然后再和全局记录的ans进行比较获得最小值。
int n;
int a[11];
int prime[11][11];
int cnt[11];//在c里实现vector的效果
void get_p(int idx){//参数为下标
    int pos=0;
    cnt[idx]=0;
    int num=a[idx];
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            prime[idx][++pos]=i;
            cnt[idx]+=1;
            while(num%i==0){
                num/=i;
            }
        }
    }
    if(num>1) {prime[idx][++pos]=num;cnt[idx]+=1;}
    return;
}
int ans=0x3f3f3f3f;
int used[1001];
void dfs(int i,int sum){
    if(i==n+1){
        if(sum<ans) ans=sum;
        //取代flag的办法,如果最终ans依旧是初始值即说明没有找到解法
        return;
    }
    //int flag=0;//为了判断无法满足要求，即没有素因数可选的情况，只能想到用flag
    //其实不行
    //用flag的话，回溯并不会影响flag（？？？？？没有完全理解）
    for(int j=1;j<=cnt[i];j++){
        int pnum=prime[i][j];
        if(used[pnum]==0){
            //flag=1;
            used[pnum]=1;
            dfs(i+1,sum+pnum);
            used[pnum]=0;
        }
    }
    
    //if(flag==0) return 0;
    return;//这里漏掉return了
}
int main() {
    for(int i=1;i<=1000;i++) used[i]=0;

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        get_p(i);
    }

    dfs(1,0);
    if(ans==0x3f3f3f3f) printf("-1");
    else printf("%d",ans);
}
