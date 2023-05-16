// Solid Rhombus Pattern

public class Pattern11 {
    public static void main(String[] args) {
        int n = 5;

        for (int i = 1; i <= n; i++) {

            // for first spaces
            for (int j = 1; j <= n - i; j++) {
                System.out.print(" ");
            }

            // for stars
            for (int j = 1; j <= n; j++) {
                System.out.print("*");
            }

            // for second spaces
            for (int j = n - i; j >= 1; j--) {
                System.out.print(" ");
            }
            System.out.println();
        }
    }
}