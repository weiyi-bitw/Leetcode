#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int n = num.size();
        assert(n >= 3);
        int out = num[0] + num[1] + num[n-1];
        int diff = abs(target-out);
        for(int i = 0; i < n-2; i++){
            int j = i+1, k = n-1;
            int d = INT_MAX, threeSum;
            while(j < k){
                threeSum = num[i] + num[j] + num[k];
                d = threeSum - target;
                if(d==0) return target;
                if(abs(d) < diff){
                    out = threeSum;
                    diff = d < 0 ? -d : d;
                }
                if(d < 0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return out;
    }
};

int main()
{
	int arr[] = {-4,-7,-2,2,5,-2,1,9,3,9,4,9,-9,-3,7,4,1,0,8,5,-7,-7};
	vector<int> v(arr, arr+22);
	Solution sol;
	cout << sol.threeSumClosest(v, 29) << endl;;

	return 0;
}

