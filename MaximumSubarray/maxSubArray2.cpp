/*
 * =====================================================================================
 *
 *       Filename:  maxSubArray2.cpp
 *
 *    Description:  divide and conquer, 60 ms
 *
 *        Version:  1.0
 *        Created:  10/15/2013 03:06:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), wc2302@columbia.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution{
  public:
	int maxSubArray(int A[], int n){
		return maxSubArrayHelper(A, 0, n-1);
	}
	int maxSubArrayHelper(int A[], int l, int r){
		if(l > r) return INT_MIN;
		if(l==r) return A[l];
		int mid = l + ((r - l)>>1);
		int lMax = INT_MIN;
		int rMax = INT_MIN;
		for(int i = mid-1, currSum = 0; i >= l; i--){
			currSum += A[i];
			lMax = max(currSum, lMax);
		}
		for(int i = mid+1, currSum = 0; i <= r; i++){
			currSum += A[i];
			rMax = max(rMax, currSum);
		}
		int midMax = A[mid] + max(lMax, 0) + max(rMax, 0);
		return max(max(maxSubArrayHelper(A, l, mid-1), maxSubArrayHelper(A, mid+1, r)), midMax);
	}

};

int main()
{
	int A[] = {-1, 2, 3, -4, 4, 6, -8};
	Solution sol;
	cout << sol.maxSubArray(A, 7) << endl;

	return 0;
}


