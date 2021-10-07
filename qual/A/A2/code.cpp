#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define sz(a) (int)(a.size())
#define pb push_back
#define all(c) c.begin(),c.end()
#define tr(it,a,c) for(auto it=c.begin()+a;it!=c.end();it++)
#define fr(i,a,n)   for(int i=a;i<n;i++)
#define frn(i,a,n) for(int i=n-1;i>=a;i--)
#define present(c,x) (c.find(x)!=c.end()) //for set/map etc.
#define cpresent(c,x) (find(all(c),x)!=c.end())
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<pair<int,int>> vp;
typedef map<int,int> mi;
const int mod=(int) 1e9+7;
 
 
int min(int a,int b){if(a<b) return a; else return b;}
int max(int a,int b){if(a>b) return a; else return b;}
int power(int a,int b){int res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int gcd(int p, int q){if(p%q==0) return q; else{return gcd(q,p%q);}} 
bool comp(int a, int b) 
{ 
    return (a > b); 
}
 
bool comp1(pi a, pi b)
{
    if(a.first==b.first)return a.second<b.second;
    else return a.first>b.first;
}
 
template<typename T> 
istream& operator>>(istream& in, vector<T>& v)
{
    for (T& x : v) in >> x; return in;
}
 
template<typename T> 
ostream& operator<<(ostream& out, vector<T>& v)
{
    for (T& x : v) out << x<<" "; return out;
}
 
template <typename T>
void sort(vector<T> &v)
{
    std::sort(v.begin(), v.end());
    return;
}
template <typename T>
T max(vector<T> &v)
{
    return *(max_element(v.begin(), v.end()));
}
template <typename T>
T min(vector<T> &v)
{
    return *(min_element(v.begin(), v.end()));
}
template <typename T>
T sum(vector<T> &v)
{
    T sum=0;
    for(int i=0;i<v.size();i++)
    {
        sum =  sum + v[i];
    }
    return sum;
}
template<typename T> 
ostream& operator<<(ostream& out, vector<vector<T>>& v)
{
    for (vector<T>& x : v)
    {
        for(T& a : x)
        {
            out << a<<" ";
        }
        out<<endl;

    } 
    return out;
}

void dfs(int i, vector<int>& dp, vvi& v)
{
    vector<int> visited(26,0);
    queue<int> s;
    s.push(i);
    dp[i]=0;
    visited[i]=1;

    while(!s.empty())
    {
        int q = s.front();
        s.pop();
        visited[q]=1;
        fr(j,0,26)
        {
            if(v[q][j]==1&&visited[j]==0)
            {
                dp[j] = dp[q] + 1;
                s.push(j);
            }
        }
    }

}



void solve()
{
    string s;
    cin>>s;

    int k;
    cin>>k;

    vvi v(26, vi(26,0));

    fr(i,0,k)
    {
        string s1;
        cin>>s1;

        v[s1[0] -'A'][s1[1] -'A']=1;
    }
    // cout<<v;

    vvi min_time(26,vi(26,-1));
    // dfs(0,min_time[0], v);
    fr(i,0,26)
    {
        dfs(i, min_time[i], v);
    }
    // cout<<min_time;
    int f=0;
    int curr =0;
    int ans = 1e9;
    fr(i,0,26)
    {
        f=0;
        curr=0;
        fr(j,0,s.size())
        {
            if(min_time[s[j]-'A'][i]==-1)
            {
                f=1;
                break;
            }
            else
            {
                curr+= min_time[s[j]-'A'][i];
            }
        }
        if(f==0)
        {
            // cout<<i<<" "<<curr<<endl;
            ans = min(ans, curr);
        }
        
    }
    if(ans==1e9)cout<<-1;
    else
    cout<<ans;

}
    
 
// #undef int
signed main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("consistency_chapter_2_validation_input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output_validation.txt", "w", stdout);
    #endif  
    std::ios_base:: sync_with_stdio(false);
    cin.tie(0);  //for cin
    // clock_t start=clock(),end;
    int t;
    cin>>t;
    // cout<<t;
    for(int i=1;i<=t;i++)   
    {
        cout<<"Case #"<<i<<": ";
        solve();
        cout<<endl;
    }
    // solve();
    // end = clock();
    // double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    // cout<<endl<<time_taken;
    return 0;   
}