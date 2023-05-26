
import java.util.*;

public class App {
    public static void main(String[] args) {
        Account account1 = new Account("George", 1122, 1000.00);
        account1.setAnnualInterestRate(1.5);
        account1.deposit(30);
    }
}

class Account {
    private String name;
    private int id;
    private double balance;
    private double annualInterestRate;
    private Date dateCreated;
    private Transaction[][] transaction = new Transaction[2000][2000];
    private int[] numlist = new int[2000];

    public Account() {
        this.id = 0;
        this.balance = 0;
        this.annualInterestRate = 0;
        this.dateCreated = new Date();
    }

    public Account(int id, double balance) {
        this.id = id;
        this.balance = balance;
    }

    public Account(String name, int id, double balance) {
        this.name = name;
        this.id = id;
        this.balance = balance;
    }

    public void setId(int ID) {
        this.id = ID;
    }

    public int getId() {
        return id;
    }

    public void setBalance(double Input) {
        balance = Input;
    }

    public double getBalance() {
        return balance;
    }

    public void setAnnualInterestRate(double Input) {
        annualInterestRate = Input;
    }

    public double getAnnualInterestRate() {
        return annualInterestRate;
    }

    public Date getDateCreaterd() {
        return dateCreated;
    }

    public double getMonthlyInterestRate() {
        return annualInterestRate / 100 / 12;
    }

    public double getMonthlyInterest() {
        return balance * annualInterestRate / 100 / 12;
    }

    public void withDraw(double take) {
        balance = balance - take;
        transaction[id][numlist[id]].set(dateCreated, 'W', take, balance, "The " + id + " account withdraw " + take);
        numlist[id]++;
    }

    public void deposit(double Input) {
        balance = balance + Input;
        transaction[id][numlist[id]].set(dateCreated, 'D', Input, balance, "The " + id + " account deposits " + Input);
        numlist[id]++;
    }

    public int getNumlist(int ID) {
        return numlist[ID];
    }

    public String getName() {
        return name;
    }
}

class Transaction {
    private Date date;
    private char type;
    private double amount;
    private double balance;
    private String description;

    public void set(Date date, char type, double amount, double balance, String description) {
        this.date = date;
        this.type = type;
        this.amount = amount;
        this.balance = balance;
        this.description = description;
    }
}