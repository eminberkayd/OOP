/* Emin Berkay Dağlar 2304400
---------EE441 Homework 2------------ */


#include <iostream>
#include<fstream>
#include<string>
#include <cstring>
using namespace std;

class Student{

private:
    int ID;
    char first, second, third;
public:
    Student(){}

    int getID();
    char getfirst();
    char getsec();
    char getthr();
    void setfirst(char firstt=NULL){
        first = firstt;
    }
    void setsec(char secondd=NULL){
        second = secondd;
    }
    void setthird(char thirdd=NULL){
        third = thirdd;
    }
    void setID(int id=0){
        ID = id;
    }
};

int Student::getID(){
    return ID;
}
char Student::getfirst(){
    return first;
}
char Student::getsec(){
    return second;
}
char Student::getthr(){
    return third;
}

class Class{
public:
    Student students[999];
};
Class ee441;
class Section{
private:
    int MAX;

    int students[99];
    int idx=0;
public:
    Section(){}

    void assStu(int id){

        if(idx != MAX){
        students[idx] = id;
        idx+=1;}

    }
    int isFull(){
        if (idx==MAX){
            return 1;
        }
        else
            return 0;
    }
    void setsize(int sz){
        MAX = sz;
    }
    int getsize(){
     return MAX;
    }
    int getStuID(int idxx){
        return students[idxx];
        }
};
Section Wed;
Section Thu;
Section Fri;

class wQueue{

public:
    int wStu[99];
    int dx=0;
    void addStu2Que(int id){
        wStu[dx] = id;
        dx+=1;
    }

};
wQueue myQue;





void makeschedule(int sizeC){

    int index = 0;

    while(index<sizeC){

        if(ee441.students[index].getsec()==NULL){

                if(ee441.students[index].getfirst()=='W'){

                    if(Wed.isFull()==0){
                    Wed.assStu(ee441.students[index].getID());}
                    else{
                        myQue.addStu2Que(ee441.students[index].getID());
                    }
                }
                else if(ee441.students[index].getfirst()=='T'){
                    if(Thu.isFull()==0){
                    Thu.assStu(ee441.students[index].getID());}
                    else{
                        myQue.addStu2Que(ee441.students[index].getID());
                    }

                }
                else{
                     if(Fri.isFull()==0){
                    Fri.assStu(ee441.students[index].getID());}
                    else{
                        myQue.addStu2Que(ee441.students[index].getID());
                }
                }}
        index+=1;





    }


    //

    index = 0;

    while(index<sizeC){

        if(ee441.students[index].getthr()==NULL && ee441.students[index].getsec()!=NULL){

                if(ee441.students[index].getfirst()=='W'){

                    if(Wed.isFull()==0){
                    Wed.assStu(ee441.students[index].getID());
                    break;}


                }
                if(ee441.students[index].getfirst()=='T'){
                    if(Thu.isFull()==0){
                    Thu.assStu(ee441.students[index].getID());
                    break;}


                }
                if(ee441.students[index].getfirst()=='F'){
                    if(Fri.isFull()==0){
                    Fri.assStu(ee441.students[index].getID());

                    break;

                    }}
                if(ee441.students[index].getsec()=='W'){
                    if(Wed.isFull()==0){
                    Wed.assStu(ee441.students[index].getID());
                    break;}
                    else{
                        myQue.addStu2Que(ee441.students[index].getID());
                    }

                }
                if(ee441.students[index].getsec()=='T'){
                    if(Thu.isFull()==0){
                    Thu.assStu(ee441.students[index].getID());
                    break;}
                    else{
                        myQue.addStu2Que(ee441.students[index].getID());
                    }


                }
                if(ee441.students[index].getsec()=='F'){
                    if(Fri.isFull()==0){
                    Fri.assStu(ee441.students[index].getID());

                    break;}
                    else{
                        myQue.addStu2Que(ee441.students[index].getID());
                    }

                }


                }
                index+=1;
           }


    index = 0;

    while(index<sizeC){

        if(ee441.students[index].getthr()!=NULL){

                if(ee441.students[index].getfirst()=='W'){

                    if(Wed.isFull()==0){
                    Wed.assStu(ee441.students[index].getID());
                    break;}

                }
                if(ee441.students[index].getfirst()=='T'){
                    if(Thu.isFull()==0){
                    Thu.assStu(ee441.students[index].getID());
                    break;}

                }
                if(ee441.students[index].getfirst()=='F'){
                    if(Fri.isFull()==0){
                    Fri.assStu(ee441.students[index].getID());

                    break;}
                }
                if(ee441.students[index].getsec()=='W'){
                    if(Wed.isFull()==0){
                    Wed.assStu(ee441.students[index].getID());
                    break;}
                }
                if(ee441.students[index].getsec()=='T'){
                    if(Thu.isFull()==0){
                    Thu.assStu(ee441.students[index].getID());
                    break;}
                }
                if(ee441.students[index].getsec()=='F'){
                    if(Fri.isFull()==0){

                    Fri.assStu(ee441.students[index].getID());

                    break;}

                }
                if(ee441.students[index].getthr()=='W'){
                    if(Wed.isFull()==0){
                    Wed.assStu(ee441.students[index].getID());
                    break;}
                    else{

                        myQue.addStu2Que(ee441.students[index].getID());
                    }
                }
                if(ee441.students[index].getthr()=='T'){
                    if(Thu.isFull()==0){
                    Thu.assStu(ee441.students[index].getID());
                    break;}
                    else{

                        myQue.addStu2Que(ee441.students[index].getID());
                    }
                }
                if(ee441.students[index].getthr()=='F'){
                    if(Fri.isFull()==0){
                    Fri.assStu(ee441.students[index].getID());

                    break;}
                    else{


                        myQue.addStu2Que(ee441.students[index].getID());
                    }
                }


           }
        index+=1;}}





















int main()
{


    int i=0;
    int j=0;

    ifstream inputtxt;
    inputtxt.open("preferences.txt");
    char myline[100];
    if (inputtxt.is_open()) {
    while (!inputtxt.eof()) {
    inputtxt >> myline;









        if(i>=3){
        int yuz = (myline[0]-'0')*100;
        int on = (myline[1]-'0')*10;
        int bir = myline[2]-'0';
        int id = yuz+on+bir;

        ee441.students[j].setID(id);
        if(myline[4]!=NULL){ee441.students[j].setfirst(myline[4]);}

        cout<<myline<<endl;

        cout<<myline[4]<<id<<endl;
        if(myline[6]!=NULL){ee441.students[j].setsec(myline[6]);}

        cout<<myline[6]<<id<<endl;
        if(myline[8]!=NULL){ee441.students[j].setthird(myline[8]);}

        cout<<myline[8]<<id<<endl;
        j+=1;



    }
    if(myline[0]=='W'){
            int x = myline[2] - '0';
            Wed.setsize(x);

            i+=1;
        }
        if(myline[0]=='T'){
            int x = myline[2] - '0';
            Thu.setsize(x);
            i+=1;
        }
        if(myline[0]=='F'){
            int x = myline[2] - '0';
            Fri.setsize(x);
            i+=1;
        }
        strncpy(myline, "", 100);
    }}
    inputtxt.close();
    makeschedule(j);


    ofstream myFile("results.txt");
    myFile<<"Wednesday"<<endl;
    int f=0;
    while(f<Wed.getsize()){
        myFile<<Wed.getStuID(f)<<endl;
        f+=1;

    }
    f=0;
    myFile<<"Thursday"<<endl;
    while(f<Thu.getsize()){

        myFile<<Thu.getStuID(f)<<endl;
        f+=1;

    }
    f=0;
    myFile<<"Friday"<<endl;

    while(f<Fri.getsize()){
        myFile<<Fri.getStuID(f)<<endl;
        f+=1;

    }
    f=0;
    myFile<<"Unassigned"<<endl;


    while(f<myQue.dx){
        myFile<<myQue.wStu[f]<<endl;
        f+=1;

    }

    myFile.close();

}

