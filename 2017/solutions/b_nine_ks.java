import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		try {
			inputStream = new FileInputStream("nine.in");
			outputStream = new FileOutputStream("nine.out");
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}

		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Solver solver = new Solver();
		solver.solve(in, out);
		out.close();
	}
}

class Solver {
	int dsum(String s) {
		int res = 0;
		for (int i = 0; i < s.length(); ++i) {
			res += s.charAt(i) - '0';
		}
		return res;
	}
	public void solve(InputReader in, PrintWriter out) {
		String a = in.next();
		String b = in.next();
		out.println((dsum(a) * dsum(b) % 9 == 0) ? "Yes" : "No");
	}
}

class InputReader {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
