/*
 * =====================================================================================
 *
 *       Filename:  threeSum.cpp
 *
 *    Description:  272 msec
 *
 *        Version:  1.0
 *        Created:  09/24/2013 09:49:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), ninpy.weiyi@gmail.com
 *   Organization:  Columbia University
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution
{
  public:
	vector< vector<int> > threeSum(vector<int> &num){
		int n = num.size();
		vector< vector<int> > out;
		if(n < 3) return out;
		vector<int> triplet;
		sort(num.begin(), num.end());
		int ti, tj;
		ti = tj = num[0]-1;
		for(int i = 0; i < n-2 && num[i] <= 0; i++){
			if(i > 0 && num[i] == num[i-1])continue;
			int j = i+1;
			int k = n-1;
			while(j < k){
				int twoSum = num[i] + num[j];
				if(twoSum + num[k] < 0){
					j++;
				}else if(twoSum + num[k] > 0){
					k--;
				}else if(num[i] != ti || num[j] != tj){
					triplet.clear();
					triplet.push_back(num[i]);
					triplet.push_back(num[j]);
					triplet.push_back(num[k]);
					ti = num[i];
					tj = num[j];
					out.push_back(triplet);
					j++; k--;
				}else{
					j++; k--;
				}
			}
		}

		return out;
	}


};

int main()
{
	int numArray[6] = {-1, 0, 1, 2, -1, -4};
	vector<int> num (numArray, numArray+6);
	vector<int> empty;
	Solution sol;
	vector<vector<int> >out = sol.threeSum(num);
	for(unsigned int i = 0; i < out.size(); i++){
		vector<int> tpl = out[i];
		for(int j = 0; j < 3; j++){
			cout << tpl[j] << "\t";
		}cout << endl;
	}


	return 0;
}


