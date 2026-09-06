import java.util.Scanner;

public class Practice_Operator {
    static void main() {
        Scanner sc= new Scanner(System.in);
        System.out.println("请输入一个3位数:");
        int num = sc.nextInt();
        int unit = num % 10;
        int decade = num /10 %10;
        int hundred = num/100%10;
        System.out.println(unit+" " +decade+" "+hundred);

    }
}
