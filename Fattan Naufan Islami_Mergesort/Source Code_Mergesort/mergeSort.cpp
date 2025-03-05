/*    
    Nama File : mergeSort.cpp
    Judul     : Implementasi Algoritma Mergesort dalam Bahasa C++
    Nama      : Fattan Naufan Islami
    NIM       : 23343037
    Prodi     : Informatika
*/

#include <iostream>
#include <vector>

using namespace std;

void gabungkan(vector<int>& array, int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    vector<int> bagian_kiri(n1), bagian_kanan(n2);

    // Salin data ke array sementara
    for (int i = 0; i < n1; i++)
        bagian_kiri[i] = array[kiri + i];
    for (int j = 0; j < n2; j++)
        bagian_kanan[j] = array[tengah + 1 + j];

    int i = 0, j = 0, k = kiri;

    // Gabungkan dua bagian yang sudah terurut
    while (i < n1 && j < n2) {
        if (bagian_kiri[i] <= bagian_kanan[j]) {
            array[k] = bagian_kiri[i];
            i++;
        } else {
            array[k] = bagian_kanan[j];
            j++;
        }
        k++;
    }

    // Salin elemen yang tersisa, jika ada
    while (i < n1) {
        array[k] = bagian_kiri[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = bagian_kanan[j];
        j++;
        k++;
    }
}

void urutkan(vector<int>& array, int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2; // Temukan titik tengah

        urutkan(array, kiri, tengah); // Rekursif untuk bagian kiri
        urutkan(array, tengah + 1, kanan); // Rekursif untuk bagian kanan

        gabungkan(array, kiri, tengah, kanan); // Gabungkan kedua bagian
    }
}

int main() {
    vector<int> array = {12, 11, 13, 5, 6, 7};
    int n = array.size();

    urutkan(array, 0, n - 1);

    cout << "Array yang terurut: ";
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;

    return 0;
}
