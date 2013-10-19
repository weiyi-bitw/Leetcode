/*
 * =====================================================================================
 *
 *       Filename:  getPermutation.cpp
 *
 *    Description:  12 ms
 *
 *        Version:  1.0
 *        Created:  10/19/2013 05:24:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), wc2302@columbia.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
  public:
	string getPermutation(int n, int k){
		string s;
		vector<char> candidate;
		int factorial[9];
		for(int i = 0; i < n; i++){ 
			if(i > 0) factorial[i] = factorial[i-1]*(i+1);
			else factorial[i] = 1;
			candidate.push_back('0' + i + 1);
		}
		k--;
		n--;
		while(n >= 0){
			int idx = k / factorial[n-1];
			s += candidate[idx];
			candidate.erase(candidate.begin() + idx);
			k %= factorial[n-1];
			n--;
		}

		return s;
	}


};

int main(){
	Solution sol;
	cout << sol.getPermutation(1, 1) << endl;; 

	return 0;
}
