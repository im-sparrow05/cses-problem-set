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
    ll n,k;
    cin>>n>>k;
    vll nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    ll ans = 0;
    int i=0,j=0;
    ll sum = 0;
    while(j<n){
        sum += nums[j];
        if(sum==k){
            ans++;
        }
        else if(sum>k){
            while(i<=j){
                sum -= nums[i];
                i++;
                if(sum<=k){
                    if(sum==k){
                        ans++;
                    }
                    break;
                }
            }
        }
        j++;
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