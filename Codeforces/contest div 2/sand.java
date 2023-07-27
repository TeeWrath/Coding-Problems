import java.util.*;
import java.lang.*;

public class sand{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while( t-- >0){
            int b = sc.nextInt();
            int c = sc.nextInt();
            int h = sc.nextInt();
            if(b==1 || c+h ==0){
                System.out.println(0);
            }
            else if(b <= c + h){
                System.out.println((2*b) - 1);
            }
            else if(b > c + h){
                System.out.println((2*(c + h)) + 1);
            }
        }
    }
}