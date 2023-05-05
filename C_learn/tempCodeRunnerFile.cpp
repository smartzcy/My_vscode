class Employee {
protected:
    string name; // 姓名

public:
    Employee(string n) :
        name(n) {
    }                              // 有参构造函数
    virtual void show() = 0;       // 纯虚函数
    virtual double earnings() = 0; // 纯虚函数
    string getName() {
        return name;
    }
};

// 老板类
class Boss : public Employee {
private:
    double weeklySalary; // 固定周工资

public:
    Boss(string n, double s) :
        Employee(n), weeklySalary(s) {
    } // 有参构造函数
    void setWeeklySalary(double s) {
        weeklySalary = s;
    } // 更改器函数
    void show() {
        cout << "Boss: " << name << endl;
        cout << "Earned: $" << weeklySalary << endl;
    }
    double earnings() {
        return weeklySalary;
    } // 计算周收入
};

// 销售员类
class CommissionWorker : public Employee {
private:
    double salary;     // 工资
    double commission; // 销售提成
    int quantity;      // 销售数量

public:
    CommissionWorker(string n, double s, double c, int q) :
        Employee(n), salary(s), commission(c), quantity(q) {
    } // 有参构造函数
    void setSalary(double s) {
        salary = s;
    } // 更改器函数
    void setCommission(double c) {
        commission = c;
    } // 更改器函数
    void setQuantity(int q) {
        quantity = q;
    } // 更改器函数
    void show() {
        cout << "Commission Worker: " << name << endl;
        cout << "Earned: $" << salary << endl;
    }
    double earnings() {
        return salary + salary * commission / 100 * quantity;
    } // 计算收入
};

// 计件工人类
class PieceWorker : public Employee {
private:
    double wagePerPiece; // 每件产品工资
    int quantity;        // 生产数量

public:
    PieceWorker(string n, double w, int q) :
        Employee(n), wagePerPiece(w), quantity(q) {
    } // 有参构造函数
    void setWage(double w) {
        wagePerPiece = w;
    } // 更改器函数
    void setQuantity(int q) {
        quantity = q;
    } // 更改器函数
    void show() {
        cout << "Piece Worker: " << name << endl;
        cout << "Earned: $" << wagePerPiece << endl;
    }
    double earnings() {
        return wagePerPiece * quantity;
    } // 计算收入
};

// 小时工人类
class HourlyWorker : public Employee {
private:
    double wage;  // 小时工资
    double hours; // 工作时数

public:
    HourlyWorker(string n, double w, double h) :
        Employee(n), wage(w), hours(h) {
    } // 有参构造函数
    void setWage(double w) {
        wage = w;
    } // 更改器函数
    void setHours(double h) {
        hours = h;
    } // 更改器函数
    void show() {
        cout << "Hourly Worker: " << name << endl;
        cout << "Earned: $" << wage << endl;
    }
    double earnings() {
        return wage * hours + (hours > 40 ? (hours - 40) * wage * 0.5 : 0);
    } // 计算收入（含加班工资）
};