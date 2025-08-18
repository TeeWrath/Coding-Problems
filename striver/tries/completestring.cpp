#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true; // Changed from false to true
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
public:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]); // Added this line
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]); // Added this line
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]); // Added this line
        }
        return true;
    }

    // This function should be inside your Trie class
bool isCompleteString(string word) {
    Node* node = root;
    for (char ch : word) {
        if (node->containsKey(ch)) {
            node = node->get(ch);
            // Check if the prefix ending at this character is a valid word
            if (node->isEnd() == false) {
                return false;
            }
        } else {
            // This case should not happen if the word was inserted
            return false;
        }
    }
    return true; // All prefixes were valid words
}
};

class Solution {
    string longestValidWord(vector<string>& words) {
        Trie trie = Trie();
        
        // inserted all words
        for(auto word: words){
            trie.insert(word);
        }

        string cs = "";

        for(auto word: words){
            if(trie.isCompleteString(word) && word.size() > cs.size()){
                cs = word;
            }
            else if(trie.isCompleteString(word) && word.length() == cs.length()){
                if(word < cs)cs = word;
            }
        }

        return cs;
    }
};
