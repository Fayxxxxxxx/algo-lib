//P16

// 当城区规模扩大之后，Fractal 的解决方案是把和原来城区结构一样的区域按照图中的方式建设在城市周围，提升城市的等级。

// 对于任意等级的城市，我们把正方形街区从左上角开始按照道路标号。

// 虽然这个方案很烂，Fractal 规划部门的人员还是想知道，如果城市发展到了等级 N
// ，编号为 A
//  和 B
//  的两个街区的直线距离是多少。

// 街区的距离指的是街区的中心点之间的距离，每个街区都是边长为 10
//  米的正方形。

// 输入格式
// 第一行输入正整数 n
// ，表示测试数据的数目。

// 以下 n
//  行，输入 n
//  组测试数据，每组一行。

// 每组数据包括三个整数 N,A,B
// ，表示城市等级以及两个街区的编号，整数之间用空格隔开。

// 输出格式
// 一共输出 n
//  行数据，每行对应一组测试数据的输出结果，结果四舍五入到整数。


#include<bits/stdc++.h>
using namespace std;

#define int long long

struct dex
{
     int x;
     int y;
};

dex solve(int n,int m)
{
    if(n==0)
    {
        return {0,0};
    }
    
    int Se=(long long)1<<(n-1);//半边长相当于
    int cnt=(long long)1<<(2*n-2);
    
    dex sdex=solve(n-1,m%cnt);
    int x=sdex.x;
    int y=sdex.y;
    
    
    int z=m/cnt;
    
    if(z==0)
    {
        return {y,x};
    }
    else if(z==1)
    {
        return {x,Se+y};
    }
    else if(z==2)
    {
        return {x+Se,Se+y};
    }
    else
    {
        return {2*Se-1-y,Se-1-x};//这里(len-1-y,len-1-x) 具体表现为将 行变列 列变行 
    }
    
}
signed  main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int T;
cin>>T;

while(T--)
{
    int n,h,o;
    cin>>n>>h>>o;
    
    dex house_h = solve(n, h - 1);
    dex house_o = solve(n, o - 1);
        
        
        int dx = house_h.x - house_o.x;
        int dy = house_h.y - house_o.y;
        double ans = sqrt(dx * dx + dy * dy) * 10.0;
        
        cout << (int)round(ans) << '\n';
}


    return 0;
}