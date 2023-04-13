public class Loan {
    private double annualInterestRate;
    private int numverOfYears;
    private double loanAmount;

    public double getAnnualInterestRate() {
        return annualInterestRate;
    }

    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
    }

    public int getNumverOfYears() {
        return numverOfYears;
    }

    public void setNumverOfYears(int numverOfYears) {
        this.numverOfYears = numverOfYears;
    }

    public double getLoanAmount() {
        return loanAmount;
    }

    public void setLoanAmount(double loanAmount) {
        this.loanAmount = loanAmount;
    }

    private java.util.Date loanDate;

    public Loan(double annualInterestRate, int numverOfYears, double loanAmount) {
        this.annualInterestRate = annualInterestRate;
        this.numverOfYears = numverOfYears;
        this.loanAmount = loanAmount;
        loanDate = new java.util.Date();
    }

    public Loan() {

    }

    public double getMonthlyPayment() {
        double monthlyInterestRate = annualInterestRate / 1200;
        double monthlyPayment = loanAmount * monthlyInterestRate
                / (1 - (1 / Math.pow(1 + monthlyInterestRate, numverOfYears * 12)));
        return monthlyPayment;
    }

    public double getTotalPayment() {
        double totalPayment = getMonthlyPayment() * numverOfYears * 12;
        return totalPayment;
    }

    public java.util.Date getLoanDate() {
        return loanDate;
    }
}
