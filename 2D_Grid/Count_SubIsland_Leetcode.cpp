#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dx[] = {0,  0, -1, 1};
ll dy[] = {-1, 1,  0, 0};

ll n , m;
ll first[101][101] , second[101][101];

void dfs(ll r , ll c , ll grid[101][101]) {
    if (r < 0 || r == n || c < 0 || c == m || grid[r][c] == 0) return;
    grid[r][c] = 0;
    cout <<"Dukse"<<" "<< r <<" "<< c <<"\n";
    for(ll i = 0; i < 4; i++) {
        ll x = dx[i] + r;
        ll y = dy[i] + c;
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                cout << x <<" "<< y <<"\n";
                dfs(x , y , grid);
        }
    }
    cout <<"Bir hoise"<<" "<< r <<" "<< c <<"\n";
}


void Strangelove(){
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) cin >> first[i][j];
    }
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) cin >> second[i][j];
    }
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(first[i][j] == 0) {
               dfs(i , j , second);
            }
        }
    }
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cout << second[i][j] <<" ";
        }
        cout <<"\n";
    }
    exit(0);
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(second[i][j] == 1) {
                dfs(i , j , second);
                ans++;
            }
        }
    }
    cout << ans <<"\n";

}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   Strangelove();
   return 0;
}
