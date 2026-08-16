class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        string res = "";
        int n = words.size();
        vector<vector<int>> graph(26);
        int indegree[26] = {0}; 
        bool present[26] = {false};

        // Mark present characters
        for (const string& word : words) {
            for (char c : word) {
                present[c - 'a'] = true;
            }
        }

        // Build the graph
        for (int i = 0; i < n - 1; i++) {
            string& w1 = words[i];
            string& w2 = words[i + 1];
            int len = min(w1.length(), w2.length());
            bool found = false;
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    int u = w1[j] - 'a';
                    int v = w2[j] - 'a';
                    graph[u].push_back(v);
                    indegree[v]++;
                    found = true;
                    break;
                }
            }
            // Invalid case: prefix issue like ["abc", "ab"]
            if (!found && w1.length() > w2.length()) return "";
        }

        // Topological Sort
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res += (char)(node + 'a');

            for (int neighbor : graph[node]) {
                indegree[neighbor]--; 
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Final check for cycle
        for (int i = 0; i < 26; ++i) {
            if (present[i] && res.find(i + 'a') == string::npos)
                return "";  
        }

        return res;
    }
};
