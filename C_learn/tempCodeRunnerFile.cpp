#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 读取输入文件数据
    ifstream fin("gpa.dat");
    string line;
    vector<pair<string, double>> students;

    while (getline(fin, line)) {
        if (line.empty()) continue;
        string name = line;
        getline(fin, line);
        if (line.empty()) continue;

        int n = stoi(line);
        double total_grade = 0;
        double total_credit = 0;
        for (int i = 0; i < n; ++i) {
            getline(fin, line);
            if (line.empty()) continue;
            int credit = stoi(line.substr(0, 1));
            double grade = stod(line.substr(2));
            total_grade += credit * grade;
            total_credit += credit;
        }
        double gpa = total_credit > 0 ? total_grade / total_credit : 0;
        students.emplace_back(name, gpa);
    }

    // 计算加权平均分的最大值和最小值
    double max_gpa = 0;
    double min_gpa = 4.0;
    for (const auto &student : students) {
        cout << "GPA for " << student.first << " = " << student.second << endl;
        max_gpa = max(max_gpa, student.second);
        min_gpa = min(min_gpa, student.second);
    }
    cout << "max GPA = " << max_gpa << endl;
    cout << "min GPA = " << min_gpa << endl;
    return 0;
}