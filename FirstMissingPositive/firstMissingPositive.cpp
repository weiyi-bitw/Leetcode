/*
 * =====================================================================================
 *
 *       Filename:  firstMissingPositive.cpp
 *
 *    Description:  OJ: 12ms
 *
 *        Version:  1.0
 *        Created:  10/06/2013 04:23:05 PM
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
	int firstMissingPositive(int A[], int n){
		int i = 0;
		while(i < n){
			while(A[i] <= n && A[i] > 0 && A[i] != i+1){
				if(A[A[i] - 1] == A[i]) break;
				int tmp = A[ A[i]-1 ];
				A[ A[i]-1 ] = A[i];
				A[i] = tmp;
			}
			i++;
		}
		for(int i = 0; i < n; i++){
			if(A[i] != i+1) return (i+1);
		}return n+1;
	}

};

int main()
{
	int A[] = {3, 4, -1, 1};
	Solution sol;
	cout << sol.firstMissingPositive(A, 4) << endl;

	return 0;
}


