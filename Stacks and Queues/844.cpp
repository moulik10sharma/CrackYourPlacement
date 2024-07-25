class Solution {
    private:
    string processString(string& str){
        stack<char>editor;
        for(auto&c : str){
            if(c != '#'){
                editor.push(c);
            }else if (!editor.empty()){
                editor.pop();
            }
        }
        string result;
        while(!editor.empty()){
            result += editor.top();
            editor.pop();
        }
        reverse(result.begin(), result.end()); 
        return result;
    }
public:
    bool backspaceCompare(string s, string t) {
        return processString(s) == processString(t);
    }
};