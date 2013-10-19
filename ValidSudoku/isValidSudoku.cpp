/*
 * =====================================================================================
 *
 *       Filename:  isValidSudoku.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/05/2013 09:36:10 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), wc2302@columbia.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution{
  public:
	static const int N;
	bool isValidSudoku(vector<vector<char> > &board){
		bool* existMem = new bool[3*N*N];
		bool** exist = new bool*[3*N];
		for(int i = 0; i < 3*N; i++){
			exist[i] = &existMem[i * N];
			for(int j = 0; j < N; j++){
				exist[i][j] = 0;
			}
		}
		
		for(int i = 0; i < N; i++){
			int x = i / 3; // block x index
			for(int j = 0; j < N; j++){
				if(board[i][j] == '.') continue;
				int y = j / 3; // block y index;
				int idx = x * 3 + y;
				int numIdx = board[i][j] - '1';
				if(exist[i][numIdx] || exist[N + j][numIdx] || exist[2*N + idx][numIdx]) return false;
				exist[i][numIdx] = exist[N + j][numIdx] = exist[2*N + idx][numIdx] = true;
			}
		}
		delete [] existMem;
                delete [] exist;
		
		return true;
	}



};

const int Solution::N = 9;

int main(){


	return 0;
}

