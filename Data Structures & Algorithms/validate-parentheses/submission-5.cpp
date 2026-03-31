class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;

        for(auto& brack : s){
            if(brack == '(' || brack == '{' || brack == '['){
                brackets.push(brack);
            }
            else{
                if (brackets.empty()) return false;
                if(brack == ')' && brackets.top() == '('){
                    brackets.pop();
                }
                else if(brack == '}' && brackets.top() == '{'){
                    brackets.pop();
                }
                else if(brack == ']' && brackets.top() == '['){
                    brackets.pop();
                }
                else{
                    return false;
                }
            }
        }

        return brackets.empty();

        
        
    }
};
