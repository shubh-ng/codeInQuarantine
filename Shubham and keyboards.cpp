#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define I2I map<int, int>
#define S2I map<string, int> 
#define C2I map<char, int>

void solve() {
    int N;
    cin>>N;
    vector<ll> v(N);
    for(int i=0; i<N; i++)
        cin>>v[i];
    sort(v.begin(), v.end());
    for(int i=0; i<N-1; i++){
        if(v[i] != v[i+1]){
            cout<<v[i]<<" ";
        }else{
            i++;
        }
    }
    if(v[N-2]!=v[N-1])
        cout<<v[N-1]<<" ";
    cout<<endl;
}
int main() {
    // Fast IO
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int T;
    cin >> T;
    int i=1;
    while( T-- ) {
        cout << "Test Case #" << i << ": ";
        solve();
        i++;
    }
    return 0;
}