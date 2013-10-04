/*
 * =====================================================================================
 *
 *       Filename:  nextPermutation.cpp
 *
 *    Description:  OJ: 64ms
 *
 *        Version:  1.0
 *        Created:  10/03/2013 03:52:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution{
  public:
	void nextPermutation(vector<int> &num){
		int n = num.size();
		if(n <= 1) return;
		int i = n-2;
		while(num[i] >= num[i+1]){
			if(i == 0) break;
			i--;
		}
		int j = n-1;
		while(num[j] <= num[i]){
			if(j == 0) break;
			j--;
		}
		int tmp;
		if(i != j){
			tmp = num[i];
			num[i] = num[j];
			num[j] = tmp;
			i++;
		}
		j = n-1;
		while(i <= j){
			tmp = num[i];
			num[i] = num[j];
			num[j] = tmp;
			i++;
			j--;
		}
	}

};

int main(){
	int arr[2] = {1, 2};
	vector<int> v(arr, arr+2);
	int n = v.size();
	Solution sol;
	sol.nextPermutation(v);

	for(int i = 0; i < n; i++){
		cout << v[i] << endl;
	}
	return 0;
}
