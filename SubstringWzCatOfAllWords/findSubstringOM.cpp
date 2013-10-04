#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <assert.h>

using namespace std;

class Solution{
  public:
	vector<int> findSubstring(string S, vector<string> &L){
		int ns = S.length();
		int nl = L.size();
		assert(nl > 0);
		int nt = L[0].length();
		map<string, int> tokenFound;
		map<string, int> token2BFound;

		for(int i = 0; i < nl; i++)
			token2BFound[L[i]]++;

		vector<int> out;
		for(int i = 0; i <= ns-nl*nt; i++){
			tokenFound.clear();
			int j;
			for(j = 0; j < nl; j++){
				string sub = S.substr(i+j*nt, nt);
				if(!token2BFound.count(sub)) break;
				tokenFound[sub]++;
				if(tokenFound[sub] > token2BFound[sub]) break;
			}
			if(j==nl) out.push_back(i);
		}
		return out;
	}

};

int main()
{
	Solution sol;
	string ss[3] = {"aa", "bb", "cc"};
	vector<string> L(ss, ss+3);
	string S = "owaabbeifvbbccaaoieccaabbjrwo";
	vector<int> out = sol.findSubstring(S, L);
	int k = out.size();
	for(int i = 0; i < k; i++){
		cout << out[i] << endl;
	}




	return 0;
}



