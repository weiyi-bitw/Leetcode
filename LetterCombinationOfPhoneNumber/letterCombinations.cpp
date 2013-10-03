#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

// OJ: 8ms

class Solution {
private:
    const static string itos[8]; 
public:
    vector<string> letterCombinations(string digits) {
        vector<string> out(1, "");
        for(unsigned int i = 0; i < digits.size(); i++){
		const string si = itos[digits[i] - '2'];
        	for(int j = out.size()-1; j >= 0; j--){
			for(int k = si.size()-1; k >= 0; k--){
				if(k)
					out.push_back(out[j] + si[k]);
				else
					out[j] += si[k];
			}
		}
        }
        return out;
    }
};

const string Solution::itos[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main()
{
	string dg = "23";
	Solution sol;
	vector<string> v = sol.letterCombinations(dg);
	for(unsigned int i = 0; i < v.size(); i++){
		cout << v[i] << "\t";
	}cout << endl;


	return 0;
}

