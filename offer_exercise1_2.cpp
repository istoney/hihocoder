/**
* [Offer收割]编程练习赛1: http://hihocoder.com/contest/hihointerview3
*     Problem 2 优化延迟: http://hihocoder.com/problemset/problem/1269
*/

// #include<iostream>
// using namespace std;
//
// int main(){
//     int N, Q;
//     cin>>N>>Q;
//     int P[N];
//     for(int i=0;i<N;i++) cin>>P[i];
//
//     int thre = 0;
//     for(int i=0;i<N;++i) thre += (i+1)*P[i];
//     if(thre<=Q) return 1;
//
//     for(int k=2;k<=N;++k){
//         thre = 0;
//         for(int i=0;i<N-1;i++){
//             if(P[i] < P[i+1]) swap(P[i], P[i+1]);
//             thre += (i+1)*P[i];
//         }
//         thre += N*P[N-1];
//         if(thre<=Q) {cout<<k<<endl; return 0;}
//     }
//
//     cout<<-1<<endl;
//     return 0;
// }

#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

int N;
long long Q, thre = 0;
int P[100005];

int tryK(int k){
    priority_queue<int> que;
    int i=0, plus=1;
    long long thr=0;
    while(i<k) que.push(P[i++]);
    while(!que.empty()){
        thr += plus*que.top();
        que.pop();
        plus++;

        if(i<N) que.push(P[i++]);
    }
    return thr <= Q;
}

int main(){

    while(scanf("%d%lld", &N, &Q)!=EOF){
        for(int i=0;i<N;i++) scanf("%d", &P[i]);

        int low=1, up=N, mid, res=-1;
        while(low <= up){
            mid = (low+up)/2;
            if(tryK(mid)){
                if(low==up){res=low;break;}
                else up = mid;
            }
            else low=mid+1;
        }
        printf("%d\n", res);
    }

    return 0;
}
