/*
 * =====================================================================================
 *
 *       Filename:  trap.cpp
 *
 *    Description:  OJ: 60ms
 *    		source: http://discuss.leetcode.com/questions/220/trapping-rain-water
 *
 *        Version:  1.0
 *        Created:  10/06/2013 05:19:50 PM
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
	int trap(int A[], int n){
		int v = 0, i = 0, j = n-1, k;
		while(i < j){
			if(A[i] <= A[j]){
				k = i+1;
				while(A[i] > A[k]){
					v += A[i] - A[k];
					k++;
				}
				i = k;
			}else{
				k = j-1;
				while(A[j] > A[k]){
					v += A[j] - A[k];
					k--;
				}
				j = k;
			}
		}
		return v;
	}

};

int main()
{
	int A[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	Solution sol;
	cout << sol.trap(A, 12) << endl;

	return 0;
}
