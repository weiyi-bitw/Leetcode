/*
 * =====================================================================================
 *
 *       Filename:  permute.cpp
 *
 *    Description:  Memory Limit Exceeded
 *
 *        Version:  1.0
 *        Created:  10/14/2013 08:49:06 PM
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
	bool nextPerm(int idx[], int n){
		if(n == 1) return false;
		int i = n-2;
		while(idx[i] >= idx[i+1]){
			i--;
			if(i == 0) break;
		}
		int j = n-1;
		while(idx[j] <= idx[i]){
			j--;
			if(j == 0) break;
		}
		if(i == j) return false;
		int tmp = idx[i];
		idx[i] = idx[j];
		idx[j] = tmp;
		i++;
		j = n-1;
		while(i <= j){
			tmp = idx[i];
			idx[i] = idx[j];
			idx[j] = tmp;
			i++;
			j--;
		}
		return true;
	}
	vector<vector<int> > permute(vector<int> &num){
		vector<vector<int> > out;
		int n = num.size();
		int* idx = new int[n];
		vector<int> perm;
		for(int i = 0; i < n; i++){ 
			idx[i] = i;
			perm.push_back(num[idx[i]]);
		}
		out.push_back(perm);
		while(nextPerm(idx, n)){
			perm.clear();
			for(int i = 0; i < n; i++) perm.push_back(num[idx[i]]);
			out.push_back(perm);
		}
		delete [] idx;
		return out;
	}

};

int main()
{
	int x[] = {1};
	int n = 1;
	vector<int> num(x, x+1);
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


