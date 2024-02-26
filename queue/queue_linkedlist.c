#include <stdbool.h>
#include <stdlib.h>

typedef long long int ll;
typedef unsigned long long int ull;

typedef struct node {
  int data;
  struct node *next;
} QueueNode;

typedef struct queue_t {
  int size;
  QueueNode *front;
} Queue;

/*
 * @brief Inisialisasi Queue
 *
 * @param Queue *queue - queue yang akan diinisialisasi
 * */
void init(Queue *queue) {
  queue->front = NULL;
  queue->size = -1;
}

/*
 * @brief Mengembalikan nilai 1 apabila Queue kosong
 *
 * @param Queue *queue - queue yang akan dicek
 * */
int isEmpty(Queue *queue) { return queue->size == -1; }

/*
 * @brief Mengembalikan data terdepan dari Queue
 *
 * @param Queue *queue - queue
 * */
int front(Queue *queue) {
  if (isEmpty(queue))
    return -1;
  else
    return queue->front->data;
}

/*
 * @brief Mengosongkan isi Queue
 *
 * @param Queue *queue - queue
 * */
void clear(Queue *queue) {
  queue->front = NULL;
  queue->size = -1;
}

/*
 * @brief Mengembalikan ukuran queue
 *
 * @param Queue *queue - queue
 * */
int size(Queue *queue) { return queue->size; }

/*
 * @brief Menghapus data terdepan dari Queue
 *
 * @param Queue *queue - queue
 * */
void pop(Queue *queue) {
  QueueNode *temp = queue->front;
  free(temp);
  queue->front = queue->front->next;
  queue->size--;
}

/*
 * @brief Mengentri data dari depan Queue
 *
 * @param Queue *queue - queue
 * */
void push(Queue *queue, int input) {
  QueueNode *newNode = malloc(sizeof(QueueNode));
  newNode->data = input;
  newNode->next = NULL;
  QueueNode *temp = queue->front;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}

int main() {}
