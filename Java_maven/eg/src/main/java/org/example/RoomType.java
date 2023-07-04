package org.example;

public enum RoomType {
    LARGE_ROOM(LargeRoom.class),
    DOUBLE_ROOM(DoubleRoom.class),
    SUITE_ROOM(SuiteHouse.class);

    private Class<? extends House> houseClass;

    RoomType(Class<? extends House> houseClass) {
        this.houseClass = houseClass;
    }

    public Class<? extends House> getHouseClass() {
        return houseClass;
    }
}