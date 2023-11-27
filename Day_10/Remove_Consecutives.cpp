#include <iostream>
#include <stack>
#include <string>
using namespace std;

string Compressor(string s)
{
    string str = "";
    if (s.length() == 0)
        return str;
    stack<char> st;
    st.push(s[0]);
    str += s[0];
    int i = 1;
    while (i < s.length())
    {
        if (s[i] == st.top())
            i++;
        else
        {
            st.push(s[i]);
            str += s[i];
            i++;
        }
    }
    return str;
}

int main()
{
    cout << "Enter the string : ";
    string s;
    getline(cin, s);
    cout << Compressor(s);
}