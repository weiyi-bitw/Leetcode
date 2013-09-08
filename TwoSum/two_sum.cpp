/*
 * =====================================================================================
 *
 *       Filename:  two_sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/08/2013 02:33:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), ninpy.weiyi@gmail.com
 *   Organization:  Columbia University
 *
 * =====================================================================================
 */

#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> m;
        map<int, int>::iterator it;
        vector<int> ans(2, 0);
        int n = numbers.size();
        for(int i = 0; i < n; i++){
            it = m.find(numbers[i]);
            if(it != m.end()){
                int idx = it->second;
                ans[0] = idx+1;
                ans[1] = i+1;
            }else{
                m[target - numbers[i]] =  i;
            }
        }
        
        return ans;
    }
};

int main(){
	Solution sol;
	int nbs[3] = {5, 75, 25};
	vector<int> numbers;
	for(int i = 0; i < 3; i++) numbers.push_back(nbs[i]);
	int target = 100;

	vector<int> ans = sol.twoSum(numbers, target);

	for(int i = 0; i < 2; i++)
		cout << ans[i] << endl;
	

	return 0;
}

