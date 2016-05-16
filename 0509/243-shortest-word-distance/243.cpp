class Solution {
public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
    unordered_map<string, vector<int>> wordsMap;
    for (int i = 0, j = words.size(); i < j; ++i) {
      wordsMap[words[i]].push_back(i);
    }
        
    vector<int> indexes1 = wordsMap[word1];
    vector<int> indexes2 = wordsMap[word2];
        
    int min = INT_MAX;
    for (auto i : indexes1) {
      for (auto j : indexes2) {
	min = abs(i - j) < min? abs(i-j) : min;
      }
    }
    return min;
  }
};
