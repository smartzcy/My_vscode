package org.example;

import java.util.Date;

public abstract class House {
    private String brand; // 租房的类型
    private double price; // 租房的单价
    private int days; // 租出去的时间
    private boolean food; // 是否早饭
    private double payMoney; // 实际付钱
    private Date date; // 出租时间
    private int type;

    public House() {

    }

    public int getTypes() {
        return type;
    }

    public void setTypes(int type) {
        this.type = type;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public int getDays() {
        return days;
    }

    public void setDays(int days) {
        this.days = days;
    }

    public boolean getFood() {
        return food;
    }

    public void setFood(boolean food) {
        this.food = food;
    }

    public double getPayMoney() {
        return payMoney;
    }

    public void setPayMoney(double payMoney) {
        this.payMoney = payMoney;
    }

    public abstract double RecentFee(int days);

    public String getBrand() {
        return brand;
    }

    public abstract boolean getReservation(int j);

    public abstract void setReservation(int k, boolean b);

    public abstract String getType();

    public abstract double[][] getPrices();
}