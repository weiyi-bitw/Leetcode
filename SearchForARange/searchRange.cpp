/*
 * =====================================================================================
 *
 *       Filename:  searchRange.cpp
 *
 *    Description:  OJ: 68ms
 *    		source: http://discuss.leetcode.com/questions/213/search-for-a-range
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
	vector<int> searchRange(int A[], int n, int target){
		vector<int> out(2, -1);
		int l = 0, r = n;
		while(l < r){
			int m = (l+r)/2;
			if(A[m] < target){
				l = m+1;
			}else{
				r = m;
			}
		}
		if(A[l] != target) return out;
		out[0] = l;

		r = n;
		while(l < r){
			int m = (l+r)/2;
			if(target < A[m]){
				r = m;
			}else{
				l = m+1;
			}
		}
		out[1] = r-1;
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
