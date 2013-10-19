/*
 * =====================================================================================
 *
 *       Filename:  maxProfit.cpp
 *
 *    Description:  OJ: 56 ms
 *    		source: http://discuss.leetcode.com/questions/287/best-time-to-buy-and-sell-stock-iii
 *
 *        Version:  1.0
 *        Created:  10/08/2013 10:11:35 PM
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
#include <algorithm>

using namespace std;

class Solution{
  public:
	int maxProfit(vector<int> &prices){
		int n = prices.size();
		int profit = 0;
		vector<int> pUntilNow(n, 0);
		vector<int> pFromNow(n, 0);
		int low = 0, high = n-1;

		for(int i = 1; i < n; i++){
			if(prices[i] < prices[low]) low = i;
			pUntilNow[i] = max(pUntilNow[i-1], prices[i] - prices[low]);
		}

		for(int j = n-2; j >= 0; j--){
			if(prices[j] > prices[high]) high = j;
			pFromNow[j] = max(pFromNow[j+1], prices[high] - prices[j]);
			profit = max(profit, pFromNow[j] + pUntilNow[j]);
		}

		return profit;
	}
};

int main()
{
	int p[] = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
	vector<int> prices(p, p+10);
	Solution sol;
	cout << sol.maxProfit(prices) << endl;

	return 0;

}


