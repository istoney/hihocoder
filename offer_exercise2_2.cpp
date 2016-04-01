//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
#define xx first
#define yy second
#define LL long long
#define MP make_pair
#define INF 0x3f3f3f3f
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1|1
#define CLR(a, b) memset(a, b, sizeof(a))

using namespace std;

const int maxn = 1111;

struct Pt{
    int x, y;
    Pt(){}
    Pt(int x, int y):x(x), y(y) {}
    void in(){scanf("%d%d", &x, &y);}
};

struct P{
    Pt p1, p2;
    void inpt(){p1.in(); p2.in();}
}p[maxn];

bool pinl(Pt a, P b){
    if(a.x > b.p1.x && a.x < b.p2.x && a.y > b.p1.y && a.y < b.p2.y) return true;
    return false;
}

bool over(P a, P b){
    Pt c, d;
    c = Pt(max(a.p1.x, b.p1.x), max(a.p1.y, b.p1.y));
    d = Pt(min(a.p2.x, b.p2.x), min(a.p2.y, b.p2.y));
    if(c.x < d.x && c.y < d.y) return true;
    return false;
}

bool can[maxn];

vector<int> G[maxn];

int dp[maxn];
bool vis[maxn];

int dfs(int u){
    if(vis[u]) return 0;
    vis[u] = true;
    int ret = 1;
    for(int i = 0; i < G[u].size(); i ++)
    {
        int v = G[u][i];
        ret += dfs(v);
    }
    return ret;
}

int main()
{
    int w, h, n;
    while(scanf("%d%d%d", &w, &h, &n) != EOF)
    {
        for(int i = 1; i <= n; i ++)
        {
            p[i].inpt();
            G[i].clear();
            can[i] = true;
        }
        int ans1 = 0, ans2 = -1;
        for(int i = 1; i <= n; i ++)
        {
            int tmp = 1, flag = 0;
            for(int j = i + 1; j <= n; j ++)
            {
                if(over(p[i], p[j])) G[i].push_back(j);//, printf("%d -- %d\n", i, j);
                if(pinl(p[i].p1, p[j])) flag |= 1;
                if(pinl(p[i].p2, p[j])) flag |= 2;
                if(pinl(Pt(p[i].p1.x, p[i].p2.y), p[j])) flag |= 4;
                if(pinl(Pt(p[i].p2.x, p[i].p1.y), p[j])) flag |= 8;
            }
//            printf("%d - %d\n", tmp, flag);
            if(flag == 15) can[i] = false;
//            if(tmp > ans1) ans1 = tmp, ans2 = i;
        }
        CLR(dp, -1);
        for(int i = 1; i <= n;i ++)
            if(can[i])
            {
                CLR(vis, false);
                int tmp = dfs(i);
                if(tmp > ans1) ans1 = tmp, ans2 = i;
            }
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}
