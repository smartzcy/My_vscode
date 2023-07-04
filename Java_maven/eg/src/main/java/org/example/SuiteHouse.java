package org.example;

public class SuiteHouse extends House {
    static double[][] PRICES = { { 1500, 1600 }, { 2000, 2100 }, { 2500, 2600 } };
    public boolean[] is_reservation = new boolean[7];

    public SuiteHouse(int type) {
        setTypes(type);
    }

    @Override
    public double RecentFee(int days) {
        double money = days * getPrice();
        if (days >= 3)
            return 0.8 * money;
        else
            return money;
    }

    @Override
    public boolean getReservation(int j) {
        return this.is_reservation[j];
    }

    @Override
    public void setReservation(int k, boolean b) {
        this.is_reservation[k] = b;
    }

    @Override
    public String getType() {
        if (getTypes() == 0)
            return "景致小套房";
        else if (getTypes() == 1)
            return "婴儿小套房";
        else
            return "亲子大套房";
    }

    public static String getTyp(int typ) {
        if (typ == 0)
            return "景致小套房";
        else if (typ == 1)
            return "婴儿小套房";
        else
            return "亲子大套房";
    }

    @Override
    public double[][] getPrices() {
        return PRICES;
    }
}