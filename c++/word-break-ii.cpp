// TLE
// https://oj.leetcode.com/problems/word-break-ii/
vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<string> results;
    vector<string> temp_solution;
    
    dfs(0, s, temp_solution, results, dict);
    return results;
}


void dfs(int pilot, string& s, vector<string>& temp_solution, vector<string>& results, unordered_set<string> &dict) {
    if (pilot == s.size()) {
        string result = "";
        for (int i = 0; i<temp_solution.size(); i++) {
            result += temp_solution[i];
            if (i != temp_solution.size() - 1) {
                result += " ";
            }
        }
        
        results.push_back(result);
    }
    
    
    for (int i = pilot; i<s.size(); i++) {
        string substr = s.substr(pilot, i-pilot+1);
        if (word-break-iidict.find(substr) != dict.end()) {
        
            temp_solution.push_back(substr);
            dfs(i+1, s, temp_solution, results, dict);
            temp_solution.pop_back();
        }
    }
}
