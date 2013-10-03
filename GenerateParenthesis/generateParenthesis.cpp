#include <iostream>
#include <string>
#include <vector>

using namespace std;

// OJ: 24ms
class Solution {
public:
    void insertRightParenthesis(vector<string> & out, string s, int l, int r){
        if(r < l) return;
        if(l==0 && r == 0){
            out.push_back(s);
            return;
        }
	
	if(l > 0){
        	string s2 = s;
        	s2 += "(";
        	insertRightParenthesis(out, s2, l-1, r);
	}
	if(r > 0){
        	s += ")";
        	insertRightParenthesis(out, s, l, r-1);
	}
    }
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        string s = "";
        insertRightParenthesis(out, s, n, n);
        return out; 
    }
};

int main()
{
	Solution sol;
	vector<string> out = sol.generateParenthesis(4);
	for(unsigned int i = 0; i < out.size(); i++){
		cout << out[i] << endl;
	}

	return 0;
}
