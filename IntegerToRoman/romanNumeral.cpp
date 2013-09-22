/*
 * =====================================================================================
 *
 *       Filename:  romanNumeral.cpp
 *
 *    Description:  92 msec
 *
 *        Version:  1.0
 *        Created:  09/21/2013 08:56:19 PM
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
  private:
	static string const thousands[3];
	static string const hundreds[9];
	static string const tens[9];
	static string const ones[9];
  public:
	string intToRoman(int num){
		string out = "";
		int t = num/1000;
		if(t > 0) out += thousands[t-1];
		int h = num%1000 / 100;
		if(h > 0) out += hundreds[h-1];
		int x = num%100 / 10;
		if(x > 0) out += tens[x-1];
		int i = num%10;
		if(i > 0) out += ones[i-1];
		return out;
	}


};

string const Solution::thousands[3] = {"M", "MM", "MMM"};
string const Solution::hundreds[9] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
string const Solution::tens[9] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
string const Solution::ones[9] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};


int main()
{
	int x = 3999;
	Solution sol;
	cout << sol.intToRoman(x) << endl;

	return 0;
}
