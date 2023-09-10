# 基本算法

## 贪心

区间覆盖问题

给出 $m$ 个区间，选出最少的区间个数覆盖 1 ~~ n

```cpp
struct node {
    int l, r;
    bool operator<(const node &t) const {
        return l < t.l;
    }
};
int main() {
    vector<node> ve;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        ve.pushk({l, r});
    }
    sort(ve.begin(), ve.end());
    int s = 1;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int tmp = 0;
        int j = i;
        while (ve[j].l <= s && j <= m - 1) tmp = max(tmp, ve[j++].r);
        // 这里根据题目情况而定，有可能是s=tmp
        s = tmp + 1;
        ans++;
        i = j - 1;
        if (s > m) break;
    }
    cout << ans << endl;
    return 0;
}

```



## 快速幂 + 龟速乘

```cpp
long long ksc(long long x, long long k) {
    long long res = 0;
    while (k) {
        if (k & 1) res = (res + x) % mod;
        k >>= 1;
        x = (x + x) % mod;
    }
    return res;
}
long long qm(long long x, long long k) {
    long long res = 1;
    while (k) {
        if (k & 1) res = ksc(res, x);
        k >>= 1;
        x = ksc(x, x);
    }
    return (long long)res;
}
```

## ST表

```cpp
int f[N][20]; // f[i][j]表示i开始的2^j个数的最大值
int n, q;
void init() {
    for (int i = 1; i <= n; i++) f[i][0] = a[i];
    int t = __lg(n) + 1;
    for (int j = 1; j < t; ++j) {
        for (int i = 1; i <= n - (1 << j) + 1; ++i) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int ask(int l, int r) {
    int k = __lg(r - l + 1);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

```

## 数学

### 区间互质

```cpp
namespace qjhz {
long long T, N, num;
long long A, B;
long long a[100];
void prime(long long n) {
    num = 0;
    for (long long i = 2; i * i <= n; i++) {
        if ((n % i) == 0) {
            num++;
            a[num] = i;
            while ((n % i) == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        num++;
        a[num] = n;
    }
    return;
}
long long solve(long long r, long long n) {
    prime(n);
    long long res = 0;
    for (long long i = 1; i < (1 << num); i++) {
        long long kk = 0;
        long long div = 1;
        for (long long j = 1; j <= num; j++) {
            if (i & (1 << (j - 1))) {
                kk++;
                div *= a[j];
            }
        }
        if (kk % 2)
            res += r / div;
        else
            res -= r / div;
    }
    return r - res;
}

long long que(long long L, long long R, long long k) {
    return solve(R, k) - solve(L - 1, k);
}

```

### 指数取模

![](D:\VScode\Markdown\2023-08-20-00-28-38-image.png)

### 欧拉函数

![](D:\VScode\Markdown\2023-08-20-00-30-41-image.png)

```cpp
void solve(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) p[tot++] = i, phi[i] = i - 1;
        for (int j = 0; p[j] <= n / i; ++j) {
            st[p[j] * i] = true;
            if (i % p[j] == 0) {
                phi[i * p[j]] = phi[i] * p[j];
                break;
            }
            phi[i * p[j]] = phi[i] * (p[j] - 1);
        }
    }
}
```

### exgcd求逆元

```cpp
void exgcd(int a, int b, int &x, int &y) {
    if (!b)
        x = 1, y = 0;
    else {
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}
int main() {
    int a, b, x, y;
    scanf("%d%d", &a, &b);
    exgcd(a, b, x, y);
    printf("%d", (x % b + b) % b);
    return 0;
}
```

### 递推法求逆元

```cpp
inv[i]=(mod-mod/i)*inv[mod%i]%mod (其中mod为模数，要求为奇质数
```

### 卢卡斯定理

```cpp
int qmi(int x, int k) {
    int res = 1;
    while (k) {
        if (k & 1) res = 1ll * res * x % mod;
        k >>= 1;
        x = 1ll * x * x % mod;
    }
    return res;
}
int C(int n, int m) {
    if (m > n) return 0;
    return 1ll * f[n] * qmi(f[m], mod - 2) % mod * qmi(f[n - m], mod - 2) % mod;
}
int lucas(long long n, long long m) {
    if (!m) return 1;
    return 1ll * C(n % mod, m % mod) * lucas(n / mod, m / mod) % mod;
}
void init() {
    f[0] = 1;
    for (int i = 1; i <= mod; i++) {
        f[i] = 1ll * f[i - 1] * i % mod;
    }
}

```

### 判断质数

```cpp
int isPrime(int n) { // 返回1表示判断为质数，0为非质数，在此没有进行输入异常检测
    float n_sqrt;
    if (n == 2 || n == 3) return 1;
    if (n % 6 != 1 && n % 6 != 5) return 0;
    n_sqrt = floor(sqrt((float)n));
    for (int i = 5; i <= n_sqrt; i += 6) {
        if (n % (i) == 0 | n % (i + 2) == 0) return 0;
    }
    return 1;
}


```

### 欧拉筛

```cpp
void prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) p[ans++] = i;
        for (int j = 0; p[j] <= n / i; j++) {
            st[p[j] * i] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

```

### 点到线段的最短距离

```cpp
typedef struct node {
    double x, y;
} Point;
double getDis2(Point a, Point b) // 得到两点距离的平方
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double disMin(Point A, Point B, Point P) {
    double r = ((P.x - A.x) * (B.x - A.x) + (P.y - A.y) * (B.y - A.y)) / getDis2(A, B);
    if (r <= 0)
        return sqrt(getDis2(A, P)); // 第一种情况, 返回AP的长
    else if (r >= 1)
        return sqrt(getDis2(B, P)); // 第二种情况, 返回BP的长度
    else                            // 第三种情况, 返回PC的长度
    {
        double AC = r * sqrt(getDis2(A, B));  // 先求AC的长度,(AC=r*|AB|)
        return sqrt(getDis2(A, P) - AC * AC); // 再勾股定理返回PC的长度
    }
}
```

### 二维几何

```cpp
const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);
const int maxp = 1010;
//`Compares a double to zero`
int sgn(double x) {
    if (fabs(x) < eps) return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}
// square of a double
inline double sqr(double x) {
    return x * x;
}
struct Point {
    double x, y;
    Point() {
    }
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }
    void input() {
        scanf("%lf%lf", &x, &y);
    }
    void output() {
        printf("%.2f %.2f\n", x, y);
    }
    bool operator==(Point b) const {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }
    bool operator<(Point b) const {
        return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;
    }
    Point operator-(const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
    // 叉积
    double operator^(const Point &b) const {
        return x * b.y - y * b.x;
    }
    // 点积
    double operator*(const Point &b) const {
        return x * b.x + y * b.y;
    }
    // 返回长度
    double len() {
        return hypot(x, y); // 库函数
    }
    // 返回长度的平方
    double len2() {
        return x * x + y * y;
    }
    // 返回两点的距离
    double distance(Point p) {
        return hypot(x - p.x, y - p.y);
    }
    Point operator+(const Point &b) const {
        return Point(x + b.x, y + b.y);
    }
    Point operator*(const double &k) const {
        return Point(x * k, y * k);
    }
    Point operator/(const double &k) const {
        return Point(x / k, y / k);
    }
    //`计算pa  和  pb 的夹角`
    //`就是求这个点看a,b 所成的夹角`
    //`测试 LightOJ1203`
    double rad(Point a, Point b) {
        Point p = *this;
        return fabs(atan2(fabs((a - p) ^ (b - p)), (a - p) * (b - p)));
    }
    //`化为长度为r的向量`
    Point trunc(double r) {
        double l = len();
        if (!sgn(l)) return *this;
        r /= l;
        return Point(x * r, y * r);
    }
    //`逆时针旋转90度`
    Point rotleft() {
        return Point(-y, x);
    }
    //`顺时针旋转90度`
    Point rotright() {
        return Point(y, -x);
    }
    //`绕着p点逆时针旋转angle`
    Point rotate(Point p, double angle) {
        Point v = (*this) - p;
        double c = cos(angle), s = sin(angle);
        return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
    }
};

struct Line {
    Point s, e;
    Line() {
    }
    Line(Point _s, Point _e) {
        s = _s;
        e = _e;
    }
    bool operator==(Line v) {
        return (s == v.s) && (e == v.e);
    }
    //`根据一个点和倾斜角angle确定直线,0<=angle<pi`
    Line(Point p, double angle) {
        s = p;
        if (sgn(angle - pi / 2) == 0) {
            e = (s + Point(0, 1));
        } else {
            e = (s + Point(1, tan(angle)));
        }
    }
    // ax+by+c=0
    Line(double a, double b, double c) {
        if (sgn(a) == 0) {
            s = Point(0, -c / b);
            e = Point(1, -c / b);
        } else if (sgn(b) == 0) {
            s = Point(-c / a, 0);
            e = Point(-c / a, 1);
        } else {
            s = Point(0, -c / b);
            e = Point(1, (-c - a) / b);
        }
    }
    void input() {
        s.input();
        e.input();
    }
    void adjust() {
        if (e < s) swap(s, e);
    }
    // 求线段长度
    double length() {
        return s.distance(e);
    }
    //`返回直线倾斜角 0<=angle<pi`
    double angle() {
        double k = atan2(e.y - s.y, e.x - s.x);
        if (sgn(k) < 0) k += pi;
        if (sgn(k - pi) == 0) k -= pi;
        return k;
    }
    //`点和直线关系`
    //`1  在左侧`
    //`2  在右侧`
    //`3  在直线上`
    int relation(Point p) {
        int c = sgn((p - s) ^ (e - s));
        if (c < 0)
            return 1;
        else if (c > 0)
            return 2;
        else
            return 3;
    }
    // 点在线段上的判断
    bool pointonseg(Point p) {
        return sgn((p - s) ^ (e - s)) == 0 && sgn((p - s) * (p - e)) <= 0;
    }
    //`两向量平行(对应直线平行或重合)`
    bool parallel(Line v) {
        return sgn((e - s) ^ (v.e - v.s)) == 0;
    }
    //`两线段相交判断`
    //`2 规范相交`
    //`1 非规范相交`
    //`0 不相交`
    int segcrossseg(Line v) {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        int d3 = sgn((v.e - v.s) ^ (s - v.s));
        int d4 = sgn((v.e - v.s) ^ (e - v.s));
        if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2) return 2;
        return (d1 == 0 && sgn((v.s - s) * (v.s - e)) <= 0) || (d2 == 0 && sgn((v.e - s) * (v.e - e)) <= 0) || (d3 == 0 && sgn((s - v.s) * (s - v.e)) <= 0) || (d4 == 0 && sgn((e - v.s) * (e - v.e)) <= 0);
    }
    //`直线和线段相交判断`
    //`-*this line   -v seg`
    //`2 规范相交`
    //`1 非规范相交`
    //`0 不相交`
    int linecrossseg(Line v) {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        if ((d1 ^ d2) == -2) return 2;
        return (d1 == 0 || d2 == 0);
    }
    //`两直线关系`
    //`0 平行`
    //`1 重合`
    //`2 相交`
    int linecrossline(Line v) {
        if ((*this).parallel(v))
            return v.relation(s) == 3;
        return 2;
    }
    //`求两直线的交点`
    //`要保证两直线不平行或重合`
    Point crosspoint(Line v) {
        double a1 = (v.e - v.s) ^ (s - v.s);
        double a2 = (v.e - v.s) ^ (e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }
    // 点到直线的距离
    double dispointtoline(Point p) {
        return fabs((p - s) ^ (e - s)) / length();
    }
    // 点到线段的距离
    double dispointtoseg(Point p) {
        if (sgn((p - s) * (e - s)) < 0 || sgn((p - e) * (s - e)) < 0)
            return min(p.distance(s), p.distance(e));
        return dispointtoline(p);
    }
    //`返回线段到线段的距离`
    //`前提是两线段不相交，相交距离就是0了`
    double dissegtoseg(Line v) {
        return min(min(dispointtoseg(v.s), dispointtoseg(v.e)), min(v.dispointtoseg(s), v.dispointtoseg(e)));
    }
    //`返回点p在直线上的投影`
    Point lineprog(Point p) {
        return s + (((e - s) * ((e - s) * (p - s))) / ((e - s).len2()));
    }
    //`返回点p关于直线的对称点`
    Point symmetrypoint(Point p) {
        Point q = lineprog(p);
        return Point(2 * q.x - p.x, 2 * q.y - p.y);
    }
};

```


