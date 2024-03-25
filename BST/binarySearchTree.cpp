#include <iostream>
#include <stdlib.h>
using namespace std;

struct BSTNode {
  struct BSTNode *left, *right;
  int key;
};

struct BST {
  BSTNode *_root;
  unsigned int _size;

  void init() {
    _root = NULL;
    _size = 0u;
  }

  bool isEmpty() { return _root == NULL; }

  bool find(int value) {
    BSTNode *temp = __search(_root, value);
    if (!temp)
      return false;

    if (temp->key == value)
      return true;
    else
      return false;
  }

  void insert(int value) {
    if (!find(value)) {
      _root = __insert(_root, value);
      _size++;
    }
  }

  void remove(int value) {
    if (find(value)) {
      _root = __remove(_root, value);
      _size++;
    }
  }

  int height() { return __bst__height(_root); }

  void traverseInorder() { __inorder(_root); }

  void traversePreorder() { __preorder(_root); }

  void traversePostorder() { __postorder(_root); }

private:
  BSTNode *__createNode(int value) {
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
  }

  BSTNode *__search(BSTNode *root, int value) {
    while (root != NULL) {
      if (value < root->key)
        root = root->left;
      else if (value > root->key)
        root = root->right;
      else
        return root;
    }
    return root;
  }

  BSTNode *__insert(BSTNode *root, int value) {
    if (root == NULL)
      return __createNode(value);

    if (value < root->key) {
      root->left = __insert(root->left, value);
    } else if (value > root->key) {
      root->right = __insert(root->right, value);
    }

    return root;
  }

  BSTNode *__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
      currNode = currNode->left;

    return currNode;
  }

  BSTNode *__remove(BSTNode *root, int value) {
    if (root == NULL)
      return NULL;

    if (value > root->key)
      root->right = __remove(root->right, value);
    else if (value < root->key)
      root->left = __remove(root->left, value);
    else {

      if (root->left == NULL) {
        BSTNode *rightChild = root->right;
        free(root);
        return rightChild;
      } else if (root->right == NULL) {
        BSTNode *leftChild = root->left;
        free(root);
        return leftChild;
      }

      BSTNode *temp = __findMinNode(root->right);
      root->key = temp->key;
      root->right = __remove(root->right, temp->key);
    }
    return root;
  }

  int __bst__height(BSTNode *node) {
    if (node == NULL)
      return 0;
    else {
      int lheight = __bst__height(node->left);
      int rheight = __bst__height(node->right);

      if (lheight > rheight)
        return (lheight + 1);
      else
        return (rheight + 1);
    }
  }

  void __inorder(BSTNode *root) {
    if (root) {
      __inorder(root->left);
      printf("%d ", root->key);
      __inorder(root->right);
    }
  }

  void __postorder(BSTNode *root) {
    if (root) {
      __postorder(root->left);
      __postorder(root->right);
      printf("%d ", root->key);
    }
  }

  void __preorder(BSTNode *root) {
    if (root) {
      printf("%d ", root->key);
      __preorder(root->left);
      __preorder(root->right);
    }
  }
};

int main(int argc, char const *argv[]) {
  BST set;
  set.init();

  set.insert(6);
  set.insert(1);
  set.insert(8);
  set.insert(12);
  set.insert(1);
  set.insert(3);
  set.insert(7);

  puts("");

  set.remove(1);
  set.remove(6);
  set.remove(8);
  puts("");
  return 0;
}
