#include <iostream>

using namespace std;

// OJ : 68ms

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n < 1) return n;
        int i = 1, j = 1;
        while(i < n){
            if(A[i] != A[i-1])
                A[j++] = A[i];
            i++;
        }
        return j;
    }
};

int main()
{
	int arr[10] = {-3, -3, -2, -1, -1, 0, 0, 0, 0, 0};
	Solution sol;
	int k = sol.removeDuplicates(arr, 10);
	for(int i = 0; i < k; i++){
		cout << arr[i] << endl;
	}


	return 0;
}

