/// Shunting Yard Algorithm
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int pri(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else
        return 2;
    cout << ch << " is not supported yet, come later ";
    return -1;
}

int solve(char ch, int d1, int d2)
{
    if (ch == '+')
        return d1 + d2;
    if (ch == '-')
        return d1 - d2;
    if (ch == '*')
        return d1 * d2;
    if (ch == '/')
        return d1 / d2;
    cout << ch << " is not supported yet, come later ";
    return -1;
}

int main()
{
    string s;
    cout << "Enter the expression : ";
    cin >> s;
    stack<int> val;
    stack<char> op;
    for (int i = 0; i < s.length(); i++)
    {
        // ascii of 0 to 9 --> 48 to 57
        if (s[i] >= '0' && s[i] <= '9')
            val.push(s[i] - '0');
        else // s[i] is an operator
        {
            if (op.empty() || pri(s[i]) > pri(op.top()))
                op.push(s[i]);
            else // pri(s[i]) <= pri(op.top())
            {
                while (!op.empty() && pri(s[i]) <= pri(op.top()))
                {
                    // solve
                    char ch = op.top();
                    op.pop();
                    int d2 = val.top();
                    val.pop();
                    int d1 = val.top();
                    val.pop();
                    int temp = solve(ch, d1, d2);
                    val.push(temp);
                }
                op.push(s[i]);
            }
        }
    }
    // if any operators are left in op
    while (!op.empty())
    {
        // solve
        char ch = op.top();
        op.pop();
        int d2 = val.top();
        val.pop();
        int d1 = val.top();
        val.pop();
        int temp = solve(ch, d1, d2);
        val.push(temp);
    }
    cout << val.top() << endl;
}