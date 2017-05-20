import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author aluno
 */
public class logica {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        BigInteger b;
        
        Scanner sc = new Scanner(System.in);
        String br = sc.next();
        
        b = new BigInteger(br);
        BigInteger b3 = new BigInteger("3");
        if (b.mod(b3).toString().equals("0")){
            System.out.println("par");
        }
        else
            System.out.println("impar");
    }
    
}
