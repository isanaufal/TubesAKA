#include <iostream>
using namespace std;

// Struct cafe untuk menyimpan data kafe
struct cafe {
    int rating;         // Rating kafe
    bool wifi;          // Apakah kafe memiliki WiFi
    bool cashless;      // Apakah kafe mendukung pembayaran non-tunai
};

const int Nmax = 150;    // Kapasitas maksimum array
cafe arrcaf[Nmax];      // Array kafe

// Fungsi untuk mengurutkan dengan selection sort
void descendingrekomen(cafe arrcaf[], int x) {
    cafe temp;
    int n = Nmax;
    int maxIndex = x; // Indeks elemen maksimum saat ini
    int maxprio = 0;
    // Hitung prioritas untuk elemen awal
    if (arrcaf[x].wifi) {
        maxprio++;
    }
    if (arrcaf[x].cashless) {
        maxprio++;
    }
    for (int i = x + 1; i < n; i++) {
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
    if (maxIndex != x) {
        temp = arrcaf[x];
        arrcaf[x] = arrcaf[maxIndex];
        arrcaf[maxIndex] = temp;
    }
}

int main() {
    int i = 0;
    int n = 0;
cafe data[] = {
    {5, true, true}, {4, false, true}, {3, true, false}, {5, true, false}, {4, true, true},
    {2, false, false}, {1, true, false}, {3, false, true}, {4, false, false}, {5, true, true},
    {3, true, true}, {2, false, true}, {1, true, false}, {5, false, false}, {4, true, true},
    {3, false, false}, {5, true, false}, {4, false, true}, {2, true, false}, {1, false, false},
    {5, true, true}, {3, true, false}, {4, false, true}, {5, true, false}, {3, true, true},
    {2, false, false}, {4, true, false}, {3, false, true}, {1, true, false}, {5, false, false},
    {5, true, true}, {4, false, true}, {3, true, false}, {5, true, false}, {4, true, true},
    {2, false, false}, {1, true, false}, {3, false, true}, {4, false, false}, {5, true, true},
    {3, true, true}, {2, false, true}, {1, true, false}, {5, false, false}, {4, true, true},
    {3, false, false}, {5, true, false}, {4, false, true}, {2, true, false}, {1, false, false},
    {5, true, true}, {3, true, false}, {4, false, true}, {5, true, false}, {3, true, true},
    {2, false, false}, {4, true, false}, {3, false, true}, {1, true, false}, {5, false, false},
    {5, true, true}, {4, false, true}, {3, true, false}, {5, true, false}, {4, true, true},
    {2, false, false}, {1, true, false}, {3, false, true}, {4, false, false}, {5, true, true},
    {3, true, true}, {2, false, true}, {1, true, false}, {5, false, false}, {4, true, true},
    {3, false, false}, {5, true, false}, {4, false, true}, {2, true, false}, {1, false, false},
    {5, true, true}, {3, true, false}, {4, false, true}, {5, true, false}, {3, true, true},
    {2, false, false}, {4, true, false}, {3, false, true}, {1, true, false}, {5, false, false},
    {5, true, true}, {4, false, true}, {3, true, false}, {5, true, false}, {4, true, true},
    {2, false, false}, {1, true, false}, {3, false, true}, {4, false, false}, {5, true, true},
    {3, true, true}, {2, false, true}, {1, true, false}, {5, false, false}, {4, true, true},
    {3, false, false}, {5, true, false}, {4, false, true}, {2, true, false}, {1, false, false},
    {5, true, true}, {3, true, false}, {4, false, true}, {5, true, false}, {3, true, true},
    {2, false, false}, {4, true, false}, {3, false, true}, {1, true, false}, {5, false, false},
    {5, true, true}, {4, false, true}, {3, true, false}, {5, true, false}, {4, true, true},
    {2, false, false}, {1, true, false}, {3, false, true}, {4, false, false}, {5, true, true},
    {3, true, true}, {2, false, true}, {1, true, false}, {5, false, false}, {4, true, true},
    {3, false, false}, {5, true, false}, {4, false, true}, {2, true, false}, {1, false, false},
    {5, true, true}, {3, true, false}, {4, false, true}, {5, true, false}, {3, true, true},
    {5, false, true}, {3, false, false}, {4, true, true}, {5, false, false}, {3, false, true},
    {0, false, false}

};


    // Salin data ke array global
    while (data[i].rating != 0) {
        arrcaf[i] = data[i];
        i++;
        n++;
    }

    // Tampilkan daftar kafe sebelum rekomendasi
    cout << "Sebelum Rekomendasi:" << endl;
    for ( i = 0; i < n; i++) {
        cout << "Kafe " << i + 1 << ":" << endl;
        cout << "  Rating: " << arrcaf[i].rating << endl;
        cout << "  WiFi: " << (arrcaf[i].wifi ? "Yes" : "No") << endl;
        cout << "  Cashless: " << (arrcaf[i].cashless ? "Yes" : "No") << endl;
    }

    // Jalankan fungsi rekomen
    for ( i = 0; i < n; i++) {
        descendingrekomen(arrcaf, i);
    }

    // Tampilkan daftar kafe setelah rekomendasi
    cout << "\nSetelah Rekomendasi (diurutkan berdasarkan rating dan prioritas fitur):" << endl;
    for ( i = 0; i < n; i++) {
        cout << "Kafe " << i + 1 << ":" << endl;
        cout << "  Rating: " << arrcaf[i].rating << endl;
        cout << "  WiFi: " << (arrcaf[i].wifi ? "Yes" : "No") << endl;
        cout << "  Cashless: " << (arrcaf[i].cashless ? "Yes" : "No") << endl;
    }

    return 0;
}
