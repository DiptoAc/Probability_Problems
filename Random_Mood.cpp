//https://codeforces.com/gym/102644/problem/B
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl;
#define endl '\n'
const ll M =1e9+7;
const ll N =1e6;
struct mat
{
    ll a,b,c,d;
    mat(ll p,ll q,ll r,ll s)
    {
        a=p;
        b=q;
        c=r;
        d=s;
    }
};
mat unit(1,0,0,1);
mat multiply(mat a,mat b)
{
    mat ans=unit;
    ans.a=a.a*b.a+a.b*b.c;ans.a%=M;
    ans.b=a.a*b.b+a.b*b.d;ans.b%=M;
    ans.c=a.c*b.a+a.d*b.c;ans.c%=M;
    ans.d=a.c*b.b+a.d*b.d;ans.d%=M;
    return ans;
}
ll happy(ll n)
{
    mat ans=unit,a(19,7,6,20);
    while(n)
    {
        if(n&1)
        {
            ans=multiply(ans,a);
        }
        a=multiply(a,a);
        n>>=1;
    }return ans.a;
}
int32_t main()
{
    fast
    ll i,j,n,m,k,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n;
        cout<<happy(n)<<endl;
    }
}
//এটা errichto র একটা ব্লগের কোশ্চেন। এটা matrix exponetiation এর প্রবলেম হলেও কিভাবে ম্যাট্রিক্স ক্যালকুলেট করা হইছে, সেটা বুঝতেছিনা
।
