#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int str_to_number(string num)
    {
        stringstream ss;
        ss << num;
        int conv;
        ss >> conv;
        return conv;
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> res;
        for (int i = 0; i < tokens.size(); i++)
        {
            string num = tokens[i];
            int conv = str_to_number(num);
            if (conv >= (-200) && conv <= (200) && num != "+" && num != "-" && num != "*" && num != "/")
            {
                res.push(conv);
            }
            else
            {
                char op = num[0];
                int first = res.top();
                res.pop();
                int second = res.top();
                res.pop();
                if (op == '+')
                {
                    res.push(second + first);
                }
                else if (op == '-')
                {
                    res.push(second - first);
                }
                else if (op == '*')
                {
                    res.push(second * first);
                }
                else if (op == '/')
                {
                    res.push(second / first);
                }
            }
        }

        return res.top();
    }
};

int main()
{
    vector<string> postfix_expression = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution result;
    cout << "The expression after evaluation is " << result.evalRPN(postfix_expression) << endl;
}
