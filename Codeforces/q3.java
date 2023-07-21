import java.util.*;
import java.lang.*;

public class q3{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while( t-- > 0){
            char arr[][] = new char[8][8];
            int i=0;
            int j=0;
            int k=0;
            for(i=0; i<8 ; i++){
                for(j=0 ; j<8 ; j++){
                    arr[i][j] = '-';
                }
            }
            for(i =0; i<8 ; i++){
                for(j=0; j<8 ; j++){
                arr[i][j] = sc.next().charAt(0);
                k =i;
                if(arr[i][j] != '.'){
                    while(i<8 && arr[i][j] == '.'){
                        i++;
                        arr[i][j] = sc.next().charAt(0);
                    }
                }
                i=k;
                break;
            }
        }
        while(i<8 && j<8){
            if(arr[i][j] == '-')
                arr[i][j] = '.';
        }
        ArrayList<Character> s = new ArrayList<Character>();
        for(i=0 ; i<8; i++){
            for(j =0; j<8 ; j++){
                if(arr[i][j] != '.'){
                    while(i<8 && arr[i][j] != '.'){
                        s.add(arr[i][j]);
                        i++;
                    }
                }
            }
        }
        System.out.println(s);
    }
}
}