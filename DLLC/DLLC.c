#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;
typedef unsigned long long int ull;

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} DLLCNode;

typedef struct {
    DLLCNode* head;
    DLLCNode* tail;
    int size;
} DLLC;

//

/*
 * @brief: Menginisialisasi linked list
 *
 * @param: DLLC *list - linked list yang akan diinisialisasi
 *
 * */
void init(DLLC *list) {
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
}

/*
 * @brief: Mengembalikan true jika linked list kosong
 *
 * @param: DLLC *list - linked list yang akan diperiksa
 *
 * */
int isEmpty(DLLC *list) { return list->size == 0; }

/*
 * @brief: Menambahkan node baru dari belakang linked list
 *
 * @param: DLLC *list - linked list yang akan dipush, int data - data yang akan
 * dipush
 * */
void pushBack(DLLC *list, int data) {
  DLLCNode *newNode = (DLLCNode *)malloc(sizeof(DLLCNode));
  newNode->data = data;
  newNode->next = NULL;
  if (list->size == 0) {
    list->head = newNode;
    list->tail = newNode;
  } else {
    newNode->prev = list->tail;
    list->tail->next = newNode;
    list->tail = newNode;
  }
  list->tail->next = list->head;
  list->head->prev = list->tail;
  list->size++;
}

/*
 * @brief: Menambahkan node baru dari depan linked list
 *
 * @param: DLLC *list - linked list yang akan dipush, int data - data yang akan
 * dipush
 * */
void pushFront(DLLC *list, int data) {
  DLLCNode *newNode = (DLLCNode *)malloc(sizeof(DLLCNode));
  newNode->data = data;
  newNode->next = list->head;
  if (list->size == 0) {
    list->tail = newNode;
  }
  list->head = newNode;
  list->head->prev = newNode;
  list->tail->next = list->head;
  list->size++;
}

/*
 * @brief: Menghapus node dari depan linked list
 *
 * @param: DLLC *list - linked list yang akan dipop dari depan
 * */
void popFront(DLLC *list) {
  if (list->size == 0) {
    return;
  }
  DLLCNode *temp = list->head;
  list->head = list->head->next;
  list->head->prev = list->tail;
  list->tail->next = list->head;
  free(temp);
  list->size--;
}

/*
 * @brief: Menghapus node dari belakang linked list
 *
 * @param: DLLC *list - linked list yang akan dipop dari belakang
 * */
void popBack(DLLC *list) {
  if (list->size == 0) {
    return;
  }
  DLLCNode *temp = list->tail;
  list->tail = list->tail->prev;
  list->head->prev = list->tail;
  list->tail->next = list->head;
  free(temp);
  list->size--;
}

/*
 * @brief: Mengembalikan node paling depan linked list
 *
 * @param: DLLC *list - linked list yang akan dipop dari belakang
 * */
int front(DLLC *list) {
  if (list->size == 0) {
    return 0;
  }
  return list->head->data;
}

/*
 * @brief: Mengembalikan node paling belakang linked list
 *
 * @param: DLLC *list - linked list yang akan dipop dari belakang
 * */
int back(DLLC *list) {
  if (list->size == 0) {
    return 0;
  }
  return list->tail->data;
}

/*
 * @brief: Menyisipkan node pada linked list sesuai indeks yang ditentukan
 *
 * @param: DLLC *list - linked list yang akan dihapus, int index - indeks yang
 * akan disisipkan, int data - data yang akan disisipkan
 * */
void insert(DLLC *list, int index, int data) {
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
  DLLCNode *newNode = (DLLCNode *)malloc(sizeof(DLLCNode));
  if (newNode) {
    DLLCNode *temp = list->head;
    for (int i = 0; i < index - 1 && temp->next != NULL; i++) {
      temp = temp->next;
    }
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;
    DLLCNode *temp1 = temp->next;
    temp1->prev = newNode;
    temp->next = newNode;
    list->size++;
  }
}

int main() {
  DLLC list;
  init(&list);
  pushBack(&list, 1);
  pushBack(&list, 2);
  pushBack(&list, 4);
  popFront(&list);
  insert(&list, 1, 3);
  for (DLLCNode *temp = list.head; temp != list.tail; temp = temp->next) {
    printf("%d ", temp->data);
  }
}


