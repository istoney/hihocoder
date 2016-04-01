#include<iostream>
#include<stdio.h>

using namespace std;

int Q, N, P;
pair<float, int> ab[60];

int rec(int level, int index, float cost, int des){
	if(level==0) return 0;

	int maxi = 0;
	for(int i=index;i<N;++i){
		float tmp = cost+ab[i].first;
		if((tmp - (int)tmp) < 0.01 && (int)tmp%5==0){
			maxi = max(maxi, des + ab[i].second);
		}
		maxi = max(maxi, rec(level-1, i+1, tmp, des + ab[i].second));
	}
	return maxi;
}

int main(){
	scanf("%d", &Q);
	while(Q--){
		scanf("%d", &N);
		float tmp_p = 0;
		for(int i=0;i<N;++i){scanf("%f %d", &ab[i].first, &ab[i].second);}
		printf("%d\n", rec(3, 0, 0, 0));
	}
	return 0;
}
