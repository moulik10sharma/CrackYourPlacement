class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        int n = words.size();
        while (i < n) {
            int j = i;
            int line_length = 0;
            while(j < n && line_length + words[j].size() + (j - i) <= maxWidth) {
                line_length += words[j].size();
                j++;
            }
            string line;
            int to_fill = maxWidth - line_length;
            for(int k = i; k < j; k++) {
                line += words[k];
                if(to_fill > 0) {
                    int count;
                    if(j == n) {
                        count = (k == j - 1) ? to_fill : 1;
                    }
                    else {
                        if(j - 1 - k == 0) count = to_fill;
                        else {
                            count = ceil((double) to_fill / (j - 1 - k));
                        }
                    }
                    line += string(count, ' ');
                    to_fill -= count;
                }
            }
            result.push_back(line);
            i = j;
        }
        return result;
    }
};