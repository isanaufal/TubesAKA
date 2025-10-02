#include <iostream>
using namespace std;

// Struct cafe untuk menyimpan data kafe
struct cafe {
    int rating;         // Rating kafe
    bool wifi;          // Apakah kafe memiliki WiFi
    bool cashless;      // Apakah kafe mendukung pembayaran non-tunai
};

const int Nmax = 25;    // Kapasitas maksimum array
cafe arrcaf[Nmax];      // Array kafe

// Fungsi untuk mengurutkan dengan selection sort
void descendingrekomen(cafe arrcaf[], int n) {
    cafe temp;
    int maxIndex = n; // Indeks elemen maksimum saat ini
    int maxprio = 0;

    // Hitung prioritas untuk elemen awal
    if (arrcaf[n].wifi) {
        maxprio++;
    }
    if (arrcaf[n].cashless) {
        maxprio++;
    }
    for (int i = n + 1; i < Nmax; i++) {
        int prio = 0;
        // Hitung prioritas elemen ke-i
        if (arrcaf[i].wifi) {
            prio++;
        }
        if (arrcaf[i].cashless) {
            prio++;
        }
        // Perbandingan rating dan prioritas
        if (arrcaf[i].rating > arrcaf[maxIndex].rating ||
            (arrcaf[i].rating == arrcaf[maxIndex].rating && prio > maxprio)) {
            maxIndex = i;
            maxprio = prio; // Update prioritas maksimum
        }
    }
    // Tukar elemen maksimum dengan elemen saat ini
    if (maxIndex != n) {
        temp = arrcaf[n];
        arrcaf[n] = arrcaf[maxIndex];
        arrcaf[maxIndex] = temp;
    }
}

int main() {
    int n = 25; // Jumlah data kafe
    // Data 25 kafe
    cafe data[] = {
        {5, true, true}, {4, true, false}, {3, false, true}, {2, true, true},
        {1, false, false}, {4, true, false}, {5, false, false}, {3, false, true},
        {4, true, true}, {2, false, false}, {5, true, false}, {1, false, true},
        {3, true, false}, {4, false, true}, {5, true, false}, {2, true, true},
        {3, true, false}, {4, false, false}, {5, true, true}, {1, false, true},
        {3, true, true}, {2, false, true}, {4, true, true}, {5, false, true},
        {3, false, true}
    };

    // Salin data ke array global
    for (int i = 0; i < n; i++) {
        arrcaf[i] = data[i];
    }

    // Tampilkan daftar kafe sebelum rekomendasi
    cout << "Sebelum Rekomendasi:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Kafe " << i + 1 << ":" << endl;
        cout << "  Rating: " << arrcaf[i].rating << endl;
        cout << "  WiFi: " << (arrcaf[i].wifi ? "Yes" : "No") << endl;
        cout << "  Cashless: " << (arrcaf[i].cashless ? "Yes" : "No") << endl;
    }

    // Jalankan fungsi rekomen
    for (int i = 0; i < n; i++) {
        descendingrekomen(arrcaf, i);
    }

    // Tampilkan daftar kafe setelah rekomendasi
    cout << "\nSetelah Rekomendasi (diurutkan berdasarkan rating dan prioritas fitur):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Kafe " << i + 1 << ":" << endl;
        cout << "  Rating: " << arrcaf[i].rating << endl;
        cout << "  WiFi: " << (arrcaf[i].wifi ? "Yes" : "No") << endl;
        cout << "  Cashless: " << (arrcaf[i].cashless ? "Yes" : "No") << endl;
    }

    return 0;
}
