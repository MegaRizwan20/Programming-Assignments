/*
 * Authors: Rizwan Khan, Zhuoran Gu
 * UCSD Email: rikhan@ucsd.edu, zhg050@ucsd.edu
 * PID: A12236946, A53213113
 * CSE Login: cs100sgv, zhg050
 */

#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>
using namespace std;

template<typename Data>
class BSTNode {

public:

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d);


  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */
  BSTNode<Data>* successor(); 

}; 


// Function definitions
// For a templated class it's easiest to just put them in the same file as 
// the class declaration

template <typename Data>
BSTNode<Data>::BSTNode(const Data & d) : left(0), right(0), parent(0), data(d) {}

/* Return a pointer to the BSTNode that contains the item that is sequentially 
 * next in the tree */
template <typename Data>
BSTNode<Data>* BSTNode<Data>::successor()
{
  // Create a BST Node that is set to the current node
  BSTNode<Data>* curr = this;
  /* Check if there is anything to the right of the current node */
  if (curr->right != NULL)
  { 
    // Set the right of the current node to the right of the current node
    curr = curr->right;
    // Check if left of current node is NULL and if not then move to the left
    while (curr->left != NULL) 
    {
      curr = curr->left;
    }
    return curr;  
  }
  // Else there is nothing to the right of the current node
  else 
  {
    /* If the parent's data is equal to null pointer, we return nullptr */
    if (curr->parent == nullptr)
    {
      return nullptr;
    }

    /* Check if the current node's data is less than the parent's data */
    if (curr->data < curr->parent->data)
    {
      curr = curr->parent;
      return curr;
    }
    // Else the current node's data is greater than the parent's data
    else
    {
      /* Check if the parent is not null and that the parent's data is less
       * than the current node's data */
      while (curr->parent != NULL && curr->parent->data < curr->data)
      {
        /* The parent of the current node is equal to nullptr so,
         * return nullptr */
        if (curr->parent == nullptr)
        {
          return nullptr;
        }
        curr = curr->parent;
      }
      // If the parent is not null then we return the parent
      if (curr->parent != NULL)
      {
        curr = curr->parent;
        return curr;
      }
      // Return 0 when we reached the biggest element in the tree
      else
      {
        return 0;
      }
    }  
  }
}

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
