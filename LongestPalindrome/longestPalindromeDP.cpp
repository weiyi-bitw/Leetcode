/*
 * =====================================================================================
 *
 *       Filename:  longestPalindromeDP.cpp
 *
 *    Description:  source: http://leetcode.com/2011/11/longest-palindromic-substring-part-i.html
 *    			792 msec
 *
 *        Version:  1.0
 *        Created:  09/18/2013 09:15:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), ninpy.weiyi@gmail.com
 *   Organization:  Columbia University
 *
 * =====================================================================================
 */


#include <string>
#include <iostream>

using namespace std;

class Solution
{
  public:
	string longestPalindrome(string s){
		int n = s.size();
		int longestBegin = 0;
		int maxSize = 1;
		if(n < 2) return s;
		if(n==2){ 
			if(s[0]==s[1])return s;
			else return s.substr(1);
		}
		bool tablemem[1000000] = {false};
		bool** table = new bool*[n];
		for(int i = 0; i < n; i++){ 
			table[i] = &tablemem[i*1000];
			table[i][i] = true;
		}
		for(int i = 0; i < n-1; i++){
			if(s[i] == s[i+1]){ 
				maxSize = 2;
				longestBegin = i;
				table[i][i+1] = true;
			}
		}
		for(int len = 3; len <= n; len++){
			for(int i = 0; i < n-len+1; i++){
				int j = i + len-1;
				if(s[i] == s[j] && table[i+1][j-1]){
					table[i][j] = true;
					longestBegin = i;
					maxSize = len;
				}
			}
		}
		delete [] table;
		return s.substr(longestBegin, maxSize);
	}
};

int main()
{
	Solution sol;
	string out = sol.longestPalindrome("acdfghgfdwi");
	cout << out << endl;
	return 0;
}
