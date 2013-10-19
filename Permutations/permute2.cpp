/*
 * =====================================================================================
 *
 *       Filename:  permute2.cpp
 *
 *    Description:  108 ms
 *
 *        Version:  1.0
 *        Created:  10/14/2013 09:08:39 PM
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

class Solution{
  public:
	vector<vector<int> > permute(vector<int> &num){
		vector<vector<int> > out;
		int n = num.size();
		if(n == 0) return out;
		if(n == 1) {
			out.push_back(num);
			return out;
		}
		for(int i = 0; i < n; i++){
			vector<int> numi(num);
			numi.erase(numi.begin()+i);
			vector<vector<int> > vvi = permute(numi);
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
	int x[] = {1, 2, 3};
	int n = 3;
	vector<int> num(x, x+n);
	Solution sol;
	vector<vector<int> > out = sol.permute(num);
	int m = out.size();
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << out[i][j] << "\t";
		}cout << endl;
	}	



	return 0;
}

