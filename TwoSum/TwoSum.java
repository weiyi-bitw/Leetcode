import java.io.*;

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int n = numbers.length;
        int[] o = order(numbers, numbers.length);
        int[] output = new int[2];
        for(int i = 0; i < n; i++){
            int j = bsearch(numbers, o, n, target - numbers[o[i]]);
            if(j != -1) {
                if(o[i] < j){
                        output[0] = o[i]+1;
                        output[1] = j+1;
                }else{
                        output[0] = j+1;
                        output[1] = o[i] + 1;
                }
                break;
            }
        }
        return output;
    }
    private static void qsort_r(int[] a, int[] idx, int l, int r){
        int i = l, j = r;
        int m = (l+r)/2;
        while(i <= j){
            while(a[idx[i]] < a[idx[m]]) i++;
            while(a[idx[j]] > a[idx[m]]) j--;
            if(i <= j){
                int tmp = idx[i];
                idx[i] = idx[j];
                idx[j] = tmp;
                i++;
                j--;
            }
        };
        if(i < r) qsort_r(a, idx, i, r);
        if(j > l) qsort_r(a, idx, l, j);
    }
    private static int[] order(int[] a, int n){
        int[] idx = new int[n];
        for(int i = 0; i < n; i++) idx[i] = i;
        qsort_r(a, idx, 0, n-1);
        return idx;
    }
    private static int bsearch(int[] a, int[] o, int n, int target){
        int m = n/2, l = 0, r = n-1;
        while(a[o[m]] != target && l < r){
            if(target > a[o[m]]){
                l = m;
                m = (m+r+1)/2;
            }else{
                r = m;
                m = (l+m)/2;
            }
        };
        if(a[o[m]] == target) return o[m];
        else return -1;
    }
}

public class TwoSum{
	public static void main(String[] args){
		int numbers[] = {5, 75, 25};
		int target = 100;
		Solution sol = new Solution();
		int[] o = sol.twoSum(numbers, target);
		System.out.println("index1=" + o[0] + ", index2=" + o[1]);
	}
}
