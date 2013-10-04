/*
 * =====================================================================================
 *
 *       Filename:  search.cpp
 *
 *    Description:  OJ: 32ms
 *
 *        Version:  1.0
 *        Created:  10/03/2013 09:17:01 PM
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
	int search(int A[], int n, int target){
		int l = 0, r = n;
		while(l <= r){
			int m = (l+r)/2;
			//cout << l << ":" << A[l] << "\t" << m << ":" << A[m] << "\t" << r << ":" << A[r] << endl;
			if(target == A[m]) return m;
			if(A[l] < A[m]){
				if(target < A[m] && target >= A[l]){
					r = m-1;
				}else{
					l = m+1;
				}
			}else{
				if(target <= A[r] && target > A[m]){
					l = m + 1;
				}else{
					r = m - 1;
				}
			}
		}
		return -1;
	}


};

int main()
{
	int A[7] = {5, 6, 7, 9, 0, 1, 3};
	Solution sol;
	cout << sol.search(A, 7, 4) << endl;
	cout << sol.search(A, 7, 2) << endl;
	cout << sol.search(A, 7, 3) << endl;
	cout << sol.search(A, 7, 5) << endl;
	cout << sol.search(A, 7, 8) << endl;

	return 0;
};
