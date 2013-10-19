/*
 * =====================================================================================
 *
 *       Filename:  solveNQueens.cpp
 *
 *    Description:  source: http://yucoding.blogspot.com/2013/01/leetcode-question-59-n-queens.html
 *		120 ms
 *        Version:  1.0
 *        Created:  10/14/2013 10:45:27 PM
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
#include <string>
#include <cstdlib>

using namespace std;

class Solution
{
  public:
	void printres(vector<int> A, int n){
		vector<string> r;
		for(int i = 0; i < n; i++){
			string str(n, '.');
			str[A[i]] = 'Q';
			r.push_back(str);
		}
		res.push_back(r);
	}
	bool isValid(vector<int> A, int r){
		for(int i = 0; i < r; i++){
			if( (A[i]==A[r]) || (abs(A[i] - A[r])==r-i)  )
				return false;
		}
		return true;
	}
	vector<vector<string> > res;
	void nqueens(vector<int> A, int cur, int n){
		if(cur==n) printres(A, n);
		else{
			for(int i = 0; i < n; i++){
				A[cur] = i;
				if(isValid(A, cur)){
					nqueens(A, cur+1, n);
				}
			}
		}
	}
	vector<vector<string> > solveNQueens(int n){
		res.clear();
		vector<int> A(n, -1);
		nqueens(A, 0, n);
		return res;	
	}
};

int main(){
	Solution sol;
	int N = 4;
	vector<vector<string> > out = sol.solveNQueens(N);
	for(unsigned int i = 0; i < out.size(); i++){
		for(int j = 0; j < N; j++){
			cout << out[i][j] << endl;
		}cout << endl;
	}

	return 0;
}


