package org.example;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.*;

public class Main {
    public static List<House> largeRoom = new ArrayList<>();
    public static List<House> doubleRoom = new ArrayList<>();
    public static List<House> suiteRoom = new ArrayList<>();
    public static List<Reservations> reservations = new ArrayList<>();
    private static final int WeekDay = 7; // 一星期有7天

    public static void main(String[] args) {
        Init();
        Show();
    }

    private static void Init() {
        largeRoom.clear();
        doubleRoom.clear();
        suiteRoom.clear();
        largeRoom.add(new LargeRoom(0));
        largeRoom.add(new LargeRoom(0));
        largeRoom.add(new LargeRoom(1));
        largeRoom.add(new LargeRoom(1));
        largeRoom.add(new LargeRoom(2));
        largeRoom.add(new LargeRoom(2));
        doubleRoom.add(new DoubleRoom(0));
        doubleRoom.add(new DoubleRoom(0));
        doubleRoom.add(new DoubleRoom(1));
        doubleRoom.add(new DoubleRoom(1));
        doubleRoom.add(new DoubleRoom(2));
        doubleRoom.add(new DoubleRoom(2));
        suiteRoom.add(new SuiteHouse(0));
        suiteRoom.add(new SuiteHouse(1));
        suiteRoom.add(new SuiteHouse(2));
    }

    // 使用hasNextInt函数来判断用户输入的是否为有效整数
    public static int getInt(Scanner scanner) {
        while (!scanner.hasNextInt()) {
            // 记得清空缓冲区
            scanner.next();
            System.out.println("您输入的有误，请再次输入!");
        }
        return scanner.nextInt();
    }

    public static void Show() {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("--------欢迎光临民宿酒店--------");
            System.out.println("1-进入管理员系统");
            System.out.println("2-进入普通用户办理系统");
            System.out.println("3-退出");
            int temp = getInt(scanner);
            switch (temp) {
                case 1:
                    CheckPwd(scanner);
                    break;
                case 2:
                    MangeClient.User(scanner);
                    break;
                case 3:
                    System.out.println("感谢你的信任和支持，再见！");
                    System.exit(0);
                    break;
                default:
                    System.out.println("请遵规则！");
            }
        }
    }

    private static void CheckPwd(Scanner scanner) {
        String Id, Pwd;
        try { // 文件读取 读入管理员的账号和密码
            File file = new File("src/main/java/org/example/CheckPwd.txt");
            BufferedReader reader = new BufferedReader(new FileReader(file));
            Id = reader.readLine();
            Pwd = reader.readLine();
            reader.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        while (true) {
            System.out.println("请输入管理员账号：");
            String id = scanner.next();
            System.out.println("请输入管理员密码：");
            String pwd = scanner.next();
            // 判断用户输入的管理员密码与文件中的密码是否一致
            if (id.equals(Id) && pwd.equals(Pwd)) {
                Manager(scanner);
                break;
            } else {
                System.out.println("账号或者密码有误，请重新输入！");
            }
        }
    }

    // 管理员界面
    private static void Manager(Scanner scanner) {
        while (true) {
            System.out.println("*******欢迎进入住房管理系统*******");
            System.out.println("1-查询所有的房间");
            System.out.println("2-查询客户订房情况");
            System.out.println("3-增加房间");
            System.out.println("4-删除房间");
            System.out.println("5-修改房间");
            System.out.println("6-更改账号密码");
            System.out.println("7-放回主界面");
            System.out.println("请输入你想要进行的操作：");
            int manage = getInt(scanner);
            switch (manage) {
                case 1 -> queryHouse();
                case 2 -> queryOrder();
                case 3 -> addHouse(scanner);
                case 4 -> deleteHouse(scanner);
                case 5 -> updateHouse(scanner);
                case 6 -> changeMi(scanner);
                case 7 -> Show();
                default -> System.out.println("请遵守规则!");
            }
        }
    }

    /**
     * 输出现有住房的信息
     * 使用泛型来写 内部类
     */
    public static void queryHouse() {
        SimpleDateFormat sp = new SimpleDateFormat("yyyy-MM-dd");
        Date date = new Date();
        System.out.println("-------大床房-------");
        RoomPrinter<House> largeRoomPrinter = new RoomPrinter<>(largeRoom, date, sp);
        largeRoomPrinter.printRoomInformation();
        System.out.println("-------双床房-------");
        RoomPrinter<House> doubleRoomPrinter = new RoomPrinter<>(doubleRoom, date, sp);
        doubleRoomPrinter.printRoomInformation();
        System.out.println("-------套房-------");
        RoomPrinter<House> suiteRoomPrinter = new RoomPrinter<>(suiteRoom, date, sp);
        suiteRoomPrinter.printRoomInformation();
    }

    // 查询订单
    private static void queryOrder() {
        System.out.println("所有的订单如下：");
        Date now = new Date();
        int Sum = 0; // 用于判断是否有有效订单
        for (Reservations reservations : reservations) {
            Date begin = reservations.getDate();
            Calendar calendar = Calendar.getInstance();
            calendar.setTime(begin);
            calendar.add(Calendar.DATE, reservations.getDay() - 1);
            Date end = calendar.getTime();
            if (end.compareTo(now) >= 0) { // 根据时间判断 这个订单是否到时间了
                Sum++;
                SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy年MM月dd日");
                System.out.println("预约人：" + reservations.getName());
                System.out.println(simpleDateFormat.format(begin) + " 到 " + simpleDateFormat.format(end) + " ");
                System.out.println(reservations.getType_name() + (reservations.getFood() == 1 ? "(有早餐)" : "(无早餐)")
                        + "\n支付的价钱为：" + (int) reservations.getPrice() + "元\n");
            }
        }
        if (Sum == 0) {
            System.out.println("现在暂无有效订单！");
        }
    }

    /**
     * 添加新房间
     */
    private static void addHouse(Scanner scanner) {
        int userIn = checkHouse(scanner);
        System.out.println("请输入你想要添加房间的具体信息：");
        int type = CheckType(scanner, userIn);
        switch (userIn) {
            case 1 -> largeRoom.add(new LargeRoom(type));
            case 2 -> doubleRoom.add(new DoubleRoom(type));
            case 3 -> suiteRoom.add(new SuiteHouse(type));
        }
        System.out.println("添加成功！");
    }

    // 检查输入的房间大类型是否合法
    private static int checkHouse(Scanner scanner) {
        while (true) {
            System.out.println("请输入你想要操作的房间类型,1-大床房,2-双床房,3-套房");
            int input = getInt(scanner);
            if (input == 1 || input == 2 || input == 3) {
                return input;
            } else {
                System.out.println("您输出的信息有误！");
            }
        }
    }

    // 用来判断输入的小类型是否合法
    private static int CheckType(Scanner scanner, int userIn) {
        int id = 0;
        while (true) {
            PrintHouse(userIn - 1);
            id = getInt(scanner);
            if (id == 1 || id == 2 || id == 3) {
                break;
            } else {
                System.out.println("请输入正确的编号！");
            }
        }
        return id;
    }

    // 删除房间
    private static void deleteHouse(Scanner scanner) {
        System.out.println("当前已有的房间如下：");
        queryHouse();
        int userIn = checkHouse(scanner);
        int id = CheckType(scanner, userIn);
        // 用枚举类型优化代码 使重复的部分省略
        List<? extends House> roomList = switch (userIn) {
            case 1 -> Main.largeRoom;
            case 2 -> Main.doubleRoom;
            default -> Main.suiteRoom;
        };
        for (int i = 0, j = 0; i < roomList.size(); i++) {
            if (roomList.get(i).getTypes() == id - 1) {
                for (j = 0; j < WeekDay; j++) {
                    // 判断删除的房间是否有人居住 如果有不能删除
                    if (roomList.get(i).getReservation(i)) {
                        break;
                    }
                }
                if (j == WeekDay) { // 如果没人居住 则删除该房间
                    System.out.println(roomList.get(i).getType() + "成功删除！");
                    roomList.remove(roomList.get(i));
                    break;
                }
            } else if (i == roomList.size() - 1) {
                System.out.println("对不起，没有找到您想要删除的房间！");
            }
        }
    }

    private static void PrintHouse(int brand) {
        System.out.println("输入你想要删除的房间信息：");
        if (brand == 0) {
            System.out.println("1-高级大房间");
            System.out.println("2-豪华大房间");
            System.out.println("3-景观大房间");
        } else if (brand == 1) {
            System.out.println("1-标准双床房");
            System.out.println("2-高级双床房");
            System.out.println("3-豪华双床房");
        } else {
            System.out.println("1-景致小套房");
            System.out.println("2-婴儿小套房");
            System.out.println("3-亲子小套房");
        }
    }

    // 修改房间信息
    private static void updateHouse(Scanner scanner) {
        int userIn = checkHouse(scanner);
        System.out.println("请输入想要修改房间的类型");
        int userId = getInt(scanner);
        userId--;
        System.out.println("请输入你想要修改的价格:(无早餐)  (有早餐)");
        double price1 = scanner.nextDouble(), price2 = scanner.nextDouble();
        if (userIn == 1) {
            LargeRoom.PRICES[userId][0] = price1;
            LargeRoom.PRICES[userId][1] = price2;
        } else if (userIn == 2) {
            DoubleRoom.PRICES[userId][0] = price1;
            DoubleRoom.PRICES[userId][1] = price2;
        } else {
            SuiteHouse.PRICES[userId][0] = price1;
            SuiteHouse.PRICES[userId][1] = price2;
        }
    }

    private static void changeMi(Scanner scanner) {
        System.out.println("请输入你要修改的账号");
        String Id = scanner.next();
        System.out.println("请输入你要修改的密码");
        String Pwd = scanner.next();
        try { // 文件读取 读入管理员的账号和密码
            File file = new File("src/main/java/org/example/CheckPwd.txt");
            BufferedWriter writer = new BufferedWriter(new FileWriter(file));
            writer.write(""); // 将内容清空
            writer.flush();
            writer.write(Id);
            writer.newLine();
            writer.write(Pwd);
            writer.flush();
            writer.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    // 泛型 内部类
    static class RoomPrinter<T extends House> {
        private List<T> roomList;
        private Date date;
        private SimpleDateFormat sp;

        public RoomPrinter(List<T> roomList, Date date, SimpleDateFormat sp) {
            this.roomList = roomList;
            this.date = date;
            this.sp = sp;
        }

        public void printRoomInformation() {
            System.out.println("房间类型\t\t价格（无早饭）\t\t价格（有早饭）\t\t是否有人租房");
            for (T room : roomList) {
                System.out.print(room.getType() + "\t\t" + room.getPrices()[room.getTypes()][0] + "\t\t"
                        + room.getPrices()[room.getTypes()][1] + "\t\t\t");
                int lastday = 0, lastbegin = 0;
                for (int i = 0; i < WeekDay; i++) {
                    if (room.getReservation(i) || (i == 6 && lastday != 0)) {
                        Calendar calendar = Calendar.getInstance();
                        calendar.setTime(date);
                        calendar.add(Calendar.DATE, lastbegin);
                        if (lastday == 1) { // 如果有超过两天的空闲 就一起输出
                            System.out.print(sp.format(calendar.getTime()) + " ");
                        } else if (lastday > 1) {
                            System.out.print(sp.format(calendar.getTime()) + "~");
                            calendar.add(Calendar.DATE, lastday);
                            System.out.print(sp.format(calendar.getTime()) + " ");
                        }
                        lastday = 0;
                        lastbegin = i + 1;
                    } else {
                        lastday++;
                    }
                }
                System.out.println("暂时无人居住");
            }
        }
    }
}