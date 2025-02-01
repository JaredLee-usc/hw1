/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  // base case if input list is empty, return
  if(in == nullptr){
    return;
  }

  // check if current node's value is odd
  if(in->value % 2 != 0){
    // if odds list is empty initialize with current node
    if(odds == nullptr){
      odds = in;
      in = in->next; // move input pointer to next node
      odds->next = nullptr;
      split(in, odds, evens); // recursively process the rest of the list
    }
    // if odds list exists, append current node to it
    else {
      odds->next = in; // connect current node to odds list
      in = in->next;  // move input pointer to next node
      odds->next->next = nullptr;
      split(in, odds->next, evens); // recursively process the rest of the list
    }
  }
  // handles even values in the current node
  else {
    // if evens list is empty initialize with current node
    if(evens == nullptr){
      evens = in;
      in = in->next; // move input pointer to next node
      evens->next = nullptr;
      split(in, odds, evens); // recursively process the rest of the list
    }
    // if odds list exists, append current node to it
    else {
      evens->next = in; // connect current node to evens list
      in = in->next; // move input pointer to next node
      evens->next->next = nullptr;
      split(in, odds, evens->next); // recursively process the rest of the list
    }
  }
}

/* If you needed a helper function, write it here */
