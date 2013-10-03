#include <iostream>

using namespace std;

// OJ: 28ms

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        int j = n-1;
        while(j >= 0 && A[j] == elem) --j;
        
        while(i < j){
            if(A[i] == elem){ 
                A[i] = A[j--];
            }
            while(j >= 0 && A[j] == elem) --j;
            i++;
        }
        
        return j+1;
    }
};

int main()
{
	int arr[9] = {0, 4, 4, 0, 4, 4, 4, 0, 2};
	Solution sol;
	int k = sol.removeElement(arr, 9, 4);
	for(int i = 0; i < k; i++){
		cout << arr[i] << endl;
	}

	return 0;
}
