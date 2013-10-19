/*
 * =====================================================================================
 *
 *       Filename:  maxSubArray.cpp
 *
 *    Description:  48 ms
 *
 *        Version:  1.0
 *        Created:  10/15/2013 02:55:36 PM
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
	int maxSubArray(int A[], int n){
		if(n == 0) return 0;
		if(n == 1) return A[0];
		int maxCurrent = A[0];
		int maxSum = A[0];
		for(int i = 1; i < n; i++){
			maxCurrent = maxCurrent >= 0 ? maxCurrent + A[i] : A[i];
			if(maxCurrent > maxSum) maxSum = maxCurrent;
		}
		return maxSum;
	}

};

int main()
{
	int A[] = {-1, 2, 3, -4, 4, 6, -8};
	Solution sol;
	cout << sol.maxSubArray(A, 7) << endl;

	return 0;
}
