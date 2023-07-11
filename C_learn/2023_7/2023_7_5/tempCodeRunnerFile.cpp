
#include <cmath>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
long long n, m, ans, sq;
long long a[N], id[N], an[N], b[N];
struct query {
    int ql, qr, Id;
    bool operator<(const query &o) const {
        if (id[ql] == id[o.ql]) {
            if (id[ql] % 2)
                return qr < o.qr;
            else