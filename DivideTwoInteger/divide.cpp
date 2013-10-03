#include <iostream>
#include <climits>
#include <assert.h>

using namespace std;

// OJ time: 36ms

class Solution {
public:
    int divide(int dividend, int divisor) {
        assert(divisor != 0);
        if(dividend == 0) return 0;
	if(dividend == divisor) return 1;
        bool pos = (dividend ^ divisor) >> 31? 0: 1;
	int q = 0, r = dividend, d = divisor;
	if(divisor == 1) return dividend;
	else if(divisor == -1) return -dividend;
	else if(divisor == INT_MIN) return 0;
        else if(divisor < 0) d = -d;

	bool intminflag = false;
	if(dividend == INT_MIN){ 
		intminflag = true;
		r = INT_MAX;
	}else if(dividend < 0){ 
		r = -r;
	}
       	int shiftcnt = 0;
       	while(d<<1 <= r && !(d & 1<<30)){ 
       	    d <<= 1;
       	    shiftcnt++;
       	}
	int t;
       	while(shiftcnt >= 0){
       	    q <<= 1;
       	    t = r - d;
       	    if(t >= 0){
       	        q++;
       	        r  = t;
       	    }
       	    d >>= 1;
       	    shiftcnt--;
       	}
	if(intminflag && t==1) q++;
	
        return pos ? q : -q;
    }
};

int main()
{
	Solution sol;
	
	int k = sol.divide(1, -1);
	cout << k << endl;
	k = sol.divide(69, -13);
	cout << k << endl;
	k = sol.divide(-1010369383, -2147483648);
	cout << k << endl;
	k = sol.divide(-2147483648, 1);
	cout << k << endl;
	k = sol.divide(-2147483648, 2);
	cout << k << endl;
	k = sol.divide(-2147483648, -2);
	cout << k << endl;
	return 0;
}
