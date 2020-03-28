#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define I2I map<int, int>
#define S2I map<string, int> 
#define C2I map<char, int>

bool comparator(pair<ll, ll> a, pair<ll, ll> b) {
    if (a > b)
        return true;
    return false;
}
void solve() {
    ll M;
    cin>>M;
    vector< pair<ll, ll> > V(M);
    for(int i=0; i<M; i++) {
        cin>>V[i].first;
        cin>>V[i].second;
    }
    ll N;
    cin>>N;
    sort(V.begin(), V.end(), comparator);
    cout << V[N-1].first << " " << V[N-1].second;
}
int main() {
    // Fast IO
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int T;
    cin>>T;
    int i = 1;
    while( T-- ) {
        cout << "Test Case #" << i <<": ";
        solve();
        i++;
    }
    return 0;
}