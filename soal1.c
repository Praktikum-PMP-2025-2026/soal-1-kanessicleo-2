/*   EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 3 - Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Rabu, 29 April 2026
 *   Nama (NIM)          : Kanessi Cleo Kinanti (13224100)
 *   Nama File           : soal1.c
 *   Deskripsi           : Sebuah museum penelitian sedang merapikan basis data artefaknya. Setiap artefak 
 *                         tercatat dengan nama, kategori, tahun penemuan, dan nilai pentingnya. Karena arsip 
 *                         akan dipakai oleh beberapa divisi sekaligus, data harus diurutkan dengan aturan 
 *                         yang konsisten dan cukup rinci. Tugas Anda adalah membantu sistem arsip menghasilkan 
 *                         urutan akhir yang sesuai dengan prioritas pengelompokan yang telah disepakati. 
                           Urutkan data artefak dengan aturan multi-kriteria. 
    Kondisi/Aturan :
    1. Tiap artefak: nama kategori tahun nilai  
    2. Urutan:  
       • kategori alfabetis naik  
       • jika sama, tahun naik  
       • jika sama, nilai turun  
       • jika sama, nama alfabetis naik 
    Format Input :
    N nama1 kategori1 tahun1 nilai1 ... namaN kategoriN tahunN nilaiN 
    Format Output :
    nama kategori tahun nilai 
    Contoh Eksekusi Program : 
    3 Orb relik 2002 80 Rune kitab 1998 95 Aegis relik 1999 100 -> input
    Rune kitab 1998 95 
    Aegis relik 1999 100 
    Orb relik 2002 80 */

#include <stdio.h>
#include <string.h>

// Struct untuk artefak
typedef struct Artefak {
    char nama[100];
    char kategori[100];
    int tahun;
    int nilai;
} Artefak;

// Deklarasi fungsi
int pembanding(Artefak data1, Artefak data2); // return 1 saat b diurutkan sebelum a

// Main
int main() {
    int N;
    scanf("%d", &N);
    Artefak data[N], temp;
    for (int i = 0; i < N; i++) {
        scanf("%s %s %d %d", data[i].nama, data[i].kategori, &data[i].tahun, &data[i].nilai);
    }
    // bubble sort
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (pembanding(data[j], data[j+1])) { // tukar kalau 1
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp; 
                }
            }
        }
    for (int i = 0; i < N; i ++) {
        printf("%s %s %d %d\n", data[i].nama, data[i].kategori, data[i].tahun, data[i].nilai);
    }
    return 0;
}

// Implementasi fungsi
int pembanding(Artefak data1, Artefak data2) {
    // kategori naik
    if (strcmp(data1.kategori, data2.kategori) != 0) {
        return (strcmp(data1.kategori, data2.kategori) > 0);
    }
    // tahun naik
    else if (data1.tahun != data2.tahun) {
        return data1.tahun > data2.tahun;
    }
    // nilai turun
    else if (data1.nilai != data2.nilai) {
        return data1.nilai < data2.nilai;
    }
    // nama naik
    else {
        return (strcmp(data1.nama, data2.nama));
    }
}

// Referensi
// [1] https://www.geeksforgeeks.org/c/c-bubble-sort/
// [2] https://www.geeksforgeeks.org/c/strcmp-in-c/
