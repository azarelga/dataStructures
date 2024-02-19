#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int ll;
typedef unsigned long long int ull;

typedef struct node {
  int data;
  struct node *next;
} SLLCNode;

typedef struct circularLinkedList {
  unsigned size;
  SLLCNode *head;
  SLLCNode *tail;
} SLLC;

/*
 * @brief: Menginisialisasi linked list
 *
 * @param: SLLC *list - linked list yang akan diinisialisasi
 *
 * */
void init(SLLC *list) {
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
}

/*
 * @brief: Mengembalikan true jika linked list kosong
 *
 * @param: SLLC *list - linked list yang akan diperiksa
 *
 * */
int isEmpty(SLLC *list) { return list->size == 0; }

/*
 * @brief: Menambahkan node baru dari belakang linked list
 *
 * @param: SLLC *list - linked list yang akan dipush, int data - data yang akan
 * dipush
 * */
void pushBack(SLLC *list, int data) {
  SLLCNode *newNode = (SLLCNode *)malloc(sizeof(SLLCNode));
  newNode->data = data;
  newNode->next = NULL;
  if (list->size == 0) {
    list->head = newNode;
    list->tail = newNode;
  } else {
    list->tail->next = newNode;
    list->tail = newNode;
  }
  list->tail->next = list->head;
  list->size++;
}

/*
 * @brief: Menambahkan node baru dari depan linked list
 *
 * @param: SLLC *list - linked list yang akan dipush, int data - data yang akan
 * dipush
 * */
void pushFront(SLLC *list, int data) {
  SLLCNode *newNode = (SLLCNode *)malloc(sizeof(SLLCNode));
  newNode->data = data;
  newNode->next = list->head;
  if (list->size == 0) {
    list->tail = newNode;
  }
  list->head = newNode;
  list->tail->next = list->head;
  list->size++;
}

/*
 * @brief: Menghapus node dari depan linked list
 *
 * @param: SLLC *list - linked list yang akan dipop dari depan
 * */
void popFront(SLLC *list) {
  if (list->size == 0) {
    return;
  }
  SLLCNode *temp = list->head;
  list->head = list->head->next;
  list->tail->next = list->head;
  free(temp);
  list->size--;
}

/*
 * @brief: Menghapus node dari belakang linked list
 *
 * @param: SLLC *list - linked list yang akan dipop dari belakang
 * */
void popBack(SLLC *list) {
  if (list->size == 0) {
    return;
  }
  SLLCNode *temp = list->head;
  while (temp->next != list->tail) {
    temp = temp->next;
  }
  free(list->tail);
  list->tail = temp;
  list->tail->next = list->head;
  list->size--;
}

/*
 * @brief: Mengembalikan node paling depan linked list
 *
 * @param: SLLC *list - linked list yang akan dipop dari belakang
 * */
int front(SLLC *list) {
  if (list->size == 0) {
    return 0;
  }
  return list->head->data;
}

/*
 * @brief: Mengembalikan node paling belakang linked list
 *
 * @param: SLLC *list - linked list yang akan dipop dari belakang
 * */
int back(SLLC *list) {
  if (list->size == 0) {
    return 0;
  }
  return list->tail->data;
}

/*
 * @brief: Menyisipkan node pada linked list sesuai indeks yang ditentukan
 *
 * @param: SLLC *list - linked list yang akan dihapus, int index - indeks yang
 * akan disisipkan, int data - data yang akan disisipkan
 * */
void insert(SLLC *list, int index, int data) {
  if (index < 0 || index > list->size) {
    return;
  }
  if (index == 0) {
    pushFront(list, data);
    return;
  }
  if (index == list->size) {
    pushBack(list, data);
    return;
  }
  SLLCNode *newNode = (SLLCNode *)malloc(sizeof(SLLCNode));
  newNode->data = data;
  SLLCNode *temp = list->head;
  for (int i = 0; i < index - 1; i++) {
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
  list->size++;
}

int main() {
  SLLC list;
  init(&list);
  pushBack(&list, 1);
  pushBack(&list, 2);
  pushBack(&list, 4);
  popFront(&list);
  insert(&list, 1, 3);
  for (SLLCNode *temp = list.head; temp != list.tail; temp = temp->next) {
    printf("%d ", temp->data);
  }

  // Potongan kode di bawah akan menghasilkan infinite loop. Coba tebak, kok
  // bisa gitu?
  //
  // for (SLLCNode *temp = list.head; temp != NULL; temp = temp->next) {
  //   printf("%d ", temp->data);
  // }
}
