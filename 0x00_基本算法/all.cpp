void mul(vector<int>& nums,int x)
{
    vector<int> c;
    int t=0;
    for(int i=0;i<n||t;i++)
    {
        if(i<n)t=nums[i]*x;
        c.push_back(t%10);
        t/=10;
    }

    return c;
}

void div(vector<int>& nums,int x)
{
    int r=0;
    vector<int> c;

    for(int i=nums.size()-1;i>=0;i--)
    {
        r=r*10+nums[i];
        c.push_back(r/x);
        r%=x;
    }
    reverse(c.begin(),c.end());
    
    while(c.size()>1&&c.back()==0)c.pop_back();

    return c;
}

void mul(vector<int>& a,vector<int> &b)
{
    vector<int> c(a.size()+b.size());

    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b.size();j++){
            c[i+j]=a[i]*b[i];
        }
    }

    int t=0;

    for(int i=0;i<c.size();i++)
    {
        t+=c[i];
        c[i]=t%10;
        t/=10;
    }

    while(c.size()>1&&c.back()==0)c.pop_back();

    return c;
}

void add(vector<int> nums,int a)
{
   for(int i=0;a;i++)
   {
    if(i>=nums.size())nums.push_back(0);
    a=a+nums[i];
    nums[i]=a%10;
    a/=10;
   }

   return nums;
}

void add(vector<int>& a,vector<int>& b)
{
    vector<int> c(max(a.size(),b.size())+1);

    
}