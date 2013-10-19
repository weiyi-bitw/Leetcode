/*
 * =====================================================================================
 *
 *       Filename:  spiralOrder.cpp
 *
 *    Description:  16 ms
 *
 *        Version:  1.0
 *        Created:  10/15/2013 03:22:35 PM
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
	vector<int> spiralOrder(vector<vector<int> > &matrix){
		vector<int> spiral;
		int m = matrix.size();
		if(m == 0) return spiral;
		int n = matrix[0].size();
		int k = 0;
		while(k < m && k < n){
			if(m-k == 1){
				for(int x = k; x < n; x++) spiral.push_back(matrix[k][x]);
				break;
			}
			if(n-k == 1){
				for(int y = k; y < m; y++) spiral.push_back(matrix[y][k]);
				break;
			}
			
			for(int x = k; x < n-1; x++)
				spiral.push_back(matrix[k][x]);
			for(int y = k; y < m-1; y++)
				spiral.push_back(matrix[y][n-1]);
			for(int x = n-1; x > k; x--)
				spiral.push_back(matrix[m-1][x]);
			for(int y = m-1; y > k; y--)
				spiral.push_back(matrix[y][k]);

			m--;
			n--;
			k++;
			
		}
		return spiral;
	}
};

int main()
{
	vector<vector<int> > matrix;
	for(int i = 0; i < 3; i++){
		vector<int> row;
		for(int j = 0; j < 3; j++){
			row.push_back(i*3 + j);
		}
		matrix.push_back(row);
	}
	

	Solution sol;
	vector<int> out = sol.spiralOrder(matrix);

	for(unsigned int i = 0; i < out.size(); i++)
		cout << out[i] << "\t";
	cout << endl;

	return 0;
}

