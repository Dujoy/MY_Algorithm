#include<bits/stdc++.h>
using namespace std;
#define pii pair<long long int,long long int>
using ll = long long;

int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {-1, 0, -1, 1, 0, 1};

vector<pii> v(1005);
map<pii , int>mp;
map<pii ,bool>visit;

void Bfs(int a , int b) {
    visit[{a , b}] = true;
    queue <pii> q;
    q.push({a , b});
    while(!q.empty()) {
        pii = q.front();
        int x = p.first , y = p.second;
        q.pop();
        for(int i = 0; i < 6; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (visit[{next_x , next_y}] == false && mp[{next_x , next_y}] == -1) {
                visit[{next_x , next_y}] = true;
                q.push({next_x , next_y});
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        mp[{v[i].first , v[i].second}] = -1;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
         int aa = v[i].first;
         int bb = v[i].second;
         if(mp[{aa , bb}] == -1 && visit[{aa , bb}] == false) {
             Bfs(aa , bb);
             ans++;
         }
    }
    cout << ans <<"\n";
    return 0;
}

