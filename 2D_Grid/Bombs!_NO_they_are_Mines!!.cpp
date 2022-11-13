#include<bits/stdc++.h>
using namespace std;
const int Maxn = 1e3 + 9;
using ll = long long;

int dx[] = {0 ,  0 , -1 , +1};
int dy[] = {+1, -1 ,  0 ,  0};

bool vis[Maxn][Maxn];
ll lev[Maxn][Maxn];
ll row_a , col_b;
queue <pair<ll , ll>> q;

void Bfs(ll source , ll dest) {
    q.push({source , dest});
    vis[source][dest] = 1;
    while(!q.empty()) {
        pair <ll , ll> p = q.front();
        ll x = p.first , y = p.second;
        q.pop();
        for(ll i = 0; i < 4; i++) {
            ll next_x = x + dx[i];
            ll next_y = y + dy[i];
            if(next_x >= 0 && next_x < row_a && next_y >= 0 && next_y < col_b && vis[next_x][next_y] == 0) {
                q.push({next_x , next_y});
                vis[next_x][next_y] = 1;
                lev[next_x][next_y] = lev[x][y] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll row_a , col_b;
    while(cin >> row_a >> col_b) {
        if(row_a == 0 && col_b == 0) break;
        memset(lev , 0 , sizeof(lev));
        memset(vis , 0 , sizeof(vis));
        ll lines;
        cin >> lines;
        for(ll i = 0; i < lines; i++) {
            ll location_of_bombs , bombs;
            cin >> location_of_bombs >> bombs;
            for(ll j = 0; j < bombs; j++) {
               ll positon;
               cin >> positon;
               vis[location_of_bombs][positon] = 1;
            }
        }
        ll start_row , start_col , target_row , target_col;
        cin >> start_row >> start_col >> target_row >> target_col;
        Bfs(start_row , start_col);
        cout << lev[target_row][target_col] <<"\n";
    }
    return 0;
}
