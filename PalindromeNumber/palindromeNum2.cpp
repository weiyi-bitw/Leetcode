/*
 * =====================================================================================
 *
 *       Filename:  palindromeNum.cpp
 *
 *    Description:  344 msec
 *
 *        Version:  1.0
 *        Created:  09/19/2013 07:39:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), ninpy.weiyi@gmail.com
 *   Organization:  Columbia University
 *
 * =====================================================================================
 */

#include <iostream>
#include <climits>

using namespace std;

class Solution
{
  public:
	bool isPalindrome(int x){
		if(x < 0 ) return false;
		int rx = 0;
		int xcp = x;
		while(xcp > 0){
			rx = rx * 10 +  xcp % 10;
			xcp /= 10;
		}
		return x == rx;
	}

};

int main()
{
	int x = 32123;
	Solution sol;
	cout << sol.isPalindrome(x) << endl;

	return 0;
}
