/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while( t-- > 0){
		    int x = sc.nextInt();
		    int y = sc.nextInt();
		    int z= sc.nextInt();
		   if((x*y)%z==0){
		       System.out.print(x*y+" ");
		       System.out.println(z);
		   }
		  else if((x*z)%y==0){
		      System.out.print(x*z+ " ");
		      System.out.println(y);
		  }
		  else if((y*z)%x==0){
		      System.out.print(y*z+" ");
		      System.out.println(x);
		  }
		  else
		      System.out.println(-1);
		}
	}
}
