//https://codeforces.com/problemset/gymProblem/102644/A
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
double happy(ll time,double p)
{
    double h=1;
    while(time)
    {
        if(time&1)
        {
            h=p*(1-h)+h*(1-p);
        }
        p=p*(1-p)+(1-p)*p;
        //পরবর্তি স্টেটে চেঞ্জ হবার সম্ভাবনা = বর্তমান স্টেট চেঞ্জ হবার সম্ভাবনা*বর্তমানে অখুশি থাকার সম্ভাবনা+বর্তমান স্টেট চেঞ্জ না হবার সম্ভাবনা*বর্তমানে খুশি থাকার সম্ভাবনা।
        time>>=1;
    }return h;
}
int32_t main()
{
    fast
    ll i,j,n,m,k,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        double p;
        cin>>n>>p;
        cout<<fixed<<setprecision(12)<<happy(n,p)<<endl;
    }
}
//এটা errichto র একটা ব্লগের কোশ্চেন। এখানে binary exponentiation ব্যাবহার করে প্রোবাবিলিটি ক্যালকুলেট করা শেখানো হয়েছে।
