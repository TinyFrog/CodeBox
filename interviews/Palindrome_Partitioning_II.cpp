https://oj.leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
public:
    int minCut(string s) {
        int length = s.size();
        if (length == 0 || length == 1) {
            return 0;
        }
        
        int** results = new int*[length];
        for (int i = 0; i<length; i++) {
            results[i] = new int[length];
            for (int j = 0; j<length; j++) {
                results[i][j] = -1;   
            }
        }
        
        int** palin_results = new int*[length];
        for (int i = 0; i<length; i++) {
            palin_results[i] = new int[length];
            for (int j = 0; j<length; j++) {
                palin_results[i][j] = -1;   
            }
        }
        
        return get_cut(0, length-1, s, results, palin_results);
    }
    
    int get_cut(int left, int right, string& s, int** results, int** palin_results) {
        if (left == right) {
            return 0;
        }
        
        if (results[left][right] != -1) {
            return results[left][right];
        }
        
        if (is_palindrome(left, right, s, palin_results)) {
            results[left][right] = 0;
            return 0;
        }
        
        int min_cut = ~(1<<31);
        for (int i = left; i<right; i++) {
            min_cut = min(min_cut, get_cut(left,i,s,results, palin_results) + get_cut(i+1, right, s, results, palin_results) + 1);
        }
        
        results[left][right] = min_cut;
        return min_cut;
    }
    
    
    bool is_palindrome(int left, int right, string& s, int** palin_results) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};
