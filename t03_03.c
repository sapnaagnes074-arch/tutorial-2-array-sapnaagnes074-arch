#include <stdio.h>
#include <limits.h> // Untuk INT_MAX dan INT_MIN
#include <float.h>  // Untuk DBL_MAX dan DBL_MIN

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

    // Deklarasi array untuk menyimpan n bilangan
    // Menggunakan Variable Length Array (VLA), yang didukung di C99
    int numbers[n]; 

    // Inisialisasi nilai minimum dan maksimum dengan nilai ekstrem
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    int num;

    printf("%d", n);

    for (int i = 0; i < n; i++) {
        // --- Validasi Input Bilangan ---
        // Memastikan bilangan berada dalam rentang -100 sampai 100
        do {
            printf("%d: ", i + 1);
            if (scanf("%d", &num) != 1 || num < -100 || num > 100) {
                // Membersihkan buffer input jika input tidak valid
                while (getchar() != '\n');
            }
        } while (num < -100 || num > 100);

        numbers[i] = num; // Simpan bilangan ke dalam array

        // Memperbarui nilai minimum
        if (num < min_val) {
            min_val = num;
        }

        // Memperbarui nilai maksimum
        if (num > max_val) {
            max_val = num;
        }
    }

    // --- Output Hasil Minimum dan Maksimum ---
    printf(" %d\n", min_val);
    printf(" %d\n", max_val);
    
    // --- Hitung rata-rata terkecil dan tertinggi dari 2 bilangan berurutan ---
    double min_avg_consecutive = DBL_MAX; // Inisialisasi dengan nilai double terbesar
    double max_avg_consecutive = DBL_MIN; // Inisialisasi dengan nilai double terkecil
    
    if (n < 2) {
        // Jika n kurang dari 2, tidak ada pasangan bilangan berurutan
    } else {
        for (int i = 0; i < n - 1; i++) { // Loop sampai n-1 agar numbers[i+1] valid
            double current_avg = (double)(numbers[i] + numbers[i+1]) / 2.0;
            
            // Perbarui nilai rata-rata terkecil
            if (current_avg < min_avg_consecutive) {
                min_avg_consecutive = current_avg;
            }
            
            // Perbarui nilai rata-rata tertinggi
            if (current_avg > max_avg_consecutive) {
                max_avg_consecutive = current_avg;
            }
        }
        printf(" %.2f\n", min_avg_consecutive);
        printf("%.2f\n", max_avg_consecutive);
    }


    return 0;
}