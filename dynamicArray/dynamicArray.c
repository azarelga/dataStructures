#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int ll;
typedef unsigned long long int ull;

typedef struct dynamicarray {
  int *arr;
  unsigned size, capacity;
} DynamicArray;

/**
 * @brief Inisiasi Dynamic Array (Default : Kapasitas = 2, Size = 0)
 *
 * @param darray - pointer ke dynamic array yang ingin diinisiasi
 */
void init(DynamicArray *darray) {
  darray->capacity = 2;
  darray->size = 0;
  darray->arr = (int *)malloc(sizeof(int) * 2);
}

/**
 * @brief Mengetahui apabila dynamic array kosong (true : kosong, false :
 * terisi)
 *
 * @param darray - pointer ke dynamic array yang ingin dicek
 * @return true - apabila kosong
 * @return false - apabila terisi
 */
bool isEmpty(DynamicArray *darray) { return (darray->size == 0); }

/**
 * @brief Mengambil nilai array paling belakang (indeks terakhir)
 *
 * @param darray - pointer ke dynamic array yang ingin diambil
 * @return int - nilai array paling belakang
 */
int back(DynamicArray *darray) {
  if (!isEmpty(darray))
    return darray->arr[darray->size - 1];
  else
    return 0;
}

/**
 * @brief Mengambil nilai array paling depan (indeks pertama)
 *
 * @param darray - pointer ke dynamic array yang ingin diambil
 * @return int - nilai array paling depan
 */
int front(DynamicArray *darray) {
  if (!isEmpty(darray))
    return darray->arr[0];
  else
    return 0;
}

/**
 * @brief Menghapus nilai array paling belakang (indeks terakhir)
 *
 * @param darray - pointer ke dynamic array yang ingin dihapus
 */
void popBack(DynamicArray *darray) {
  if (!isEmpty(darray))
    darray->size--;
  else
    return;
}

/**
 * @brief Menambahkan elemen ke akhir dynamic array
 *
 * @param darray - pointer ke dynamic array yang ingin ditambahkan
 * @param value - nilai yang ingin ditambahkan ke array
 */
void pushBack(DynamicArray *darray, int value) {
  if (darray->size + 1 > darray->capacity) {
    darray->capacity *= 2;
    int *newArray = (int *)malloc(sizeof(int) * darray->capacity);
    memcpy(newArray, &(darray->arr[0]), sizeof(int) * darray->size);
    int *ol = darray->arr;
    darray->arr = newArray;
    free(ol);
  }
  darray->arr[darray->size++] = value;
}

/**
 * @brief Mengambil nilai pada index dynamic array yang diinginkan
 *
 * @param darray
 * @param index - Index yang diinginkan (apabila indeks melampaui
 * size/kapasitas, nilai yang dikembalikan adalah nilai terakhir)
 * @return int - nilai pada index yang diinginkan
 */
int getAt(DynamicArray *darray, unsigned index) {
  if (!isEmpty(darray)) {
    if (index >= darray->size)
      return darray->arr[darray->size - 1];
    else
      return darray->arr[index];
  }
  return 0;
}

/**
 * @brief Mengubah nilai elemen pada indeks tertentu
 *
 * @param darray - pointer ke dynamic array yang ingin diubah
 * @param index - indeks yang ingin diubah
 * @param value - nilai baru pada indeks yang ingin diubah
 */
void setAt(DynamicArray *darray, unsigned index, int value) {
  if (!isEmpty(darray)) {
    if (index >= darray->size)
      darray->arr[darray->size - 1] = value;
    else
      darray->arr[index] = value;
  }
}

void print(int *darray, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", darray[i]);
  }
}

/**
 * @brief Menambahkan elemen ke dynamic array pada indeks tertentu
 *
 * @param darray - pointer ke dynamic array yang ingin ditambahkan
 * @param index - indeks yang ingin ditambahkan
 * @param value - nilai yang ingin ditambahkan
 */
void insertAt(DynamicArray *darray, unsigned index, int value) {
  if (index + 1 >= darray->capacity)
    pushBack(darray, value);
  else {
    if (darray->size + 1 > darray->capacity) {
      darray->capacity *= 2;
    }
    int *newArray = (int *)malloc(sizeof(int) * darray->capacity);

    memcpy(newArray, darray->arr, sizeof(int) * index);
    newArray[index] = value;
    memcpy(&newArray[index + 1], &(darray->arr[index]),
           sizeof(int) * (darray->size + 1));

    int *ol = darray->arr;
    darray->arr = newArray;
    free(ol);
    darray->size++;
  }
}

/**
 * @brief Menghapus elemen pada indeks tertentu
 *
 * @param darray - pointer ke dynamic array yang ingin dihapus
 * @param index - indeks yang ingin dihapus
 */
void removeAt(DynamicArray *darray, unsigned index) {
  if (index + 1 >= darray->capacity)
    popBack(darray);
  else {
    int *newArray = (int *)malloc(sizeof(int) * darray->capacity);

    memcpy(newArray, darray->arr, sizeof(int) * index);
    memcpy(&newArray[index + 1], &(darray->arr[index + 1]),
           sizeof(int) * (darray->size - index));
    int *ol = darray->arr;
    darray->arr = newArray;
    free(ol);
    darray->size -= 1;
  }
}

int main() {
  DynamicArray myArray;

  // init
  init(&myArray);

  // pushBack
  pushBack(&myArray, 10);
  pushBack(&myArray, 20);
  pushBack(&myArray, 30);
  pushBack(&myArray, 40);

  // insert at
  insertAt(&myArray, 1, 69);
  insertAt(&myArray, 2, 529);
  removeAt(&myArray, 2);
  print(myArray.arr, myArray.size);
  // setAt
  setAt(&myArray, 0, 100);

  printf("%d", getAt(&myArray, 3));
}
