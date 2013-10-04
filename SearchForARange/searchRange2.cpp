/*
 * =====================================================================================
 *
 *       Filename:  searchRange.cpp
 *
 *    Description:  OJ: 72ms
 *
 *        Version:  1.0
 *        Created:  10/03/2013 11:09:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), wc2302@columbia.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
	int binSearch(int A[], int n , int l, int r, int target){
		int m;
		while(l <= r){
			m = (l + r)/2;
			if(A[m] == target) return m;
			if(target < A[m]){
				r = m-1;
			}else{
				l = m+1;
			}
		}
		return -1;
	}
	vector<int> searchRange(int A[], int n, int target){
		int k = binSearch(A, n, 0, n-1, target);
		cout << k << endl;
		vector<int> out(2, -1);
		out[0] = k;
		out[1] = k;
		int u = k, l = k;
		while(u != -1 || l != -1){
			if(u < n-1) u = binSearch(A, n-u-1, u+1, n-1, target);
			else u = -1;
			cout << "u: " << u << endl;
			if(u != -1) out[1] = u;
			if(l > 0) l = binSearch(A, l, 0, l-1, target);
			else l = -1;
			cout << "l: " << l << endl;
			if(l != -1) out[0] = l;
		}
		return out;
	}


};

int main()
{
	int A[21] = {0,1,1,1,2,2,4,5,5,5,6,6,7,7,7,7,7,8,9,9,10};
	vector<int> out;
	Solution sol;
	out = sol.searchRange(A, 21, 5);
	cout << out[0] << "\t" << out[1] << endl;
};
