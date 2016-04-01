#include<iostream>
#include<stdio.h>

using namespace std;

int Q, N, P;
float A[60];
int B[60];

int main(){
	cout<<(5.5%5)<<endl;
	scanf("%d", &Q);
	while(Q--){
		scanf("%d", &N);
		float tmp_p = 0;
		for(int i=0;i<N;++i){scanf("%f %d", &A[i], &B[i]);tmp_p += A[i];}

		P = tmp_p;
		int M = P*2+1;
		int dp[N+1][M];
		for(int j=0;j<M;++j) dp[0][j] = 0;
		for(int i=1;i<=N;++i){
			dp[i][0] = 0;
			for(int j=1;j<M;++j){
				dp[i][j] = max(dp[i-1][j], dp[i-1][int(j-A[i-1]*2)]+B[i-1]);
			}
		}

		printf("%d\n", dp[N+1][M]);
	}
	return 0;
}
