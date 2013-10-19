/*
 * =====================================================================================
 *
 *       Filename:  rotate.cpp
 *
 *    Description:  32 ms
 *
 *        Version:  1.0
 *        Created:  10/14/2013 09:56:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), wc2302@columbia.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution{
  public:
	void rotate(vector<vector<int> > &matrix){
		int n = matrix.size();
		for(int i = 0; i < n/2; i++){
			for(int j = i; j < n-i-1; j++){
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[n-j-1][i];
				matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
				matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
				matrix[j][n-i-1] = tmp;
			}
		}
	}
};

int main(){
	int n = 4;
	vector<vector<int> > matrix(4, vector<int>(4));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			matrix[i][j] = i*n + j;
			cout << matrix[i][j] << "\t";
		}cout << endl;
	}

	cout << endl;

	Solution sol;
	sol.rotate(matrix);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << matrix[i][j] << "\t";
		}cout << endl;
	}


	return 0;
}


