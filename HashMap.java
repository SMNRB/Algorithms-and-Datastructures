package algodat_hw6;

public class HashMap {
	static int hashMap(String s) { 
	int h=0;
	for (int i=0; i < s.length(); i++) {
		// 5–bit cyclic shift of the running sum:
		h = (h << 5) | (h >>> 27);
		h += (int) s.charAt(i); // add in next character
		}
	return h; 
	}
	

	
	private static int N = 101319;
	
	static int compressHash(int hash) {
		return hash % N;
	}
}