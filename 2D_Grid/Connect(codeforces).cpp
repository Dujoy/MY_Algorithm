#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int dx[] = {1, -1,  0,  0};
int dy[] = {0,  0,  1, -1};

char c[50][50];
bool vis[50][50];
vector<pii> v1, v2;
ll n , a , b , cc , d;

void Bfs(ll x , ll y) {
    vis[x][y] = true;
    queue <pair<ll , ll>> q;
    v1.push_back(pii(x + 1 , y + 1));
    q.push({x , y});
    while(!q.empty()) {
        pair <ll , ll> p = q.front();
        ll x = p.first , y = p.second;
        q.pop();
        for(ll i = 0; i < 4; i++) {
           ll next_x = x + dx[i];
           ll next_y = y + dy[i];
           if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && c[next_x][next_y] == '0' && vis[next_x][next_y] == false) {
               vis[next_x][next_y] = true;
               c[next_x][next_y] = '1';
               v1.push_back( pii(next_x + 1 , next_y + 1) );
               q.push({next_x , next_y});
           }
        }
    }
}


void Bfs_second(ll x , ll y) {
    vis[x][y] = true;
    queue <pair<ll , ll>> q;
    v2.push_back(pii(x + 1 , y + 1));
    q.push({x , y});
    while(!q.empty()) {
        pair <ll , ll> p = q.front();
        ll x = p.first , y = p.second;
        q.pop();
        for(ll i = 0; i < 4; i++) {
           ll next_x = x + dx[i];
           ll next_y = y + dy[i];
           if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && c[next_x][next_y] == '0' && vis[next_x][next_y] == false) {
               vis[next_x][next_y] = true;
               c[next_x][next_y] = '1';
               v2.push_back( pii(next_x + 1 , next_y + 1) );
               q.push({next_x , next_y});
           }
        }
    }
}

void Strangelove(){
    cin >> n;
    cin >> a >> b;
    cin >> cc >> d;
    a-- , b--;
    cc-- , d--;
    memset(vis, false , sizeof(vis));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    Bfs(a , b);
    if(vis[cc][d]) {
        cout <<"0\n";
        return;
    }
    Bfs_second(cc , d);
    ll ans= 1e18;
    for(int i=0; i<v1.size(); i++) {
       for(int j=0; j<v2.size(); j++) {
          ans = min(ans , (ll)(v1[i].first - v2[j].first) * (v1[i].first - v2[j].first) + (ll)(v1[i].second - v2[j].second) * (v1[i].second - v2[j].second));
       }
    }
    cout<< ans <<endl;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   Strangelove();
   return 0;
}
