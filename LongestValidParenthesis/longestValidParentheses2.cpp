/*
 * =====================================================================================
 *
 *       Filename:  longestValidParentheses2.cpp
 *
 *    Description:  OJ: 52ms
 *    		source: http://discuss.leetcode.com/questions/212/longest-valid-parentheses
 *
 *        Version:  1.0
 *        Created:  10/03/2013 09:05:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), wc2302@columbia.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
  public:
	int longestValidParentheses(string s){
		return max(lvpHelper(s.begin(), s.end(), '('), lvpHelper(s.rbegin(), s.rend(), ')'));
	}
	
	template<class Iter>
	int lvpHelper(Iter begin, Iter end, char ch){
		int out = 0;
		int l = 0, r = 0;
		for(; begin != end; begin++){
			if(*begin == ch){
				l++;
			}else if(l > r){ 
				r++;
				if(l == r) out = max(out, l<<1);
			}else{
				l = r = 0;
			}
		}
		return out;
	}

};
int main(){
	string s = "(((())(()(";
	Solution sol;
	cout << sol.longestValidParentheses(s) << endl;


	return 0;
}



