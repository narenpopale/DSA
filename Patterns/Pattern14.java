// Diamond Pattern

public class Pattern14 {
    public static void main(String[] args) {
        int n = 4;

        // for upper half
        for (int i = 1; i <= n; i++) {

            // for spaces
            for (int j = 1; j <= n - i; j++) {
                System.out.print(" ");
            }

            // for first half
            for (int j = 1; j <= i; j++) {
                System.out.print("*");
            }

            // for second half
            for (int j = 1; j < i; j++) {
                System.out.print("*");
            }

            System.out.println();
        }

        // for lower half
        for (int i = n; i >= 1; i--) {

            // for spaces
            for (int j = 1; j <= n - i; j++) {
                System.out.print(" ");
            }

            // for first half
            for (int j = 1; j <= i; j++) {
                System.out.print("*");
            }

            // for second half
            for (int j = 1; j < i; j++) {
                System.out.print("*");
            }

            System.out.println();
        }
    }
}
