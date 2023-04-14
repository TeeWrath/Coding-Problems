//MY OWN LOGIC :)
// CRAZY BISHOP PROBLEM
/*Problem

Chef has a matrix of size N×NN\times NN×N.
There are NNN bishops placed on the matrix, in a zig-zag fashion, at the cells (1,1),(2,2),(1,3),(2,4),(1,5),…,(1, 1), (2, 2), (1, 3), (2, 4), (1, 5), \dots,(1,1),(2,2),(1,3),(2,4),(1,5),…, and so on.

For example, for N=4N = 4N=4, the matrix looks like:
Screenshot-2023-04-12-at-1-26-20-AM.png

Your task is to determine the minimum number of moves required to reach a position where each cell (i,i)(i, i)(i,i) contains exactly one bishop for all 1≤i≤N1\le i \le N1≤i≤N.

For the above mentioned case of N=4N = 4N=4, the final position should be:
Screenshot-2023-04-12-at-1-32-03-AM.png

Note:

    Bishops can only move diagonally. In one move, you can place exactly one bishop from its initial cell to any other cell lying on either of its diagonals.
    Bishops cannot move outside the matrix.
    No cell can contain more than one bishop at a time.
    A bishop cannot jump over another bishop.

Input Format

    The first line of input will contain a single integer TTT - the number of test cases.
    Each test case consists of a single integer NNN - the size of the matrix.

Output Format

For each test case, output a single integer, the minimum number of moves required to reach a position where each cell (i,i)(i, i)(i,i) contains exactly one bishop for all 1≤i≤N1\le i \le N1≤i≤N.
Constraints

    1≤T≤1041 \leq T \leq 10^{4}1≤T≤104
    1≤N≤1091 \leq N \leq 10^91≤N≤109

Sample 1:
Input:
4
1
4
2
6

Output:
0
3
0
6

Explanation:

Test case 111: The bishop is already in its final position. Thus, no moves are required.

Test case 222: We require a minimum of 333 moves to reach the final position:

    Move bishop from (2,2)(2,2)(2,2) to (4,4)(4, 4)(4,4).
    Move bishop from (1,3)(1,3)(1,3) to (2,2)(2, 2)(2,2).
    Move bishop from (2,4)(2,4)(2,4) to (3,3)(3, 3)(3,3).

Test case 333: The bishops are already in their final position. Thus, no moves are required. */
import java.util.*;

public class crzybshp{
    public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		while(t-- >0){
		    int n = sc.nextInt();
		    if(n <= 2){
		        System.out.println(0);
		    }
		    else if(n == 3){
		        System.out.println(2);
		    }
		    else if(n > 3){
		        if(n%2 == 0){
		            System.out.println(2 + (((n-3)/2)*3) +1);
		        }
		        else{
		            System.out.println(2 + (((n-3)/2)*3) );
		        }
		    }
		}
		sc.close();
	}
}