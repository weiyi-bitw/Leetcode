/*
 * =====================================================================================
 *
 *       Filename:  romanToInt.cpp
 *
 *    Description:  196 msec
 *
 *        Version:  1.0
 *        Created:  09/21/2013 09:17:44 PM
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
#include <map>

using namespace std;

class Solution
{
  private:
	static map<char, int> createMap() {
		map<char, int> m;
		m['I'] = 1;
		m['V'] = 5;
		m['X'] = 10;
		m['L'] = 50;
		m['C'] = 100;
		m['D'] = 500;
		m['M'] = 1000;
		return m;
	}
	static map<char, int> rimap;
  public:
	int romanToInt(string s){
		int n = s.size();
		int num = 0, i = 0;
		while(i < n){
			if(i < n-1){
				if(rimap[s[i+1]] > rimap[s[i]]) num -= rimap[s[i]];
				else num += rimap[s[i]];
			}else{
				num += rimap[s[i]];
			}
			i++;
		}
		return num;
	}


};

map<char, int> Solution::rimap = Solution::createMap();


int main()
{
	Solution sol;
	string r = "MMXIII";
	cout << sol.romanToInt(r) << endl;

	return 0;
}


