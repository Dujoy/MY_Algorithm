#include<bits/stdc++.h>
#define M 1000000
using namespace std;
using ll = long long;

bool marked[M];
vector <ll> prime;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marked[0] = marked[1] = false;
    for(int i = 2;i < M; i++){
       marked[i] = true;
    }
    for (int i = 2; i <= sqrt(M); i++) {
       if (marked[i] == true) { // i is a prime
          for (int j = i * i; j <= M; j += i) {
             marked[j] = false;
          }
       }
    }
    ll n;
    cin >> n;
    ll cnt = 0;
    for(ll i = 1; i <= 100000;i++) {
        if(marked[i] == true) {
            cnt++;
            if(cnt == n) {
                cout << i <<"\n";
                exit(0);
            }
        }
        else continue;
    }
    return 0;
}
