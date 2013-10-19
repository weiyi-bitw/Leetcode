/*
 * =====================================================================================
 *
 *       Filename:  totalNQueens.cpp
 *
 *    Description:  48 ms
 *    		source: http://discuss.leetcode.com/questions/230/n-queens-ii
 *
 *        Version:  1.0
 *        Created:  10/15/2013 12:50:48 PM
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
	int cnt, upper;
	int totalNQueens(int n){
		upper = (1 << n) - 1;
		cnt = 0;
		blocks(0, 0, 0);
		return cnt;
	}
	int blocks(int row, int ld, int rd){
		int pos, p;
		if(row != upper){
			pos = upper & (~(row | ld | rd));
			while(pos != 0){
				p = pos & (-pos);
				pos = pos - p;
				blocks(row + p, (ld+p) << 1, (rd+p) >> 1);
			}
		}else{
			cnt++;
		}
	}

};

int main()
{
	Solution sol;
	cout << sol.totalNQueens(4) << endl;

	return 0;
}

