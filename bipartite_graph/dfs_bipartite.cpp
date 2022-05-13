class Solution {
    bool isDfsBipartite(int i,vector<vector<int>>& graph,vector<int>& color)
    {
        for(auto x:graph[i])
        {
            if(color[x]==-1)
            {
                color[x]=1-color[i];
                if(!isDfsBipartite(x,graph,color))
                    return false;
            }
            else if(color[x]==color[i])
                 return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int sz = graph.size();
        vector<int> color(sz,-1);
        for(int i=0;i<sz;i++){
            if(color[i]==-1){
                color[i]=0;
                if(!isDfsBipartite(i,graph,color))
                    return false;
            }
        }
        return true;
    }
};