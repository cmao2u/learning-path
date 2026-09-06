import java.util.Scanner;

public class Practice_Scanner2 {
    static void main() {
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入身高:");
        double height = sc.nextDouble();
        System.out.println("请输入体重:");
        double weight = sc.nextDouble();
        double BMI = weight/(height*height);
        System.out.println(BMI);
    }
}
