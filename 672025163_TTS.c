#include <stdio.h>

// 1. Pembuatan Struct Mahasiswa
struct Mahasiswa {
    char nama[51];
    char nim[21];
    float nilai_tugas;
    float nilai_uts;
    float nilai_uas;
    float nilai_akhir;
    char grade;
};

int main() {
    // 2. Batasan Input Data (Maksimal 50 mahasiswa)
    struct Mahasiswa mhs[50];
    int jumlah_mhs;

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &jumlah_mhs);

    // Validasi agar tidak melebihi kapasitas array
    if (jumlah_mhs > 50) {
        printf("Kapasitas maksimal hanya 50 mahasiswa!\n");
        return 1;
    }

    // 3. Proses Input data mahasiswa
    for (int i = 0; i < jumlah_mhs; i++) {
        printf("\nData Mahasiswa ke-%d\n", i + 1);
        
        printf("Nama : ");
        scanf(" %[^\n]s", mhs[i].nama); 
        printf("NIM  : ");
        scanf("%s", mhs[i].nim);
        
        printf("Nilai Tugas : ");
        scanf("%f", &mhs[i].nilai_tugas);
        
        printf("Nilai UTS   : ");
        scanf("%f", &mhs[i].nilai_uts);
        
        printf("Nilai UAS   : ");
        scanf("%f", &mhs[i].nilai_uas);

        mhs[i].nilai_akhir = (0.20 * mhs[i].nilai_tugas) + (0.30 * mhs[i].nilai_uts) + (0.50 * mhs[i].nilai_uas);

        if (mhs[i].nilai_akhir >= 80) {
            mhs[i].grade = 'A';
        } else if (mhs[i].nilai_akhir >= 70) {
            mhs[i].grade = 'B';
        } else if (mhs[i].nilai_akhir >= 60) {
            mhs[i].grade = 'C';
        } else if (mhs[i].nilai_akhir >= 50) {
            mhs[i].grade = 'D';
        } else {
            mhs[i].grade = 'E';
        }
    }

    // 4. Format Output berbentuk tabel
    printf("\n=========================================================================================\n");
    printf("| %-25s | %-15s | %-7s | %-7s | %-7s | %-11s | %-5s |\n", "Nama", "NIM", "Tugas", "UTS", "UAS", "Nilai Akhir", "Grade");
    printf("=========================================================================================\n");
    
    for (int i = 0; i < jumlah_mhs; i++) {
        printf("| %-25s | %-15s | %-7.2f | %-7.2f | %-7.2f | %-11.2f | %-5c |\n", 
               mhs[i].nama, 
               mhs[i].nim, 
               mhs[i].nilai_tugas, 
               mhs[i].nilai_uts, 
               mhs[i].nilai_uas, 
               mhs[i].nilai_akhir, 
               mhs[i].grade);
    }
    printf("=========================================================================================\n");

    return 0;
}