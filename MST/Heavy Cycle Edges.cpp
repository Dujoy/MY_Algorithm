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
vector<int> Print;

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
    int n , e;
    while(scanf("%d %d",&n,&e)) {
        if(n == 0 && e == 0) break;
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        v.clear();
        Print.clear();
        for(int i = 0; i < e; i++) {
            int f , t , c;
            cin >> f >> t >> c;
            v.push_back(Edge(f,t,c));
        }
        sort(v.begin() , v.end(), cmp);
        for(int i = 0; i < e; i++) {
            int aa = Find(v[i].a);
            int bb = Find(v[i].b);
            if(aa != bb) Union(aa , bb);
            else Print.push_back(v[i].c);
        }
        if(Print.size() == 0)  printf("forest\n");
        else {
            sort(Print.begin() , Print.end());
            printf("%d" , Print[0]);
            for(int i = 1; i < Print.size(); i++) {
                printf(" %d", Print[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
