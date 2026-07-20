//起床困难综合症

// 每扇防御门包括一个运算 op
//  和一个参数 t
// ，其中运算一定是 OR,XOR,AND
//  中的一种，参数则一定为非负整数。

// 如果还未通过防御门时攻击力为 x
// ，则其通过这扇防御门后攻击力将变为 x op t
// 。

// 最终 drd 受到的伤害为对方初始攻击力 x
//  依次经过所有 n
//  扇防御门后转变得到的攻击力。

// 由于 atm 水平有限，他的初始攻击力只能为 0
//  到 m
//  之间的一个整数（即他的初始攻击力只能在 0,1,…,m
//  中任选，但在通过防御门之后的攻击力不受 m
//  的限制）。

// 为了节省体力，他希望通过选择合适的初始攻击力使得他的攻击能让 drd 受到最大的伤害，请你帮他计算一下，他的一次攻击最多能使 drd 受到多少伤害。


#include<bits/stdc++.h>
using namespace std;

int n,m;

int cal(vector<string>& ops,vector<int> &ts,int l,int bitset)
{
    int res=bitset;
    
    for(int i=0;i<n;i++)
    {
        if(ops[i]=="AND")
        {
            res=(res&((ts[i]>>l)&1));
        }
        else if(ops[i]=="OR")
        {
            res=(res|((ts[i]>>l)&1));
        }
        else
        {
            res=(res^((ts[i]>>l)&1));
        }
    }
    
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    cin>>n>>m;
    
    vector<string> ops(n);
    vector<int> ts(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>ops[i]>>ts[i];
    }
    
    int bis0[31]={};
    int bis1[31]={};
    
    for(int i=30;i>=0;i--)
    {
        bis0[i]=cal(ops,ts,i,0);
        bis1[i]=cal(ops,ts,i,1);
    }
    
    long long ans=0;
    long long atk=0;
    
    for(int i=30;i>=0;i--)
    {
        if(bis1[i]>bis0[i]&&atk+(1<<i)<=m)
        {
            atk+=(1<<i);
            ans+=(1<<i);
        }
        else
        {
            ans+=(bis0[i]<<i);
        }
    }
    
    cout<<ans;
    
    
    return 0;
}