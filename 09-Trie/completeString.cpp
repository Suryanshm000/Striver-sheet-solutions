// problem link: https://www.codingninjas.com/codestudio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

#include<bits/stdc++.h>
using namespace std;


struct Node {
    Node *links[26];
    bool flag = false;

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
    //setting flag to true at the end of the word
    void setEnd()
    {
        flag = true;
    }
    //checking if the word is completed or not
    bool isEnd()
    {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word)
    {
        //initializing dummy node pointing to root initially
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            //moves to reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkIfPrefixExists(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containKey(word[i]))
            {
                node = node->get(word[i]);
                // if prefix word is not ending
                if (node->isEnd() == false)
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a) {
    // Write your code here.
    Trie trie;
    for (auto s : a)
    {
        trie.insert(s);
    }
    string longest = "";

    for (auto s : a)
    {
        if (trie.checkIfPrefixExists(s))
        {
            if (s.size() > longest.size())
                longest = s;
            else if (s.size() == longest.size())
            {
                if (s < longest)
                    longest = s;
            }
        }
    }

    if (longest == "")
        return "None";
    return longest;
}