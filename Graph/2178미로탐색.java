import java.util.*;

public class Main{
	static int n,m;
	static boolean[][] maze;
	//distance: 가지못할경우 거리는 0이다
	static int[][] distance;
	
    public static void main(String [] argv){
    	//input
    	Scanner sc = new Scanner(System.in);
    	n = sc.nextInt();
    	m = sc.nextInt();
    	maze = new boolean[n][m];
    	for(int i = 0; i<n; i++) {
    		String input = sc.next();
    		for(int j = 0; j<m; j++) {
    			maze[i][j] = (input.charAt(j) != '0');
    		}
    	}
    	bfs(0,0);
    	System.out.println(distance[n-1][m-1]);
    	
    }
    public static void bfs(int r, int c) {
    	Queue<int[]> q = new LinkedList<int[]>();
    	distance = new int[n][m];
    	int[] dr = {0,0,1,-1};
    	int[] dc = {1,-1,0,0};
    	int[] startNode = {r,c};
    	q.offer(startNode);
    	distance[r][c] = 1;
    	while(!q.isEmpty()) {
    		int[] node = q.poll();
    		for(int i = 0; i<4; i++) {
    			int[] next = {node[0] + dr[i], node[1] + dc[i]};
    			if(0<=next[0] && next[0]<n && 0<=next[1] && next[1]<m) {
    				if(maze[next[0]][next[1]] == true && distance[next[0]][next[1]] == 0) {
    					q.offer(next);
    					distance[next[0]][next[1]] = distance[node[0]][node[1]] + 1;
    				}
    			}
    		}
    	}
    }
}
