// Emin Berkay Daglar - 2304400
// EE441 Data Structures Homework 1
// © Copyright - All rights reserved.

#include<iostream>
#include<string>
#define MAX_SIZE 10

using namespace std;

	class Student{
		private:
			int ID;
			string name;
			string surname;
			float quiz_scores[4];
			float hw_scores[3];
			float final_score;
		public:
			Student(){}
			int getID();
			void setID(int id);
			string getName(), getSurname();
			void setName(string nm), setSurname(string sn);
			float* getQuizScores();
			float* getHwScores();
			float getFinalExamScore();
			void setQuizScores(float q1, float q2, float q3, float q4), setHwScores(float hw1, float hw2, float hw3), setFinalExamScore(float fin);
			float overallCourseScore(float q, float hw, float f);
	};
	int Student::getID(){return ID;}
 	void Student::setID(int id){ID = id;}
	string Student::getName(){return name;}
	string Student::getSurname(){return surname;}
	void Student::setName(string nm){name = nm;}
	void Student::setSurname(string sn){surname = sn;}
	void Student::setQuizScores(float q1, float q2, float q3, float q4){
		quiz_scores[0] = q1;
		quiz_scores[1] = q2;
		quiz_scores[2] = q3;
		quiz_scores[3] = q4;
	}
	float* Student::getQuizScores(){
	return quiz_scores;
	}
	void Student::setHwScores(float hw1, float hw2, float hw3){
		hw_scores[0] = hw1;
		hw_scores[1] = hw2;
		hw_scores[2] = hw3;

	}
 	float* Student::getHwScores(){
	 return hw_scores;
	 }
	void Student::setFinalExamScore(float fin){ final_score = fin;}
	float Student::getFinalExamScore(){return final_score;}
	float Student::overallCourseScore(float q, float hw, float f){
			return ((quiz_scores[0]+quiz_scores[1]+quiz_scores[2]+quiz_scores[3])*q + (hw_scores[0]+hw_scores[1]+hw_scores[2])*hw + final_score*f);

	}
	class Course{
		private:
			Student students[MAX_SIZE];
			int num;//the current number of students in EE441 course.
			float weightQ = 30.0, weightHW = 30.0, weightF = 40.0;

		public:
			Course(){num=0;}
			int getNum();//returns how many students are in the course
			float calculateAverage();
			void addNewStudent(int id, string namE, string surnamE), updateWeights(float n_q, float n_hw, float n_f);//adds new student to the course
			Student getStudentInfo(int id);
			Student getStudent(int idx);
			float getQ_W(), getHW_W(), getF_W();
			void incNum();//increments the number of student in the course
			void changeScore(int ID, float quiz_scores[4], float hw_scores[3], float final_score);//used for changing scores


	};
	Course EE441;

	void Course::changeScore(int ID, float quiz_scores[4], float hw_scores[3], float final_score){
        EE441.students[EE441.getNum()-1].setQuizScores(quiz_scores[0], quiz_scores[1], quiz_scores[2], quiz_scores[3]);
		EE441.students[EE441.getNum()-1].setHwScores(hw_scores[0],hw_scores[1],hw_scores[2]);
		EE441.students[EE441.getNum()-1].setFinalExamScore(final_score);
	}

	void Course::incNum(){
		num+=1;
	}
	Student Course::getStudent(int idx){
		return students[idx];
	}
	float Course::getQ_W(){
		return weightQ;
	}
	float Course::getHW_W(){
		return weightHW;
	}
	float Course::getF_W(){
		return weightF;
	}
	int Course::getNum(){return num;}
	float Course::calculateAverage(){
		float ort_q=0, total_q =0;
		float ort_hw=0, total_hw =0;
		float ort_f=0, total_f =0;
		for(int l=0; l<EE441.getNum(); l++){

			total_q+=((*(EE441.getStudent(l).getQuizScores()))+(*(EE441.getStudent(l).getQuizScores()+1))+(*(EE441.getStudent(l).getQuizScores()+2))+(*(EE441.getStudent(l).getQuizScores()+3)));
			total_hw+=((*(EE441.getStudent(l).getHwScores()))+(*(EE441.getStudent(l).getHwScores()+1))+(*(EE441.getStudent(l).getHwScores()+2)));
			total_f+=EE441.getStudent(l).getFinalExamScore();
		}
		ort_q = total_q/(4*EE441.getNum());
		ort_hw = total_hw/(3*EE441.getNum());
		ort_f = total_f/EE441.getNum();
		cout << "Quizzes-Avg:"<<ort_q<<endl;
		cout << "Homeworks-Avg:"<<ort_hw<<endl;
		cout << "Final-Avg:"<<ort_f<<endl;
	}
	void Course::addNewStudent(int id, string namE, string surnamE){

		incNum();
		EE441.students[EE441.getNum()-1].setID(id);
		EE441.students[EE441.getNum()-1].setName(namE);
		EE441.students[EE441.getNum()-1].setSurname(surnamE);

	}
	void Course::updateWeights(float n_q, float n_hw, float n_f){
		weightQ = n_q;
		weightHW = n_hw;
		weightF = n_f;

	}
	Student Course::getStudentInfo(int id){
		int i;
		for(i=0; i<num; i++){
			if(id==students[i].getID()){

				break;
			};

		}


		return EE441.students[i];

		}




void addNewStudent(int ID, string name, string surname){
	EE441.addNewStudent(ID, name, surname);


}
void showStudent(int ID){
    while(1){
    if (EE441.getStudentInfo(ID).getID()==0){
        cout<<"Invalid ID. Please try again: ";
        continue;

    }
    else{
	cout<<"ID:"<<EE441.getStudentInfo(ID).getID()<<endl;
    cout<<"Name: "<<EE441.getStudentInfo(ID).getName()<<endl;
    cout<<"Surname: "<<EE441.getStudentInfo(ID).getSurname()<<endl;
	cout<<"Quiz Scores:"<<*(EE441.getStudentInfo(ID).getQuizScores())<<"  "<<*(EE441.getStudentInfo(ID).getQuizScores()+1)<<"  "<<*(EE441.getStudentInfo(ID).getQuizScores()+2)<<"  "<<*(EE441.getStudentInfo(ID).getQuizScores()+3)<<endl;
	cout<<"Homework Scores: "<<*(EE441.getStudentInfo(ID).getHwScores())<<"  "<<*(EE441.getStudentInfo(ID).getHwScores()+1)<<"  "<<*(EE441.getStudentInfo(ID).getHwScores()+2)<<endl;
	cout<<"Final Exam Score:"<<EE441.getStudentInfo(ID).getFinalExamScore()<<endl;
	break;}}}






void changeStudentScores(int ID, float quiz_scores[4], float hw_scores[3], float final_score){

    EE441.changeScore(ID, quiz_scores, hw_scores, final_score);

}
void changeWeights(Course cl){
	float q, hw, finl;
	while(1){
    cout<<"Enter new Quiz weight(in percentage): "<<endl;
    cin>>q;
    cout<<"Enter new Homework weight(in percentage): "<<endl;
    cin>>hw;
    cout<<"Enter new Final Exam weight(in percentage): "<<endl;
    cin>>finl;
    if((q+hw+finl)==100){
        cl.updateWeights(q,hw,finl);
        break;
    }
    else {
        cout<<"The weights' sum is not equal to 100 percent. Please try again by considering this!"<<endl;
        continue;
    }
	}

    cout<<"\n\n\nWeights updated succesfully.\nNew weights are:\n\n For Quiz:"<<q<<"\n For Homework:"<<hw<<"\n For Final Exam:"<<finl<<endl;

}
void showAverage(){
  	EE441.calculateAverage();
}
void showAbove(float threshold){
    int cnt=0;
	for(int o=0; o<EE441.getNum(); o++){
		if(EE441.getStudent(o).overallCourseScore(EE441.getQ_W(), EE441.getHW_W(), EE441.getF_W()) > threshold){
            cnt+=1;
			showStudent(EE441.getStudent(o).getID());
		}

	}
	if (cnt==0){
        cout<<"No student is found in this interval.\n\n\n"<<endl;
	}


}
void showBelow(float threshold){
    int cnt=0;
	for(int o=0; o<EE441.getNum(); o++){
        cnt+=1;
		if(EE441.getStudent(o).overallCourseScore(EE441.getQ_W(), EE441.getHW_W(), EE441.getF_W()) < threshold){
			showStudent(EE441.getStudent(o).getID());
		}




	}
	if (cnt==0){
        cout<<"No student is found in this interval.\n\n\n"<<endl;
	}

}
char exit_Q(){
	char x;
	cout<<"If you want to continue with other options type 'Y' , otherwise the interface will be closed: ";
	cin>>x;
	return x;
}
int main(){
	int sel=0;
	cout<<"Welcome to the EE441 Classroom Interface!\nChoose your option:"<<endl;

	while(1){
	cout<<"(1) - Add Student\n(2) - Search a student by ID\n(3) - Change a student" << "'" <<"s score\n";
	cout<<"(4) - Update Weights\n(5) - Show classroom average\n(6) - Show students with overall score above a threshold\n";
	cout << "(7) - Show students with overall score below a threshold\n(8) - Exit\n\n\n Your choice:";

	cin >>sel;

	if (sel==8){
		cout << "The program is closing...";
		break;
	}
	else if (sel == 1){
		int id;
		string namE, surnamE;
		float quiz[4], hw[3], fnl;
		cout << "Enter student's ID, name, surname and scores (quizzes, homeworks, final):\n";
		cin >> id >> namE >> surnamE >> quiz[0] >> quiz[1] >> quiz[2] >> quiz[3] >> hw[0] >> hw[1] >> hw[2] >> fnl;
		addNewStudent(id, namE, surnamE);
		changeStudentScores(id, quiz, hw, fnl);

		if(exit_Q()=='Y'){
			continue;
		}
		else {
			cout << "The program is closing...";
			break;

	}}
	else if (sel == 2){
		int id;
		cout << "-------SEARCHING MODE ------ \n\n\nEnter Student ID:";
		cin >> id;
		showStudent(id);
		if(exit_Q()=='Y'){
			continue;
		}
		else {
			cout << "The program is closing...";
			break;
	}}
	else if (sel == 3){
		int id;
		cout<<"Enter the ID of the student whose scores will be updated:";
		cin>>id;
		float q[4];
		cout<<"Enter quiz notes by seperating them with spaces:";
		cin>>q[0]>>q[1]>>q[2]>>q[3];
		float h[3];
		cout<<"Enter homework notes by seperating them with spaces:";
		cin>>h[0]>>h[1]>>h[2];
		float fin;
		cout<<"Enter his/her final score:";
		cin>>fin;
		changeStudentScores(id, q, h, fin);
		if(exit_Q()=='Y'){
			continue;
		}
		else {
			cout << "The program is closing...";
			break;
	}

	}
	else if (sel == 4){
		changeWeights(EE441);
		if(exit_Q()=='Y'){
			continue;
		}
		else {
			cout << "The program is closing...";
			break;
	}
	}
	else if (sel == 5){
        if(EE441.getNum()==0){
            cout<<"There is no registered student in this course.";
        }
        else {EE441.calculateAverage();}

		if(exit_Q()=='Y'){
			continue;
		}
		else {
			cout << "The program is closing...";
			break;
	}

	}
	else if (sel == 6){
		float thr;
		cout << "Enter threshold:";
		cin >> thr;
		showAbove(thr);
		if(exit_Q()=='Y'){
			continue;
		}
		else {
			cout << "The program is closing...";
			break;
	}

	}
	else if (sel == 7){
		float thr;
		cout <<"Enter threshold:";
		cin >> thr;
		showBelow(thr);
		if(exit_Q()=='Y'){
			continue;
		}
		else {
			cout << "The program is closing...";
			break;
	}
	}
	else{
		cout << "\n\nAn error happened. Please type a proper value!";
		continue;

	}
	}

}

