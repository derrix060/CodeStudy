import java.io.*;
import java.util.*;
 
 
class Main{
   public static void main(String[] args) {
       MyScanner sc = new MyScanner();
       out = new PrintWriter(new BufferedOutputStream(System.out));

        int size = sc.nextInt();
        Stack<Integer> parenthesis = new Stack<>();
        int max = 0;
        int count = 0;
        int last = 0;

        while(size-- != 0){
            int numb = sc.nextInt();
            if (numb > 0){
                if (!parenthesis.isEmpty()){
                    last = count;
                    count = 0;
                }
                parenthesis.push(numb);
            }
            if (numb < 0){
                if (!parenthesis.isEmpty()){
                    int temp = parenthesis.pop();
                    if (temp == (-numb)){
                        count ++;
                        if(parenthesis.isEmpty()){
                            count += last;
                        }
                        max = count > max ? count : max;
                    }
                    else{
                        // Wrong number
                        count = 0;
                        last = 0;
                        parenthesis.clear();
                    }
                }
            }
        }
        out.println(max * 2);

            
        //}
        // Start writing your solution here. -------------------------------------
    
        /*
        int n      = sc.nextInt();        // read input as integer
        long k     = sc.nextLong();       // read input as long
        double d   = sc.nextDouble();     // read input as double
        String str = sc.next();           // read input as String
        String s   = sc.nextLine();       // read whole line as String

        int result = 3*n;
        out.println(result);                    // print via PrintWriter
        */

        // Stop writing your solution here. -------------------------------------
        out.close();
   }

     

   //-----------PrintWriter for faster output---------------------------------
   public static PrintWriter out;
      
   //-----------MyScanner class for faster input----------
   public static class MyScanner {
      BufferedReader br;
      StringTokenizer st;
 
      public MyScanner() {
         br = new BufferedReader(new InputStreamReader(System.in));
      }
 
      String next() {
          while (st == null || !st.hasMoreElements()) {
              try {
                  st = new StringTokenizer(br.readLine());
              } catch (IOException e) {
                  e.printStackTrace();
              }
          }
          return st.nextToken();
      }
 
      int nextInt() {
          return Integer.parseInt(next());
      }
 
      long nextLong() {
          return Long.parseLong(next());
      }
 
      double nextDouble() {
          return Double.parseDouble(next());
      }
 
      String nextLine(){
          String str = "";
	  try {
	     str = br.readLine();
	  } catch (IOException e) {
	     e.printStackTrace();
	  }
	  return str;
      }

   }
   //--------------------------------------------------------
}