public class TaxicabNumbers {
    public static void findTaxicabNumbers(int n) {
        for (int a = 1; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                for (int c = a; c < n; c++) {
                    for (int d = c + 1; d < n; d++) {
                        if ((a * a * a + b * b * b) == (c * c * c + d * d * d)) {
                            System.out.println(a + "^3 + " + b + "^3 = " + c + "^3 + " + d + "^3");
                        }
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        int n = 1000; // You can adjust this value based on your needs
        findTaxicabNumbers(n);
    }
}
