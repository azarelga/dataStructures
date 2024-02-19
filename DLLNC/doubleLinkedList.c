#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int ll;
typedef unsigned long long int ull;

typedef struct dnode_t {
  int data;
  struct dnode_t *next;
  struct dnode_t *prev;
} DListNode;

typedef struct dlist_t {
  unsigned size;
  DListNode *head;
  DListNode *tail;
} DList;

/**
 * @brief Inisialisasi DLLNC (Default : Size = 0, Head = NULL, Tail = NULL)
 *
 * @param Pointer ke DLLNC yang akan diinisialisasi
 */
void dlist_init(DList *list) {
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
}

/**
 * @brief Mengembalikan true apabila DLLNC kosong
 *
 * @param Pointer ke DLLNC
 */
bool dlist_isEmpty(DList *list) { return (list->head == NULL); }

/**
 * @brief menambahkan data ke belakang dari dllnc
 *
 * @param pointer ke dllnc yang akan diisi dan nilai yang akan dimasukkan
 */
void dlist_pushBack(DList *list, int value) {
  DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
  if (newNode) {
    list->size++;
    newNode->data = value;
    newNode->next = NULL;
    if (dlist_isEmpty(list)) {
      list->head = newNode;
      list->tail = newNode;
    } else {
      DListNode *temp = list->tail;
      newNode->prev = temp;
      temp->next = newNode;
      list->tail = newNode;
    }
  }
}

/**
 * @brief menambahkan data ke depan dari DLLNC
 *
 * @param pointer ke DLLNC yang akan diisi dan nilai yang akan dimasukkan
 */
void dlist_pushFront(DList *list, int value) {
  DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
  if (newNode) {
    list->size++;
    newNode->data = value;
    if (dlist_isEmpty(list))
      newNode->next = NULL;
    else {
      newNode->next = list->head;
      list->head->prev = newNode;
    }
    list->head = newNode;
  }
}

/**
 * @brief menghapus data dari depan DLLNC
 *
 * @param pointer ke DLLNC yang akan dihapus data terdepannya
 */
void dlist_popFront(DList *list) {
  if (!dlist_isEmpty(list)) {
    DListNode *temp = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    free(temp);
    list->size--;
  }
}

/**
 * @brief menghapus data dari belakang DLLNC
 *
 * @param pointer ke DLLNC yang akan dihapus data terbelakangnya
 */
void dlist_popBack(DList *list) {
  if (!dlist_isEmpty(list)) {
    DListNode *temp = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    free(temp);
    list->size--;
  }
}

/**
 * @brief menambahkan data ke indeks yang ditentukan dari DLLNC
 *
 * @param pointer ke DLLNC yang akan diisi, indeks yang akan disisipkan dan
 * nilai yang akan dimasukkan pada indeks tersebut
 */
void dlist_insertAt(DList *list, int index, int value) {
  if (dlist_isEmpty(list) || index >= list->size) {
    dlist_pushBack(list, value);
    return;
  }

  else if (index == 0) {
    dlist_pushFront(list, value);
    return;
  }

  DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
  if (newNode) {
    DListNode *temp = list->head;
    for (int i = 0; i < index - 1 && temp->next != NULL; i++) {
      temp = temp->next;
    }
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;
    DListNode *temp1 = temp->next;
    temp1->prev = newNode;
    list->size++;
  }
}

int dlist_back(DList *list) {
  if (!dlist_isEmpty(list)) {
    return list->tail->data;
  }
  return 0;
}

int dlist_front(DList *list) {
  if (!dlist_isEmpty(list))
    return list->head->data;
  return 0;
}

int dlist_getAt(DList *list, int index) {
  if (!dlist_isEmpty(list)) {
    DListNode *temp = list->head;
    for (int i = 0; i < index && temp->next != NULL; i++) {
      temp = temp->next;
    }
    return temp->data;
  }
  return 0;
}

int main() {
  DList myLinkedList;
  dlist_init(&myLinkedList);
  dlist_pushBack(&myLinkedList, 10);
  dlist_pushBack(&myLinkedList, 20);
  dlist_pushBack(&myLinkedList, 30);
  dlist_pushBack(&myLinkedList, 40);
  printf("%d\n", dlist_getAt(&myLinkedList, 3));
}
