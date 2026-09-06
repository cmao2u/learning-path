import java.sql.SQLOutput;

public class Practice_DataType {
    static void main() {
        double height = 1.75;
        double weight = 62.5;
        double BMI = (weight/(height*height));
        System.out.println((BMI));
        double maxWeight = 23.9*height*height;
        System.out.println(maxWeight);
    }
}
