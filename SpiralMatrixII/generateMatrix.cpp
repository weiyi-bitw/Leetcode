/*
 * =====================================================================================
 *
 *       Filename:  generateMatrix.cpp
 *
 *    Description:  24ms
 *
 *        Version:  1.0
 *        Created:  10/19/2013 04:48:46 PM
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
	vector<vector<int> > generateMatrix(int n){
		vector<vector<int> > out(n, vector<int>(n, -1) );
		int k = 0;
		int cnt = 1;
		while(n > k){
			if(n - k == 1){
				out[k][k] = cnt;
				break;
			}
			for(int j = k; j < n-1; j++) out[k][j] = cnt++;
			for(int i = k; i < n-1; i++) out[i][n-1] = cnt++;
			for(int j = n-1; j > k; j--) out[n-1][j] = cnt++;
			for(int i = n-1; i > k; i--) out[i][k] = cnt++;
			k++;
			n--;
		}

		return out;
	}


};

int main()
{
	Solution sol;
	int n = 7;
	vector<vector<int> > out = sol.generateMatrix(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << out[i][j] << "\t";
		}cout << endl;
	}

	return 0;
}
