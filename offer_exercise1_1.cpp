/**
* [Offer收割]编程练习赛1: http://hihocoder.com/contest/hihointerview3
*        Problem 1 九宫: http://hihocoder.com/problemset/problem/1268?sid=653016
*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int N = 3;

bool update(int i, int j, int p, int &sum, vector<set<int>> &poss, vector<int> &JG){
    if(p==0){
		JG[i*N+j]=0;
		return false;
	}
    if(JG[i*N+j]!=0) return false;

    JG[i*N+j] = p;
    int s = 0;
    if(JG[i*N] && JG[i*N+1] && JG[i*N+2]){
        s = JG[i*N] + JG[i*N+1] + JG[i*N+2];
        if(sum && sum!=s) {JG[i*N+j]=0;return false;}
        sum = s;
    }

    if(JG[j] && JG[N+j] && JG[2*N+j]){
        s = JG[j] + JG[N+j] + JG[2*N+j];
        if(sum && sum!=s) {JG[i*N+j]=0;return false;}
        sum = s;
    }

    if(i==j){
        if(JG[0] && JG[4] && JG[8]){
            s = JG[0] + JG[4] + JG[8];
            if(sum && sum!=s) {JG[i*N+j]=0;return false;}
            sum = s;
        }
    }

    if(i+j==N-1){
        if(JG[2] && JG[4] && JG[6]){
            s = JG[2] + JG[4] + JG[6];
            if(sum && sum!=s) {JG[i*N+j]=0;return false;}
            sum = s;
        }
    }

    poss[i*N+j].clear();
    for(int x=0;x<N;++x)
        for(int y=0;y<N;++y)
            poss[x*N+y].erase(p);

    return true;
}

int recurse(int sum, vector<set<int>> poss, vector<int> &JG){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(!JG[i*N+j]){
                int count = 0;
                vector<int> JG_ret;
                for(set<int>::iterator it=poss[i*N+j].begin();it!=poss[i*N+j].end();++it){
                    int sum_tmp = sum;
                    vector<set<int>> poss_tmp = poss;
                    vector<int> JG_tmp = JG;

                    if(update(i, j, *it, sum_tmp, poss_tmp, JG_tmp)) {
                        int tmp = recurse(sum_tmp, poss_tmp, JG_tmp);
                        if(tmp==1) JG_ret = JG_tmp;
                        count += tmp;
                    }
                }
                if(count==1) JG = JG_ret;
                return count;
            }
        }
    }

    return 1;
}

int main(){
    vector<int> JG(N*N, 0);
    set<int> tmp({1, 2, 3, 4, 5, 6, 7, 8, 9});
    vector<set<int>> poss(N*N, tmp);

    int sum = 0, p;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>p;
            update(i, j, p, sum, poss, JG);
        }
    }

    int count = recurse(sum, poss, JG);
    if(count==1){
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j) cout<<JG[i*N+j]<<" ";
			cout<<endl;
        }
    }
    else cout<<"Too Many"<<endl;
    return 0;
}
