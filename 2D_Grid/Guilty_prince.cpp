#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int dx[] = {1, -1,  0,  0};
int dy[] = {0,  0,  1, -1};

char c[50][50];
bool vis[50][50];
ll n , m , ans , a , b , print;

ll Bfs(ll x , ll y) {
    vis[x][y] = true;
    queue <pair<ll , ll>> q;
    q.push({x , y});
    ans++;
    while(!q.empty()) {
        pair <ll , ll> p = q.front();
        ll x = p.first , y = p.second;
        q.pop();
        for(ll i = 0; i < 4; i++) {
           ll next_x = x + dx[i];
           ll next_y = y + dy[i];
           if(next_x >= 0 && next_x < m && next_y >=0 && next_y < n && c[next_x][next_y] != '#' && vis[next_x][next_y] == false) {
               vis[next_x][next_y] = 1;
               q.push({next_x , next_y});
               ans++;
           }
        }
    }
    return ans;
}

void Strangelove(){
    cin >> n >> m;
    for(ll i = 0; i < m; i++) {
        for(ll j = 0; j < n; j++) {
            c[i][j] = 0;
        }
    }
    memset(vis, false , sizeof(vis));
    for(ll i = 0; i < m; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> c[i][j];
            if(c[i][j] == '@') {
                a = i , b = j;
            }
        }
    }
    print = 0;
    print = Bfs(a , b);
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t;
   cin >> t;
   ll ab = 1;
   vector <ll> v;
   while(t--) {
     Strangelove();
     v.push_back(print);
   }
   cout <<"Case" <<" "<< 1 <<":"<<" "<< v[0] <<"\n";
   for(ll i = 1; i < v.size(); i++) {
     ab++;
     cout <<"Case"<<" "<< ab <<":"<<" "<< v[i] - v[i - 1] <<"\n";
   }
   return 0;
}

