package org.example;

import org.apache.poi.xssf.usermodel.XSSFRow;
import org.apache.poi.xssf.usermodel.XSSFSheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

import java.io.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.ZoneId;
import java.time.temporal.ChronoUnit;
import java.util.*;

/**
 * 用户使用界面
 */
public class MangeClient {
    private static HashMap<String, String> Id_Pwd = new HashMap<>(); // 存放用户名和密码的映射表
    private static final int WeekDay = 7; // 一星期有7天
    private static String now_Id; // 用于存放现在登录用户的Id

    public static void User(Scanner scanner) {
        ReaderExcel();
        while (true) {
            System.out.println("请输入你要进行的操作：");
            System.out.println("1-登录");
            System.out.println("2-注册");
            System.out.println("3-返回");
            int UserIn = Main.getInt(scanner);
            switch (UserIn) {
                case 1 -> CheckPwd(scanner);
                case 2 -> Register(scanner);
                case 3 -> {
                    return;
                }
                default -> System.out.println("请遵守规则!");
            }
        }
    }

    /**
     * 用户登录
     */
    private static void CheckPwd(Scanner scanner) {
        String Id, Pwd;
        while (true) {
            System.out.println("请输入账号：");
            Id = scanner.next();
            System.out.println("请输入密码：");
            Pwd = scanner.next();
            if (Id_Pwd.get(Id) == null) {
                System.out.println("您输入的账号不存在 请问是否用当前的账号注册");
                System.out.println("1-使用当前账号注册");
                System.out.println("2-重新输入账号");
                int UserIn = Main.getInt(scanner);
                if (UserIn == 1) {
                    while (true) {
                        System.out.println("请输入密码：");
                        Pwd = scanner.next();
                        System.out.println("请再输入一次确认密码：");
                        String AgePwd = scanner.next();
                        if (Pwd.equals(AgePwd)) {
                            break;
                        } else {
                            System.out.println("您输入的两次密码不一样，请再次输入");
                        }
                    }
                    Id_Pwd.put(Id, Pwd);
                    AddExcel(Id, Pwd);
                    System.out.println("账号创建成功，请前去登录！");
                }
            } else if (!Id_Pwd.get(Id).equals(Pwd)) {
                System.out.println("您输入的密码有误，请再次尝试！");
            } else {
                now_Id = Id;
                Show(scanner);
                break;
            }
        }
    }

    /**
     * 从Excel中读入用户的账号和密码
     * 太慢了
     */
    private static void ReaderExcel() {
        try {
            // 创建一个文件输入流
            FileInputStream in = new FileInputStream("src/main/java/org/example/client.xlsx");
            // 使用BufferedInputStream提高读取效率
            BufferedInputStream bufferedIn = new BufferedInputStream(in);
            // 创建一个XSSFWorkbook对象
            XSSFWorkbook workbook = new XSSFWorkbook(bufferedIn);
            XSSFSheet sheet = workbook.getSheetAt(0);
            // 创建一个HashMap，用于存储id和密码
            HashMap<String, String> idPwdMap = new HashMap<>();
            // 遍历sheet中的每一行
            for (int i = 1; i <= sheet.getLastRowNum(); i++) {
                // 获取每一行的每一列
                XSSFRow row = sheet.getRow(i);
                // 获取每一列的第一个单元格的值
                String id = row.getCell(0).getStringCellValue();
                // 获取每一列的第二个单元格的值
                String pwd = row.getCell(1).getStringCellValue();
                // 将id和密码存入HashMap中
                idPwdMap.put(id, pwd);
            }
            workbook.close();
            bufferedIn.close();
            Id_Pwd.putAll(idPwdMap); // 将整个映射添加到Id_Pwd
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    // 向Excel里面存放数据 新的账号存放在最后一行
    private static void AddExcel(String Id, String Pwd) {
        try {
            FileInputStream in = new FileInputStream("src/main/java/org/example/client.xlsx");
            try (XSSFWorkbook workbook = new XSSFWorkbook(in)) {
                XSSFSheet sheet = workbook.getSheetAt(0);
                // 创建一个新的行，行号从1开始
                FileOutputStream out = new FileOutputStream("src/main/java/org/example/client.xlsx");
                // 创建一个新的行，行号从1开始
                XSSFRow row = sheet.createRow((short) (sheet.getLastRowNum() + 1));
                // 创建一个新的单元格，列号为0，值为Id
                row.createCell(0).setCellValue(Id);
                // 创建一个新的单元格，列号为1，值为Pwd
                row.createCell(1).setCellValue(Pwd);
                // 将行写入文件
                out.flush();
                // 将行写入文件
                workbook.write(out);
                out.close();
            }
            in.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * 注册操作
     */
    private static void Register(Scanner scanner) {
        String Id, Pwd;
        System.out.println("请输入你想要注册的账号名:");
        Id = scanner.next();
        while (Id_Pwd.size() != 0 && Id_Pwd.get(Id) != null) {
            System.out.println("您输入的账号以有人注册，请尝试登录或者输入新的账号,1-退出前往登录,2-输入新的账号");
            int UserIn = Main.getInt(scanner);
            if (UserIn == 1) {
                return;
            } else {
                System.out.println("请输入账号：");
                Id = scanner.next();
            }
        }
        while (true) {
            System.out.println("请输入密码：");
            Pwd = scanner.next();
            System.out.println("请再输入一次确认密码：");
            String AgePwd = scanner.next();
            if (Pwd.equals(AgePwd)) {
                break;
            } else {
                System.out.println("您输入的两次密码不一样，请再次输入：");
            }
        }
        Id_Pwd.put(Id, Pwd);
        AddExcel(Id, Pwd);
        System.out.println("账号创建成功，请前去登录!");
    }

    private static void Show(Scanner scanner) {
        while (true) {
            System.out.println("-------欢迎登录租房管理系统-------");
            System.out.println("1-进入预约系统");
            System.out.println("2-进入撤销预约系统");
            System.out.println("3-查看我的预约");
            System.out.println("4-修改密码");
            System.out.println("5-退出");
            int UserIn = Main.getInt(scanner);
            switch (UserIn) {
                case 1 -> Reservation(scanner);
                case 2 -> Revoke(scanner);
                case 3 -> ShowMy();
                case 4 -> changePwd(scanner);
                case 5 -> {
                    Main.Show();
                    return;
                }
                default -> System.out.println("请遵守规则！");
            }
        }
    }

    /**
     * 预约系统
     */
    private static void Reservation(Scanner scanner) {
        Main.queryHouse();
        while (true) {
            System.out.println("请输入你想要预约的房间类型:(输入-1退出预定)");
            System.out.println("1-大房间");
            System.out.println("2-双床房");
            System.out.println("3-套房");
            int userIn = Main.getInt(scanner);
            switch (userIn) {
                case -1 -> {
                    return;
                }
                case 1 -> {
                    Hire(scanner, 0);
                    return;
                }
                case 2 -> {
                    Hire(scanner, 1);
                    return;
                }
                case 3 -> {
                    Hire(scanner, 2);
                    return;
                }
                default -> System.out.println("请遵守规则!");
            }
        }
    }

    private static void Hire(Scanner scanner, int brand) {
        PrintHouse(brand);
        int userIn = Main.getInt(scanner);
        if (userIn == 1 || userIn == 2 || userIn == 3) {
            Date now = new Date();
            System.out.printf("现在时间为%tY-%tm-%td\n", now, now, now);
            System.out.println("请选择您要预约的日期：格式 year-month-day");
            while (true) {
                String b = scanner.next();
                SimpleDateFormat ft = new SimpleDateFormat("yyyy-MM-dd");
                Date begin;
                try {
                    begin = ft.parse(b);
                } catch (ParseException ex) {
                    System.out.println("您输入的格式不对，请重新输入！");
                    continue;
                }
                System.out.println("请输入您想要居住的时间（包括预约当天, 只能预约7天以内）");
                int day = Main.getInt(scanner);
                LocalDate today = LocalDate.now();
                LocalDate be = begin.toInstant().atZone(ZoneId.systemDefault()).toLocalDate();
                long daysDiff = ChronoUnit.DAYS.between(today, be);
                while (daysDiff + day - 1 > WeekDay) {
                    System.out.println("您输入的时间超过最长预定时间，请重新输入！");
                    day = Main.getInt(scanner);
                }
                int conform = -1;
                // 枚举类型 优化代码 使其精简
                List<? extends House> roomList = switch (brand) {
                    // 如果brand为0，则返回大房间
                    case 0 -> Main.largeRoom;
                    // 如果brand为1，则返回双房间
                    case 1 -> Main.doubleRoom;
                    // 如果brand为默认值，则返回套房间
                    default -> Main.suiteRoom;
                };
                // 遍历roomList，获取每个房间的类型
                for (int i = 0; i < roomList.size(); i++) {
                    House house = roomList.get(i);
                    if (house.getTypes() != userIn - 1)
                        // 如果房间类型不等于用户输入的类型，则跳过
                        if (house.getTypes() != userIn - 1)
                            continue;
                    // 初始化isAvailable为true
                    boolean isAvailable = true;
                    // 遍历daysDiff到daysDiff + day - 1，获取每个房间的预约情况
                    for (long j = daysDiff; j <= daysDiff + day - 1; j++) {
                        // 如果房间的预约情况为true，则isAvailable为false，跳出循环
                        if (house.getReservation((int) j)) {
                            isAvailable = false;
                            break;
                        }
                    }
                    // 如果isAvailable为true，则将i的值赋值给conform，并将每个房间的预约情况设置为true
                    if (isAvailable) {
                        conform = i;
                        for (long k = daysDiff; k <= daysDiff + day - 1; k++) {
                            house.setReservation((int) k, true);
                        }
                        break;
                    }
                }
                if (conform == -1) {
                    System.out.println("没有合适的房间，请换个时间或者换个房间！");
                    break;
                }
                System.out.println("请选择是否需要早饭：0-不需要 1-需要");
                int is_Food = Main.getInt(scanner);
                Reservations reservation = new Reservations(now_Id, userIn - 1, brand, is_Food, day, begin, now);
                // AddReservation(reservation);
                Main.reservations.add(reservation); // 向List中存入订单数据
                System.out.println("预约房间成功：");
                System.out.println("您预约的房间是：" + (brand == 0 ? LargeRoom.getTyp(userIn - 1)
                        : brand == 1 ? DoubleRoom.getTyp(userIn - 1) : SuiteHouse.getTyp(userIn - 1)));
                Calendar calendar = Calendar.getInstance();
                calendar.setTime(begin);
                calendar.add(Calendar.DATE, day - 1);
                System.out.println("预约的时间为：" + ft.format(begin) + "~" + ft.format(calendar.getTime()));
                System.out.println("请支付" + (int) reservation.getPrice() + "元");
                break;
            }
        } else {
            System.out.println("请输入正确的编号！");
            Hire(scanner, brand);
        }
    }

    private static void PrintHouse(int brand) {
        System.out.println("请输入你想要预约的类型：");
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

    private static void Revoke(Scanner scanner) {
        ShowMy();
        System.out.println("请输入您想要撤销的编号：");
        int UserIn = Main.getInt(scanner);
        Date now = new Date();
        int reservationSum = 1; // 存放订单的量
        for (Reservations reservations : Main.reservations) {
            if (reservations.getName().equals(now_Id)) {
                Date begin = reservations.getDate();
                Calendar calendar = Calendar.getInstance();
                calendar.setTime(begin);
                calendar.add(Calendar.DATE, reservations.getDay() - 1);
                Date end = calendar.getTime();
                // 判断订单时间是否有效
                if ((end.getTime() - now.getTime()) / 24 / 60 / 60 / 1000 >= 0
                        && ((now.getTime() - reservations.getNow_date().getTime()) / 24 / 60 / 60 / 1000) != 0) {
                    if (reservationSum == UserIn) {
                        System.out.println("撤销成功！");
                        System.out.println("回退给您" + (int) reservations.getPrice() + "元");
                        Main.reservations.remove(reservations);
                        return;
                    }
                    reservationSum++;
                }
            }
        }
        System.out.println("没有找到对应的订单，以自动退出！");
    }

    // 查看订单
    private static void ShowMy() {
        System.out.println("您的预约的房间如下：");
        Date now = new Date();
        int reservationSum = 1; // 订单的量
        for (Reservations reservations : Main.reservations) {
            if (reservations.getName().equals(now_Id)) {
                Date begin = reservations.getDate();
                Calendar calendar = Calendar.getInstance();
                calendar.setTime(begin);
                calendar.add(Calendar.DATE, reservations.getDay() - 1);
                Date end = calendar.getTime();
                if ((end.getTime() - now.getTime()) / 24 / 60 / 60 / 1000 >= 0) {
                    SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy年MM月dd日");
                    System.out.println("订单编号：" + (reservationSum++));
                    System.out.println(simpleDateFormat.format(begin) + " 到 " + simpleDateFormat.format(end) + " ");
                    System.out.println(reservations.getType_name() + (reservations.getFood() == 1 ? "(有早餐)" : "(无早餐)")
                            + "\n您支付的价钱为：" + (int) reservations.getPrice() + "元\n");
                }
            }
        }
        if (reservationSum == 1) {
            System.out.println("暂无订单！");
        }
    }

    // 更改密码
    private static void changePwd(Scanner scanner) {
        System.out.println("请输入您原本的密码：");
        String userIn = scanner.next();
        while (!Id_Pwd.get(now_Id).equals(userIn)) {
            System.out.println("请输入正确的原密码：");
            userIn = scanner.next();
        }
        System.out.println("请输入新密码：");
        String new_Pwd = scanner.next();
        System.out.println("请再次输入一遍新密码：");
        String two_Pwd = scanner.next();
        while (!two_Pwd.equals(new_Pwd)) {
            System.out.println("您两次输入的密码有误，请再次输入");
            System.out.println("请输入新密码：");
            new_Pwd = scanner.next();
            System.out.println("请在此输入：");
            two_Pwd = scanner.next();
        }
        Id_Pwd.put(now_Id, new_Pwd);
        ChangeExcel(now_Id, new_Pwd);
        System.out.println("密码修改成功！");
    }

    // 修改Excel 中对应账号的密码
    private static void ChangeExcel(String Id, String Pwd) {
        try {
            FileInputStream in = new FileInputStream("src/main/java/org/example/client.xlsx");
            try (XSSFWorkbook workbook = new XSSFWorkbook(in)) {
                XSSFSheet sheet = workbook.getSheetAt(0);
                FileOutputStream out = new FileOutputStream("src/main/java/org/example/client.xlsx");
                for (int i = 1; i <= sheet.getLastRowNum(); i++) {
                    if (sheet.getRow(i).getCell(0).getStringCellValue().equals(Id)) {
                        sheet.getRow(i).getCell(1).setCellValue(Pwd);
                        break;
                    }
                }
                out.flush();
                workbook.write(out);
                out.close();
            }
            in.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    // private static void AddReservation(Reservations reservations) {
    // try {
    // FileInputStream in = new
    // FileInputStream("src/main/java/org/example/Reservation.xlsx");
    // FileOutputStream out = new
    // FileOutputStream("src/main/java/org/example/Reservation.xlsx");
    // XSSFWorkbook workbook = new XSSFWorkbook(in);
    // XSSFSheet sheet = workbook.getSheetAt(0);
    // XSSFRow row = sheet.createRow((short) (sheet.getLastRowNum() + 1));
    // row.createCell(0).setCellValue(reservations.getName());
    // row.createCell(1).setCellValue(reservations.getType());
    // row.createCell(2).setCellValue(reservations.getBrand());
    // row.createCell(3).setCellValue(reservations.getFood());
    // row.createCell(4).setCellValue(reservations.getDay());
    // row.createCell(5).setCellValue(reservations.getDate());
    // row.createCell(6).setCellValue(reservations.getNow_date());
    // row.createCell(7).setCellValue(reservations.getPrice());
    // out.flush();
    // workbook.write(out);
    // in.close();
    // out.close();
    // } catch (IOException e) {
    // throw new RuntimeException(e);
    // }
    // }
    //
    // private static void RemoveReservation(Reservations reservations) {
    // try {
    // FileInputStream in = new
    // FileInputStream("src/main/java/org/example/Reservation.xlsx");
    // FileOutputStream out = new
    // FileOutputStream("src/main/java/org/example/Reservation.xlsx");
    // XSSFWorkbook workbook = new XSSFWorkbook(in);
    // XSSFSheet sheet = workbook.getSheetAt(0);
    // for (int i = 1; i <= sheet.getLastRowNum(); i++) {
    // XSSFRow row = sheet.getRow(i);
    // if (row.getCell(0).getStringCellValue().equals(reservations.getName()) &&
    // row.getCell(6).getStringCellValue().equals(reservations.getNow_date().toString()))
    // {
    // row.createCell(8).setCellValue(false);
    // break;
    // }
    // }
    // out.flush();
    // in.close();
    // out.close();
    // } catch (IOException e) {
    // throw new RuntimeException(e);
    // }
    // }
}
