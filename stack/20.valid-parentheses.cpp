

/*
    20. 有效的括号
    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
    
    有效字符串需满足：
        左括号必须用相同类型的右括号闭合。
        左括号必须以正确的顺序闭合。
        注意空字符串可被认为是有效字符串。
*/

/*
    示例 1:
    输入"(("
    输出：false
    示例 2:
    输入: "()[]{}"
    输出: true
    示例 3:
    输入: "(]"
    输出: false
    示例 4:
    输入: "([)]"
    输出: false
    示例 5:
    输入: "{[]}"
    输出: true
*/

class Solution {
public:
    bool isValid(string str) {
       // 括号序列长度是奇数，肯定非法
       if( str.size()%2 ==1 ) 
            return false;
        
        stack<char>my_stack;
        for(auto c: str){
            if(c=='(')
                my_stack.push(')');
            else if(c=='[')
                my_stack.push(']');
            else if(c=='{')
                my_stack.push('}');
            else{
                // 字符配对
                if( !my_stack.empty() && c == my_stack.top())
                    my_stack.pop();
                else
                    return false;
            }
        }
        // 应对 "((" 用例
        if(my_stack.empty())
            return true;
        else
            return false;
    }
};