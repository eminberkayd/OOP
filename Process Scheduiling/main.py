#include <iostream>
#include <fstream>
using namespace std;


class Node{ // Node structure for Linked List
private:
    int processID, arrivalTime, runTime, priority;
    Node* previousNode;  // A pointer which points to the previous node, initially NULL
    Node* nextNode;      // A pointer which points to the next node, initially NULL

public:
    Node()
    {
      previousNode = NULL;
      nextNode     = NULL;


    } //Default Constructor
    Node(int processID_i, int arrivalTime_i, int runTime_i, int priority_i)// Parameterized Constructor, _i added for inputs
    { processID    = processID_i;
      arrivalTime  = arrivalTime_i;
      runTime      = runTime_i;
      priority     = priority_i;
      previousNode = NULL;
      nextNode     = NULL;
    }
    int getPriority(){return priority;}
    int getProcessID(){return processID;}
    int getArrivalTime(){return arrivalTime;}
    int getRunTime(){return runTime;}

    Node* getPreviousNodePointer(){return previousNode;}
    Node* getNextNodePointer(){return nextNode;}

    void setPreviousNodePointer(Node* x){previousNode=x;}
    void setNextNodePointer(Node* x){nextNode=x;}
    void decrementRunTime(){runTime--;}
};

class LinkedList{

private:
    Node* head;
    int searching, inserting;
    int insertedFlag;

public:
    LinkedList()
    {
        searching=inserting=insertedFlag=0;

        head = NULL;
    }
    int getSearching(){return searching;}
    int getInserting(){return inserting;}

    void enqueue(Node* x)

    {   inserting++;
        if(head==NULL)
        {
        head = x;

        }
        else if((x->getPriority())<(head->getPriority()))
              {
                  x->setNextNodePointer(head);
                  head->setPreviousNodePointer(x);
                  head = x;

              }
        else if((x->getPriority())>(head->getPriority()))
              {
                Node* temp;
                temp = head;

                while((x->getPriority())>(temp->getPriority()))
                      {   inserting++;


                          if((temp->getNextNodePointer())!=NULL)//That means the Node x's priority is the lowest, so we should put it at the end of queue.
                           {
                              temp = temp->getNextNodePointer();



                           }
                           else
                           {
                             insertedFlag = 1;
                             break;

                           }}
                if(insertedFlag==1){
                    temp->setNextNodePointer(x);
                    x->setPreviousNodePointer(temp);
                    insertedFlag=0;
                }


                else if(insertedFlag==0)
                {
                    Node* temp2;

                    temp2 = temp->getPreviousNodePointer();

                    temp2->setNextNodePointer(x);
                    temp->setPreviousNodePointer(x);
                    x->setPreviousNodePointer(temp2);
                    x->setNextNodePointer(temp);


                }}
            }


    Node* dequeue()

    { searching++;
      Node* temp3;

      temp3 = head;

      head = head->getNextNodePointer();

      return temp3;


    }

    bool isEmpty() // Empty Queue Checking
    {
        if (head==NULL){                // If head points to nothing
        return true;

        }
      else{
        return false;



    }}


};

class Node2{ // Node structure for Binary Search Tree
private:
    int processID, arrivalTime, runTime, priority;
    Node2* Left;  // A pointer which points to the left node, initially NULL
    Node2* Right;      // A pointer which points to the right node, initially NULL


public:
    Node2()
    {
      Left  = NULL;
      Right = NULL;



    } //Default Constructor
    Node2(int processID_i, int arrivalTime_i, int runTime_i, int priority_i)// Parameterized Constructor, _i added for inputs
    { processID    = processID_i;
      arrivalTime  = arrivalTime_i;
      runTime      = runTime_i;
      priority     = priority_i;
      Left         = NULL;
      Right        = NULL;



    }
    int getPriority(){return priority;}
    int getProcessID(){return processID;}
    int getArrivalTime(){return arrivalTime;}
    int getRunTime(){return runTime;}

    Node2* getLeftNodePointer(){return Left;}
    Node2* getRightNodePointer(){return Right;}

    void setLeftNodePointer(Node2* x){Left=x;}
    void setRightNodePointer(Node2* x){Right=x;}
    void decrementRunTime(){runTime--;}
};

class BinarySearchTree{
private:
    Node2* root;
    int searching, inserting;


public:
    BinarySearchTree()
    {
        searching=inserting=0;

        root = NULL;
    }

    void enqueue(Node2* x){
        inserting++;

        if(root==NULL){

            root=x;

        }
        else
            insertAfterRoot(x,root);
        }

    Node2* insertAfterRoot(Node2* target, Node2* place){

        if(place==NULL){

            return place;
        }

        if((target->getPriority())>(place->getPriority())){


            place = insertAfterRoot(target,place->getRightNodePointer());


            place = target;


        }
        else
        {

            place = insertAfterRoot(target,place->getLeftNodePointer());


            place = target;

        }

        }


    Node2* dequeue(){
        searching++;
        Node2* temp;
        temp = root;
        while(temp->getLeftNodePointer()!=NULL){

            temp = temp->getLeftNodePointer();
        }
        return temp;

    }

    bool isEmpty(){
        if(root==NULL){
            return 1;
        }
        else
            return 0;


    }

};



int main()
{   /* reading processes from file */
    ifstream processesFile;                          /* input file stream */
    processesFile.open("processes1000.txt");
    int numProcesses;                                /* number of processes */
    processesFile >> numProcesses;                   /* read from file */
    //Node2 process[numProcesses];                      /* create Node array */
    Node process[numProcesses];
    int processID, arrivalTime, runTime, priority;
    for(int i=0; i<numProcesses; ++i){
    processesFile >> processID >> arrivalTime >> runTime >> priority; /* read 4 integers from file */
    //process[i] = Node2(processID, arrivalTime, runTime, priority);     /* construct i'th element of the array */
    process[i] = Node(processID, arrivalTime, runTime, priority);
    }
    processesFile.close();  /* end of reading from file */
    LinkedList RQ;
    //BinarySearchTree RQ;
    int time = 0;
    bool CPUbusy = false;
    //Node2* currentProcess = NULL; //For Tree Structure
    Node* currentProcess = NULL; //For Linked List Structure
    int processIndex = 0;
    int sayi=0;

    while ((processIndex<numProcesses) || (!(RQ.isEmpty())) || (CPUbusy == true)){

        if (processIndex<numProcesses){
            if( process[processIndex].getArrivalTime() == time ){
                RQ.enqueue(&process[processIndex]);
                processIndex++;
            }
        }
        if (CPUbusy == true){
            currentProcess->decrementRunTime();
            }

        if(currentProcess!=NULL){
        if(currentProcess->getRunTime()==0)
            {
            CPUbusy = false;
            }}

        if((CPUbusy == false) && (!(RQ.isEmpty()))){

             currentProcess = RQ.dequeue();
             sayi++;

             int id = currentProcess->getProcessID();
             cout<<"ID : "<<id<<" "<<sayi<<endl;
             CPUbusy = true;
        }
        time++;
      }
      cout<<"\n\n Searching : "<<RQ.getSearching()<<endl;
      cout<<"\n Inserting : "<<RQ.getInserting()<<endl;

    }

