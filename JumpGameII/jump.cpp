/*
 * =====================================================================================
 *
 *       Filename:  jump.cpp
 *
 *    Description:  OJ: 56ms
 *		source: http://discuss.leetcode.com/questions/223/jump-game-ii
 *        Version:  1.0
 *        Created:  10/08/2013 11:47:20 PMa
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), wc2302@columbia.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
  public:
	int jump(int A[], int n){
		int reach = 0;
		int step = 0;
		int pos = 0;
		for(int i = 0; i < n; i++){
			if(i > pos){
				pos = reach;
				step++;
			}
			reach = max(reach, i+A[i]);
		}
		if(reach < n-1) return -1;
		return step;
	}

};

int main()
{
	

	return 0;
}
