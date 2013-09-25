/*
 * =====================================================================================
 *
 *       Filename:  longestCommonPrefix.cpp
 *
 *    Description:  36 msec
 *
 *        Version:  1.0
 *        Created:  09/21/2013 10:03:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), ninpy.weiyi@gmail.com
 *   Organization:  Columbia University
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
	string lcp(string s1, string s2){
		int i = 0;
		int n = s1.size(), m = s2.size();
		while( i < n && i < m ){
			if(s1[i] != s2[i]) break;
			i++;
		}
		return s1.substr(0, i);
	}
	string longestCommonPrefix(vector<string> &strs){
		int n = strs.size();
		if(n == 0) return "";
		if(n == 1) return strs[0];
		string x = lcp(strs[0], strs[1]);
		for(int i = 2; i < n; i++){
			x = lcp(x, strs[i]);
		}
		return x;
	}


};

int main()
{
	Solution sol;
	vector<string> strs;
	strs.push_back("abcde");
	strs.push_back("abcdt");
	strs.push_back("abcdeowi");
	strs.push_back("abclik");
	cout << sol.longestCommonPrefix(strs) << endl;

	return 0;


}

