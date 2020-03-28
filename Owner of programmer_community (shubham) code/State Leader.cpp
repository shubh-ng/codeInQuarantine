#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define I2I map<int, int>
#define S2I map<string, int> 
#define C2I map<char, int>

int frequency(string name) {
    int count = 0;
    int freq[26] = {0};
    for(char ch: name)
        freq[ch-'A']++;
    for(int i=0; i<26; i++)
        if(freq[i])
            count++;
    return count;
}
void solve() {
    int N;
    cin>>N;
    cin.ignore();
    int maxLen = 0;
    vector< pair<pair<string, string>, int> > temp;
    while( N-- ){
        string name;
        getline(cin, name);
        string onlyAlphabates;
        for(char ch: name)
            if(ch >= 'A' && ch <= 'Z')
                onlyAlphabates += ch;
        int len = frequency(onlyAlphabates);
        maxLen = max(maxLen, len);
        temp.push_back({{onlyAlphabates, name}, len});
    }
    sort(temp.begin(), temp.end());
    for(auto it: temp) {
        if(it.second == maxLen) {
            cout << it.first.second;
            break;
        }
    }
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
	    cout << "Test Case#" << i << ": ";
	    solve();
	    i++;
	}
	return 0;
}