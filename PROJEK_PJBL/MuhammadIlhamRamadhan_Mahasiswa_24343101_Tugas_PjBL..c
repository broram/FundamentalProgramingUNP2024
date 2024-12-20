/*
	Nama File       : projekfunda.c
	Programmer      : Muhammad Ilham Ramadhan 24343101
	Tgl. pembuatan  : 11/12/2024
	Deskripsi       : Projek ini adalah projek pengelompokan nilai dengan menghitung kecepatan file atau input manual
*/

#include <stdio.h>
#include <time.h> // Untuk mengukur waktu

void biodata() {
    printf("Program pengelompokan nilai \n");
    printf("==========================================================\n");
    printf("Nama : Muhammad Ilham Ramadhan\n");
    printf("Nim  : 24343101\n");
    printf("==============================\n");
}

// Fungsi untuk memproses nilai dan menentukan kategori
void prosesNilai(FILE *outputFile, int nilai, int count) {
    if (nilai < 0 || nilai > 100) {
        if (outputFile) {
            fprintf(outputFile, "Nilai: %d - Error: Nilai tidak valid\n", nilai);
        } else {
            printf("Nilai: %d - Error: Nilai tidak valid\n", nilai);
        }
    } else {
        char kategori;
        if (nilai >= 85) {
            kategori = 'A';
        } else if (nilai >= 70) {
            kategori = 'B';
        } else if (nilai >= 55) {
            kategori = 'C';
        } else if (nilai >= 40) {
            kategori = 'D';
        } else {
            kategori = 'E';
        }
        if (outputFile) {
            fprintf(outputFile, "Nilai: %d - Kategori: %c\n", nilai, kategori);
        } else {
            printf("Nilai: %d - Kategori: %c\n", nilai, kategori);
        }
    }
}

int main() {
    biodata();

    int pilihan;
    char lanjut;

    do {
        printf("Pilih metode input:\n");
        printf("1. Input melalui file\n");
        printf("2. Input secara manual\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            FILE *inputFile;    // Pointer untuk file input
            FILE *outputFile;   // Pointer untuk file output
            int nilai;          // Variabel untuk menyimpan nilai dari file
            int count = 0;      // Variabel untuk menghitung jumlah data
            clock_t start, end; // Variabel untuk mencatat waktu

            // Mulai mengukur waktu
            start = clock();

            // Membuka file input
            inputFile = fopen("D:\\ramdan\\projek\\program funda\\input_3.txt", "r");
            if (inputFile == NULL) {
                printf("File input_3.txt tidak ditemukan!\n");
                return 1; // Keluar program jika file tidak ditemukan
            } else {
                printf("File input_3.txt ditemukan, memproses data...\n");
            }

            // Membuka file output
            outputFile = fopen("D:\\ramdan\\projek\\program funda\\output_3.txt", "w");
            if (outputFile == NULL) {
                printf("File output_3.txt tidak dapat dibuat!\n");
                fclose(inputFile);
                return 1;
            }

            // Membaca file input dan memproses nilai
            while (fscanf(inputFile, "%d", &nilai) != EOF) {
                count++;
                prosesNilai(outputFile, nilai, count);
            }

            // Menutup file
            fclose(inputFile);
            fclose(outputFile);

            // Menghentikan pengukuran waktu
            end = clock();

            // Menghitung waktu eksekusi
            double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Hasil telah disimpan ke output_3.txt\n");
            printf("Waktu eksekusi: %.5f detik\n", time_taken);
        } else if (pilihan == 2) {
            int nilai, count = 0;
            clock_t start, end; // Variabel untuk mencatat waktu

            // Mulai mengukur waktu
            start = clock();

            printf("Masukkan nilai (ketik -1 untuk berhenti):\n");
            while (1) {
                printf("Masukkan nilai: ");
                scanf("%d", &nilai);
                if (nilai == -1) {
                    break;
                }
                count++;
                prosesNilai(NULL, nilai, count);
            }

            // Menghentikan pengukuran waktu
            end = clock();

            // Menghitung waktu eksekusi
            double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Proses selesai.\n");
            printf("Waktu eksekusi: %.5f detik\n", time_taken);
        } else {
            printf("Pilihan tidak valid. Program dihentikan.\n");
        }

        printf("Apakah Anda ingin melanjutkan? (y/n): ");
        scanf(" %c", &lanjut);
    } while (lanjut == 'y' || lanjut == 'Y');

    printf("Program selesai.\n");
    return 0;
}
