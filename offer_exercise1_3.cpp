#include<iostream>
using namespace std;

int Q, N, M, K, T;
int cost[105];      //cost for every level material
int value[10][105]; //for every level construction, every level material's value
int dp[10005];

int main(){
    scanf("%d", &Q);
    while(Q--){
        scanf("%d%d%d%d", &N, &M, &K, &T);
        for(int i=0;i<M;++i) scanf("%d", &cost[i]);
        for(int i=0;i<M;++i) scanf("%d", &value[0][i]);

        bool noAnswer = false;
        for(int i=1;i<N;++i){
            int count=0;
            for(int j=0;j<M;++j){
                value[i][j] = value[i-1][j]/T;
                count += value[i][j];
            }

            if(count <= 0) {noAnswer = true;break;}
        }
        if(noAnswer){cout<<"No Answer"<<endl; continue;}

        int ans = 0;
        for(int n=0;n<N;++n){       //for every level construction
        	dp[0] = 0;
            //material 1
            for(int k=1;k<=K;++k) {
            	if(value[n][0]==0) dp[k] = 0x3fffffff;
            	else dp[k] = k/value[n][0] + (k%value[n][0]>0?1:0);
			}
            //material 2~M
            for(int m=1;m<M;++m){
                for(int k=K;k>=1;--k){
                    for(int j=1;;++j){
                    	if(k-j*value[n][m] > 0)
                        	dp[k] = min(dp[k], j*cost[m] + dp[k-j*value[n][m]]);
                        else{
                        	dp[k] = min(dp[k], j*cost[m] + dp[0]);
                        	break;
						}
                    }
                }
            }

            ans += dp[K];
        }

        cout<<ans<<endl;
    }
}
