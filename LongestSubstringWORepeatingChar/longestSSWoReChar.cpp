/*
 * =====================================================================================
 *
 *       Filename:  longestSSWoReChar.cpp
 *
 *    Description:  Judge small: 12 msec. Judge large: 56 msec.
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

using namespace std;

class Solution
{
  public:
	int lengthOfLongestSubstring(string s) {
        	int sz = s.size();
		int map[256];
		for(int i = 0; i < 256; i++) map[i] = -1;
		int longestLength = 0;
		int lengthCurrent = 0;
		int breakpoint = 0;
		for(int i = 0; i < sz; i++){
			int idx = (int) s[i];
			if( map[idx] >= 0 ){
				breakpoint = breakpoint > map[idx] ? breakpoint : map[idx];
				lengthCurrent = i - breakpoint;
				map[idx] = i;
			}else{
				map[idx] = i;
				lengthCurrent++;
			}
			if(lengthCurrent > longestLength) longestLength = lengthCurrent;
		}
		return longestLength;
	}
};

int main()
{
	string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
	Solution sol;
	int ll = sol.lengthOfLongestSubstring(s);

	cout << ll << endl;

}


