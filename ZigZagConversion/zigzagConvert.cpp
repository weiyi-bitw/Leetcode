/*
 * =====================================================================================
 *
 *       Filename:  zigzagConvert.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/18/2013 10:37:31 PM
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
	string convert(string s, int nRows){
		if(nRows == 1) return s;
		int n = s.size();
		string t = "";
		int sep = 2 * (nRows - 1);
		for(int i = 0; i < nRows; i++){
			int itv = 2*i;
			if(itv == 0) itv = sep;
			for(int k = i; k < n; k += itv){
				t.push_back(s[k]);
				itv = itv == sep ? sep : sep - itv;
			}
		}
		return t;
	}
};

int main()
{
	Solution sol;
	string s = "ABCD";
	string out = sol.convert(s,4);
	cout << out << endl;

	return 0;
}

