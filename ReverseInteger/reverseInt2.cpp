/*
 * =====================================================================================
 *
 *       Filename:  reverseInt.cpp
 *
 *    Description:  60 msec
 *
 *        Version:  1.0
 *        Created:  09/19/2013 03:34:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), ninpy.weiyi@gmail.com
 *   Organization:  Columbia University
 *
 * =====================================================================================
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
  public:
	int reverse(int x){
		int factor = 1;
		int sign = x < 0 ? -1 : 1;
		int xcp = x < 0 ? -x : x;
		stack<int> stk;
		while(xcp > 0){
			stk.push(xcp % 10);
			xcp /= 10;
		}
		int y = 0;
		while(!stk.empty()){
			y += stk.top() * factor;
			stk.pop();
			factor *= 10;
		}
		return sign * y;
	}
};

int main()
{
	Solution sol;
	int x = -321;
	int y = sol.reverse(x);
	cout << y << endl;
	return 0;
}
