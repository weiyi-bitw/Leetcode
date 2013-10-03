#include <iostream>
#include <limits.h>
#include <string>
#include <map>

using namespace std;

// OJ: 36ms

class Solution {
public:
    string minWindow(string S, string T) {
        int n = S.length();
        int nt = T.length();
        string out = "";

	if(nt > n) return out;

        int charT[256] = {0};
	int charS[256] = {0};
        for(int i = 0; i < nt; i++)
            charT[(int)T[i]]++;
        
        int l = 0, r = 0;
        int needToFind = nt, minWin = INT_MAX;
        while(r < n){
	    cout << l << ":" << S[l] << "\t" << r << ":" << S[r] << "\t" << needToFind << endl;
	    
            while(needToFind > 0 && r < n){
		int sr = (int) S[r];
		if(charS[sr] < charT[sr]){
                	needToFind--;
		}
		charS[sr]++;
                r++;
            }
	    cout << l << ":" << S[l] << "\t" << r << ":" << S[r] << "\t" << needToFind << endl;
	    int sl = (int) S[l];
	    cout << charS[sl] << "\t" << charT[sl] << endl;
	    while(charS[sl] > charT[sl]){
		charS[sl]--;
		l++;
		sl = (int) S[l];
	    }
	    cout << l << ":" << S[l] << "\t" << r << ":" << S[r] << "\t" << needToFind << endl;
	    if(needToFind == 0 && r-l < minWin){
		minWin = r-l;
		out = S.substr(l, minWin);
		cout << "Found: " << out << "\t" << minWin << endl;
	    }
	    charS[sl]--;
	    l++;
	    needToFind++;
        }
        
        return out;
    }
};

int main()
{
	string S = "a";
	string T = "b";
	Solution sol;

	string out = sol.minWindow(S, T);
	cout << out << endl;


	return 0;
}

