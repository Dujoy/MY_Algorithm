#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {-1, 1,  -1, 1, 2, 2,  -2, -2};
int dy[] = {2,  2, -2, -2, -1, 1, -1, 1};

ll vis[8][8] , lev[8][8];
queue <pair<ll , ll>> q;

bool is_valid(ll xx , ll yy) {
   return (xx >= 0 && xx < 8 && yy >= 0 && yy < 8);
}

ll Bfs(string source , string dest) {
    ll sourceX = source[0] - 'a' ,  sourceY = source[1] - '1';
    ll destX = dest[0] - 'a' , destY = dest[1] - '1';
    q.push({sourceX , sourceY});
    vis[sourceX][sourceY] = 1;
    while(!q.empty()) {
        pair <ll , ll> p = q.front();
        ll x = p.first , y = p.second;
        q.pop();
        for(ll i = 0; i < 8; i++) {
            ll next_x = x + dx[i];
            ll next_y = y + dy[i];
            if(!is_valid(next_x , next_y)) continue;
            if(!vis[next_x][next_y]) {
                q.push({next_x , next_y});
                lev[next_x][next_y] = lev[x][y] + 1;
                vis[next_x][next_y] = 1;
            }
        }
    }
    return lev[destX][destY];
}

void Reset() {
   for(ll i = 0; i < 8; i++) {
      for(ll j = 0; j < 8; j++) {
          lev[i][j] = 0;
          vis[i][j] = 0;
      }
   }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    cout << s[0] - 'a';
    cout << s[1] - '1';
    ll n;
    cin >> n;
    while(n--) {
        Reset();
        string s1 , s2;
        cin >> s1 >> s2;
        cout << Bfs(s1 , s2) <<"\n";
    }
    return 0;
}
