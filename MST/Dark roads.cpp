#include<bits/stdc++.h>
using namespace std;

struct Edge {
   int a , b , c;
   Edge(int x , int y , int z) {
       a = x;
       b = y;
       c = z;
   }
};
vector<Edge> v;

int cmp (Edge a , Edge b) {
   return a.c < b.c;
}

int parent[20000];
int Find(int a) {
    if(a == parent[a]) return a;
    return(parent[a] = Find(parent[a]));
}

void Union(int u, int v){
    int p = Find(u);
    int q = Find(v);
    if (p != q) parent[q] = p;
}

int main() {
    int n;
    while(scanf("%d %d",&n)) {
        if(n == 0) break;
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        int sum = 0;
        v.clear();
        for(int i = 0; i < e; i++) {
            int f , t , c;
            cin >> f >> t >> c;
            sum += c;
            v.push_back(Edge(f,t,c));
        }
        sort(v.begin() , v.end(), cmp);
        int total = 0;
        for(int i = 0; i < e; i++) {
            int aa = Find(v[i].a);
            int bb = Find(v[i].b);
            if(aa != bb) {
                total += v[i].c;
                Union(aa , bb);
            }
        }
        cout << sum - total <<"\n";
    }
    return 0;
}
