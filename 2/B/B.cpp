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


int c;
void dfs(int i, vector<int>& visited, vvi& graph, vi freq_new, vi& freq, set<int>& all, vi& freq_old)
{
    visited[i] = 1;

    // vector<int> t = {i};
    for(auto x: graph[i])
    {
        if(visited[x] != 1)
        {
            // rank[x] = rank[i] + 1;

            dfs(x,visited,graph, freq_new, freq, all, freq_old);

            // t.insert(t.end(), curr.begin(), curr.end());
        }
    }
    freq_new[freq[i]]++;

    if(freq_new[freq[i]] == freq_old[freq[i]])
    {
        all.erase(freq[i]);
    }

    if(all.find(freq[i])==all.end() && i!=1)
    {
        c++;
    }

    return;

}



void solve()
{
    int n;
    cin>>n;

    vvi graph(n+1);
    int x,y;
    vvi edges;
    fr(i,0,n-1)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        edges.push_back({x,y});

    }
    vector<int> freq(n+1), freq_old(n+1), freq_new(n+1);
    fr(i,0,n)cin>>freq[i+1];

    fr(i,1,n+1)
    {
        freq_old[freq[i]]++;
    }

    set<int> all;
    fr(i,1,n+1)
    {
        if(freq_old[i]>0)all.insert(i);
    }

    vi visited(n+1,0);

    c = 0;
    
    dfs(1, visited, graph, freq_new, freq, all, freq_old);


    cout<<c;


}
    
 
// #undef int
signed main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
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