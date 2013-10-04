/*
 * =====================================================================================
 *
 *       Filename:  longestValidParentheses.cpp
 *
 *    Description:  OJ: 36ms
 *
 *        Version:  1.0
 *        Created:  10/03/2013 04:07:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution{
  public:
	int longestValidParentheses(string s){
		int n = s.size();
		int maxLen = 0;
		int block = -1;
		stack<int> leftPos;
		for(int i = 0; i < n; i++){
			if(s[i] == '('){
				leftPos.push(i);
			}else{
				if(leftPos.empty()){
					block = i;
				}else{
					leftPos.pop();
					int len = leftPos.empty() ? i - block : i-leftPos.top();
					if(len > maxLen) maxLen = len;
				}
			}

		}
		return maxLen;
	}
};


int main(){
	string s = "(((())(()(";
	Solution sol;
	cout << sol.longestValidParentheses(s) << endl;


	return 0;
}


