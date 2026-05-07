class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // hashmap <key, value> -> key is the anagram, values are the original strings 

        unordered_map<string, vector<string>> groups;  // hash map

        for (string s: strs) { 
            int BUCKET[26] = {}; 
            for (char c: s) BUCKET[c - 'a']++; 

            string key = ""; 
            for (int i = 0; i < 26; i++){
                key += to_string(BUCKET[i]) + '#'; // where the tag symbol is a seperator required [11,2] vs [2,11]
            }

           groups[key].push_back(s); // [anagram key, original string] 
        }

        vector<vector<string>> result;

        for (auto& [key, anagrams] : groups ) result.push_back(anagrams); 
        return result; 
        
    }
};
