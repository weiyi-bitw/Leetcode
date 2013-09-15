/*
 * =====================================================================================
 *
 *       Filename:  findKthSmallest.cpp
 *
 *    Description:  Practice 1: find kth smallest element
 *
 *        Version:  1.0
 *        Created:  09/12/2013 09:53:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), ninpy.weiyi@gmail.com
 *   Organization:  Columbia University
 *
 * =====================================================================================
 */

#include <assert.h>
#include <limits.h>
#include <iostream>

using namespace std;

int findKthSmallestElementSingle(int A[], int m, int k)
{
	assert( k <= (m) ); assert(k > 0);
	return (A[(k-1)]);
}

int findKthSmallestElement(int A[], int m, int B[], int n, int k)
{
	assert( k <= (m+n) ); assert(k > 0);
	if(m == 0) return findKthSmallestElementSingle(B, n, k);
	else if(n == 0) return findKthSmallestElementSingle(A, m, k);

	int i = (int)((double) m / (m+n) * (k-1));
	int j = k-1-i;
	assert( i >=0 );assert(j >= 0);assert( i <= m );assert(j <= n);

	int Ai = (i == m) ? INT_MAX : A[i];
	int Bj = (j == n) ? INT_MAX : B[j];
	int Aim1 = (i == 0) ? INT_MIN : A[i-1];
	int Bjm1 = (j == 0) ? INT_MIN : B[j-1];

	cout << Aim1 << "," << Ai << "\t" << Bjm1 << "," << Bj << endl;

	if(Ai < Bj && Bjm1 <= Ai) return Ai;
	else if(Bj <= Ai && Aim1 < Bj) return Bj;

	assert( (Ai > Bj && Aim1 > Bj) || (Ai < Bj && Ai < Bjm1) );

	if(Ai < Bj) return findKthSmallestElement(A+i+1, m-1-i, B, j, k-i-1);
	else return findKthSmallestElement(A, m, B+j+1, n-1-j, k-j-1);
}

int main()
{
	int A[1] = {1};
	int B[1] = {1};

	int k = findKthSmallestElement(A, 1, B, 1,2);

	cout << k << endl;	
}
