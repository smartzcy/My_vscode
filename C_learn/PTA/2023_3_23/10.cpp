#include <iostream>
#include "vector"
#include "set"
#include <map>
#include "queue"
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9;
int n, m, k;
struct node {
    string str;
    map<string, int> s;
    map<string, int> wen;
    vector<node *> vec;
};
void Print(node *root, int deep) {
    for (int i = 0; i < deep; i++) cout << "  ";
    cout << root->str << endl;
    for (auto i : root->s) {
        Print(root->vec[i.second], deep + 1);
    }
    for (auto i : root->wen) {
        Print(root->vec[i.second], deep + 1);
    }
}
int main() {
    cin >> n;
    node *root = new node();
    root->str = "root";
    while (n--) {
        int flag = 0;
        string str, s = "";
        cin >> str;
        node *now;
        for (auto i : str) {
            if (i != '\\') {
                s += i;
            } else {
                flag++;
                if (flag == 1) {
                    if (root->s.empty() || root->s.find(s) == root->s.end()) {
                        node *temp = new node();
                        temp->str = s;
                        root->vec.push_back(temp);
                        root->s[s] = root->vec.size() - 1;
                        now = temp;
                    } else {
                        now = root->vec[root->s[s]];
                    }
                } else {
                    if (now->s.empty() || now->s.find(s) == now->s.end()) {
                        node *temp = new node();
                        temp->str = s;
                        now->vec.push_back(temp);
                        now->s[s] = now->vec.size() - 1;
                        now = temp;
                    } else {
                        now = now->vec[now->s[s]];
                    }
                }
                s = "";
            }
        }
        if (s != "") {
            if (flag == 0) {
                if (root->wen.empty() || root->wen.find(s) == root->wen.end()) {
                    node *temp = new node();
                    temp->str = s;
                    root->vec.push_back(temp);
                    root->wen[s] = root->vec.size() - 1;
                }
            } else {
                if (now->wen.empty() || now->wen.find(s) == now->wen.end()) {
                    node *temp = new node();
                    temp->str = s;
                    now->vec.push_back(temp);
                    now->wen[s] = now->vec.size() - 1;
                }
            }
        }
    }
    Print(root, 0);
}