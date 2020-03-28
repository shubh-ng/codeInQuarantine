#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define I2I map<int, int>
#define S2I map<string, int> 
#define C2I map<char, int>

// split string based on space
void split(string str, vector<string> & V) {
    stringstream  ss(str);
    string word;
    while( ss>>word ) {
        V.push_back(word);
    }
}

// is program is having valid syntax
bool validSyntax(vector<string> V) {
    if( V[0] == "<body>" && V[V.size()-1] == "</body>" )
        return true;
    return false;
}

// checks whether string is an attribute
bool isAttribute(string attribute) {
	int size = attribute.size();
    for(int i=0; i<size; i++){
    	if(attribute[i] == '=' && attribute[i+1] == '"' && attribute[size-1] == '"')
    		return true;
    }
    return false;
}

void parseQueries(string query, map<string, vector< pair<string, string> >> parser) {
    // extracting tag and attribute
    stringstream ss(query);
    string tagName, attribute;
    getline(ss, tagName, '.');
    getline(ss, attribute, '.');
    if( parser.find(tagName) == parser.end() ) {
        cout << "undefined";
    }else{
        vector<pair<string, string>> attributes = parser[tagName];
        bool found = false;
        for(auto it: attributes) {
            if(it.first == attribute) {
                cout << it.second;
                found = true;
                break;
            }
        }
        if( !found )
            cout << "undefined";
    }
    cout << endl;
}
int main() {
    // Fast IO
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int N;
    cin>>N;
    cin.ignore();
    vector<string> lines(N);
    // Taking each line as input
    for(int i=0; i<N; i++) {
        getline(cin, lines[i]);
    }
    if( validSyntax(lines) ) {
        map<string, vector< pair<string, string> >> parser;
        // Traversing each tag ignoring first and last tag
        for(int i=1; i<N-1; i++) {
            // taking single tag
            string tag = lines[i];
            vector<string> splits;
            split(tag, splits);
            // for(auto it: splits)
            //     cout<<it<<endl;
            string tagName = splits[0].substr(1);
            // cout<<tagName<<endl;
            vector< pair<string, string> > attributes;
            // traversing each attributes along with closing tag
            for(int j=1; j<N; j++) {
                string attribute = splits[j];
                // if string is an attribute, extract its 
                // values and push into attributes vector
                if( isAttribute(attribute) ) {
                    pair<string, string> keyValue;
                    // extracting key value pair
                    stringstream attr(attribute);
                    getline(attr, keyValue.first, '=');
                    getline(attr, keyValue.second, '=');
                    attributes.push_back(keyValue);
                }else{
                    break;
                }
            }
            parser[tagName] = attributes;
        }
        
        int Q;
        cin>>Q;
        cin.ignore();
        while( Q-- ) {
            string query;
            getline(cin, query);
            cout << "console.log(" << query << ") => ";
            parseQueries(query, parser);
        }
    }else{
        cout << "Invalid syntax";
    }
    return 0;
}