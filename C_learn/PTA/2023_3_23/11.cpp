#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e6 + 10;
const int INF = 1e9;
int n, m;
map<string, int> map1;
int main() {
    cin >> n;
    getchar();
    while (n--) {
        set<string> se;
        queue<int> que;
        string str;
        getline(cin, str);
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '#') {
                if (!que.empty()) {
                    int num = que.front();
                    que.pop();
                    string s = str.substr(num, i - num + 1);
                    string s1;
                    for (auto j : s) {
                        if (j <= 'z' && j >= 'a')
                            s1 += j;
                        else if (j <= 'Z' && j >= 'A')
                            s1 += (j - 'A' + 'a');
                        else if (j == ' ')
                            s1 += " ";
                        else if (j <= '9' && j >= '0')
                            s1 += j;
                    }
                    if (se.find(s1) == se.end()) map1[s1]++;
                    se.insert(s1);
                } else {
                    que.push(i);
                }
            }
        }
    }
    int maxx = 0, flag = 0;
    string maxx_str;
    for (auto i : map1) {
        if (maxx < i.second) {
            maxx = i.second;
            maxx_str = i.first;
            flag = 0;
        } else if (maxx == i.second) {
            flag++;
        }
    }
    cout << (char)(maxx_str[0] - 'a' + 'A') << maxx_str.substr(1) << endl;
    cout << maxx << endl;
    if (flag != 0) cout << "And " << flag << " more ..." << endl;
}