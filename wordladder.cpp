#include <bits/stdc++.h>
using namespace std;

class WordLadder {
    public:
        int diff(string a,string b)
        {
            int n=a.length(),c=0;
            for(int i=0;i<n;i++)
                if(a[i]!=b[i])
                    c++;
            return c;
        }
        int ladderLength(string beginWord, string endWord, vector<string> wordList) {
            if(beginWord==endWord)
                return 0;
            int n=wordList.size();
            unordered_map<string,vector<string>> mp;
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(diff(wordList[i],wordList[j])==1)
                    {
                        mp[wordList[i]].push_back(wordList[j]);
                        mp[wordList[j]].push_back(wordList[i]);
                    }
                }
            }
            for(int i=0;i<n;i++)
                if(diff(wordList[i],beginWord)==1)
                {
                    mp[wordList[i]].push_back(beginWord);
                    mp[beginWord].push_back(wordList[i]);
                }
            queue<string> q;
            int ans=1;
            unordered_set<string> vis;
            q.push(beginWord);
            vis.insert(beginWord);
            while(!q.empty())
            {
                int sz=q.size();
                while(sz--)
                {
                    string s=q.front();
                    q.pop();
                    for(auto x:mp[s])
                    {
                        if(vis.find(x)==vis.end())
                        {
                            vis.insert(x);
                            q.push(x);
                            if(x==endWord)
                                return ans+1;
                        }
                    }
                }
                ans++;
            }
        return 0;
        }
};

int main() {
    string beginWord, endWord;
    cin >> beginWord >> endWord;
    int n;
    cin >> n;
    vector<string> wordList;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        wordList.push_back(s);
    }
    int result = WordLadder().ladderLength(beginWord, endWord, wordList);
    cout << result;
    return 0;
}
