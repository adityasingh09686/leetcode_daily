class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
		vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for(auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
		
		queue<int> q;
		for (int i = 0; i<n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> ans;
		
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			
			ans.push_back(node);
			
			for (auto p : adj[node]) {
				indegree[p]--;
				
				if (indegree[p] == 0) {
					q.push(p);
				}
			}
		}
		return ans.size() == numCourses ? true : false;
    }
};