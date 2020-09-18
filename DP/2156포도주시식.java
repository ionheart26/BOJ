//d[n][m]: n번째, n-1번째 잔의 상태가 m일때 최대 값
//4가지 상태가 있다: 00, 01, 10, 11
//1: 마심, 0: 안마심
//0,2->0
//0,2->1
//1,3->2
//1->3

import java.util.*;
import java.math.*;

public class Main{
    public static void main(String [] argv){
    	//input
    	Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();
    	int[] wine = new int[n];
    	for(int i = 0; i<n; i++) {
    		wine[i] = sc.nextInt();
    	}
    	
    	int[][] d = new int[10000][4];
    	//initialization
    	d[0][0] = 0;
    	d[0][1] = wine[0];
    	d[0][2] = 0;
    	d[0][3] = wine[0];
    	
    	//iteration
    	for(int i = 1; i<n; i++) {
    		d[i][0] = Math.max(d[i-1][0], d[i-1][2]);
    		d[i][1] = Math.max(d[i-1][0], d[i-1][2]) + wine[i];
    		d[i][2] = Math.max(d[i-1][1], d[i-1][3]);
    		d[i][3] = d[i-1][1] + wine[i];
    	}
    	
    	//answer
    	int[] result = new int[4];
    	System.arraycopy(d[n-1], 0, result, 0, 4);
    	Arrays.sort(result);
    	int ans = result[3];
    	System.out.println(ans);
    }
}
