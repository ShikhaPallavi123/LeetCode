class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{' ){
                stack.push(s[i]);
            }else{
                if(stack.empty() || s.size() == 1){
                    return false;
                }

                if((s[i] == ')' && stack.top() != '(') ||
                    (s[i] == ']'&& stack.top() != '[') ||
                    (s[i] == '}' && stack.top()!= '{')){
                         return false;
                    }

                    stack.pop();
            }
        }

         return stack.empty();
    }
};