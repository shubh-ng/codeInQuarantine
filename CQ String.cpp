#include <bits/stdc++.h>

using namespace std;

int combinations = 1;
void printAllCombinations(string pattern, int i, int j)
{
	if (pattern[i] == '\0')
	{
	    cout << "Test Case #"<< j << ": Combination #" << combinations << ": " << pattern << endl;
        combinations++;
		return;
	}

	// if the current character is '%'
	if (pattern[i] == '%')
	{
			// replace '%' with C
			pattern[i] = 'C';
			
			// recur for the remaining pattern
			printAllCombinations(pattern, i + 1, j);
			
			// backtrack
			pattern[i] = '%';

			// replace '%' with Q
			pattern[i] = 'Q';
			
			// recur for the remaining pattern
			printAllCombinations(pattern, i + 1, j);
			
			// backtrack
			pattern[i] = '%';
		return;
	}

	// if the current character is C or Q, ignore it and 
	// recur for the remaining pattern
	printAllCombinations(pattern, i + 1, j);
}

// main function
int main()
{
    int T;
    cin>>T;
    int j = 1;
    while(T--){
        string pattern;
        cin>>pattern;
        combinations = 1;
    	printAllCombinations(pattern, 0, j);
    	j++;
    }
	return 0;
}