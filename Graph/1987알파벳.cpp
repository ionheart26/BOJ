//brute force
//경로를 만든다: 3의 26제곱?
//base case는 알파벳이 중복될 경우이다
//함수호출마다 최대값을 비교한다
import java.util.*;

class Pair{
	int r, c;
	Pair(int r, int c){
		this.r = r;
		this.c = c;
	}
}
public class Main{
	static int r,c;
	static char[][] map;
	static boolean[] used = new boolean[26];
	static final int[] dr = {-1, 0, 1, 0};
	static final int[] dc = {0, 1, 0, -1};
	public static void main(String[] args) {
		//input
		Scanner sc = new Scanner(System.in);
		r = sc.nextInt();
		c = sc.nextInt();
		map = new char[r][c];
		for(int i = 0; i<r; i++) {
			String input = sc.next();
			for(int j = 0; j<c; j++) {
				map[i][j] = input.charAt(j);
			}
		}
		used[map[0][0]-'A'] = true;
		System.out.println(go(1, new Pair(0,0)));
	}
	static int go(int cnt, Pair p) {
		int ans = cnt;
		int tr = p.r;
		int tc = p.c;
		for(int i = 0; i<4; i++) {
			int nr = tr + dr[i];
			int nc = tc + dc[i];
			if(0<=nr && nr<r && 0<=nc && nc<c) {
				int nCharIndex = map[nr][nc]-'A';
				if(!used[nCharIndex]) {
					used[nCharIndex] = true;
					int temp = go(cnt+1, new Pair(nr, nc));
					if(ans < temp) ans = temp;
					used[nCharIndex] = false;
				}
			}
		}
		return ans;
	}
}
