#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define I2I map<int, int>
#define S2I map<string, int> 
#define C2I map<char, int>
void initSet(set<string> &S) {
    S.insert("HANDS");
    S.insert("ELBOW");
    S.insert("FACE");
    S.insert("SPACE");
    S.insert("SICK");
}
void solve(int testcaseNumber) {
    int N;
    cin>>N;
    set<string> S;
    initSet(S);
    int j=1;
    while( N-- ) {
        string name;
        cin>>name;
        int precautions;
        cin>>precautions;
        int count = 0;
        while( precautions-- ) {
            string precaution;
            cin>>precaution;
            if( S.find(precaution) != S.end() )
                count++;
        }
        int percentage = count*100/S.size();
        cout << "Test Case #" << testcaseNumber << "." << j << ": ";
        cout << name << " ";
        cout << count*100/S.size() << "% ";
        (percentage >= 50) ? cout << "AWARE" : cout << "UNAWARE";
        cout << endl;
        j++;
    }
}
int main() {
    // Fast IO
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
	int T;
	cin >> T;
	int i=1;
	while( T-- ) {
	    solve(i);
	    i++;
	}
	return 0;
}