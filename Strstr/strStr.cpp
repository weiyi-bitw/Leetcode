#include <iostream>

using namespace std;

// OJ : 24 ms

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        char *p = haystack, *pfirst = NULL, *padv = p;
        char *q = needle;
	if(!(*q)) return p;
	while(*++q) padv++;
        while(*padv++){
        	pfirst = p;
                q = needle;
        	while(*p == *q && *p && *q){
			p++;q++;
		}
               	if(!(*q)) return pfirst;
                p = pfirst + 1;
        }
        return NULL;
    }
};

int main()
{
	char h[] = "mississippi";
	char n[] = "ssi";
	char *t = h;
	while(*t){
		cout << *t << endl;
		t++;
	}
	cout << endl;
	Solution sol;
	char *o = sol.strStr(h, n);
	if(o){
		t = n;
		while(*t++)
			cout << *o++ << endl;
	}else{
		cout << "null" << endl;
	}
	return 0;
}


