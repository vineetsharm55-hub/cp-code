class Solution {
public:
    int start = 0;
    int maxLen = 1;

    void expand(string &s, int left, int right) {

        while (left >= 0 && right < s.length() && s[left] == s[right]) {

            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }

            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {

        int n = s.length();

        for (int i = 0; i < n; i++) {
            expand(s, i, i);       // Odd length
            expand(s, i, i + 1);   // Even length
        }

        return s.substr(start, maxLen);
    }
};