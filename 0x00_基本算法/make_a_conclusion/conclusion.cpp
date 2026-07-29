#define int long long

int mod;

int cal(int a,int b)
{
    int res=0;

    while(b)
    {
        if(b&1){
            res=(res+a)%mod;
        }
        a=a*2%mod;
        b>>=1;
    }
}



int arr[n][n];
//记录从i 到 j 的距离

int dp[1<<n][n];

求dp[(1<<n)-1][n-1];

dp[1][0]=0;

for(int mask=1;mask<n;mask++)
{
    for(int end=0;end<n;end++)
    {
        if(mask&(1<<end))
        {
          for(int nex=0;nex<n;nex++)
          {
            if(((mask^(1<<end))>>nex)&1)
            {
              dp[mask][end]=min(dp[mask][end],dp[mask^(1<<end)][nex]+arr[nex][end]);
            }
          }
        }
    }
}

for(int mask=1;mask<(1<<n);mask++)
{
    for(int end=0;end<n;end++)
    {
        if((mask>>end)&1)
        {
            for(int nex=0;nex<n;nex++)
            {
                if(!((mask>>nex)&1))
                {
                    dp[mask|nex][nex]=min(dp[mask|(1<<nex)][nex],dp[mask][end]+arr[end][nex]);
                }
            }
        }
    }
}

int bits_0[32];
itn bits_1[32];

struct attacks
{
    string op;
    int t;
};

int n,m;

vector<attacks> nums(n);

int main()
{

    

for(int j=31;j>=0;j--)
{
    int res_0=0;
    int res_1=1;
    
    for(int i=0;i<=n;i++)
    {
        string op=nums[i].op;
        int t=nums[i].t;

        if(op=="OR")
        {
            res_0|=(t>>j)&1;
            res_1|=(t>>j)&1;
        }
        else if(op=="XOR")
        {
            res_0^=(t>>j)&1;
            res_1^=(t>>j)&1;
        }
        else
        {
            res_0&=(t>>j)&1;
            res_1&=(t>>k)&1;
        }

        bits_0[i]=res_0;
        bits_1[i]=res_1;
    }
}
    int total=0;
    int ans=0;
for(int i=31;i>=0;i--)
{
int res_1=bits_1[i];
int res_0=bits_0[i];

if(res_0<res_1&&total+(1<<res_1)<=m)
{
    ans+=(1<<res_1);
    total+=(1<<res_0);
}
else
{
    ans+=(1<<res_0);
}
}
cout<<ans<<endl;

}


int n;
vector<double> nums(n+1);

bool check(double mid)
{
    vector<double> prefix(n+2);

    for(int i=1;i<=n;i++)
    {
        prefix[i]=prefix[i-1]+nums[i]-mid;
    }
    
    double Min=INT_MAX;
    
    for(int i=0,j=f;j<=n;i++,j++)
    {
        Min=min(Min,prefix[i]);

        if(Min<=prefix[j])
        {
            return true;
        }
    }
    return false;
}

double left=0;
double right=2001;

while(right-left>1e-5)
{
    double mid=left+(right-left)/2;

    check(mid)?left=mid:right=mid;
}

cout<<(int)(right*1000)<<endl;













b[i];
c[i];


struct film
{
  int id;
  int audio;
  int word;
};

bool cmp(film& a,film& b)
{
    if(a.audio!=b.audio)
    {
        return a.audio>b.audio;
    }
    return a.word>b.word;
}

int n;
cin>>n;

unordered_map<int,int> mp;

for(int i=1;i<=n;i++)
{
    int x;
    cin>>x;

    mp[x]++;
}

vector<film> films;

for(int i=1;i<=m;i++)cin>>b[i];
for(int i=1;i<=m;i++)cin>>c[i];

films[i].id=i;
films[i].audio=mp[b[i]];
films[i].word=mp[c[i]];

sort(films.begin()+1,films.end(),cmp);

cout<<films[1].id<<endl;    


int tmp[N];
vector<int> nums;
void merge_sort(int left,int right)
{
    if(right-left<=1)
    {
        return ;
    }


    int mid=left+(right-left)/2;

    merge_sort(left,mid);
    merge_sort(mid,right);

    int i=left;
    int r=mid;

    while(i<mid&&j<right)
    {
        if(nums[i]<=nums[j])
        {
            tmp[k++]=nums[i++];
        }
        else
        {
            tmp[k++]=nums[j++];
            ans+=mid-1-left+1;
        }
    }
    
    while(i<mid)tmp[k++]=nums[i++];
    while(j<right)tmp[k++]=nums[j++];

    for(int p=0;p<k;p++)
    {
      nums[left+p]=tmp[p];
    }
}