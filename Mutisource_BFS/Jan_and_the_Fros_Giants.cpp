#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dx[] ={0 , 0 , -1, 1};
ll dy[] ={-1 , 1 , 0 , 0};

char Grid[205][205];
ll fire[205][205];
ll jane[205][205];
bool visited[205][205];
ll r , c;

bool valid(ll x, ll y){
    return x >= 1 && x <= r && y >= 1 && y <= c && Grid[x][y] != '#' && visited[x][y] == 0;
}
bool escape(ll x, ll y){
    return x < 1 || x > r || y < 1 || y > c;
}
void resetVisited(){
    for (ll i = 1; i <= r; i++){
        for (ll j = 1; j <= c; j++){
            visited[i][j] = 0;
        }
    }
}

void reset(){
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            fire[i][j] = INT_MAX;
            jane[i][j] = INT_MAX;
        }
    }
}

void M_Fire(vector <pair<ll , ll>> v_fires) {
    resetVisited();
    queue <pair<ll , ll>> Q;
    for(auto u : v_fires) {
        Q.push(u);
        visited[u.first][u.second] = 1;
        fire[u.first][u.second] = 0;
    }
    while(!Q.empty()) {
        pair <ll , ll> current = Q.front();
        Q.pop();
        for(ll i = 0; i < 4; i++) {
            ll next_x = current.first + dx[i];
            ll next_y = current.second + dy[i];
            if (valid(next_x, next_y)){
                fire[next_x][next_y] = fire[current.first][current.second] + 1;
                visited[next_x][next_y] = 1;
                Q.push({next_x, next_y});
            }
        }
    }
}

int Jane_BFS(pair <ll , ll> ane) {
    resetVisited();
    queue <pair<ll , ll>> Q;
    Q.push(ane);
    visited[ane.first][ane.second] = 1;
    jane[ane.first][ane.second] = 0;
    while(!Q.empty()) {
        pair <ll , ll> current = Q.front();
        Q.pop();
        for(ll i = 0; i < 4; i++) {
            ll next_x = current.first + dx[i];
            ll next_y = current.second + dy[i];
            if (escape(next_x, next_y)){
                return jane[current.first][current.second] + 1;
            }
            if (valid(next_x, next_y)){
                if (fire[next_x][next_y] > jane[current.first][current.second] + 1){
                    jane[next_x][next_y] = jane[current.first][current.second] + 1;
                    visited[next_x][next_y] = 1;
                    Q.push({next_x, next_y});
                }
            }
        }
    }
    return -1;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    for(ll cs = 1; cs <= tc; cs++) {
        cin >> r >> c;
        reset();
        vector <pair<ll , ll>> v_fires;
        pair <ll , ll> jane;
        for(ll i = 1; i <= r; i++) {
            for(ll j = 1; j <= c; j++) {
                cin >> Grid[i][j];
                if(Grid[i][j] == 'F') v_fires.push_back({i , j});
                else if(Grid[i][j] == 'J') jane = {i , j};
            }
        }
        M_Fire(v_fires);
        ll ans = Jane_BFS(jane);
        cout << "Case " << cs << ": ";
        if (ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";
    }
    return 0;
}


