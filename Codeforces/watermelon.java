import java.util.*;
import java.lang.*;

public class watermelon{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        if(t%2 == 1 || t == 2)
            System.out.println("NO");
        else
            System.out.println("YES");
    }
}