#include <iostream>
#include <string>
#include <cctype>   // Untuk fungsi toupper dan isdigit
#include <iomanip>  // Untuk formatting output
#include <vector>   // Untuk penggunaan vector
#include <algorithm>// Untuk transformasi string (tolower, toupper)

using namespace std;

// Fungsi untuk mengubah huruf menjadi angka berdasarkan urutan dalam alfabet
int hurufKeAngka(char huruf) {
    huruf = toupper(huruf); // Ubah huruf ke uppercase
    if (huruf >= 'A' && huruf <= 'Z') {
        return huruf - 'A' + 1; // Mengubah A menjadi 1, B menjadi 2, dst.
    }
    return 0; // Jika bukan huruf, nilai 0
}

// Fungsi untuk menghitung persentase kecocokan
int hitungPersentaseCocok(string nama1, string nama2, string tglLahir1, string tglLahir2, int umur1, int umur2) {
    // Gabungkan nama, tanggal lahir, dan umur menjadi satu string
    string gabungan = nama1 + nama2 + tglLahir1 + tglLahir2 + to_string(umur1) + to_string(umur2);
    int total = 0;

    // Menelusuri setiap karakter dari gabungan string
    for (char huruf : gabungan) {
        total += hurufKeAngka(huruf); // Mengubah karakter menjadi angka
        if (isdigit(huruf)) { // Jika karakter adalah digit (angka)
            total += huruf - '0'; // Tambahkan nilai digit langsung
        }
    }

    // Mengambil dua digit terakhir sebagai persentase
    return total % 100; 
}

// Fungsi untuk format nama (misalnya membuat huruf pertama menjadi kapital)
string formatNama(string nama) {
    // Ubah semua huruf menjadi lowercase terlebih dahulu
    transform(nama.begin(), nama.end(), nama.begin(), ::tolower);
    
    // Ubah huruf pertama menjadi uppercase
    if (!nama.empty()) {
        nama[0] = toupper(nama[0]);
    }
    
    return nama;
}

int main() {
    string nama1, nama2;
    string tglLahir1, tglLahir2;
    int umur1, umur2;

    // Input untuk nama pertama
    cout << "Masukkan nama pertama: ";
    getline(cin, nama1);

    // Input untuk tanggal lahir pertama
    cout << "Masukkan tanggal lahir pertama (DDMMYYYY): ";
    cin >> tglLahir1;

    // Input untuk umur pertama
    cout << "Masukkan umur pertama: ";
    cin >> umur1;
    cin.ignore(); // Mengabaikan newline agar getline berikutnya berfungsi dengan baik

    // Input untuk nama kedua
    cout << "Masukkan nama kedua: ";
    getline(cin, nama2);

    // Input untuk tanggal lahir kedua
    cout << "Masukkan tanggal lahir kedua (DDMMYYYY): ";
    cin >> tglLahir2;

    // Input untuk umur kedua
    cout << "Masukkan umur kedua: ";
    cin >> umur2;

    // Format nama
    nama1 = formatNama(nama1);
    nama2 = formatNama(nama2);

    // Menghitung persentase kecocokan
    int persentase = hitungPersentaseCocok(nama1, nama2, tglLahir1, tglLahir2, umur1, umur2);

    // Menampilkan hasil dengan format yang lebih baik menggunakan iomanip
    cout << fixed << setprecision(2); // Mengatur precision jika ingin hasil lebih presisi
    cout << "Persentase kecocokan antara " << nama1 << " dan " << nama2 << " adalah: " << persentase << "%" << endl;

    return 0;
}
