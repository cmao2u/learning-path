import java.util.Scanner;

public class Practice_HPcalculate {
    static void main() {
        Scanner sc = new Scanner(System.in);
        int hp = 200;
        System.out.println("请输入扣除的血量:");
        int x = sc.nextInt();
        while(x<0)
        {
            x =sc.nextInt();
        }
        hp = hp -x;
        if(hp <= 0)
        {
            hp = 1;
        }
        System.out.println("请输入恢复的血量:");
        int y = sc.nextInt();
        hp = hp + y;
        if (hp > 200)
        {
            hp = 200;
        }
        System.out.println("血量为:"+hp);



    }
}
