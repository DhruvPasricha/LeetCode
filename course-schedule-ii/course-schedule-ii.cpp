class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> inDegree(numCourses);
        vector<int> Adj[numCourses];
        for(auto &prerequisite : prerequisites) {
            int course = prerequisite[0];
            int preCourse = prerequisite[1];
            inDegree[course]++;
            Adj[preCourse].push_back(course);
        }
        queue<int> q;
        vector<bool> visited(numCourses, false);
        for(int i = 0;i < numCourses;i++){
            if(inDegree[i] == 0) {
                q.push(i);
                visited[i] = true;
            }
        }
        
        vector<int> Ans;
        while(q.size() > 0) {
            auto f = q.front();
            q.pop();
            Ans.push_back(f);
            for(int nb : Adj[f]) {
                if(!visited[nb]) {
                    inDegree[nb]--;
                    if(inDegree[nb] == 0) {
                        q.push(nb);
                        visited[nb] = true;
                    }
                }
            }
        }
        if(Ans.size() != numCourses) Ans.clear(); 
        return Ans;
    }
};