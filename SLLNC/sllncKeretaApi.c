#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int ll;
typedef unsigned long long int ull;

typedef struct gerbong {
  char namaGerbong[100];
  int jumlahKursi;
} Gerbong;

typedef struct snode {
  Gerbong data;
  struct snode *next;
} Node;

typedef struct slist {
  unsigned size;
  Node *head, *tail;
} LinkedList;

/**
 * @brief Inisialisasi Linked List (Default : Size = 0, Head = NULL, Tail =
 * NULL)
 *
 * @param Pointer ke list yang akan diinisialisasi
 */
void init(LinkedList *list) {
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
}

/**
 * @brief Mengembalikan true apabila Linked List kosong
 *
 * @param Pointer ke list
 */
bool isEmpty(LinkedList *list) { return (list->head == NULL); }

/**
 * @brief Menghapus data dari depan Linked List
 *
 * @param Pointer ke list yang akan dihapus
 */
void popFront(LinkedList *list) {
  if (!isEmpty(list)) {
    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
  }
}

/**
 * @brief Menghapus data dari belakang Linked List
 *
 * @param Pointer ke list yang akan dihapus
 */
void popBack(LinkedList *list) {
  if (!isEmpty(list)) {
    Node *temp = list->head;
    Node *prev = NULL;
    while (temp->next != NULL) {
      prev = temp;
      temp = temp->next;
    }
    if (prev) {
      prev->next = NULL;
      list->tail = prev;
    } else {
      list->head = NULL;
      list->tail = NULL;
    }
    free(temp);
    list->size--;
  }
}

/**
 * @brief Menambahkan data ke belakang dari Linked List
 *
 * @param Pointer ke list yang akan diisi dan nilai yang akan dimasukkan
 */
void pushBack(LinkedList *list, Gerbong value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode) {
    list->size++;
    newNode->data = value;
    newNode->next = NULL;

    // Kalo Linked Listnya kosong
    if (isEmpty(list)) {
      list->head = newNode;
      list->tail = newNode;
      // Kalo Linked Listnya sudah berisi
    } else {
      Node *temp = list->tail;
      temp->next = newNode;
      list->tail = newNode;
    }
  }
}

/**
 * @brief Menambahkan data ke depan dari Linked List
 *
 * @param Pointer ke list yang akan diisi dan nilai yang akan dimasukkan
 */
void pushFront(LinkedList *list, Gerbong value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode) {
    list->size++;
    newNode->data = value;
    if (isEmpty(list))
      newNode->next = NULL;
    else {
      newNode->next = list->head;
    }
    list->head = newNode;
  }
}

/**
 * @brief Menambahkan data ke index yang ditentukan dari Linked List
 *
 * @param Pointer ke list yang akan diisi, indeks yang ingin disisipkan data
 * baru dan nilai yang akan dimasukkan
 */
void delete(LinkedList *list, int index) {
  if (isEmpty(list) || index >= list->size) {
    popBack(list);
    return;
  }

  else if (index == 0) {
    popFront(list);
    return;
  }

  Node *prev = list->head;
  while (index - 1 > 0) {
    prev = prev->next;
    index--;
  }
  Node *temp = prev->next;
  prev->next = prev->next->next;
  free(temp);
}

/**
 * @brief Menambahkan data ke index yang ditentukan dari Linked List
 *
 * @param Pointer ke list yang akan diisi, indeks yang ingin disisipkan data
 * baru dan nilai yang akan dimasukkan
 */
void insertAt(LinkedList *list, int index, Gerbong value) {
  if (isEmpty(list) || index >= list->size) {
    pushBack(list, value);
    return;
  }

  else if (index == 0) {
    pushFront(list, value);
    return;
  }

  Node *newNode = (Node *)malloc(sizeof(Node));

  // Disini kita punya 2 langkah
  // 1. Nextnya node barunya di assign ke temp->next habis looping
  // 2. Ganti nextnya di index-1
  if (newNode) {
    Node *temp = list->head;

    for (int i = 0; i < index - 1 && temp->next != NULL; i++) {
      temp = temp->next;
    }
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
    list->size++;
  }
}

/**
 * @brief Mengembalikan nilai paling belakang dari Linked List
 *
 * @param Pointer ke list
 */
Gerbong tail(LinkedList *list) {
  if (!isEmpty(list)) {
    return list->tail->data;
  }
  Gerbong empty;
  return empty;
}

/**
 * @brief Mengembalikan nilai paling depan dari Linked List
 *
 * @param Pointer ke list
 */
Gerbong head(LinkedList *list) {
  if (!isEmpty(list))
    return list->head->data;
  Gerbong empty;
  return empty;
}

/**
 * @brief Mengembalikan nilai pada indeks yang diinginkan dari Linked List
 *
 * @param Pointer ke list dan index yang diinginkan
 */
Gerbong getAt(LinkedList *list, int index) {
  if (!isEmpty(list)) {
    Node *temp = list->head;
    for (int i = 0; i < index && temp->next != NULL; i++) {
      temp = temp->next;
    }
    return temp->data;
  }
  Gerbong empty;
  return empty;
}
int main() {
  LinkedList keretaApi;
  init(&keretaApi);

  Gerbong gerbong1 = {"Ekonomi - 1", 100};
  Gerbong gerbong2 = {"Bisnis - 1", 50};
  Gerbong gerbong3 = {"Eksekutif - 1", 20};
  Gerbong gerbong4 = {"Eksekutif - 2", 20};

  // Menambahkan gerbong ke keretaApi
  pushBack(&keretaApi, gerbong1);
  pushBack(&keretaApi, gerbong2);
  pushBack(&keretaApi, gerbong3);
  pushBack(&keretaApi, gerbong4);

  // Menghapus gerbong pada indeks tertentu keretaApi
  delete (&keretaApi, 2);

  // Mencetak semua gerbong pada keretaApi
  Node *temp = keretaApi.head;
  while (temp != NULL) {
    printf("Nama Gerbong: %s\n", temp->data.namaGerbong);
    printf("Jumlah Kursi: %d\n", temp->data.jumlahKursi);
    temp = temp->next;
    printf("\n");
  }

  // Mencetak gerbong ke 3 pada keretaApi
  printf("Gerbong ke-3\nNama Gerbong: %s\n", getAt(&keretaApi, 2).namaGerbong);
}
