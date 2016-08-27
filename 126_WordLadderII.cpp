#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <unordered_map>
using namespace std;


vector<string> get_neighbours(string str, unordered_set<string> &dict)
{
    vector<string> res;
    for(int i = 0; i < str.size(); i++)
    {
        char tmp = str[i];
        for(int c = 'a'; c <= 'z'; c++)
        {
            if(c != tmp)
            {
                str[i] = c;
                if(dict.find(str) != dict.end())
                    res.push_back(str);
            }
        }
        str[i] = tmp;
    }
    return res;
}


void dfs(unordered_map<string, set<pair<string, int>>>& parents, string curr_word, vector<vector<string>>& result, vector<string> path)
{
    set<pair<string, int>> ss = parents[curr_word];
    for(auto val: ss)
    {
        path.push_back(val.first);
        if(parents.count(val.first) == 0)
        {
            reverse(path.begin(), path.end());
            result.push_back(path);
            return;
        }
        dfs(parents, val.first, result, path);
        path.pop_back();
    }
}

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
{
    vector<vector<string>> result;
    vector<string> path;
    queue<pair<string, int>> queue; //广搜的队列，存储值和层数
    unordered_map<string, set<pair<string, int>>> parents;  //存储遍历过程中节点的父节点
    unordered_map<string, bool> visited;
    
    dict.insert(start);
    dict.insert(end);
    queue.push(make_pair(start, 1));
    visited[start] = true;
    while(!queue.empty())
    {
        auto curr = queue.front();
        queue.pop();
        for(string adj: get_neighbours(curr.first, dict))
        {
            if(!visited[adj])
            {//没有访问过的点，直接插入队列和parents表中
                queue.push(make_pair(adj, curr.second + 1));
                parents[adj].insert(curr);
                visited[adj] = true;
            }
            else if(parents.count(adj) && parents[adj].begin()->second == curr.second)
            {//如果子节点被访问过，但是父节点表里有子节点的父节点，且子节点父节点和当前遍历的节点是在一层
                parents[adj].insert(curr);
            }
        }
    }
    
    path.push_back(end);
    dfs(parents, end, result, path);
    return result;
}



int main()
{
    string s = "hit";
    string e = "cog";
    vector<string> dicts = {"hot","dot","dog","lot","log"};
    unordered_set<string> dict(dicts.begin(), dicts.end());
    vector<vector<string>> res = findLadders(s, e, dict);
    for(auto v: res)
    {
        for(auto str: v)
        {
            cout << str << " ";
        }
        cout << endl;
    } 
    return 0;
}