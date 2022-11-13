#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
using ll = long long;

int dx[] = {1, -1,  0, 0};
int dy[] = {0,  0, 1, -1};

ll n , m;
ll v[N][N];
bool vis[N][N];
ll lev[N][N];
queue <pair <ll,ll>> q;


void BFS(){
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(v[i][j] == 0) {
                q.push({i , j});
                vis[i][j] = true;
                lev[i][j] = 0;
            }
        }
    }
    ll store = 0;
    while(!q.empty()) {
        pair <ll , ll> p = q.front();
        ll x = p.first , y = p.second;
        q.pop();
        for(ll i = 0; i < 4; i++) {
            ll childx = x + dx[i];
            ll childy = y + dy[i];
            if (childx >= 0 && childx < n && childy >= 0 && childy < m && vis[childx][childy] == false && v[childx][childy] != -1) {
                q.push({childx , childy});
                lev[childx][childy] = lev[x][y] + 1;
                vis[childx][childy] = true;
            }
            else if(v[childx][childy] == -1) lev[childx][childy] = -1;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    BFS();
    cout <<"\n";
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cout << lev[i][j]<<" ";
        }
        cout <<"\n";
    }
    cout <<"\n";
    return 0;
}
