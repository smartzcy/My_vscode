package org.example;

import java.util.Date;

/*
预约的订单
 */
public class Reservations {
    private String name;
    private int type;
    private int brand;
    private int food;
    private int day;
    private Date date;
    private Date now_date;

    private double price;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getType() {
        return type;
    }

    public void setType(int type) {
        this.type = type;
    }

    public int getBrand() {
        return brand;
    }

    public void setBrand(int brand) {
        this.brand = brand;
    }

    public int getFood() {
        return food;
    }

    public void setFood(int food) {
        this.food = food;
    }

    public int getDay() {
        return day;
    }

    public void setDay(int day) {
        this.day = day;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public Reservations(String name, int type, int brand, int food, int day, Date date, Date now_date) {
        this.name = name;
        this.type = type;
        this.brand = brand;
        this.food = food;
        this.day = day;
        this.date = date;
        this.now_date = now_date;
        setPrice();
    }

    private void setPrice() {
        if (this.brand == 0) {
            this.price = (this.day >= 3 ? 0.8 : 1) * this.day * LargeRoom.PRICES[this.type][this.food];
        } else if (this.brand == 1) {
            this.price = (this.day >= 3 ? 0.8 : 1) * this.day * DoubleRoom.PRICES[this.type][this.food];
        } else {
            this.price = (this.day >= 3 ? 0.8 : 1) * this.day * SuiteHouse.PRICES[this.type][this.food];
        }
    }

    public double getPrice() {
        return this.price;
    }

    public String getType_name() {
        if (this.brand == 0) {
            return LargeRoom.getTyp(this.type);
        } else if (this.brand == 1) {
            return DoubleRoom.getTyp(this.type);
        } else {
            return SuiteHouse.getTyp(this.type);
        }
    }

    public Date getNow_date() {
        return now_date;
    }

    public void setNow_date(Date now_date) {
        this.now_date = now_date;
    }
}