#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class modulo
{
    static ll P, Q, R; static bool no_prime_mod_check; ll val;
 
    modulo& normalize(const ll x)
    {
        if (not P)
            domain_error("uninitialized mod");
 
        if ((val = x%P) < 0)
            val += P;
 
        return *this;
    }
 
    bool valid_base(ll p) const
    {
        if (val == 0)
        {
            if (p <= 0)
                throw domain_error("0^p and p <= 0");
        }
 
        return val > 1;
    }
 
    static void validate_exponent(ll& p)
    {
        if (p >= 0)
            return;
 
        if ((p = -p) <= R)
            p *= Q;
        else
            throw range_error("x^p exponent (p) is out-of-range");
    }
 
public:
    modulo(ll x = 0) { normalize(x); }
 
    static int  mod() { return P; }
 
    static void mod(ll p)
    {
        if (p < 3)
            domain_error(to_string(p)+" is an invalid mod");
 
        P = p, Q = p-2, R = LLONG_MAX/Q;
 
        /*if (no_prime_mod_check)
            return;
 
        for (ll q = sqrt(p), x = 2; x <= q; ++x)
            if (p%x == 0)
                domain_error(to_string(p)+" is non-prime, divisible by "+to_string(x));*/
 
    }
 
    ll operator () () const { return val; }
 
    modulo& operator  =(ll x) { return normalize(x); }
 
    modulo& operator  =(const modulo& x) { val  = x.val; return *this; }
 
    modulo& operator +=(const modulo& x) { ll z = val; return normalize(z+x.val); }
    modulo& operator -=(const modulo& x) { ll z = val; return normalize(z-x.val); }
    modulo& operator *=(const modulo& x) { ll z = val; return normalize(z*x.val); }
 
    friend modulo operator ^(modulo x,ll p) /// power operator x^p
    {
        modulo y = 1;
 
        if (x.valid_base(p))
            for (validate_exponent(p); p > 0; p >>= 1, x *= x)
                if (p&1)
                    y *= x;
 
        return y;
    }

    modulo& operator /=(modulo x) { return *this *= x^Q; }
 
    modulo& operator +=(ll x) { return *this += modulo(x); }
    modulo& operator -=(ll x) { return *this -= modulo(x); }
    modulo& operator *=(ll x) { return *this *= modulo(x); }
    modulo& operator /=(ll x) { return *this /= modulo(x); }
 
    modulo& operator ++() { return *this += 1; }
    modulo& operator --() { return *this -= 1; }
 
    modulo operator ++(int unused) { modulo z(*this); ++*this; return z; }
    modulo operator --(int unused) { modulo z(*this); --*this; return z; }
 
    friend modulo operator +(modulo x, const modulo& y) { return x += y; }
    friend modulo operator *(modulo x, const modulo& y) { return x *= y; }
    friend modulo operator -(modulo x, const modulo& y) { return x -= y; }
    friend modulo operator /(modulo x, const modulo& y) { return x /= y; }
 
    friend modulo operator +(modulo x, ll y) { return x += y; }
    friend modulo operator *(modulo x, ll y) { return x *= y; }
    friend modulo operator -(modulo x, ll y) { return x -= y; }
    friend modulo operator /(modulo x, ll y) { return x /= y; }
 
    friend modulo operator +(ll x, modulo y) { return y += x; }
    friend modulo operator *(ll x, modulo y) { return y *= x; }
 
    friend modulo operator -(ll x, const modulo& y) { modulo z(x); return z -= y; }
    friend modulo operator /(ll x, const modulo& y) { modulo z(x); return z /= y; }
 
    bool operator  <(const modulo& x) const { return val <  x.val; }
    bool operator ==(const modulo& x) const { return val == x.val; }
    bool operator  >(const modulo& x) const { return val >  x.val; }
    bool operator !=(const modulo& x) const { return val != x.val; }
    bool operator <=(const modulo& x) const { return val <= x.val; }
    bool operator >=(const modulo& x) const { return val >= x.val; }
 
    bool operator  <(ll x) const { return val <  x; }
    bool operator ==(ll x) const { return val == x; }
    bool operator  >(ll x) const { return val >  x; }
    bool operator !=(ll x) const { return val != x; }
    bool operator <=(ll x) const { return val <= x; }
    bool operator >=(ll x) const { return val >= x; }
 
    friend istream& operator >> (istream& input, modulo &x)
    {
        ll z; input >> z, x.normalize(z); return input;
    }
 
    friend ostream& operator << (ostream& output, const modulo& x)
    {
        return output << x.val;
    }
 
    class factorial: vector<modulo>
    {
        void lazy_evaluation(int n)
        {
            for (ll p = size(); n >= p; ++p)
                push_back(back()*p);
        }
 
    public:
 
        factorial() { push_back(1); }
 
        ll binomial_coefficient(ll n, ll m)
        {
            if (n < 0 or m < 0 or m > n)
                return 0;
 
            if (m == 0 or m == n)
                return 1;
 
            if (n >= P and n <= (m+P-1))
                return 0;
 
            lazy_evaluation(n); auto z = at(n)/(at(m)*at(n-m)); return z();
        }
 
        modulo operator [](ll n)
        {
            lazy_evaluation(n); return at(n);
        }
    };
};
ll modulo::P, modulo::Q, modulo::R; bool modulo::no_prime_mod_check;

#define M 1000000007

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> arr(n);
        for(auto &x : arr)
            cin >> x;
        vector<int> bits(61);
        for(ll x : arr) {
            for(int i = 0; i <= 60; i++) {
                bits[i] += (((1LL << i) & x) != 0);
            }
        }

        ll ans = 0;
        for(int i = 0; i < n; i++) {
            ll andValue = 0;
            for(int j = 0; j <= 60; j++) {
                if(!((1LL << j) & arr[i])) continue;
                andValue += ((1LL << j)%M * bits[j]%M)%M;
                andValue %= M;
            }

            ll orValue = 0;
            for(int j = 0; j <= 60; j++) {
                if((1LL << j) & arr[i]) {
                    orValue += ((1LL << j)%M * n%M)%M;
                } else {
                    orValue += ((1LL << j)%M * bits[j]%M)%M;
                }
                orValue %= M;
            }

            ans += (andValue * orValue)%M;
        }
        
        cout << (ans)%M << "\n";
    }
    
    return 0;
}