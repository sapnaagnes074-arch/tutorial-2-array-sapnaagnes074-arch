#include <stdio.h>
#include <limits.h> // Untuk INT_MAX dan INT_MIN

int main() {
    int n;

    // --- Validasi Input n ---
    // Memastikan n adalah bilangan bulat positif
    do {
        printf("Masukkan jumlah bilangan (n > 0): ");
        if (scanf("%d", &n) != 1 || n <= 0) {
            printf("Input tidak valid. Harap masukkan bilangan bulat positif.\n");
            // Membersihkan buffer input jika input tidak valid
            while (getchar() != '\n');
        }
    } while (n <= 0);

    // Inisialisasi nilai minimum dan maksimum dengan nilai ekstrem
    // Ini memastikan bahwa setiap angka yang valid akan lebih besar dari min_val dan lebih kecil dari max_val pada iterasi pertama.
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    int num;

    printf("Masukkan %d bilangan bulat antara -100 dan 100:\n", n);

    for (int i = 0; i < n; i++) {
        // --- Validasi Input Bilangan ---
        // Memastikan bilangan berada dalam rentang -100 sampai 100
        do {
            printf("Bilangan ke-%d: ", i + 1);
            if (scanf("%d", &num) != 1 || num < -100 || num > 100) {
                printf("Input tidak valid. Harap masukkan bilangan bulat antara -100 dan 100.\n");
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

    printf("--- Hasil Program ---\n");
    printf("Nilai terkecil: %d\n", min_val);
    printf("Nilai terbesar: %d\n", max_val);
    printf("--- Akhir Program ---\n");

    return 0;
}