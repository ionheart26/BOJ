//brute force
//알파벳을 조합해보고 단어의 최대개수를 구한다
//단어의 비교는 비트마스크를 이용한다: 26개의 알파벳이므로 32비트int로 표현가능하다
import java.util.*;

public class Main{
	static int ans = 0;
	static int[] words;
	public static void main(String[] args) {
		//input
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		words = new int[n];
		for(int i = 0; i<n; i++) {
			String input = sc.next();
			for(char c: input.toCharArray()) {
				words[i] |= (1<<(c-'a'));
			}
		}
		go(0,k,0);
		System.out.println(ans);
	}
	static void go(int index, int k, int mask) {
		//backtracking
		if(k<0) return;
		//base case
		if(index == 26) {
			int temp = count(mask);
			if(ans < temp) {
				ans = temp;
			}
			return;
		}
		//recursion
		if(index==('a'-'a') || index==('n'-'a') || index==('t'-'a') || index==('i'-'a') || index==('c'-'a')) {
			go(index+1, k-1, mask|(1<<index));
		}
		else {
			go(index+1, k-1, mask|(1<<index));
			go(index+1, k, mask);
		}
	}
	static int count(int mask) {
		int cnt = 0;
		for(int word: words) {
			if((word & ((1<<26)-1-mask))==0) {
				cnt++;
			}
		}
		return cnt;
	}
}
