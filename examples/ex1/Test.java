import ex.TTYUtil;
public class Test {
  static {
    try {
    	// System.load("/Users/millad/temp/java-c-interface/libttyutil.so");
    	System.loadLibrary("ttyutil");
    } catch (UnsatisfiedLinkError e) {
      System.err.println("Native code library failed to load.\n" + e);
      System.exit(1);
    }
  }

    public static void main(String[] args) {
        if (TTYUtil.isTTY()) {
            System.out.println("TTY: "+TTYUtil.getTTYName());
            String str = TTYUtil.getReptition("Hello from Millad", 5);
            System.out.print(str);

            int n = 10000000;
            double []arr = new double[n];
            // ByteBuffer byteBuff = ByteBuffer.allocateDirect(n*Double.BYTES);
            // double []arr = byteBuff.array();
            for(int i=0;i<n;i++)
            	arr[i] = i;
            double avg = TTYUtil.getAvg(arr);
            System.out.print("The avg is ");
            System.out.println(avg);
            avg = TTYUtil.getAvg(arr);
            System.out.print("The avg is ");
            System.out.println(avg);
        } else {
            System.out.println("Not a TTY");
        }
    }
}
