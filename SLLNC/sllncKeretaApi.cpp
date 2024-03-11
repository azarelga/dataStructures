#include <iostream>
#include <list>
using namespace std;

typedef struct Gerbong {
  char namaGerbong[1000];
  int jumlahKursi;
} Gerbong;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  list<Gerbong> keretaApi;

  Gerbong gerbong1 = {"Ekonomi - 1", 100};
  Gerbong gerbong2 = {"Bisnis - 1", 50};
  Gerbong gerbong3 = {"Eksekutif - 1", 20};
  Gerbong gerbong4 = {"Eksekutif - 2", 20};

  // Menambahkan gerbong ke dalam kereta api
  keretaApi.push_back(gerbong1);
  keretaApi.push_back(gerbong2);
  keretaApi.push_back(gerbong3);
  keretaApi.push_back(gerbong4);

  // Menghapuskan gerbong pada indeks ke-2
  auto it = keretaApi.begin();
  advance(it, 2);
  keretaApi.erase(it);

  // Menampilkan semua gerbong yang ada
  for (auto it = keretaApi.begin(); it != keretaApi.end(); it++) {
    cout << "Nama Gerbong: " << it->namaGerbong << endl;
    cout << "Jumlah Kursi: " << it->jumlahKursi << endl;
    cout << "=============================" << endl;
  }

  // Mencetak gerbong ke-3 pada keretaApi
  auto it1 = keretaApi.begin();
  advance(it1, 2);
  cout << "Nama Gerbong: " << it1->namaGerbong << endl;
  cout << "Jumlah Kursi: " << it1->jumlahKursi << endl;
}
