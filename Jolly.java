import java.util.Arrays;
import java.util.Scanner;

public class Jolly {

	// public static void main(String[] args) {
	//
	// Scanner sc = new Scanner(System.in);
	// int n = sc.nextInt();
	// int arr[] = new int[n];
	// int jollyArr[] = new int[n - 1];
	// boolean isJolly = true;
	//
	// for (int i = 0; i < arr.length; i++)
	// arr[i] = sc.nextInt();
	//
	// for (int i = 0; i < arr.length - 1; i++)
	// jollyArr[i] = Math.abs(arr[i + 1] - arr[i]);
	//
	// Arrays.sort(jollyArr);
	//
	// for(int i = 0 ; i<jollyArr.length; i++)
	// if(jollyArr[i]!= (i+1))
	// isJolly = false;
	//
	// if (isJolly)
	// System.out.println("Jolly");
	// else
	// System.out.println("Not jolly");
	//
	// }

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int arr[] = new int[n];
		boolean jollyArr[] = new boolean[n];
		boolean isJolly = true;

		for (int i = 0; i < arr.length; i++)
			arr[i] = sc.nextInt();

		for (int i = 0; i < arr.length - 1; i++) {

			int jollyIdx = Math.abs(arr[i + 1] - arr[i]);

			// 범위 벗어나면 안되
			if (jollyIdx >= n) {
				isJolly = false;
				break;
			}

			// 이미 true 라면 안되
			if (jollyArr[jollyIdx]) {
				isJolly = false;
				break;
			}
			jollyArr[jollyIdx] = true;
		}

//		if (isJolly) {
//			for (int i = 1; i < jollyArr.length; i++)
//				if (!jollyArr[i])
//					isJolly = false;
//		}

		if (isJolly)
			System.out.println("Jolly");
		else
			System.out.println("Not jolly");

	}

}
