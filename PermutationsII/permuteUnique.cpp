/*
 * =====================================================================================
 *
 *       Filename:  permuteUnique.cpp
 *
 *    Description:  252 ms
 *
 *        Version:  1.0
 *        Created:  10/14/2013 09:46:06 PM
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
#include <algorithm>

using namespace std;

class Solution{
  public:
	vector<vector<int> > permuteUnique(vector<int> &num){
		vector<vector<int> > out;
		int n = num.size();
		if(n == 0) return out;
		if(n == 1){
			out.push_back(num);
			return out;
		}

		sort(num.begin(), num.end());
		for(int i = n-1; i >= 0; i--){
			if(i < n-1 && num[i] == num[i+1]) continue;
			vector<int> numi(num);
			numi.erase(numi.begin() + i);
			vector<vector<int> > vvi = permuteUnique(numi);
			for(unsigned int j = 0; j < vvi.size(); j++){
				vvi[j].push_back(num[i]);
			}
			out.insert(out.end(), vvi.begin(), vvi.end());
		}

		return out;
	}

};

int main()
{
	int x[] = {1, 1, 2};
	int n = 3;
	vector<int> num(x, x+n);
	Solution sol;
	vector<vector<int> > out = sol.permuteUnique(num);
	int m = out.size();
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << out[i][j] << "\t";
		}cout << endl;
	}	



	return 0;
}



