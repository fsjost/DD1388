#include <iostream>
#include <algorithm>
#include "bintree.h"
using namespace std;

void insert(Node * & p, int key, double to_be_inserted){
  if(p == nullptr){
    p = new Node;
    p -> key   = key;
    p -> data  = to_be_inserted;
    p -> left  = nullptr;
    p -> right = nullptr;
  }
  else{
    if(p -> key == key){
      p -> data = to_be_inserted;
    }
    else{
      Node*& gemuse = (p -> key > key) ? p-> left : p-> right;
      insert(gemuse, key, to_be_inserted);
    }
  }
}

const double & find(Node * p, const int & to_be_found){
  if(!p){
    throw out_of_range("The key you're looking for can't be found\n");
  }
  else if(p -> key == to_be_found){
    return p -> data;
  }
  else if(p -> left == nullptr && p -> right == nullptr){
    throw out_of_range("The key you're looking for can't be found\n");
  }
  else{
    Node* gemuse = (p -> key > to_be_found) ? p-> left : p-> right;
    return find(gemuse, to_be_found);
  }
  throw out_of_range("The Key you're looking for can't be found\n");
}

void delete_tree(struct Node * & p){
  while(p != nullptr){
    delete_tree(p->left);
    delete_tree(p->right);
    delete(p); p = nullptr;                           //Deleting the pointer and setting it to the null pointer
  }
}

unsigned int max_height(Node * p){
  if(p == nullptr)
    return 0;
  else{
    int lheight = max_height(p -> left);
    int rheight = max_height(p -> right);
    return max(lheight,rheight)+1;
  }
}

unsigned int min_height(Node * p){
  if(p == nullptr)
    return 0;
  else{
    int lheight = min_height(p -> left);
    int rheight = min_height(p -> right);
    return min(lheight,rheight)+1;
  }
}

unsigned int size(Node * p){
  if(p == nullptr)
    return 0;
  else{
    int lheight = size(p -> left);
    int rheight = size(p -> right);
    return lheight+rheight+1;
  }
}

bool is_balanced(Node * p){
  if(p == nullptr)
    return true;
  else{
    int lheight = max_height(p -> left);
    int rheight = max_height(p -> right);
    return abs(lheight-rheight)<= 1 && is_balanced(p -> left) && is_balanced(p -> right);
  }
}

Node* find_max_left(Node* p){
  while(p ->right != nullptr){
    p = p -> right;
  }
  return p;
}

Node* find_min_right(Node* p){
  while(p ->left != nullptr){
    p = p -> left;
  }
  return p;
}

void remove(Node * & p, const int & key){
  if(!p){
    throw out_of_range("The key you're looking for can't be found\n");
  }
  if(p == nullptr){
    return;
  }
  if(key < p -> key){
    remove(p->left, key);
  }
  else if(key > p->key){
    remove(p -> right, key);
  }
  else{
    if(p -> left == nullptr && p -> right == nullptr){
      delete p;
      p = nullptr;
    }
    else if(p -> left && p -> right){
      if(find_max_left(p) >= find_min_right(p)){
        Node *temp = find_max_left(p->left);
        p -> key = temp -> key;
        p -> data = temp -> data;
        remove(p -> left, temp -> data);
      }
      else{
        Node *temp = find_min_right(p->right);
        p -> key = temp -> key;
        p -> data = temp -> data;
        remove(p -> right, temp -> data);
      }
    }
    else{
      Node* temp =(p -> left) ? p -> left : p -> right;
      delete p;
      p = temp;
    }
  }
}

double & edit(Node * p, const int & to_be_changed){
  if(!p){
    throw out_of_range("The key you're looking for can't be found\n");
  }
  if(p -> key == to_be_changed){
    return p -> data;
  }
  else if(p -> left == nullptr && p -> right == nullptr){
    throw out_of_range("The key you're looking for can't be found\n");
  }
  else{
    Node* gemuse = (p -> key > to_be_changed) ? p-> left : p-> right;
    return edit(gemuse, to_be_changed);
  }
  throw out_of_range("The Key you're looking for can't be found\n");
}

/*
int main() {
  cout << endl;
  Node *root = nullptr;
  insert(root,11,11);
  insert(root,6,6);
  insert(root,4,4);
  insert(root,5,5);
  insert(root,8,8);
  insert(root,10,10);
  insert(root,19,19);
  insert(root,17,17);
  insert(root,43,43);
  insert(root,31,31);
  insert(root,49,49);
  cout << size(root) << endl;
  cout << size(root) << endl;
  cout << endl;
  delete_tree(root);          // Ta bort
  return 0;
}
*/
