string in_to_back(string s)
{
    stack<int> st;
    string res;

    for(int i=0;i<s.size();i++)
    {
        char x=s[i];

        if(isdigt(x)||isalpha(x))
        {
            res+=x;
        }
        else if(x=='(')
        {
            st.push(x);
        }
        else if(x==')')
        {
            while(!st.empty()&&st.top()!='(')
            {
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty()&&priority(st.top())>=priority(x))
            {
             res+=st.top();
             st.pop();
            }
            st.push(x);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}


int result(string res)
{
    stack<int> ans;

    for(char x:res)
    {
        if(isdigit(x))
        {
            ans.push(x-'0');
        }
        else
        {
            int a=ans.top();ans.pop();
            int b=ans.top();ans.pop();

            if(x=='*')res.push(a*b);
            if(x=='/')res.push(a/b);
            if(x=='+')res.push(a+b);
            if(x=='-')res.push(a-b);
        }
    }
    return res.top();
}