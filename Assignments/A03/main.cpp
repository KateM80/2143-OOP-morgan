/*****************************************************************************
*                    
*  Author:           Kate Morgan
*  Email:            kbmorgan0911@my.msutexas.edu
*  Label:            AO3
*  Title:            Commented code
*  Course:           CMPS 2143
*  Semester:         Spring 2023
* 
*  Description:
*        This program is used as an emxple of how to do commenting properly.
*        The program itself contians a class used to implement circular queues
*        as an Array, with a method to overide << opperators.
* 
*  Usage:
*        The program is used by running the main.cpp
* 
*  Files:            
*        Main.cpp       :contians implmentaion of the code
*****************************************************************************/
#include <iostream>

using namespace std;


/**
 * CircularArrayQue
 * 
 * Description:
 *      This class implements a circular queue based using an Array. The queue allows
 *      the user to input a set size for the queue, in addition to pushing data and poping
 *      data. 
 * 
 * Public Methods:
 *      CircularArrayQue()
 *      CircularArrayQue(int size)
 *      void Push(int item)
 *      int Pop()
 *      friend ostream &operator<<(ostream &os, const CircularArrayQue &other)
 * 
 * Private Methods:
 *      void init(int size = 0)
 *      bool Full()
 * 
 * Usage: 
 *      CircularArrayQue C1(5)      //Create an instance of CIrcularArrayQue
 *      C1.Push(1)                  //Adds 1 to the queue
 *      C1.Pop()                    //Removes the front of the queue
 *      cout << C1                  //Will print the Array to console
 *      
 */

class CircularArrayQue {
private:
    int *Container;     //Pointer to store Items in Queue
    int Front;          //used to keep the front of the Queue
    int Rear;           //Used to keep the end of the Queue
    int QueSize;        //items in the Queue
    int CurrentSize;    //Keeps track of the size of the Queue

    // to intialize the Queue
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    } 

    // check if the Queue is currently full
    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    //Defualt constructor
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    //overides the constructor to let the user input a size
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    //puts data in to the queue 
    void Push(int item) {
        if (!Full()) {      //will put the data in if the queue is not full 
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {            //will print out full if full
            cout << "FULL!!!!" << endl;
        }
    }

    //returns and removes data from queue
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    //calls the method to overide the << opperator
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

/**
     * Public : ostream &operator<<
     * 
     * Description:
     *      Overides the << operator to be used to print out 
     *      the CirrcularArrayQue
     * 
     * Params:
     *      ostream &os     
     *                  //passes in ostream
     *      const CircularArrayQue &other
     *                  //Passes in the Queue and keeps it const
     *      
     * Returns:
     *      returns the change to the Ostream for the << operator
     */
ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);     //Creation of a CircularArrayQue C1 with a size of 5

    // C1.Push(34);     
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);     
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;         //Prints out the queue because of << overrides

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}