class MinStack
{
public:
  stack<long long> st;
  long long min;
  MinStack()
  {
    min = LLONG_MAX;
  }

  void push(int val)
  {
    long long temp = (long long)(val);
    if (st.empty())
    {
      min = temp;
      st.push(temp);
    }
    else if (temp < min)
    {
      long long x = 2 * temp - min;
      st.push(x);
      min = temp;
    }
    else
      st.push(temp);
  }

  void pop()
  {
    if (st.top() < min)
    {
      long long old_min = 2 * min - st.top();
      min = old_min;
    }
    st.pop();
  }

  int top()
  {
    if (st.top() < min)
      return (int)(min);
    return (int)st.top();
  }

  int getMin()
  {
    return (int)(min);
  }
};