import java.util.Scanner;

public class Practice_Switch {
    static void main() {
        System.out.println("请输入a:");
        Scanner sc = new Scanner(System.in);
        double a = sc.nextDouble();
        System.out.println("请输入b:");
        double b = sc.nextDouble();
        String operator ="*";
        double result = switch(operator)
        {
            case "+" -> a+b;
            case "-" -> a-b;
            case "*" -> a*b;
            case "/" -> a/b;
            default -> 0;
        };
        System.out.println("结果是"+result);
    }
}

