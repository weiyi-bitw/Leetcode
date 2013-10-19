/*
 * =====================================================================================
 *
 *       Filename:  solveSudoku.cpp
 *
 *    Description:  OJ: 72ms
 *
 *        Version:  1.0
 *        Created:  10/05/2013 09:09:47 PM
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

using namespace std;

class Solution{
  public:
	void eliminateCandidate(vector<vector<char> > &board, bool* candidate, int i, int j){
		int x = i/3;
		int y = j/3;
		for(int k = 0; k < 9; k++){
			char b = board[i][k];
			if(b != '.') candidate[b-'1'] = false;
			b = board[k][j];
			if(b != '.') candidate[b-'1'] = false;
			b = board[x*3 + k/3][y*3 + k%3];
			if(b != '.') candidate[b-'1'] = false;
		}
	}
	bool solveCell(vector<vector<char> > &board, int x, int y){
		// find next empty
		int i = x, j = y;
		while(i < 9){
			if(board[i][j] == '.') break;
			i = j == 8 ? i+1 : i;
			j = j == 8 ? 0 : j+1;
		}
		if(i == 9) return true;
		bool* candidate = new bool[9];
		for(int k = 0; k < 9; k++) candidate[k] = true;
		eliminateCandidate(board, candidate, i, j);
		for(int k = 0; k < 9; k++){
			if(candidate[k]){ 
				board[i][j] = ('1' + k);
				if(solveCell(board, i, j)) return true;
			}
			board[i][j] = '.';
		}
		delete [] candidate;
		return false;
	}
	void solveSudoku(vector<vector<char> > &board){
		solveCell(board, 0, 0);
	}
};

int main()
{
	string input[] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
	vector<vector<char> > board(9);
	for(int i = 0; i < 9; i++){
		const char* ptr = input[i].c_str();
		board[i] = vector<char>(ptr, ptr+9);
	}
	Solution sol;
	sol.solveSudoku(board);
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << board[i][j] << "\t";
		}cout << endl;
	}

	return 0;
}


