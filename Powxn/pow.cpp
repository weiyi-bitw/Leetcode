/*
 * =====================================================================================
 *
 *       Filename:  pow.cpp
 *
 *    Description:  32 ms
 *
 *        Version:  1.0
 *        Created:  10/14/2013 10:37:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), wc2302@columbia.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

class Solution{
  public:
	double pow(double x, int n){
		if(n == 0) return 1.0;
		double half = pow(x , n/2);
		if(n % 2 == 0){
			return half * half;
		}else if(n > 0){
			return half * half * x;
		}else{
			return half * half / x;
		}
	}
};

int main()
{
	double x = 1.000001;
	int n = 123456;
	Solution sol;
	cout << sol.pow(x, n) << endl;

	return 0;
}


