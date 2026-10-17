public class MAX {
    public static void main(String[] args) {
        if (args.length < 3) {
            System.out.println("需要3个整数作为命令行参数！");
            return;
        }

        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        int c = Integer.parseInt(args[2]);
        int max;

        if (a > b && a > c) {
            max = a;
        } else if (b > c) {
            max = b;
        } else {
            max = c;
        }

        System.out.println("三个数中最大的是：" + max);
    }
}
