
/*****************************************************************************
*                    
*  Author:           Kate Morgan
*  Email:            kbmorgan0911@gmail.com 
*  Label:            Program 1 - vector class
*  Title:            Vector class
*  Course:           2143 Object Oriented Programming
*  Semester:         spring 2023
* 
*  Description:
*        This program creats a linked list to store integers using a class
*        called Vector. The class contians multiple methods to allow use of the
*        Vector.
* 
*  Usage:
*        
* 
*  Files:            
*        main.cpp
*        input.dat
*        test.out
*****************************************************************************/
#include <fstream>
#include <iostream>
using namespace std;

/**
 * struct node
 * 
 * Description:
 *          Creates a node to be used in linked lists, includes a next and prev
 *          pointer for double linked lists
 * 
 * Public Methods:
 *            node() 
 *            node(int x)
 *      
 * 
 * Usage: 
 *       node *temp = new node() to create a new list
 *       
 *      
 */
struct node {
  int data;
  node *next;
  node *prev;

  node() {
    data = 0;
    next = prev = nullptr;
  }
  node(int x) {
    data = x;
    next = prev = nullptr;
  }
};

/**
 * Class Vector
 * 
 * Description:
 *      Uses a double linked list to create a vector that can store int data
 *      The methods can be used to add or remove data along with printing the data
 *      to an output file and to console
 * 
 * Public Methods:
 *                  vector()
 *                  vector(int *a, int size)
 *                  Vector(string filename)
 *                  Vector(const Vector &v1)
 *             void pushFront(int Val)
 *             void pushFront(Vector &v1)
 *             void pushRear(int val)
 *             void pushRear(Vector &v1)
 *             void pushAt(int loc, int val)
 *             void inOrderPush()
 *             int popFront()
 *             int popRear()
 *             int popAt(int loc)
 *             int find(int val)
 *             void print()
 * 
 * Private Methods:
 *             none
 * 
 * Usage: 
 *        Vector v1          Creates a vector
 *        Vector v2(A, 5)    Creates a vector and fills it with an exsisting array
 *        v2.pushFront(9)    Pushes a number to the front
 *        v2.pushRear(63)    Pushes a number to the end
 *        v2.print()         Prints the vector to console and an outfile
 */
class Vector {
private:
  node *head;
  node *tail;
  int index;

public:
  // Constuctors
  Vector() { head = tail = nullptr; }
  
  Vector(int Arr[], int size) {
    head = tail = nullptr;
    for (int i = 0; i < size +1; i++) {
      pushRear(Arr[i]);
    }
  }
  Vector(string filename) {
    ifstream infile;         //infile for opening files
    head = tail = nullptr;
    infile.open(filename);
    int temp;

    while (!infile.eof()) {  //Loop till end of file to read in data
      infile >> temp;
      pushRear(temp);
    }
  }
  Vector(const Vector &v1) {
    head = tail = nullptr;
    node *temp = v1.head;    //Creates a temp node to traverse and read in data

    while (temp != nullptr) {//Loops through the vector
      pushRear(temp->data);
      temp = temp->next;
    }
  }

  // Adding things to the list

  void pushFront(int Val) {
    node *temp = new node(Val);  //temp node 
    if (head == nullptr) {       //check if the vector is empty
      head = tail = temp;
    } else {                     //Else statement for when vector is not full
      temp->next = head;
      head->prev = temp;
      head = temp;
    }
  }
  void pushFront(Vector &v1) {  
    node *temp = new node();        //Temp node
    temp = v1.tail;
    while (temp->prev != nullptr) { //While loop to get through vector
      temp->next = head;
      head->prev = temp;
      head = temp;
      temp = temp->prev;
    }
  }
  void pushRear(int val) {
    node *temp = new node();  //temp node
    if (head == nullptr) {    //check if the the vector is empty
      head = tail = temp;
    } else {                  //else for when the vector is not empty
      tail->next = temp;
      temp->prev = tail;
      tail = temp;
      tail -> data = val;
    }
  }
  void pushRear(Vector &v1) {
    node *temp = new node();          //temp node
    temp = v1.head;
    while (temp->next != nullptr) {   //loop to run through other vector
      tail->next = temp;
      temp->prev = tail;
      tail = temp;
      temp = temp->next;
    }
  }
  void pushAt(int loc, int val) {
    node *trav = new node();        //temp node to trav the vector
    node *temp = new node(val);     //temp node 
    trav->next = head;
    int i = 0;                      //int to keep track of location
    while (i != loc -1) {           //while loop to find the inset location
      trav = trav->next;
      i++;
    }
    temp->next = trav;
    temp->prev = trav->prev;
    trav->prev = temp;
  }
  void inOrderPush() {}

  // Remove things
  int popFront() {
    node *temp = new node();    //temp node
    temp = head;
    head = head->next;
    return temp->data;
    delete temp;
  }
  int popRear() {
    node *temp = new node();    //temp node
    temp = tail;
    tail = tail->prev;
    return temp->data;
    delete temp;
  }
  int popAt(int loc) {
    node *trav = new node();    //temp node to traverse the vector
    node *temp = new node();    //temp node
    int i = 0;                  //int to keep track of location
    trav->next = head;
    while (i != loc) {          //while loop to find location
      trav = trav->next;
      i++;
    }
    temp = trav;
    trav = trav->next;
    trav->prev = temp->prev;
    return temp->data;
    delete temp;
  }
  int find(int val) {
    node *trav = new node();         //temp node to traverse the vector
    int count = 0;                   //int to keep track of travel
    trav = head;
    while (trav->next != nullptr) {  //while loop to traverse the vector
      if (trav->data == val) {       //if to find the value
        return count;
      } else {                       //else to traverse the vector till the value is found
        trav = trav->next;
        count++;
      }
    }
    return -1;                        //returns -1 if value not found
  }

  // Print
  void print() {
    ofstream outfile;                  //used to open the output file
    outfile.open("test.out");
    node *trav = new node();           //temp node to traverse the vector
    trav = head;
    outfile << "Kate Morgan\n" << "feb 6, 2023\n" << "spring 2023\n";
    cout <<"[";
    outfile << "[";
    while (trav->next != nullptr) {    //while loop to traverse the vector and print it
      cout << trav->data << " ";
      outfile << trav->data << " ";
      trav = trav->next;
    }
    cout  << "]" << endl;
    outfile  << "]" << endl;
  }
};

int main() {

  int x = 0;

  Vector v1;
  v1.pushFront(18);
  v1.pushFront(20);
  v1.pushFront(25);
  v1.pushRear(18);
  v1.pushRear(20);
  v1.pushRear(25);
  v1.print();
  // [25, 20, 18, 18, 20, 25]

  int A[] = {11, 25, 33, 47, 51};
  Vector v2(A, 5);
  v2.print();
  // [11, 25, 33, 47, 51]

  v2.pushFront(9);
  // v2.inOrderPush(27);
  v2.pushRear(63);
  v2.print();
  // [9, 11, 25, 33, 47, 51, 63]

  v1.pushRear(v2);
  v1.print();
  // [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

  x = v1.popFront();
  x = v1.popFront();
  x = v1.popFront();
  v1.print();
  // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
  cout << x << endl;
  // 18

  x = v1.popRear();
  x = v1.popRear();
  x = v1.popRear();
  v1.print();
  // [18, 20, 25, 9, 11, 25, 27, 33]
  cout << x << endl;
  // 47

  x = v2.popAt(3);
  v2.print();
  // [9, 11, 25, 33, 47, 51, 63]
  cout << x << endl;
  // 27

  x = v2.find(51);
  cout << x << endl;
  // 5

  x = v2.find(99);
  cout << x << endl;
  // -1

  Vector v3(v1);
  v3.print();
  // [18, 20, 25, 9, 11, 25, 27, 33]

  v3.pushFront(v2);
  v3.print();
  //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

  Vector v4("input.dat");
  v4.pushRear(v3);
  v4.print();
  // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18,
  // 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47,
  // 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]
}