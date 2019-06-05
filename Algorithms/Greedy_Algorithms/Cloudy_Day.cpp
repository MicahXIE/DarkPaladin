#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

const long double PI = 3.1415926535897932384626433832795;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 1001000;

int n, m;
int p[N], x[N];
int y[N], r[N];

vector<pii> cities;
vector<pair<pii, int> > ranges;
map<int, vector<pii> > events;

ll bomber_pop[N];

int main(){
    sd(n);
    assert(1 <= n and n <= 1000000);

    for(int i = 1; i <= n; i++){
        sd(p[i]);
        assert(1 <= p[i] and p[i] <= 1000000000);
    }

    for(int i = 1; i <= n; i++){
        sd(x[i]);
        assert(1 <= x[i] and x[i] <= 1000000000);
    }

    for(int i = 1; i <= n; i++){
        events[x[i]].pb(mp(2, p[i]));
    }

    sd(m);
    assert(1 <= m and m <= 1000000);

    for(int i = 1; i <= m; i++){
        sd(y[i]);
        assert(1 <= y[i] and y[i] <= 1000000000);
    }

    for(int i = 1; i <= m; i++){
        sd(r[i]);
        assert(1 <= r[i] and r[i] <= 1000000000);
    }

    for(int i = 1; i <= m; i++){
        events[y[i]-r[i]].pb(mp(1, i));
        events[y[i]+r[i]+1].pb(mp(-1, i));
    }

    ll not_under_attack = 0;

    set<int> active;
    foreach(vv, events){
        int cord = vv->fi;
        vector<pii> &v = vv->se;
    
        sort(v.begin(), v.end());
    
        foreach(it, v){
            if(it->fi == -1){
                active.erase(it->se);
            }
            else if(it->fi == 1){
                active.insert(it->se);
            }
            else{
                if(active.size() == 1){
                    bomber_pop[*active.begin()] += it->se;  
                }
                else if(active.size() == 0){
                    not_under_attack += it->se;
                }
            }
        }
    }

    ll mx = 0;
    for(int i = 1; i <= m; i++){
        mx = max(mx, bomber_pop[i]);
    }

    printf("%lld\n", not_under_attack + mx);

    return 0;
}

