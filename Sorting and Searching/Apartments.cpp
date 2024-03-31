#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
#define vi vector<int>
#define vll vector<ll>
#define ln "\n" 
#define INF LLONG_MAX
#define MOD 1000000007
#define MIN_IN(A) *(std::min_element(A.begin(), A.end()));
#define MAX_IN(A) *(std::max_element(A.begin(), A.end()));
#define MAX_AT(A) (std::max_element(A.begin(), A.end()) - A.begin());
#define MIN_AT(A) (std::min_element(A.begin(), A.end()) - A.begin());
#define GCD(a,b) std::__gcd(a,b);
#define LCM(a,b) (a)*((b)/std::__gcd(a,b));
#define SORT(A) std::sort(A.begin(), A.end());
#define RSORT(A) std::sort(A.rbegin(), A.rend());
#define REVERSE(A) std::reverse(A.begin(), A.end());

////------------------------------------sieve of Eratosthenes-----------------------------------------------//
// vi sieve(int n) {
//     vi primes(n + 1, true);
//     primes[0] = primes[1] = false;
//     for (int i = 2; i * i <= n; ++i) {
//         if (primes[i]) {
//             for (int j = i * i; j <= n; j += i) {
//                 primes[j] = false;
//             }
//         }
//     }
//     vi result;
//     for (int i = 2; i <= n; ++i) {
//         if (primes[i]) {
//             result.push_back(i);
//         }
//     }
//     return result;
// }

////////----------------sort vector<pair<ll,ll>> decending order on 1st element --------------------//////
// static bool mycmp(pair<ll,ll>& a,pair<ll,ll>& b){
//     if(a.first==b.first){
//         return a.second<b.second;
//     }
//     return a.first>b.first;
// }


///////-------------------------return a^b % MOD  -----------------------------------////////////////
// ll power(ll a, ll b) {
//         ll res = 1;
//         while (b > 0) {
//             if (b & 1)   // check least significant bit
//                 res = (res * a)%MOD;
//             a = (a * a)%MOD;   // preparing for next a
//             b >>= 1;
//         }
//         return res;
//     }

// -------------avoid collision in unordered set and map------------//////////
// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };

void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    vll stud(n);
    vll appart(m);
    for(int i=0;i<n;i++){
        cin>>stud[i];
    }
    for(int i=0;i<m;i++){
        cin>>appart[i];
    }
    SORT(stud);
    SORT(appart);
    ll ans = 0;
    int i=0,j=0;
    
    while(i<n && j<m){
        ll a1 = appart[j]-k;
        ll a2 = appart[j]+k;
        
        if(stud[i]<= a2 && stud[i]>=a1){
            i++;
            j++;
            ans++;
        }
        else if(a2<stud[i]){
            j++;
        }
        else if(a1>stud[i]){
            i++;
        }
    }
    
    cout<<ans<<ln;
    
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    
    while(t!=0){
        
    	solve();

    	t--;
    }
}