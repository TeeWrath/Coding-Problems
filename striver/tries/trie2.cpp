#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    int ew =0;
    int cp =0;

    int getEnd(){
        return ew;
    }

    int getPrefix(){
        return cp;
    }
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

    void increaseEnd(){
        ew++;
    }

    void increasePrefix(){
        cp++;
    }

    void deleteEnd(){
        ew--;
    }

    void reducePrefix(){
        cp--;
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
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word)
    {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i]))node = node->get(word[i]);
            else return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string prefix)
    {
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(node->containsKey(prefix[i]))node = node->get(prefix[i]);
            else return 0;
        }
        return node->getPrefix();
    }

    void erase(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else return;
        }
        node->deleteEnd();
    }
};