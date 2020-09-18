import java.util.*;
import java.io.*;
public class Main {
	//start부터 end까지 존재하는 2개의 배열을 merge한다
	//cnt를 리턴
	static long mergeSort(int[] a, int start, int end) {
		if(start == end) return 0;
		int mid = (start+end)/2;
		long cnt = mergeSort(a, start, mid) + mergeSort(a, mid+1, end);
		int[] temp = new int[end-start+1];
		int i = start, j = mid + 1, k = 0;
		while(i<=mid && j<=end) {
			if(a[i] <= a[j]) temp[k++] = a[i++];
			else {
				cnt += (long)(mid-i+1);
				temp[k++] = a[j++];
			}
		}
		while(i<=mid) temp[k++] = a[i++];
		while(j<=end) temp[k++] = a[j++];
		for(i = start; i<=end; i++) {
			a[i] = temp[i-start];
		}
		return cnt;
	}
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.valueOf(br.readLine());
        int[] a = new int[n];
        String[] line = br.readLine().split(" ");
        for (int i=0; i<n; i++) {
            a[i] = Integer.valueOf(line[i]);
        }
        long ans = mergeSort(a, 0, n-1);
        System.out.println(ans);
    }
}
