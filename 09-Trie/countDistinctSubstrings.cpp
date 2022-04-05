// problem link: https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

#include<bits/stdc++.h>
using namespace std;


struct Node {
    Node *links[26];

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
};


int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    int cnt = 0;
    Node *root = new Node();

    for (int i = 0; i < s.size(); i++)
    {
        // each time start with root
        Node *node = root;
        for (int j = i; j < s.size(); j++)
        {
            // if char doesn't exist then count as different substring
            if (!node->containKey(s[j]))
            {
                cnt++;
                node->put(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }

    return cnt + 1;
}