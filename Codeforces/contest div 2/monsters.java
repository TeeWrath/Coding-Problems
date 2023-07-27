import java.util.*;

public class monsters {
    public static void printArray(int[] arr){
        int n = arr.length;
        for(int i=0; i<n ; i++){
            System.out.print(arr[i] + "\t");
        }
    }

    public static boolean isFull(int[] arr){
        for(int i=0 ; i<arr.length; i++){
            if(arr[i] >= 0){
                return false;
            }
        }
        return true;
    }

    public static void find(int[] arr, int max, int count, int first){
        for(int i=0; i<arr.length; i++){
            if(arr[i] > max){
                max = arr[i];
                count++;
                if(count ==1){
                    first = i;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- >0){
            int n = sc.nextInt();
            int k = sc.nextInt();
            int num[] = new int[n]; // array for input
            int arr[] = new int[n]; // ouput array
            for(int i=0 ; i<n; i++){
                num[i] = sc.nextInt();
            }
            int max = Integer.MIN_VALUE;
            int count =0;
            int first =0;
            while(!isFull(num)){
                int i=0;
                    find(num,max, count, first);
                    if(count >1){
                        num[first] = num[first] - k;
                        if(num[first] <= 0){
                            arr[i] = first+1;
                            i++;
                        }
                        count = 0;
                        find(num, max, count, first);
                    }
                    else if(count == 1){
                        num[first] = num[first] - k;
                        if(num[first] <= 0){
                            arr[i] = first +1;
                            i++;
                        }
                        count =0;
                        find(num, max, count, first);
                    }
                printArray(arr);
            }
            
        }
        sc.close();
    }
}
