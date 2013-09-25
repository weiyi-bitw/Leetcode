/*
 * =====================================================================================
 *
 *       Filename:  romanToInt.cpp
 *
 *    Description:  168 msec
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
	static int m[32];
	void createMap() {
		m[ ('I'-'A')] = 1;
		m[ ('V'-'A')] = 5;
		m[ ('X'-'A')] = 10;
		m[ ('L'-'A')] = 50;
		m[ ('C'-'A')] = 100;
		m[ ('D'-'A')] = 500;
		m[ ('M'-'A')] = 1000;
	}
  public:
	int romanToInt(string s){
		createMap();
		int n = s.size();
		int num = 0, i = 0;
		while(i < n){
			if(i < n-1){
				if(m[s[i+1]-'A'] > m[s[i]-'A']) num -= m[s[i]-'A'];
				else num += m[s[i]-'A'];
			}else{
				num += m[s[i]-'A'];
			}
			i++;
		}
		return num;
	}


};

int Solution::m[32];


int main()
{
	Solution sol;
	string r = "MMXIII";
	cout << sol.romanToInt(r) << endl;

	return 0;
}


