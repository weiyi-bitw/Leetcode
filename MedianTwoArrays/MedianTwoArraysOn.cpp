/*
 * =====================================================================================
 *
 *       Filename:  MedianTwoArraysOn.cpp
 *
 *    Description:  This is not the correct answer for it has O(n) time complexity
 *    			Judge Small: 144 msec. Judge Large: 196 msec
 *
 *        Version:  1.0
 *        Created:  09/08/2013 05:41:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), ninpy.weiyi@gmail.com
 *   Organization:  Columbia University
 *
 * =====================================================================================
 */

#include <iostream>

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int target = (m+n)/2;
        int a = 0, b = 0, cnt = 0;
        int o = -1, preo = -1;
        while(cnt <= target){
            preo = o;
            if(a >= m){
                o = B[b++];
            }else if(b >= n){
                o = A[a++];
            }else{
                if(A[a] < B[b]){
                    o = A[a++];
                }else{
                    o = B[b++];
                }
            }
            cnt++;
        }
        double totalMed = (m+n)&1 ? o : (double)(o + preo)/2;
        return totalMed;        
    }
};

int main(){
	int A[1] = {1};
	int B[2] = {2, 3};
	Solution sol;
	double med = sol.findMedianSortedArrays(A, 0, B, 2);
	std::cout << med << std::endl;

	return 0;
}


