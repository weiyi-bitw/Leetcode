#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Memory limits exceeds

class Solution {
public:
    void insertElements(vector<string> &allStringComb, string si, int k){
        int ns = allStringComb.size();
        for(int i = 0; i < ns; i++){
            string s = allStringComb[i];
            for(unsigned int j = 0; j < s.length(); j += k){
                string snew = s;
                snew.insert(j, si);
                allStringComb.push_back(snew);
            }
            s += si;
            allStringComb[i] = s;
        }
    }
    vector<string> getAllPermutations(vector<string> &L){
        int n = L.size();
        vector<string> allStringComb;
        allStringComb.push_back("");
        for(int i = 0; i < n; i++){
            insertElements(allStringComb, L[i], L[i].size());
        }
	return allStringComb;
    }
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> out;
        vector<string> allComb = getAllPermutations(L);
	for(unsigned int i = 0; i < allComb.size(); i++){
		string s = allComb[i];
		int it = 0;
		while(true){
			it = S.find(s, it+1);
			if((size_t)it != string::npos) out.push_back(it);
			else break;
		}
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

