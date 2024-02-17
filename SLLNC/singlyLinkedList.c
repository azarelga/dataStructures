#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int ll;
typedef unsigned long long int ull;

typedef struct snode_t {
  int data;
  struct snode_t *next;
} node;

typedef struct slist_t {
  unsigned size;
  node *head, *tail;
} list;

/**
 * @brief Inisialisasi SLLNC (Default : Size = 0, Head = NULL, Tail = NULL)
 *
 * @param Pointer ke list yang akan diinisialisasi
 */
void slist_init(list *list) {
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
}

/**
 * @brief Mengembalikan true apabila SLLNC kosong
 *
 * @param Pointer ke list
 */
bool slist_isEmpty(list *list) { return (list->head == NULL); }

/**
 * @brief Menghapus data dari depan SLLNC
 *
 * @param Pointer ke list yang akan dihapus
 */
void slist_popFront(list *list) {
  if (!slist_isEmpty(list)) {
    node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
  }
}

/**
 * @brief Menghapus data dari belakang SLLNC
 *
 * @param Pointer ke list yang akan dihapus
 */
void slist_popBack(list *list) {
  if (!slist_isEmpty(list)) {
    node *temp = list->head;
    node *prev = NULL;
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
 * @brief Menambahkan data ke belakang dari SLLNC
 *
 * @param Pointer ke list yang akan diisi dan nilai yang akan dimasukkan
 */
void slist_pushBack(list *list, int value) {
  node *newNode = (node *)malloc(sizeof(node));
  if (newNode) {
    list->size++;
    newNode->data = value;
    newNode->next = NULL;

    // Kalo Linked Listnya kosong
    if (slist_isEmpty(list)) {
      list->head = newNode;
      list->tail = newNode;
      // Kalo Linked Listnya sudah berisi
    } else {
      node *temp = list->tail;
      temp->next = newNode;
      list->tail = newNode;
    }
  }
}

/**
 * @brief Menambahkan data ke depan dari SLLNC
 *
 * @param Pointer ke list yang akan diisi dan nilai yang akan dimasukkan
 */
void slist_pushFront(list *list, int value) {
  node *newNode = (node *)malloc(sizeof(node));
  if (newNode) {
    list->size++;
    newNode->data = value;
    if (slist_isEmpty(list))
      newNode->next = NULL;
    else {
      newNode->next = list->head;
    }
    list->head = newNode;
  }
}

/**
 * @brief Menambahkan data ke index yang ditentukan dari SLLNC
 *
 * @param Pointer ke list yang akan diisi, indeks yang ingin disisipkan data
 * baru dan nilai yang akan dimasukkan
 */
void slist_insertAt(list *list, int index, int value) {
  if (slist_isEmpty(list) || index >= list->size) {
    slist_pushBack(list, value);
    return;
  }

  else if (index == 0) {
    slist_pushFront(list, value);
    return;
  }

  node *newNode = (node *)malloc(sizeof(node));

  // Disini kita punya 2 langkah
  // 1. Nextnya node barunya di assign ke temp->next habis looping
  // 2. Ganti nextnya di index-1
  if (newNode) {
    node *temp = list->head;

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
 * @brief Mengembalikan nilai paling belakang dari SLLNC
 *
 * @param Pointer ke list
 */
int slist_back(list *list) {
  if (!slist_isEmpty(list)) {
    return list->tail->data;
  }
  return 0;
}

/**
 * @brief Mengembalikan nilai paling depan dari SLLNC
 *
 * @param Pointer ke list
 */
int slist_front(list *list) {
  if (!slist_isEmpty(list))
    return list->head->data;
  return 0;
}

/**
 * @brief Mengembalikan nilai pada indeks yang diinginkan dari SLLNC
 *
 * @param Pointer ke list dan index yang diinginkan
 */
int slist_getAt(list *list, int index) {
  if (!slist_isEmpty(list)) {
    node *temp = list->head;
    for (int i = 0; i < index && temp->next != NULL; i++) {
      temp = temp->next;
    }
    return temp->data;
  }
  return 0;
}

int main() {
  list myLinkedList;
  slist_init(&myLinkedList);
  slist_pushBack(&myLinkedList, 10);
  slist_pushBack(&myLinkedList, 20);
  slist_pushBack(&myLinkedList, 30);
  slist_pushBack(&myLinkedList, 40);
  printf("%d\n", slist_getAt(&myLinkedList, 0));
}
