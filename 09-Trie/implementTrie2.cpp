// problem link: https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include<bits/stdc++.h>
using namespace std;


struct Node {
    Node *links[26];
    int cntPrefix = 0;
    int cntEndWith = 0;

    //checks if the reference trie is present or not
    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    //creating reference trie
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    //to get the next node for traversal
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    // increase a letter count as prefix
    void increasePrefix()
    {
        cntPrefix++;
    }

    // increase word count
    void increaseEnd()
    {
        cntEndWith++;
    }

    int getEnd()
    {
        return cntEndWith;
    }
    int getPrefix()
    {
        return cntPrefix;
    }
    void reducePrefix()
    {
        cntPrefix--;
    }
    void removeEnd()
    {
        cntEndWith--;
    }
};

class Trie {
private:
    Node *root;
public:

    Trie() {
        // Write your code here.
        root = new Node();
    }

    void insert(string &word) {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            //moves to reference trie
            node = node->get(word[i]);
            // increase prefix count
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getPrefix();
    }

    void erase(string &word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containKey(word[i]))
            {
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else
                return;
        }
        node->removeEnd();
    }
};
