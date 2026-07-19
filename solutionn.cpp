class Solution {
public:
    void dfs(int i, vector<bool>& visited, vector<vector<int>>& rooms,unordered_set<int>& keys){
        visited[i]=true;
        for(int j=0;j<rooms[i].size();j++){
            int key=rooms[i][j];
            keys.insert(key);
            if(!visited[key]){
                dfs(key,visited,rooms,keys);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n,false);
        unordered_set<int> keys;
        keys.insert(0);
        for(int i=0;i<n;i++){
            if(!visited[i] && keys.count(i)){
                dfs(i,visited,rooms,keys);
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i] )
                return false;
        }
        return true;
    }
};
