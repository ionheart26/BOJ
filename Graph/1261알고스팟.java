//get distance from (0,0) to (n-1,m-1)
import java.util.*;

class Pair{
	int x, y;
	Pair(int x, int y){
		this.x = x;
		this.y = y;
	}
}
public class Main{
	static final int[] dr = {-1,0,1,0};
	static final int[] dc = {0,1,0,-1};
	public static void main(String[] args) {
		//input
		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		int n = sc.nextInt();
		int[][] maze = new int[n][m];
		for(int i = 0; i<n; i++) {
			String input = sc.next();
			for(int j = 0; j<m; j++) {
				maze[i][j] = (input.charAt(j) - '0');
			}
		}
		//dist: -1 if not visited
		int[][] dist = new int[n][m];
		for(int i = 0; i<n ;i++) {
			for(int j = 0; j<m; j++) {
				dist[i][j] = -1;
			}
		}
		Deque<Pair> deq = new ArrayDeque<Pair>();
		deq.addFirst(new Pair(0,0));
		dist[0][0] = 0;
		while(!deq.isEmpty()) {
			Pair p = deq.pollFirst();
			int x = p.x;
			int y = p.y;
			for(int i = 0; i<4; i++) {
				int nx = x + dr[i];
				int ny = y + dc[i];
				if(0<=nx && nx<n && 0<=ny && ny<m) {
					if(dist[nx][ny] == -1) {
						if(maze[nx][ny] == 0) {
							deq.addFirst(new Pair(nx,ny));
							dist[nx][ny] = dist[x][y];
						}
						else {
							deq.addLast(new Pair(nx,ny));
							dist[nx][ny] = dist[x][y] + 1;
						}
					}
				}
			}
		}
		System.out.println(dist[n-1][m-1]);
	}
}
