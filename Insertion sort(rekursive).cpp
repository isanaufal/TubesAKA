#include <iostream>
using namespace std;

// Struct cafe untuk menyimpan data kafe
struct cafe {
    int rating;         // Rating kafe
    bool wifi;          // Apakah kafe memiliki WiFi
    bool cashless;      // Apakah kafe mendukung pembayaran non-tunai
};

const int Nmax = 150;    // Kapasitas maksimum array
cafe arrcaf[Nmax];       // Array kafe
int n = 0;               // Jumlah data kafe

cafe* descendingrekomen(cafe arrcaf[], int n) {
    if (n <= 1) return arrcaf;

    // Urutkan n-1 elemen pertama
    descendingrekomen(arrcaf, n - 1);

    // Sisipkan elemen terakhir pada posisi yang sesuai
    cafe key = arrcaf[n - 1];
    int keyPrio = 0;
    if (key.wifi) {
        keyPrio++;
    }
    if (key.cashless) {
        keyPrio++;
    }
    int i = n - 2;
    while (i >= 0) {
        int currentPrio = 0;
        if (arrcaf[i].wifi) {
            currentPrio++;
        }
        if (arrcaf[i].cashless) {
            currentPrio++;
        }
        if (arrcaf[i].rating < key.rating ||
            (arrcaf[i].rating == key.rating && currentPrio < keyPrio)) {
            arrcaf[i + 1] = arrcaf[i];
            i--;
        } else {
            break;
        }
    }
    arrcaf[i + 1] = key;

    return arrcaf;
}

int main() {
    int i = 0;

    // Data awal kafe
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

    // Salin data ke array global dan hitung jumlah elemen
    while (data[i].rating != 0) {
        arrcaf[i] = data[i];
        i++;
        n++;
    }

    // Tampilkan daftar kafe sebelum rekomendasi
    cout << "Sebelum Rekomendasi:" << endl;
    for (i = 0; i < n; i++) {
        cout << "Kafe " << i + 1 << ":" << endl;
        cout << "  Rating: " << arrcaf[i].rating << endl;
        cout << "  WiFi: " << (arrcaf[i].wifi ? "Yes" : "No") << endl;
        cout << "  Cashless: " << (arrcaf[i].cashless ? "Yes" : "No") << endl;
    }

    // Jalankan fungsi rekomendasi
    cafe* sortedArr = descendingrekomen(arrcaf, n);

    // Tampilkan daftar kafe setelah rekomendasi
    cout << "\nSetelah Rekomendasi (diurutkan berdasarkan rating dan prioritas fitur):" << endl;
    for (i = 0; i < n; i++) {
        cout << "Kafe " << i + 1 << ":" << endl;
        cout << "  Rating: " << sortedArr[i].rating << endl;
        cout << "  WiFi: " << (sortedArr[i].wifi ? "Yes" : "No") << endl;
        cout << "  Cashless: " << (sortedArr[i].cashless ? "Yes" : "No") << endl;
    }
    return 0;
}
