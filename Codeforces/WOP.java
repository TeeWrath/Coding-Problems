import java.util.*;
import java.lang.*;

public class WOP{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while( t-- > 0){
            String grid ="";
            for(int i=0 ; i<8 ; i++){
                grid += sc.next();
            }
            System.out.println(grid.replaceAll("\\.",""));
        }
    }
}