/*
    Interquartile Range

    Given a sorted singly linked list without a tail (e.g, head -> 1 -> 2 -> 3 -> 4), 
    return the interquartile range of the data set using the slow and fast pointer 
    approach OR using a methodology that does not iterate over the linked list 
    twice. You must not iterate over the entire linked list more than once and you 
    cannot use arrays, vectors, lists or an STL implementation of List ADT in this problem.

    Sample Input:
        2 4 4 5 6 7 8
    
    Sample Output:
        3.00 
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Node {
    public:
        int value;
        Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = key;
    if(head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

float interQuartile(Node* head)
{
    Node* p1 = head;
    Node* p2 = head;
    Node* p3 = head;
    Node* p4 = head;
    int count = 0;

    while (p4->next != nullptr) {
      p4 = p4->next;
      if (count % 2 == 0) {
        p2 = p2->next;
      }
      if (count % 4 == 0 && count != 0) {
        p1 = p1->next;
      }
      if (count % 4 != 0 && count != 0) {
        p3 = p3->next;
      }
      count++;
    }
  count++;
  float Q1;
  float Q3;
  float IQR;
    if (count % 4 == 0) { 
      if (p1->next) {
        Q1 = (static_cast<float>(p1->value) + static_cast<float>(p1->next->value))/2.0; 
      } else {
        Q1 = static_cast<float>(p1->value);
      }
      if (p3->next) {
        Q3 = (static_cast<float>(p3->value) + static_cast<float>(p3->next->value))/2.0; 
      } else {
        Q3 = static_cast<float>(p3->value);
      }
    }
    if (count % 4 == 1) {
      if (p1->next) {
        Q1 = (static_cast<float>(p1->value) + static_cast<float>(p1->next->value))/2.0; 
      } else {
        Q1 = static_cast<float>(p1->value);
      }
      if (p3->next) {
        Q3 = (static_cast<float>(p3->value) + static_cast<float>(p3->next->value))/2.0; 
      } else {
        Q3 = static_cast<float>(p3->value);
      }
    }
    if (count % 4 == 2) {
      Q1 = static_cast<float>(p1->value);
      if (p3->next) {
        Q3 = static_cast<float>(p3->next->value); 
      } else {
        Q3 = static_cast<float>(p3->value);
      }
    }
    if (count % 4 == 3) {
      Q1 = static_cast<float>(p1->value);
      if (p3->next) {
        Q3 = static_cast<float>(p3->next->value); 
      } else {
        Q3 = static_cast<float>(p3->value);
      }
    }
    IQR = Q3 - Q1;
    return IQR;   
}   