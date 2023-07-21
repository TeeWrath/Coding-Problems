//CODECHEF - START90D - DIV4 - PRINTINGBIN

import java.util.*;
import java.lang.*;
import java.io.*;

    public class printingbin {
    	public static void convertArray(int newarr[], int arr[], int n){
	        for( int i = 0 ; i<n ; i++){
	            newarr[i] = arr[i]^1;
	        }
	    }
	
	public static void printArray(int arr[]){
	    for(int i=0 ; i<arr.length ; i++){
	        System.out.print(arr[i]+"\t");
	    }
	    System.out.println();
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		while( t-- > 0){
		    int n = sc.nextInt();
		    int arr[] = new int[n];
		    
		    for( int i = 0 ; i<n ; i++){
	            arr[i] = sc.nextInt();
	        }
		    
		    int newarr[] = new int[n];
		    convertArray(newarr, arr, n);
		    printArray(newarr);
		}
	}

    }
