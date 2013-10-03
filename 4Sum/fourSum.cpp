#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

// 252ms
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > out;
        sort(num.begin(), num.end());
        int n = num.size();
        if(n < 4) return out;
        vector<int> oneSol;
        int ip = INT_MAX, jp = INT_MAX, kp = INT_MAX;
        for(int i = 0; i < n-3; i++){
            if(i > 0 && num[i] == num[i-1]) continue;
            for(int j = i+1; j < n-2; j++){
                if(j > i+1 && num[j] == num[j-1]) continue;
                int k = j+1, l = n-1;
                while(k < l){
                    int threeSum = num[i] + num[j] + num[k];
                    int sum = threeSum + num[l];
                    if(sum == target){
                        if(num[k] != kp || num[i] != ip || num[j] != jp){
                            ip = num[i];
                            jp = num[j];
                            kp = num[k];
                            oneSol.clear();
                            oneSol.push_back(num[i]);
                            oneSol.push_back(num[j]);
                            oneSol.push_back(num[k]);
                            oneSol.push_back(num[l]);
                            out.push_back(oneSol);
                        }
                        k++; l--;
                    }else if(sum < target){
                        k++;
                    }else{
                        l--;
                    }
                }
            }
        }
        return out;
    }
};

int main()
{
	int a[] = {-4,-3,-2,-1,0,0,1,2,3,4};
	vector<int> v(a, a+10);
	Solution sol;
	vector<vector<int> > out = sol.fourSum(v, 0);

	for(unsigned int i = 0; i < out.size(); i++){
		for(int j = 0; j < 4; j++){
			cout << out[i][j] << "\t";
		}cout << endl;
	}

	return 0;
}

