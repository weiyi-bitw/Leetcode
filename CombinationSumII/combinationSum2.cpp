/*
 * =====================================================================================
 *
 *       Filename:  combinationSum2.cpp
 *
 *    Description:  OJ: 60ms
 *
 *        Version:  1.0
 *        Created:  10/06/2013 12:34:22 PM
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
	void combinationSumHelper(vector<int> &candidate, vector<vector<int> > &out, vector<int> &v, int i, int res){
		int n = candidate.size();
		if(res == 0){
			out.push_back(v);
			return;
		}
		for(int j = i; j < n; j++){
			if(j > i && candidate[j] == candidate[j-1]) continue;
			if(candidate[j] > res) return;
			vector<int> v2(v);
			v2.push_back(candidate[j]);
			int newRes = res - candidate[j];
			combinationSumHelper(candidate, out, v2, j+1, newRes);
		}
	}
	vector<vector<int> > combinationSum2(vector<int> &candidate, int target){
		sort(candidate.begin(), candidate.end());
		vector<vector<int> > out;
		vector<int> v;
		combinationSumHelper(candidate, out, v, 0, target);
		return out;
	}
};

int main()
{
	int C[] = {10, 1, 2, 7, 6, 1, 5};
	int target = 8;
	vector<int> candidate(C, C+7);
	Solution sol;
	vector<vector<int> > out = sol.combinationSum(candidate, target);
	int n = out.size();
	for(int i = 0; i < n; i++){
		vector<int> o = out[i];
		for(size_t j = 0; j < o.size(); j++){
			cout << o[j] << "\t";
		}cout << endl;
	}

	return 0;
}
