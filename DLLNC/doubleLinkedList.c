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
} DLLNCNode;

typedef struct dlist_t {
  unsigned size;
  DLLNCNode *head;
  DLLNCNode *tail;
} DLLNC;

/**
 * @brief Inisialisasi DLLNC (Default : Size = 0, Head = NULL, Tail = NULL)
 *
 * @param Pointer ke DLLNC yang akan diinisialisasi
 */
void dlist_init(DLLNC *list) {
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
}

/**
 * @brief Mengembalikan true apabila DLLNC kosong
 *
 * @param Pointer ke DLLNC
 */
bool dlist_isEmpty(DLLNC *list) { return (list->head == NULL); }

/**
 * @brief menambahkan node ke belakang dari dllnc
 *
 * @param pointer ke dllnc yang akan diisi dan nilai yang akan dimasukkan
 */
void dlist_pushBack(DLLNC *list, int value) {
  DLLNCNode *newNode = (DLLNCNode *)malloc(sizeof(DLLNCNode));
  if (newNode) {
    list->size++;
    newNode->data = value;
    newNode->next = NULL;
    if (dlist_isEmpty(list)) {
      list->head = newNode;
      list->tail = newNode;
    } else {
      DLLNCNode *temp = list->tail;
      newNode->prev = temp;
      temp->next = newNode;
      list->tail = newNode;
    }
  }
}

/**
 * @brief menambahkan node ke depan dari DLLNC
 *
 * @param pointer ke DLLNC yang akan diisi dan nilai yang akan dimasukkan
 */
void dlist_pushFront(DLLNC *list, int value) {
  DLLNCNode *newNode = (DLLNCNode *)malloc(sizeof(DLLNCNode));
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
 * @brief menghapus node dari depan DLLNC
 *
 * @param pointer ke DLLNC yang akan dihapus data terdepannya
 */
void dlist_popFront(DLLNC *list) {
  if (!dlist_isEmpty(list)) {
    DLLNCNode *temp = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    free(temp);
    list->size--;
  }
}

/**
 * @brief menghapus node dari belakang DLLNC
 *
 * @param pointer ke DLLNC yang akan dihapus data terbelakangnya
 */
void dlist_popBack(DLLNC *list) {
  if (!dlist_isEmpty(list)) {
    DLLNCNode *temp = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    free(temp);
    list->size--;
  }
}

/**
 * @brief menambahkan node ke indeks yang ditentukan dari DLLNC
 *
 * @param pointer ke DLLNC yang akan diisi, indeks yang akan disisipkan dan
 * nilai yang akan dimasukkan pada indeks tersebut
 */
void dlist_insertAt(DLLNC *list, int index, int value) {
  if (dlist_isEmpty(list) || index >= list->size) {
    dlist_pushBack(list, value);
    return;
  }

  else if (index == 0) {
    dlist_pushFront(list, value);
    return;
  }

  DLLNCNode *newNode = (DLLNCNode *)malloc(sizeof(DLLNCNode));
  if (newNode) {
    DLLNCNode *temp = list->head;
    for (int i = 0; i < index - 1 && temp->next != NULL; i++) {
      temp = temp->next;
    }
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;
    DLLNCNode *temp1 = temp->next;
    temp1->prev = newNode;
    temp->next = newNode;
    list->size++;
  }
}

/*
 * @brief: Mengembalikan node paling depan linked list
 *
 * @param: DLLNC *list - linked list yang akan dipop dari belakang
 * */
int dlist_back(DLLNC *list) {
  if (!dlist_isEmpty(list)) {
    return list->tail->data;
  }
  return 0;
}

/*
 * @brief: Mengembalikan node paling depan linked list
 *
 * @param: DLLNC *list - linked list yang akan dipop dari belakang
 * */
int dlist_front(DLLNC *list) {
  if (!dlist_isEmpty(list))
    return list->head->data;
  return 0;
}

int dlist_getAt(DLLNC *list, int index) {
  if (!dlist_isEmpty(list)) {
    DLLNCNode *temp = list->head;
    for (int i = 0; i < index && temp->next != NULL; i++) {
      temp = temp->next;
    }
    return temp->data;
  }
  return 0;
}

int main() {
  DLLNC myLinkedList;
  dlist_init(&myLinkedList);
  dlist_pushBack(&myLinkedList, 10);
  dlist_pushBack(&myLinkedList, 20);
  dlist_pushBack(&myLinkedList, 30);
  dlist_pushBack(&myLinkedList, 40);
  printf("%d\n", dlist_getAt(&myLinkedList, 3));
}
