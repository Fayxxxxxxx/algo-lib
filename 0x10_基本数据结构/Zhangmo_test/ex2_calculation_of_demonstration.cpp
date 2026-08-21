#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
int pow(int a,int b)
{
    int res=1;

    while(b)
    {
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int cal_pri(char x)
{
    if(x=='(')
    {
        return 1;
    }
    else if(x=='+'||x=='-')
    {
      return 2;
    }
    else if(x=='*'||x=='/')
    {
        return 3;
    }
    return 4;
}
vector<string> middle_to_back(string s)
{
    stack<char> st;
    vector<string> res;
    
    for(int i=0;i<(int)s.size();i++)
    {
        char x=s[i];

        if(isdigit(x)||x=='-')
        {
            string tmp;

            while(isdigit(s[i])||x=='-')
            {
                tmp+=x;
                i++;
            }
            i--;
            res.push_back(tmp);
        }
        else if(x=='(')
        {
            st.push(x);
        }
        else if(x==')')
        {
            while(!st.empty()&&st.top()!='(')
            {
                res.push_back(string(1,st.top()));
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty()&&cal_pri(st.top())>=cal_pri(x))
            {
                res.push_back(string(1,st.top()));
                st.pop();
            }
            st.push(x);
        }
    }
    while(!st.empty())
    {
        res.push_back(string(1,st.top()));
        st.pop();
    }
    return res;
}

int cal(vector<string> &res)
{
    stack<int> num;
    for(string s:res)
    {
        if(isdigit(s[0])||s[0]=='-')
        {
            if(s[0]=='-')
            {
               s.erase(s.begin());
               num.push(stoi(s)*-1);
            }
            else
            {
                num.push(stoi(s));
            }
        }
        else
        {
            if(num.size()<=1)
            {
                break;
            }
            int a=num.top();
            num.pop();
            int b=num.top();
            num.pop();

            if(s=="*")num.push(b*a);
            if(s=="/")num.push(b/a);
            if(s=="+")num.push(b+a);
            if(s=="-")num.push(b-a);
            if(s=="^")num.push(pow(b,a));
        }
    }
    return num.top();
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
string s;
cin>>s;

vector<string> res=middle_to_back(s);
cout<<cal(res);



    return 0;
}





#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

ll qpow(ll a,ll b)
{
    ll res=1;

    while(b)
    {
        if(b&1) res=res*a;
        a=a*a;
        b>>=1;
    }

    return res;
}

int cal_pri(char x)
{
    if(x=='+'||x=='-')
        return 1;

    if(x=='*'||x=='/')
        return 2;

    if(x=='^')
        return 3;

    // 一元负号优先级最高
    if(x=='~')
        return 4;

    return 0;
}

bool is_op(char x)
{
    return x=='+'||x=='-'||x=='*'||x=='/'||x=='^';
}

vector<string> middle_to_back(string s)
{
    stack<char> st;
    vector<string> res;

    // 当前是不是正在期待一个操作数
    bool expect_num=true;

    for(int i=0;i<(int)s.size();i++)
    {
        char x=s[i];

        // 多位数
        if(isdigit(x))
        {
            string tmp;

            while(i<(int)s.size()&&isdigit(s[i]))
            {
                tmp+=s[i];
                i++;
            }

            i--;

            res.push_back(tmp);

            // 已经有一个数了
            expect_num=false;
        }
        else if(x=='(')
        {
            st.push(x);

            // 左括号后面应该出现操作数
            expect_num=true;
        }
        else if(x==')')
        {
            while(!st.empty()&&st.top()!='(')
            {
                res.push_back(string(1,st.top()));
                st.pop();
            }

            // 有对应左括号就删掉
            if(!st.empty()&&st.top()=='(')
            {
                st.pop();
                expect_num=false;
            }
            // 如果没有，说明这个右括号是多余的，直接忽略
        }
        else if(is_op(x))
        {
            // 当前期待操作数，此时 +/- 是正负号
            if((x=='+'||x=='-')&&expect_num)
            {
                // 一元 + 什么都不用做
                if(x=='-')
                    st.push('~');
            }
            else
            {
                while(!st.empty()&&
                      st.top()!='('&&
                      cal_pri(st.top())>=cal_pri(x))
                {
                    res.push_back(string(1,st.top()));
                    st.pop();
                }

                st.push(x);

                // 二元运算符后面又要一个操作数
                expect_num=true;
            }
        }
    }

    while(!st.empty())
    {
        // 多余的左括号直接忽略
        if(st.top()!='(')
            res.push_back(string(1,st.top()));

        st.pop();
    }

    return res;
}

ll cal(vector<string> &res)
{
    stack<ll> num;

    for(string s:res)
    {
        if(isdigit(s[0]))
        {
            num.push(stoll(s));
        }
        else if(s=="~")
        {
            ll a=num.top();
            num.pop();

            num.push(-a);
        }
        else
        {
            ll b=num.top();
            num.pop();

            ll a=num.top();
            num.pop();

            if(s=="*")
                num.push(a*b);

            else if(s=="/")
                num.push(a/b);

            else if(s=="+")
                num.push(a+b);

            else if(s=="-")
                num.push(a-b);

            else if(s=="^")
                num.push(qpow(a,b));
        }
    }

    return num.top();
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

    string s;
    cin>>s;

    vector<string> res=middle_to_back(s);

    cout<<cal(res)<<endl;

    return 0;
}
