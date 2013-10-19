/*
 * =====================================================================================
 *
 *       Filename:  trap.cpp
 *
 *    Description:  OJ: 44ms
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
		int v = 0, i = 0;
		while(i < n){
			if(A[i] < 1){ 
				i++;
				continue;
			}
			//cout << "i: " << i << endl;
			int h = A[i];
			int maxAj = 0, maxJ = i+1;
			int j;
			for(j = i+1; j < n; j++){
				if(A[j] >= h){
					maxJ = j;
					break;
				}
				if(A[j] >= maxAj){ 
					maxAj = A[j];
					maxJ = j;
				}
			}
			if(j == n) h = maxAj;
			//cout << "MaxJ: " << maxJ << ":" << A[maxJ] << endl;
			for(i = i+1; i < maxJ; i++){
				v += h - A[i];
			}
			//cout << "Add volume to: " << v << endl;
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
