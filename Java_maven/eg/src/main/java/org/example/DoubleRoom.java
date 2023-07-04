package org.example;

public class DoubleRoom extends House {

    static double[][] PRICES = { { 600, 700 }, { 800, 900 }, { 1000, 1100 } };
    public boolean[] is_reservation = new boolean[7];

    public DoubleRoom(int type) {
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
            return "标准双床房";
        else if (getTypes() == 1)
            return "高级双床房";
        else
            return "豪华双床房";
    }

    @Override
    public double[][] getPrices() {
        return PRICES;
    }

    public static String getTyp(int typ) {
        if (typ == 0)
            return "标准双床房";
        else if (typ == 1)
            return "高级双床房";
        else
            return "豪华双床房";
    }
}