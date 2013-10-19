/*
 * =====================================================================================
 *
 *       Filename:  maxProfit.cpp
 *
 *    Description:  OJ: 56 ms
 *
 *        Version:  1.0
 *        Created:  10/08/2013 09:42:32 PM
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

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
	int low = 0, maxDiff = 0;
	for(int i = 0; i < n; i++){
		if(prices[i] < prices[low]) low = i;
		int diff = prices[i] - prices[low];
		if(diff > maxDiff){ 
			maxDiff = diff;
		}
	}
        return maxDiff;
    }
};

int main(){
	int p[] = {3, 3, 5, 0, 0, 3, 1, 4};
	vector<int> prices(p, p+8);

	Solution sol;
	cout << sol.maxProfit(prices) << endl;;

	return 0;
}

