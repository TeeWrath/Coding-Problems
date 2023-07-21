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
		while( t-- > 0 ){
		    int n = sc.nextInt();
		    sc.nextLine();
		    String a = sc.nextLine();
		    String b = sc.nextLine();
		    String c = sc.nextLine();
		    StringBuilder d = new StringBuilder();
		    for(int i=0 ; i<n ; i++){
		        d.append((char)((c.charAt(i)-'a' + b.charAt(i)-a.charAt(i) + 26)%26 + 'a'));
		    }
		    System.out.println(d.toString());
		}
	}
}
