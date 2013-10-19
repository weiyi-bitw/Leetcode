/*
 * =====================================================================================
 *
 *       Filename:  canJump.cpp
 *
 *    Description:  52 ms
 *
 *        Version:  1.0
 *        Created:  10/15/2013 04:20:18 PM
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

class Solution
{
  public:
	bool canJump(int A[], int n){
		if(n == 1) return true;
		int maxReach = 0;
		for(int i = 0; i <= maxReach; i++){
			int reach = i + A[i];
			if(reach >= n-1) return true;
			if(reach > maxReach) maxReach = reach;
		}
		return false;
	}
};

int main()
{
	int A[] = {1, 2};
	Solution sol;
	cout << sol.canJump(A, 2) << endl;

	return 0;
}

