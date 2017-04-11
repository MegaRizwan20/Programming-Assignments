/*
 * Authors: Rizwan Khan, Zhuoran Gu
 * UCSD Email: rikhan@ucsd.edu, zhg050@ucsd.edu
 * PID: A12236946, A53213113
 * CSE Login: cs100sgv, zhg050
 */

#include "BSTInt.h"
#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2017
 * Author: Christine Alvarado and YOU
 * TODO: Add more tests
 */
int main() {

    /* Create an STL vector of some ints */
    /*test*/
    vector<int> v;
    vector<int> c;
    /*v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(100);
    v.push_back(-33);*/

    /*v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    //v.push_back(4);*/
    //
    	/*v.push_back(11);
	v.push_back(10);
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);*/
	v.push_back(13);
	v.push_back(16);
	v.push_back(10);
	v.push_back(12);
	v.push_back(9);
	v.push_back(14);
	v.push_back(17);
	v.push_back(11);
	v.push_back(15);
	/*v.push_back(5);
	v.push_back(5);*/

    /* Create an instance of BST holding int */
    BSTInt b;

    /* For checking if the height of the tree is correct */
    int heightTest;

    /* Testing to see if the tree is empty. If it is not empty then the return
     * value is incorrect */
    bool emptyTest = b.empty();
    if (emptyTest == false)
    {
       cout << "Incorrect empty return value " << endl;
       return -1;
    }

    /* Testing the height of an empty tree */
    heightTest = b.height();
    cout << "The empty tree height is " << heightTest << endl;
    if (heightTest != 0)
    {
      cout << "Incorrect height value " << endl;
      return -1;
    }

    // Could use: for(auto item : v) { instead of the line below
    for(int item : v) {
        bool pr = b.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }


    /* Test size. */
    cout << "Size is: " << b.size() << endl;
    if(b.size() != v.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : v) {
        if(!b.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    /* Testing to see the tree has values, if it is empty then the return value
     * is incorrect */
    emptyTest = b.empty();
    if (emptyTest == true)
    {
      cout << "Incorrect empty return value " << endl;
      return -1;
    }

    /* Testing the height of a tree after the insertions */
    heightTest = b.height();
    cout << "The height of the tree after insertion " << heightTest << endl;
    if (heightTest != 3)
    {
      cout << "Incorrect tree height " << endl;
      return -1;
    }

    //cout << "All first insert tests passed " << endl;


    /* UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED ITERATOR */

    /*
    // Test the template version of the BST  with ints 
    BST<int> btemp;
    for (int item : v) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;
              
    }

    // Now test finding the elements we just put in
    for (int item: v) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt) 
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }



    // Test the iterator: The iterator should give an in-order traversal
  
    // Sort the vector, to compare with inorder iteration on the BST
    sort(v.begin(),v.end());

    cout << "traversal using iterator..." << endl;
    auto vit = v.begin();
    auto ven = v.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto en = btemp.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it = btemp.begin();
    for(; vit != ven; ++vit) {
        if(! (it != en) ) {
            cout << *it << "," << *vit 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it << endl;
        if(*it != *vit) {
            cout << *it << "," << *vit 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it;
    }

    cout << "success!" << endl;

    */

    // ADD MORE TESTS HERE.  You might also want to change what is input
    // into the vector v.
    cout << "Second insert test, testing inserting duplicate. " << endl;
    c.push_back(5);
    //c.push_back(5);

    BSTInt a;

    // Could use: for(auto item : v) { instead of the line below
    for(int item : c) {
        bool pr = a.insert(item);
        if( !pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }

    /* Test size. */
    cout << "Size is: " << a.size() << endl;
    if(a.size() != 1) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : c) {
        if(!a.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    /* Testing the height of a tree with only one node */
    heightTest = a.height();
    if (heightTest != 0)
    {
      cout << "Incorrect height for tree with one node " << endl;
      return -1;
    }

    cout << "All tests passed!" << endl;
    return 0;
}
