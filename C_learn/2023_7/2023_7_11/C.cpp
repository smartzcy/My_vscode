#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int A, B, C;
double dp[110][110][110];
double dfs(int x, int y, int z) {
    if (x >= 100 || y >= 100 || z >= 100) return 0;
    if (dp[x][y][z] > 0) return dp[x][y][z];
    dp[x][y][z] = 1.0;
    dp[x][y][z] += 1.0 * x / (x + y + z) * dfs(x + 1, y, z);
    dp[x][y][z] += 1.0 * y / (x + y + z) * dfs(x, y + 1, z);
    dp[x][y][z] += 1.0 * z / (x + y + z) * dfs(x, y, z + 1);
    return dp[x][y][z];
}
int main() {
    cin >> A >> B >> C;
    printf("%.10f\n", dfs(A, B, C));
}