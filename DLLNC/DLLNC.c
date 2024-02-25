#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int ll;
typedef unsigned long long int ull;

typedef struct dnode {
  int data;
  struct dnode *next;
  struct dnode *prev;
} Node;

typedef struct dlist {
  unsigned size;
  Node *head;
  Node *tail;
} DoublyLinkedList;

/**
 * @brief Inisialisasi DoublyLinkedList (Default : Size = 0, Head = NULL, Tail =
 * NULL)
 *
 * @param Pointer ke DoublyLinkedList yang akan diinisialisasi
 */
void init(DoublyLinkedList *list) {
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
}

/**
 * @brief Mengembalikan true apabila DoublyLinkedList kosong
 *
 * @param Pointer ke DoublyLinkedList
 */
bool isEmpty(DoublyLinkedList *list) { return (list->head == NULL); }

/**
 * @brief menambahkan node ke belakang dari dllnc
 *
 * @param pointer ke dllnc yang akan diisi dan nilai yang akan dimasukkan
 */
void pushBack(DoublyLinkedList *list, int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode) {
    list->size++;
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(list)) {
      list->head = newNode;
      list->tail = newNode;
    } else {
      Node *temp = list->tail;
      newNode->prev = temp;
      temp->next = newNode;
      list->tail = newNode;
    }
  }
}

/**
 * @brief menambahkan node ke depan dari DoublyLinkedList
 *
 * @param pointer ke DoublyLinkedList yang akan diisi dan nilai yang akan
 * dimasukkan
 */
void pushFront(DoublyLinkedList *list, int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode) {
    list->size++;
    newNode->data = value;
    if (isEmpty(list))
      newNode->next = NULL;
    else {
      newNode->next = list->head;
      list->head->prev = newNode;
    }
    list->head = newNode;
  }
}

/**
 * @brief menghapus node dari depan DoublyLinkedList
 *
 * @param pointer ke DoublyLinkedList yang akan dihapus data terdepannya
 */
void popFront(DoublyLinkedList *list) {
  if (!isEmpty(list)) {
    Node *temp = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    free(temp);
    list->size--;
  }
}

/**
 * @brief menghapus node dari belakang DoublyLinkedList
 *
 * @param pointer ke DoublyLinkedList yang akan dihapus data terbelakangnya
 */
void popBack(DoublyLinkedList *list) {
  if (!isEmpty(list)) {
    Node *temp = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    free(temp);
    list->size--;
  }
}

/**
 * @brief menambahkan node ke indeks yang ditentukan dari DoublyLinkedList
 *
 * @param pointer ke DoublyLinkedList yang akan diisi, indeks yang akan
 * disisipkan dan nilai yang akan dimasukkan pada indeks tersebut
 */
void insertAt(DoublyLinkedList *list, int index, int value) {
  if (isEmpty(list) || index >= list->size) {
    pushBack(list, value);
    return;
  }

  else if (index == 0) {
    pushFront(list, value);
    return;
  }

  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode) {
    Node *temp = list->head;
    for (int i = 0; i < index - 1 && temp->next != NULL; i++) {
      temp = temp->next;
    }
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;
    Node *temp1 = temp->next;
    temp1->prev = newNode;
    temp->next = newNode;
    list->size++;
  }
}

/*
 * @brief: Mengembalikan node paling depan linked list
 *
 * @param: DoublyLinkedList *list - linked list yang akan dipop dari belakang
 * */
int back(DoublyLinkedList *list) {
  if (!isEmpty(list)) {
    return list->tail->data;
  }
  return 0;
}

/*
 * @brief: Mengembalikan node paling depan linked list
 *
 * @param: DoublyLinkedList *list - linked list yang akan dipop dari belakang
 * */
int front(DoublyLinkedList *list) {
  if (!isEmpty(list))
    return list->head->data;
  return 0;
}

int getAt(DoublyLinkedList *list, int index) {
  if (!isEmpty(list)) {
    Node *temp = list->head;
    for (int i = 0; i < index && temp->next != NULL; i++) {
      temp = temp->next;
    }
    return temp->data;
  }
  return 0;
}

int main() {
  DoublyLinkedList myLinkedList;
  init(&myLinkedList);
  pushBack(&myLinkedList, 10);
  pushBack(&myLinkedList, 20);
  pushBack(&myLinkedList, 30);
  pushBack(&myLinkedList, 40);
  printf("%d\n", getAt(&myLinkedList, 3));
}
