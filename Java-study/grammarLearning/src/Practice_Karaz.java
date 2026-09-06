import java.util.Scanner;

public class Practice_Karaz {
    static void main() {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        if(num>50&&num%2==0)
        {
            System.out.println("yes");
        }
        else
        {
            System.out.println("no");
        }
    }
}
