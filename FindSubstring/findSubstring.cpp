#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// source: https://github.com/anson627/leetcode/blob/master/SubstringwithConcatenationofAllWords/SubstringwithConcatenationofAllWords.cpp
// OJ: 1712ms


class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
	map<string, int> hasFound;
	map<string, int> toFind;
	
	for(size_t i = 0; i < L.size(); i++) toFind[L[i]]++;
	int N = L.size();
	int M = L[0].size();

	vector<int> out;

	for(int i = 0; i <= (int)S.size() - N*M; i++){
		hasFound.clear();
		int j;
		for(j = 0; j < N; j++){
			int k = i+j*M;
			string sub = S.substr(k, M);
			if(!toFind.count(sub)) break;
			hasFound[sub]++;
			if(hasFound[sub] > toFind[sub]) break;
		}
		if(j == N) out.push_back(i);

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

