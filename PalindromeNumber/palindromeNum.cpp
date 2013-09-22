/*
 * =====================================================================================
 *
 *       Filename:  palindromeNum.cpp
 *
 *    Description:  304 msec
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
		if(x < 0) return false;
		int left = 1;
		while(x / left >= 10){
			left *= 10;
		}
		if(left == 1) return true;
		while(x > 0){
			int l = x / left;
			int r = x % 10;
			if(l != r) return false;
			x = (x % left) / 10;
			left /= 100;
		}
		return true;
	}

};

int main()
{
	int x = 1167557611;
	Solution sol;
	cout << sol.isPalindrome(x) << endl;

	return 0;
}
