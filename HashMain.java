package algodat_hw6;

public class HashMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		HashMap HM = new HashMap();
		System.out.println("Not compressed:");
		System.out.println(HM.hashMap("Boot"));
		System.out.println(HM.hashMap("Boat"));
		System.out.println(HM.hashMap("Tom"));
		System.out.println(HM.hashMap("Neurology"));
		System.out.println("Compressed:");
		System.out.println(HM.compressHash(HM.hashMap("Boot")));
		System.out.println(HM.compressHash(HM.hashMap("Boat")));
		System.out.println(HM.compressHash(HM.hashMap("Tom")));
		System.out.println(HM.compressHash(HM.hashMap("Neurology")));
		
		// I dont have any collisions
		// load factor of 4 / N
		System.out.println(4 / 101319);
	}

}
