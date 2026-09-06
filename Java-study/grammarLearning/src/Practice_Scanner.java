import java.util.Scanner;

public class Practice_Scanner {
    static void main() {
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入第一个整数:");
        int num1 = sc.nextInt();
        System.out.println("请输入第二个整数:");
        int num2 = sc.nextInt();
        int sum = num1 + num2;
        System.out.println(sum);
    }
}
