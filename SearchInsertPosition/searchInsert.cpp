/*
 * =====================================================================================
 *
 *       Filename:  searchInsert.cpp
 *
 *    Description:  OJ: 40ms
 *
 *        Version:  1.0
 *        Created:  10/04/2013 12:01:28 AM
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
	int searchInsert(int A[], int n, int target){
		int l = 0;
		int r = n;
		int m;
		while(l < r){
			m = (l+r)/2;
			if(A[m] == target) return m;
			if(target < A[m]){
				r = m;
			}else{
				l = m+1;
			}
		}
		return l;
	}
};

int main()
{
	int A[4] = {1, 3, 5, 6};
	Solution sol;
	cout << sol.searchInsert(A, 4, 5) << endl;
	cout << sol.searchInsert(A, 4, 2) << endl;
	cout << sol.searchInsert(A, 4, 7) << endl;
	cout << sol.searchInsert(A, 4, 0) << endl;


}


