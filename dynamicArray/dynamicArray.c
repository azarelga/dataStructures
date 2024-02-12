#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int ll;
typedef unsigned long long int ull;

typedef struct dynamicarray_t {
  int *_arr;
  unsigned _size, _capacity;
} DynamicArray;

/**
 * @brief Inisiasi Dynamic Array (Default : Kapasitas = 2, Size = 0)
 *
 * @param darray
 */
void dArray_init(DynamicArray *darray) {
  darray->_capacity = 2;
  darray->_size = 0;
  darray->_arr = (int *)malloc(sizeof(int) * 2);
}

/**
 * @brief Mengetahui apabila dynamic array kosong (true : kosong, false :
 * terisi)
 *
 * @param darray
 * @return true
 * @return false
 */
bool dArray_isEmpty(DynamicArray *darray) { return (darray->_size == 0); }

/**
 * @brief Mengambil nilai array paling belakang (indeks terakhir)
 *
 * @param darray
 * @return int
 */
int dArray_back(DynamicArray *darray) {
  if (!dArray_isEmpty(darray))
    return darray->_arr[darray->_size - 1];
  else
    return 0;
}

/**
 * @brief Mengambil nilai array paling depan (indeks pertama)
 *
 * @param darray
 * @return int
 */
int dArray_front(DynamicArray *darray) {
  if (!dArray_isEmpty(darray))
    return darray->_arr[0];
  else
    return 0;
}

/**
 * @brief Menghapus nilai array paling belakang (indeks terakhir)
 *
 * @param darray
 */
void dArray_popBack(DynamicArray *darray) {
  if (!dArray_isEmpty(darray))
    darray->_size--;
  else
    return;
}

/**
 * @brief Menambahkan elemen ke dynamic array sesuai dengan implementasi yang
 * didiskusikan pada modul
 *
 * @param dArray Array yang ingin ditambahkan
 * @param value Nilai yang ingin ditambahkan ke array
 */
void dArray_pushback(DynamicArray *dArray, int value) {
  if (dArray->_size + 1 > dArray->_capacity) {
    dArray->_capacity *= 2;
    int *newArray = (int *)malloc(sizeof(int) * dArray->_capacity);
    memcpy(newArray, &(dArray->_arr[0]), sizeof(int) * dArray->_size);
    int *oldArray = dArray->_arr;
    dArray->_arr = newArray;
    free(oldArray);
  }
  dArray->_arr[dArray->_size++] = value;
}

/**
 * @brief Mengambil nilai pada index dynamic array yang diinginkan
 *
 * @param darray
 * @param index Index yang diinginkan (apabila indeks melampaui size/kapasitas,
 * nilai yang dikembalikan adalah nilai terakhir)
 * @return int
 */
int dArray_getAt(DynamicArray *darray, unsigned index) {
  if (!dArray_isEmpty(darray)) {
    if (index >= darray->_size)
      return darray->_arr[darray->_size - 1];
    else
      return darray->_arr[index];
  }
  return 0;
}

/**
 * @brief Mengubah nilai elemen pada indeks tertentu
 *
 * @param darray
 * @param index
 * @param value
 */
void dArray_setAt(DynamicArray *darray, unsigned index, int value) {
  if (!dArray_isEmpty(darray)) {
    if (index >= darray->_size)
      darray->_arr[darray->_size - 1] = value;
    else
      darray->_arr[index] = value;
  }
}

void print(int *darray, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", darray[i]);
  }
}

void dArray_insertAt(DynamicArray *darray, unsigned index, int value) {
  if (index + 1 >= darray->_capacity)
    dArray_pushback(darray, value);
  else {
    if (darray->_size + 1 > darray->_capacity) {
      darray->_capacity *= 2;
    }
    int *newArray = (int *)malloc(sizeof(int) * darray->_capacity);

    memcpy(newArray, darray->_arr, sizeof(int) * index);
    newArray[index] = value;
    memcpy(&newArray[index + 1], &(darray->_arr[index]),
           sizeof(int) * (darray->_size + 1));

    int *oldArray = darray->_arr;
    darray->_arr = newArray;
    free(oldArray);
    darray->_size++;
  }
}

void dArray_removeAt(DynamicArray *darray, unsigned index) {
  if (index + 1 >= darray->_capacity)
    dArray_popBack(darray);
  else {
    int *newArray = (int *)malloc(sizeof(int) * darray->_capacity);

    memcpy(newArray, darray->_arr, sizeof(int) * index);
    memcpy(&newArray[index + 1], &(darray->_arr[index + 1]),
           sizeof(int) * (darray->_size - index));
    int *oldArray = darray->_arr;
    darray->_arr = newArray;
    free(oldArray);
    darray->_size -= 1;
  }
}

int main() {
  DynamicArray myArray;

  // init
  dArray_init(&myArray);

  // pushback
  dArray_pushback(&myArray, 10);
  dArray_pushback(&myArray, 20);
  dArray_pushback(&myArray, 30);
  dArray_pushback(&myArray, 40);

  // insert at
  dArray_insertAt(&myArray, 1, 69);
  dArray_insertAt(&myArray, 2, 529);
  dArray_removeAt(&myArray, 2);
  print(myArray._arr, myArray._size);
  // setAt
  dArray_setAt(&myArray, 0, 100);

  printf("%d", dArray_getAt(&myArray, 3));
}
