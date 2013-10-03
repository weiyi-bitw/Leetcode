#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

// OJ : 12ms

class Solution {
private:
    static map<char, string> itos;
    void createMap(){
        itos['2'] = "abc";
        itos['3'] = "def";
        itos['4'] = "ghi";
        itos['5'] = "jkl";
        itos['6'] = "mno";
        itos['7'] = "pqrs";
        itos['8'] = "tuv";
        itos['9'] = "wxyz";
    }
public:
    vector<string> expandStrings(vector<string> v, string s){
        vector<string> out;
        for(unsigned int i = 0; i < v.size(); i++){
            for(unsigned int j = 0; j < s.size(); j++){
                string si = v[i];
                si += s[j];
                out.push_back(si);
            }
        }
        return out;
    }
    vector<string> letterCombinations(string digits) {
        if(itos.size() == 0) createMap();
        vector<string> out;
        out.push_back("");
        for(unsigned int i = 0; i < digits.size(); i++){
            vector<string> tmp(out);
            out = expandStrings(tmp, itos[digits[i]]);
        }
        return out;
    }
};

map<char, string> Solution::itos;

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

