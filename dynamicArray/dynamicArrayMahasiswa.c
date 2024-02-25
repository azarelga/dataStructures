#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int ll;
typedef unsigned long long int ull;

typedef struct mahasiswa {
  char nama[100];
  float ipk;
} Mahasiswa;

typedef struct darray {
  Mahasiswa *arr;
  unsigned size, capacity;
} DynamicArray;

void init(DynamicArray *darray) {
  darray->capacity = 2;
  darray->size = 0;
  darray->arr = (Mahasiswa *)malloc(sizeof(Mahasiswa) * 2);
}

bool isEmpty(DynamicArray *darray) { return (darray->size == 0); }

void popBack(DynamicArray *darray) {
  if (!isEmpty(darray))
    darray->size--;
  else
    return;
}

void pushBack(DynamicArray *darray, Mahasiswa value) {
  if (darray->size + 1 > darray->capacity) {
    darray->capacity *= 2;
    Mahasiswa *newArray =
        (Mahasiswa *)malloc(sizeof(Mahasiswa) * darray->capacity);
    memcpy(newArray, &(darray->arr[0]), sizeof(Mahasiswa) * darray->size);
    Mahasiswa *ol = darray->arr;
    darray->arr = newArray;
    free(ol);
  }
  darray->arr[darray->size++] = value;
}

Mahasiswa back(DynamicArray *darray) {
  if (!isEmpty(darray))
    return darray->arr[darray->size - 1];
  else
    return (Mahasiswa){"", 0};
}

int main() {
  DynamicArray daftarMahasiswa;

  // Inisialisasi dynamic array
  init(&daftarMahasiswa);

  // Menambahkan data ke dynamic array
  Mahasiswa mhs1 = {"Andi", 3.5};
  Mahasiswa mhs2 = {"Budi", 2.3};
  Mahasiswa mhs3 = {"Caca", 3.8};
  pushBack(&daftarMahasiswa, mhs1);
  pushBack(&daftarMahasiswa, mhs2);
  pushBack(&daftarMahasiswa, mhs3);

  // Menghapus data terbaru
  popBack(&daftarMahasiswa);

  // Print data terbaru
  printf("Nama: %s, Umur: %f\n", back(&daftarMahasiswa).nama,
         back(&daftarMahasiswa).ipk);
}
