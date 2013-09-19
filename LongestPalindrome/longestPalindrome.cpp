/*
 * =====================================================================================
 *
 *       Filename:  longestPalindrome.cpp
 *
 *    Description:  204 msec
 *
 *        Version:  1.0
 *        Created:  09/18/2013 08:29:48 PM
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
		if(n < 2) return s;
		if(n==2){ 
			if(s[0]==s[1])return s;
			else return s.substr(1);
		}
		int maxSize = 0;
		string maxPalindrome;
		int i = 1;
		while(i < n){
			int j = i-1, k = i;
			int size = 0;
			while(s[k] == s[j]){
				size += 2;
				k++; j--;
				if(k >= n || j < 0) break;
			}
			if(size > maxSize){ 
				maxSize = size;
				maxPalindrome = s.substr(j+1, k-j-1);
			}
			j = i-1, k = i+1;
			size = 1;
			while(s[k] == s[j]){
				size += 2;
				k++; j--;
				if(k >= n || j < 0) break;
			}
			if(size > maxSize){
				maxSize = size;
				maxPalindrome = s.substr(j+1, k-j-1);
			}
			i++;
		}
		return maxPalindrome;
	}
};


int main()
{
	Solution sol;
	string s = sol.longestPalindrome("ccd");
	cout << s << endl;
	return 0;
}



