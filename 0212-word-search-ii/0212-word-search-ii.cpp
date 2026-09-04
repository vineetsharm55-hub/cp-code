class Solution {
public:

    struct TrieNode{
        TrieNode *child[26];
        string word;

        TrieNode()
        {
            for(int i=0;i<26;i++)
                child[i] = nullptr;
        }
    };

    TrieNode *root = new TrieNode();

    vector<string> ans;
    void insert(string &word)
    {
        TrieNode *node = root;
        for(char c:word)
        {
            int idx = c-'a';
            if(!node ->child[idx])
            {
                node->child[idx] = new TrieNode();
            }
            node = node->child[idx];
        }
        node->word=word;
    }
    void dfs(vector<vector<char>> &board,int r,int c,TrieNode *node)
    {
        // out of bounds
        if(r < 0 || c < 0 || r >=board.size() || c>=board[0].size())
         return;

         char ch = board[r][c];

         // Already visited
         if(ch =='#')
         {
            return;
         }
         int idx = ch - 'a';
         // no such prefix in tree
         if(!node->child[idx])
          return;

        node = node->child[idx];
        //Found a complete word
        if(!node->word.empty())
        {
            ans.push_back(node->word);
            // prevent finding the same word again
            node->word="";
        }

        // Mark current cell as visited
        board[r][c] = '#';
        dfs(board,r+1,c,node);
        dfs(board,r-1,c,node);
        dfs(board,r,c+1,node);
        dfs(board,r,c-1,node);

        // backtrack
        board[r][c] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        for(string word:words)
        {
            insert(word);
        }
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dfs(board,i,j,root);
            }
        }

        return ans;
    }
};