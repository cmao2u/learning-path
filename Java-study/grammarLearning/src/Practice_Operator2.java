import java.util.Scanner;

public class Practice_Operator2 {
    static void main() {
        Scanner sc = new Scanner(System.in);
        int seconds = sc.nextInt();
        int hour =seconds/3600;
        int minute= (seconds%3600/60);
        int second = (seconds%3600%60);
        System.out.println(hour+" "+minute+" "+second);

    }
}
