/*
 * =====================================================================================
 *
 *       Filename:  longestSSWoReChar.cpp
 *
 *    Description:  Judge small: 4 msec. Judge large: 48 msec.
 *
 *        Version:  1.0
 *        Created:  09/14/2013 10:39:37 PM
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
#include <algorithm>

using namespace std;

class Solution
{
  public:
	int lengthOfLongestSubstring(string s) {
        	int sz = s.size();
		int i = 0, j = 0;
		int maxLen = 0;
		bool exist[256] = {false};
		while(j < sz){
			int idx = (int) s[j];
			if(exist[ idx ]){
				maxLen = max(maxLen, j-i);
				while(s[i] != s[j]){
					exist[ (int)s[i] ] = false;
					i++;
				}
				i++;
			}else{
				exist[ idx ] = true;
			}
			j++;
		}
		maxLen = max(maxLen, sz-i);
		return maxLen;
	}
};

int main()
{
	string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
	Solution sol;
	int ll = sol.lengthOfLongestSubstring(s);

	cout << ll << endl;

}


