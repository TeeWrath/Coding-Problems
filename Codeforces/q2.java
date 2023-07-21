import java.util.*;
import java.lang.*;

public class q2{
    public static int max(int n, int m){
        return (n>m) ? n:m ;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while( t-- > 0){
            int n = sc.nextInt();
            int arr[] = new int[n];
            int m = Integer.MIN_VALUE;
            for(int i=0 ; i<n ; i++){
                int a = sc.nextInt();
                arr[i] = sc.nextInt();
                if(a <= 10){
                    m = max(m, arr[i]);}
            }
            for(int i=0 ; i<n ; i++){
                if(m == arr[i]){
                    System.out.println(i+1);
                }
            }
        }
    }
}