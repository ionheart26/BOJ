/*
 * 1. 섬들을 구별한다: bfs를 사용, 큐에 저장, 각각의 섬은 인덱스로 접근가능하다.
 * 2. 섬을 확장하면서 & 각 섬에서 각 바다노드까지의 최소거리를 저장: bfs사용
 * 3. 섬이 인접한 곳에서 최소값을 찾는다.
 */
import java.util.*;

class Pair{
	int x,y;
	Pair(int x, int y){
		this.x = x;
		this.y = y;
	}
}

public class Main{
	static final int[] dr = {0,0,1,-1};
	static final int[] dc = {1,-1,0,0};
	static int n;
	static int[][] map;
	//islands: 1단계에서 각 섬에 번호를 붙이고, 2단계에서 섬을 확장한다
	static int[][] islands;
	//distance: 3단계에서 각 바다노드까지의 최소거리를 저장
	static int[][] distance;
    public static void main(String [] argv){
    	//input
    	Scanner sc = new Scanner(System.in);
    	n = sc.nextInt();
    	map = new int[n][n];
    	islands = new int[n][n];
    	distance = new int[n][n];
    	for(int i = 0; i<n; i++) {
    		for(int j = 0; j<n; j++) {
    			distance[i][j] = -1;
    			int input = sc.nextInt();
    			if(input == 1) {
    			map[i][j] = 1;
    			distance[i][j] = 0;
    			}
    		}
    	}
    	
    	/*step1: number islands*/
    	int islandsCnt = 0;
    	for(int i = 0; i<n; i++) {
    		for(int j = 0; j<n; j++) {
    			//새로운 섬일 경우 큐에 저장
    			if(map[i][j] == 1 && islands[i][j] == 0) {
    				Queue<Pair> q = new LinkedList<Pair>();
    				q.add(new Pair(i,j));
    				islands[i][j] = ++islandsCnt;
    				while(!q.isEmpty()) {
    					Pair node = q.poll();
	    				for(int k = 0; k<4; k++) {
	    					int nx = node.x + dr[k];
	    					int ny = node.y + dc[k];
	    					if(0<=nx && nx<n && 0<=ny && ny<n) {
	    						if(map[nx][ny] == 1 && islands[nx][ny] == 0) {
	    							q.add(new Pair(nx,ny));
	    							islands[nx][ny] = islandsCnt;
	    						}
	    					}
	    				}
    				}
    			}
    		}
    	}
    	/*step2: 섬을 확장하면서 최소거리 계산*/
    	//make queue
    	Queue <Pair> q = new LinkedList<Pair>();
    	for(int i = 0; i<n; i++) {
    		for(int j = 0; j<n; j++) {
    			if(map[i][j] == 1) {
    				q.add(new Pair(i,j));
    			}
    		}
    	}
    	//extend islands & calculate distance, using bfs
    	while(!q.isEmpty()) {
    		Pair node = q.poll();
    		for(int i = 0; i<4; i++) {
    			int nx = node.x + dr[i];
    			int ny = node.y + dc[i];
    			if(0<=nx && nx<n && 0<=ny && ny<n) {
    				if(islands[nx][ny] == 0) {
    					q.add(new Pair(nx,ny));
    					islands[nx][ny] = islands[node.x][node.y];
    					distance[nx][ny] = distance[node.x][node.y] + 1; 
    				}
    			}
    		}
    	}

    	/*step3: find min*/
    	int min = Integer.MAX_VALUE;
    	for(int i = 0; i<n; i++) {
    		for(int j = 0; j<n; j++) {
    			for(int k = 0; k<4; k++) {
    				int nx = i + dr[k];
    				int ny = j + dc[k];
    				if(0<=nx && nx<n && 0<=ny && ny<n) {
    					if(islands[i][j] != islands[nx][ny]) {
    						if(min > distance[i][j] + distance[nx][ny]) {
    							min = distance[i][j] + distance[nx][ny];
    						}
    					}
    				}
    			}
    		}
    	}
    	System.out.println(min);
    }
}
