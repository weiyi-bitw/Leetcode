/*
 * =====================================================================================
 *
 *       Filename:  maxProfit.cpp
 *
 *    Description:  OJ: 56 ms
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

using namespace std;

class Solution{
  public:
	int maxProfit(vector<int> &prices){
		int n = prices.size();
		int low = 0, profit = 0;
		for(int i = 1; i < n; i++){
			if(prices[i] < prices[low]) low = i;
			if(i + 1 < n && prices[i+1] < prices[i]){
				profit += prices[i] - prices[low];
				low = i+1;
			}else if(i == n-1 && prices[i] >= prices[i-1]){
				profit += prices[i] - prices[low];
			}
		}
		return profit;
	}
};


