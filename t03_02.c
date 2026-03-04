#include <stdio.h>
#include <limits.h> // Untuk INT_MAX dan INT_MIN
#include <float.h>  // Untuk DBL_MAX
#include <stdlib.h> // Untuk malloc dan free

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

    // Alokasikan array untuk menyimpan n bilangan
    int *numbers = (int *)malloc(n * sizeof(int));
    if (numbers == NULL) {
        return 1; // Keluar dengan kode error
    }

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

    printf("Nilai terkecil: %d\n", min_val);
    printf("Nilai terbesar: %d\n", max_val);
    
    // --- Triple Dazz ---
    // Fitur Baru: Menghitung rata-rata dari setiap 2 bilangan berurutan dan mencari yang terkecil
    double min_avg_consecutive = DBL_MAX; // Inisialisasi dengan nilai double terbesar
    
    if (n < 2) {
    } else {
        for (int i = 0; i < n - 1; i++) {
            // Hitung rata-rata pasangan berurutan
            double current_avg = (double)(numbers[i] + numbers[i+1]) / 2.0;
            
            // Perbarui nilai rata-rata terkecil jika ditemukan yang lebih kecil
            if (current_avg < min_avg_consecutive) {
                min_avg_consecutive = current_avg;
            }
        }
        printf(" %.2f\n", min_avg_consecutive);
    }


    free(numbers); // Bebaskan memori yang dialokasikan untuk array
    return 0;
}