class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char, int> mp;
        queue<int> Q;

        for (int i = 0; i < s.size(); i++) {

            mp[s[i]]++;
            Q.push(i);

            while (!Q.empty() && mp[s[Q.front()]] > 1) {
                Q.pop();
            }
        }

        return Q.empty() ? -1 : Q.front();
    }
};