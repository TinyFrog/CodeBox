// https://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/
// have to give up my code bacause of TLE

class Solution {
public:
void preprocessing(vector<string> &L,  map<string, int>& mapping) {
    for (auto word : L) {
        if (mapping.find(word) != mapping.end()) {
            mapping[word]++;
        } else {
            mapping[word] = 1;
        }
    }
}

bool are_we_good(map<string, int>& mapping) {
    for (auto record : mapping) {
        if (record.second > 0) {
            return false;
        }
    }
    
    return true;
}

vector<int> findSubstring(string S, vector<string> &L) {
    int good_start = 0;
    int current = 0;
    int length = S.size();
    int word_length = L[0].size();
    
    map<string, int> initial_mapping;
    vector<int> results;
    
    preprocessing(L, initial_mapping);
    map<string, int> mapping = initial_mapping;
    
    while (current < length) {
        if (current + word_length - 1 >= length) {
            break;
        }
        
        string this_word = S.substr(current, word_length);
        
        if (mapping.find(this_word) == mapping.end()) {
            // this word doesn't match, move good_start to the next word
            current = good_start + 1;
            good_start = current;
            mapping = initial_mapping;
            continue;
            
        } else if (mapping[this_word] == 0) {
            // matched but more than needed -- invalid
            // for example: barbarfoo and we're processing the 2nd bar
            // start from here again, clear the counter.
            for (int i = good_start; i<current; i++) {
                string word_from_good_start = S.substr(i, word_length);
                mapping[word_from_good_start]++;
                if (word_from_good_start == this_word) {
                    good_start = i + word_length;
                    break;
                }
            }
        } 
        
        mapping[this_word]--;
        
        if (are_we_good(mapping)) {
            results.push_back(good_start);
            string word_from_good_start = S.substr(good_start, word_length);
            mapping[word_from_good_start]++;
            good_start = good_start + word_length;
        }
        
        current = current + word_length;
    }
    
    return results;
}
};
