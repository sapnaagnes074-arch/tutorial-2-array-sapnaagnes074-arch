#include <stdio.h>
#include <limits.h> // Untuk INT_MAX dan INT_MIN

int main() {
    int n;

    // --- Validasi Input n ---
    // Memastikan n adalah bilangan bulat positif
    do {
        if (scanf("%d", &n) != 1 || n <= 0) {
            // Membersihkan buffer input jika input tidak valid
            while (getchar() != '\n');
        }
    } while (n <= 0);

    // Inisialisasi nilai minimum dan maksimum dengan nilai ekstrem
    // Ini memastikan bahwa setiap angka yang valid akan lebih besar dari min_val dan lebih kecil dari max_val pada iterasi pertama.
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    int num;

    printf("%d", n);

    for (int i = 0; i < n; i++) {
        // --- Validasi Input Bilangan ---
        // Memastikan bilangan berada dalam rentang -100 sampai 100
        do {
            printf("Bilangan ke-%d: ", i + 1);
            if (scanf("%d", &num) != 1 || num < -100 || num > 100) {
                // Membersihkan buffer input jika input tidak valid
                while (getchar() != '\n');
            }
        } while (num < -100 || num > 100);

        // Memperbarui nilai minimum
        if (num < min_val) {
            min_val = num;
        }

        // Memperbarui nilai maksimum
        if (num > max_val) {
            max_val = num;
        }
    }

    printf(" %d\n", min_val);
    printf("%d\n", max_val);
    return 0;
}