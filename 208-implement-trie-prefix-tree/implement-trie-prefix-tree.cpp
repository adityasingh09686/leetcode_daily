struct Node {
    Node* links[26];
    bool flag = false;
    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }
    bool containsKey(char ch) { return (links[ch - 'a'] != NULL); }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};

class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        string s = word;
        int n = word.size();
        Node* node = root;
        for (int i = 0; i < n; i++) {
            if (!node->containsKey(s[i])) {
                node->put(s[i], new Node());
            }
            // moving to the reference trie
            node = node->get(s[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        string s = word;
        int n = word.size();
        Node* node = root;
        for (int i = 0; i < n; i++) {
            if (!node->containsKey(s[i])) {
                return false;
            }
            node = node->get(s[i]);
        }
        
        return node->isEnd() == true;
    }

    bool startsWith(string prefix) {
        string s = prefix;
        Node* node = root;
        int n = prefix.size();
        for (int i = 0; i < n; i++) {
            if (!node->containsKey(s[i])) {
                return false;
            }
            node = node->get(s[i]);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */