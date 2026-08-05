class Solution {
public:

    vector<string> below20 = {
        "", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen",
        "Eighteen", "Nineteen"
    };

    vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy",
        "Eighty", "Ninety"
    };

    // Converts number from 1 to 999
    string helper(int num) {

        if(num == 0)
            return "";

        // 1 - 19
        if(num < 20)
            return below20[num] + " ";

        // 20 - 99
        if(num < 100)
            return tens[num / 10] + " " + helper(num % 10);

        // 100 - 999
        return below20[num / 100] + " Hundred " + helper(num % 100);
    }


    string numberToWords(int num) {

        if(num == 0)
            return "Zero";

        string ans = "";

        // Billion
        if(num >= 1000000000) {
            ans += helper(num / 1000000000) + "Billion ";
            num %= 1000000000;
        }

        // Million
        if(num >= 1000000) {
            ans += helper(num / 1000000) + "Million ";
            num %= 1000000;
        }

        // Thousand
        if(num >= 1000) {
            ans += helper(num / 1000) + "Thousand ";
            num %= 1000;
        }

        // Remaining number
        if(num > 0) {
            ans += helper(num);
        }

        // Remove last space
        while(!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};