class Solution{
  public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        unordered_map<string, vector<string>> store;
        for (const auto& str : string_list) {
            int charCount[26] = {0};
            for (char c : str) {
                charCount[c - 'a']++;
            }
            string hashStr = "";
            for (int j = 0; j < 26; j++) {
                hashStr += to_string(charCount[j]);
                hashStr += "#";
            }
            store[hashStr].push_back(str);
        }
        vector<vector<string>> result;
        for (const auto& entry : store) {
            result.push_back(entry.second);
        }
        return result;
    }
};