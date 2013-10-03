#include <iostream>
#include <string>

using namespace std;

// OJ time: 8 msec
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
	if(n & 1) return false;
	char* stk = new char[n/2];
	int top = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') stk[++top] = s[i];
            else if(top < 0){
                return false;
            }else if(s[i] == ')'){
                if(stk[top] == '(') top--;
                else return false;
            }else if(s[i] == '}'){
                if(stk[top] == '{') top--;
                else return false;
            }else if(s[i] == ']'){
                if(stk[top] == '[') top--;
                else return false;
            }
        }
	delete [] stk;
	if(top < 0)
	        return true;
	return false;
    }
};

int main()
{
	string s = "}][}}{[))){}{}){(}]))})[({";
	Solution sol;
	cout << sol.isValid(s) << endl;


	return 0;
}


