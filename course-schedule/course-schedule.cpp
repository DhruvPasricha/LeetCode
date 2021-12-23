class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
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
        int count = 0;
        for(int i = 0;i < numCourses;i++){
            if(inDegree[i] == 0) {
                q.push(i);
                visited[i] = true;
            }
        }
        
        while(q.size() > 0) {
            auto f = q.front();
            q.pop();
            count++;
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
        
        return count == numCourses;
    }
};