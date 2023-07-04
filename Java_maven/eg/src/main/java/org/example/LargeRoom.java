package org.example;

public class LargeRoom extends House {
    static double[][] PRICES = { { 600, 700 }, { 700, 800 }, { 850, 950 } };
    public boolean[] is_reservation = new boolean[7];

    @Override
    public boolean getReservation(int j) {
        return this.is_reservation[j];
    }

    @Override
    public void setReservation(int k, boolean b) {
        this.is_reservation[k] = b;
    }

    public LargeRoom(int type) {
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
    public String getType() {
        if (getTypes() == 0)
            return "高级大床房";
        else if (getTypes() == 1)
            return "豪华大床房";
        else
            return "景观大床房";
    }

    public static String getTyp(int typ) {
        if (typ == 0)
            return "高级大床房";
        else if (typ == 1)
            return "豪华大床房";
        else
            return "景观大床房";
    }

    @Override
    public double[][] getPrices() {
        return PRICES;
    }
}
