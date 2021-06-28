class WordDictionary {
public:
    struct Node
    {
        bool is_end;
        Node *next[26];
        Node()
        {
            is_end = false;
            for (int i = 0; i < 26; i ++ )
                next[i] = NULL;
        }
    };

    Node *root;

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *p = root;
        for (char c : word)
        {
            int son = c - 'a';
            if (!p->next[son]) p->next[son] = new Node();
            p = p->next[son];
        }
        p->is_end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string &word, int k, Node *u)
    {
        if (k == word.size()) return u->is_end;
        if (word[k] != '.')
        {
            if (u->next[word[k] - 'a']) return dfs(word, k + 1, u->next[word[k] - 'a']);
        }
        else
        {
            for (int i = 0; i < 26; i ++ )
                if (u->next[i])
                {
                    if (dfs(word, k + 1, u->next[i])) return true;
                }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
