#ifndef CLASS_H 
#define CLASS_H 
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

class Class
{
	private: 
		string ProfName; string ClassName; string CourseCode;
		int creditHours;                 
		int ql, al, hl, tl, e5l, e6l, e7l, e8l, e9l, e10l;
		bool quizConfrim, testConfrim, assignmentsConfrim, hwConfrim, 
				e5Confrim, e6Confrim, e7Confrim, e8Confrim, e9Confrim, e10Confrim;
		double quizWeight, testWeight, assignmentsWeight, hwWeight, etc5Weight, etc6Weight, etc7Weight,
				etc8Weight, etc9Weight, etc10Weight, totalWeight;
		double qPercent, tPercent, aPercent, hPercent, etc5Percent, etc6Percent, 
				etc7Percent, etc8Percent, etc9Percent, etc10Percent;		
		string etc5Name; string etc6Name; string etc7Name; string etc8Name; string etc9Name; string etc10Name; 		
		//Vectors containing obtained grade
		vector<double> quiz; vector<double> test; vector<double> assignments; vector<double> hw; vector<double> etc5;
		vector<double> etc6; vector<double> etc7; vector<double>etc8; vector<double> etc9; vector<double> etc10;
		//Vectors containing what grade is out of
		vector<double> quizTotal; vector<double> testTotal; vector<double> assignmentsTotal; vector<double> hwTotal; vector<double> etc5Total;
		vector<double> etc6Total; vector<double> etc7Total; vector<double>etc8Total; vector<double> etc9Total; vector<double> etc10Total;
		double grade;
		
//{
	public:
		// Constructor
		Class();
		
		//Stats Function
		void statsPrediction(int array[]);
		
		// Mutator functions
		void setDescription(string, string, string, int);
		void setQuiz(double array[], double arrayt[], int size, bool, double);
		void setTest(double array[], double arrayt[], int size, bool, double);
		void setAssignments(double array[], double arrayt[], int size, bool, double);
		void setHW(double array[], double arrayt[], int size, bool, double);
		void setEtc5(double array[], double arrayt[], int size, bool, double, string);
		void setEtc6(double array[], double arrayt[], int size, bool, double, string);
		void setEtc7(double array[], double arrayt[], int size, bool, double, string);
		void setEtc8(double array[], double arrayt[], int size, bool, double, string);
		void setEtc9(double array[], double arrayt[], int size, bool, double, string);
		void setEtc10(double array[], double arrayt[], int size, bool,double, string);
		void setQuizPercent();
		void setTestPercent();
		void setAssignmentsPercent();
		void setHWPercent();
		void setEtc5Percent();
		void setEtc6Percent();
		void setEtc7Percent();
		void setEtc8Percent();
		void setEtc9Percent();
		void setEtc10Percent();
		void setFullWeight();
		void setGrade();
		void deleteQuiz();
		void deleteTest();
		void deleteAssignments();
		void deleteHW();
		void deleteEtc5();
		void deleteEtc6();
		void deleteEtc7(); 
		void deleteEtc8();
		void deleteEtc9();
		void deleteEtc10();
		void addQuiz(double, double);
		void addTest(double, double);
		void addAssignments(double, double);
		void addHW(double, double);
		void addEtc5(double, double);
		void addEtc6(double, double);
		void addEtc7(double, double); 
		void addEtc8(double, double);
		void addEtc9(double, double);
		void addEtc10(double, double);
		void removeQuiz(unsigned int);
		void removeTest(unsigned int);
		void removeAssignments(unsigned int);
		void removeHW(unsigned int);
		void removeEtc5(unsigned int);
		void removeEtc6(unsigned int);
		void removeEtc7(unsigned int);
		void removeEtc8(unsigned int);
		void removeEtc9(unsigned int);
		void removeEtc10(unsigned int);

		// Accessor functions 
			//These will be inline functions
		string getProfName() const
			 {return ProfName;} 
		string getClassName() const
			{return ClassName;}
		string getCourseCode() const
			{return CourseCode;}
		int getcreditHours() const
			{return creditHours;}
		double getQPercent() const
			{return qPercent;}
		double getTPercent() const
			{return tPercent;}
		double getAPercent() const
			{return aPercent;}
		double getHPercent() const
			{return hPercent;}
		double getEtc5Percent() const
			{return etc5Percent;}			
		double getEtc6Percent() const
			{return etc6Percent;}			
		double getEtc7Percent() const
			{return etc7Percent;}
		double getEtc8Percent() const
			{return etc8Percent;}			
		double getEtc9Percent() const
			{return etc9Percent;}			
		double getEtc10Percent() const
			{return etc10Percent;}			
		double getGrade() const
			{return grade;}
		bool getQuizConfrim() const
			{return quizConfrim;}
		bool getTestConfrim() const
			{return testConfrim;}
		bool getAssignmentsConfrim() const
			{return assignmentsConfrim;}
		bool getHwConfrim() const
			{return hwConfrim;}
		bool getE5Confrim() const
			{return e5Confrim;}
		bool getE6Confrim() const
			{return e6Confrim;}
		bool getE7Confrim() const
			{return e7Confrim;}
		bool getE8Confrim() const
			{return e8Confrim;}
		bool getE9Confrim() const
			{return e9Confrim;}
		bool getE10Confrim() const
			{return e10Confrim;}
		string getE5Name() const
			{return etc5Name;}
		string getE6Name() const
			{return etc6Name;}
		string getE7Name() const
			{return etc7Name;}
		string getE8Name() const
			{return etc8Name;}
		string getE9Name() const
			{return etc9Name;}
		string getE10Name() const
			{return etc10Name;}
		int getQuizLength() const
			{return ql;}
		int getTestLength() const
			{return tl;}
		int getAssignmentsLength() const
			{return al;}
		int getHwLength() const
			{return hl;}
		int getEtc5Length() const
			{return e5l;}
		int getEtc6Length() const
			{return e6l;}
		int getEtc7Length() const
			{return e7l;}
		int getEtc8Length() const
			{return e8l;}
		int getEtc9Length() const
			{return e9l;}
		int getEtc10Length() const
			{return e10l;}	
		double getQuizWeight() const
			{return quizWeight;}
		double getTestWeight() const
			{return testWeight;}
		double getAssignmentsWeight() const
			{return assignmentsWeight;}		
		double getHwWeight() const
			{return hwWeight;}
		double getEtc5Weight() const
			{return etc5Weight;}
		double getEtc6Weight() const
			{return etc6Weight;}
		double getEtc7Weight() const
			{return etc7Weight;}
		double getEtc8Weight() const
			{return etc8Weight;}
		double getEtc9Weight() const
			{return etc9Weight;}
		double getEtc10Weight() const
			{return etc10Weight;}
		double getTotalWeight() const
			{return totalWeight;}
			//Non-inline functions
		void displayDescription() const;
		void printQuiz() const;
		void printQuizDetails() const;
		void printTest() const;
		void printAssignments() const;
		void printHw() const;
		void printEtc5() const;
		void printEtc6() const;
		void printEtc7() const;
		void printEtc8() const;
		void printEtc9() const;
		void printEtc10() const;

	double getQuiz(unsigned int) const;
	double getQuizTotal(unsigned int) const;
	double getTest(unsigned int) const;
	double getTestTotal(unsigned int) const;
	double getHw(unsigned int) const;
	double getHwTotal(unsigned int) const;
	double getAssignments(unsigned int) const;
	double getAssignmentsTotal(unsigned int) const;
	double getEtc5(unsigned int) const;
	double getEtc5Total(unsigned int) const;
	double getEtc6(unsigned int) const;
	double getEtc6Total(unsigned int) const;
	double getEtc7(unsigned int) const;
	double getEtc7Total(unsigned int) const;
	double getEtc8(unsigned int) const;
	double getEtc8Total(unsigned int) const;
	double getEtc9(unsigned int) const;
	double getEtc9Total(unsigned int) const;
	double getEtc10(unsigned int) const;
	double getEtc10Total(unsigned int) const;
};
//Constructor
Class::Class()                              
{	
	quizConfrim = false; 
	testConfrim = false; 
	assignmentsConfrim = false;
	hwConfrim = false;
	e5Confrim = false;
	e6Confrim = false; 
	e7Confrim = false;
	e8Confrim = false; 
	e9Confrim = false;
	e10Confrim = false;
	grade = 0.0;
} 

void Class::setDescription(string PN , string CN, string CC, int CH)
{
	ProfName = PN; 
	ClassName = CN;
	CourseCode = CC;
	creditHours = CH;
}

void Class::displayDescription() const	
{	
	cout << "Class name: " << ClassName << endl;
	cout << "Course code: " << CourseCode << endl;
	cout << "Professor's name: " << ProfName << endl;
	cout << "Credit hours: " << creditHours << endl;
}

void Class::setQuiz(double array[], double arrayt[], int size, bool truth, double percent)
{	
	quizConfrim = truth;
	ql = size;
	quizWeight = percent;
	double sum = 0;
	double sumt = 0;
	for(int i = 0; i < size; i++)
	{	
		quiz.push_back(array[i]);
		quizTotal.push_back(arrayt[i]);
		sum = sum + array[i];
		sumt = sumt + arrayt[i];
	}
	qPercent = ((sum/sumt)*percent);
}

void Class::setTest(double array[], double arrayt[], int size, bool truth,double percent)
{
	testConfrim = truth;
	testWeight = percent;
	tl = size;
	double sum = 0;
	double sumt = 0;
	for(int i = 0; i < size; i++)
	{	
		test.push_back(array[i]);
		testTotal.push_back(arrayt[i]);
		sum = sum + array[i];
		sumt = sumt + arrayt[i];
	}
	tPercent = ((sum/sumt)*percent);
}

void Class::setAssignments(double array[], double arrayt[], int size, bool truth, double percent)
{
	assignmentsConfrim = truth;
	assignmentsWeight = percent ;
	al = size;
	double sum = 0;
	double sumt = 0;
	for(int i = 0; i < size; i++)
	{	
		assignments.push_back(array[i]);
		assignmentsTotal.push_back(arrayt[i]);
		sum = sum + array[i];
		sumt = sumt + arrayt[i];
	}
	aPercent = ((sum/sumt)*percent);
}

void Class::setHW(double array[], double arrayt[], int size, bool truth, double percent)
{	
	hwConfrim = truth;
	hwWeight = percent;
	hl = size;
	double sum = 0;
	double sumt = 0;	
	for(int i = 0; i < size; i++)
	{	
		hw.push_back(array[i]);
		hwTotal.push_back(arrayt[i]);
		sum = sum + array[i];
		sumt = sumt + arrayt[i];
	}
	hPercent = ((sum/sumt)*percent);
}

void Class::setEtc6(double array[], double arrayt[], int size, bool truth, double percent, string name)
{
	etc6Name = name;
	e6Confrim = truth;
	etc6Weight = percent;
	e6l = size;
	double sum = 0;
	double sumt = 0;
	for(int i = 0; i < size; i++)
	{
		etc6.push_back(array[i]);
		etc6Total.push_back(arrayt[i]);
		sum = sum + array[i];
		sumt = sumt + arrayt[i];
	}
	etc6Percent = ((sum/sumt)*percent);
}

void Class::setEtc5(double array[], double arrayt[], int size, bool truth, double percent, string name)
{
	etc5Name = name;
	e5Confrim = truth;
	etc5Weight = percent;
	e5l = size;
	double sum = 0;
	double sumt = 0;
	for(int i = 0; i < size; i++)
	{
		etc5.push_back(array[i]);
		etc5Total.push_back(arrayt[i]);
		sum = sum + array[i];
		sumt = sumt + arrayt[i];
	}
	etc5Percent = ((sum/sumt)*percent);
}

void Class::setEtc7(double array[], double arrayt[], int size, bool truth, double percent, string name)
{
	etc7Name = name;
	e7Confrim = truth;
	etc7Weight = percent;
	e7l = size;
	double sum = 0;
	double sumt = 0;
	for(int i = 0; i < size; i++)
	{	
		etc7.push_back(array[i]);
		etc7Total.push_back(arrayt[i]);
		sum = sum + array[i];
		sumt = sumt + arrayt[i];
	}
	etc7Percent = ((sum/sumt)*percent);
}

void Class::setEtc8(double array[], double arrayt[], int size, bool truth, double percent, string name)
{
	etc8Name = name;
	e8Confrim = truth;
	etc8Weight = percent;
	e8l = size;
	double sum = 0;
	double sumt = 0;
	for(int i = 0; i < size; i++)
	{	
		etc8.push_back(array[i]);
		etc8Total.push_back(arrayt[i]);
		sum = sum + array[i];
		sumt = sumt + arrayt[i];
	}
	etc8Percent = ((sum/sumt)*percent);
}

void Class::setEtc9(double array[], double arrayt[], int size, bool truth, double percent, string name)
{
	etc9Name = name;
	e9Confrim = truth;
	etc9Weight = percent;
	e9l = size;
	double sum = 0;
	double sumt = 0;
	for(int i = 0; i < size; i++)
	{
		etc9.push_back(array[i]);
		etc9Total.push_back(arrayt[i]);
		sum = sum + array[i];
		sumt = sumt + arrayt[i];
	}
	etc9Percent = ((sum/sumt)*percent);
}

void Class::setEtc10(double array[], double arrayt[], int size, bool truth, double percent, string name)
{
	etc10Name = name;
	e10Confrim = truth;
	etc10Weight = percent;
	e10l = size;
	double sum = 0;
	double sumt = 0;
	for(int i = 0; i < size; i++)
	{
		etc10.push_back(array[i]);
		etc10Total.push_back(arrayt[i]);
		sum = sum + array[i];
		sumt = sumt + arrayt[i];
	}
	etc10Percent = ((sum/sumt)*percent);
}

void Class::printQuiz() const
{
	cout << "Printing Quiz Grades" << endl;
	cout << setprecision(2) << fixed;
	for(unsigned int i = 0; i < quiz.size(); i++)
	{
		cout << left << setw(3) << (i+1) << right << setw(8) << quiz[i] << " out of " << setw(8) << quizTotal[i] << endl;
	}
}

void Class::printQuizDetails() const
{
	cout << "length is " << al << endl;
	cout << "weight is " << assignmentsWeight << endl;
	cout << "bool is " << assignmentsConfrim << endl;
}

void Class::printTest() const
{
	cout << "Printing test" << endl;
	cout << setprecision(2) << fixed;
	for(unsigned int i = 0; i < test.size();i++){
		cout << left << setw(3) << (i+1) << right << setw(8) << test[i] << " out of " << setw(8) << testTotal[i] << endl;
	}
	cout << endl;
}

void Class::printAssignments() const
{
	cout << "Printing assignments" << endl;
	cout << setprecision(2) << fixed;	
	for(unsigned int i = 0; i < assignments.size();i++){
		cout << left << setw(3) << (i+1) << right << setw(8) << assignments[i] << " out of " << setw(8) << assignmentsTotal[i] << endl;
	}
	cout << endl;
}

void Class::printHw() const
{
	cout << "Printing Hw" << endl;
	cout << setprecision(2) << fixed;	
	for(unsigned int i = 0; i < hw.size();i++){
		cout << left << setw(3) << (i+1) << right << setw(8) << hw[i] << " out of " << setw(8) << hwTotal[i] << endl;
	}
	cout << endl;
}

void Class::printEtc5() const
{
	cout << "Printing etc5" << endl;	
	cout << setprecision(2) << fixed;
	for(unsigned int i = 0; i < etc5.size();i++){
		cout << left << setw(3) << (i+1) << right << setw(8) << etc5[i] << " out of " << setw(8) << etc5Total[i] << endl;
	}
	cout << endl;
}

void Class::printEtc6() const
{
	cout << "Printing etc6" << endl;
	cout << setprecision(2) << fixed;	
	for(unsigned int i = 0; i < etc6.size();i++){
		cout << left << setw(3) << (i+1) << right << setw(8) << etc6[i] << " out of " << setw(8) << etc6Total[i] << endl;
	}
	cout << endl;
}

void Class::printEtc7() const
{
	cout << "Printing etc7" << endl;	
	cout << setprecision(2) << fixed;
	for(unsigned int i = 0; i < etc7.size();i++){
		cout << left << setw(3) << (i+1) << right << setw(8) << etc7[i] << " out of " << setw(8) << etc7Total[i] << endl;
	}
	cout << endl;
}

void Class::printEtc8() const
{
	cout << "Printing etc 8" << endl;	
	cout << setprecision(2) << fixed;
	for(unsigned int i = 0; i < etc8.size();i++){
		cout << left << setw(3) << (i+1) << right << setw(8) << etc8[i] << " out of " << setw(8) << etc8Total[i] << endl;
	}
	cout << endl;
}

void Class::printEtc9() const
{
	cout << "Printing etc9" << endl;
	cout << setprecision(2) << fixed;
	for(unsigned int i = 0; i < etc9.size();i++){
		cout << left << setw(3) << (i+1) << right << setw(8) << etc9[i] << " out of " << setw(8) << etc9Total[i] << endl;
	}
	cout << endl;
}

void Class::printEtc10() const
{
	cout << "Printing etc10" << endl;
	cout << setprecision(2) << fixed;	
	for(unsigned int i = 0; i < etc10.size();i++){
		cout << left << setw(3) << (i+1) << right << setw(8) << etc10[i] << " out of " << setw(8) << etc10Total[i] << endl;
	}
	cout << endl;
}

void Class::setFullWeight()
{
	totalWeight = 0.0;
	if(quizConfrim){
		totalWeight = (totalWeight + quizWeight) * 1.0;}
	if(testConfrim){
		totalWeight = (totalWeight + testWeight) * 1.0;}
	if(assignmentsConfrim){
		totalWeight = (totalWeight + assignmentsWeight) * 1.0;}
	if(hwConfrim){
		totalWeight = (totalWeight + hwWeight) * 1.0;}
	if(e5Confrim){
		totalWeight = (totalWeight + etc5Weight) * 1.0;}
	if(e6Confrim){
		totalWeight = (totalWeight + etc6Weight) * 1.0;}
	if(e7Confrim){
		totalWeight = (totalWeight + etc7Weight) * 1.0;}
	if(e8Confrim){
		totalWeight = (totalWeight + etc8Weight) * 1.0;}
	if(e9Confrim){
		totalWeight = (totalWeight + etc9Weight) * 1.0;}
	if(e10Confrim){
		totalWeight = (totalWeight + etc10Weight) * 1.0;}
}

void Class::setGrade() 
{	
	grade = 0.0;
	if(quizConfrim){
		grade = grade + qPercent;}
	if(testConfrim){
		grade = grade + tPercent;}
	if(assignmentsConfrim){
		grade = grade + aPercent;}
	if(hwConfrim){
		grade = grade + hPercent;}
	if(e5Confrim){
		grade = grade + etc5Percent;}
	if(e6Confrim){
		grade = grade + etc6Percent;}
	if(e7Confrim){
		grade = grade + etc7Percent;}
	if(e8Confrim){
		grade = grade + etc8Percent;}
	if(e9Confrim){
		grade = grade + etc9Percent;}
	if(e10Confrim){
		grade = grade + etc10Percent;}
	grade = grade * 100.0;
}

void Class::deleteQuiz()
{
	quizConfrim = false;
	quiz.clear();
	quizTotal.clear();
	ql = 0;
	quizWeight = 0.0;
	qPercent = 0.0;
}
	
void Class::deleteTest()
{
	testConfrim = false;
	test.clear();
	testTotal.clear();
	tl = 0;
	testWeight = 0.0;
	tPercent = 0.0;
}

void Class::deleteAssignments()
{
	assignmentsConfrim = false;
	assignments.clear();
	assignmentsTotal.clear();
	al = 0;
	assignmentsWeight = 0.0;
	aPercent = 0.0;
}

void Class::deleteHW()
{
	hwConfrim = false;
	hw.clear();
	hwTotal.clear();
	hl = 0;
	hwWeight = 0.0;
	hPercent = 0.0;
}

void Class::deleteEtc5()
{
	etc5Name.clear();
	e5Confrim = false;
	etc5.clear();
	etc5Total.clear();
	e5l = 0;
	etc5Weight = 0.0;
	etc5Percent = 0.0;
}

void Class::deleteEtc6()
{
	etc6Name.clear();
	e6Confrim = false;
	etc6.clear();
	etc6Total.clear();
	e6l = 0;
	etc6Weight = 0.0;
	etc6Percent = 0.0;
}

void Class::deleteEtc7() 
{
	etc7Name.clear();
	e7Confrim = false;
	etc7.clear();
	etc7Total.clear();
	e7l = 0;
	etc7Weight = 0.0;
	etc7Percent = 0.0;
}

void Class::deleteEtc8()
{
	etc8Name.clear();
	e8Confrim = false;
	etc8.clear();
	etc8Total.clear();
	e8l = 0;
	etc8Weight = 0.0;
	etc8Percent = 0.0;
}

void Class::deleteEtc9()
{
	etc9Name.clear();
	e9Confrim = false;
	etc9.clear();
	etc9Total.clear();
	e9l = 0;
	etc9Weight = 0.0;
	etc9Percent = 0.0;
}

void Class::deleteEtc10()
{
	etc10Name.clear();
	e10Confrim = false;
	etc10.clear();
	etc10Total.clear();
	e10l = 0;
	etc10Weight = 0.0;
	etc10Percent = 0.0;
}

void Class::addQuiz(double score, double Stotal)
{
	quiz.push_back(score);
	quizTotal.push_back(Stotal);
	ql =(ql + 1);
}

void Class::addTest(double score, double Stotal)
{
	test.push_back(score);
	testTotal.push_back(Stotal);
	tl =(tl + 1);
}

void Class::addAssignments(double score, double Stotal)
{
	assignments.push_back(score);
	assignmentsTotal.push_back(Stotal);
	al =(tl + 1);
}

void Class::addHW(double score, double Stotal)
{
	hw.push_back(score);
	hwTotal.push_back(Stotal);
	hl =(hl + 1);
}

void Class::addEtc5(double score, double Stotal)
{
	etc5.push_back(score);
	etc5Total.push_back(Stotal);
	e5l =(e5l + 1);
}

void Class::addEtc6(double score, double Stotal)
{
	etc6.push_back(score);
	etc6Total.push_back(Stotal);
	e6l =(e6l + 1);
}

void Class::addEtc7(double score, double Stotal) 
{
	etc7.push_back(score);
	etc7Total.push_back(Stotal);
	e7l =(e7l + 1);
}

void Class::addEtc8(double score, double Stotal)
{
	etc8.push_back(score);
	etc8Total.push_back(Stotal);
	e8l =(e8l + 1);
}

void Class::addEtc9(double score, double Stotal)
{
	etc9.push_back(score);
	etc9Total.push_back(Stotal);
	e9l =(e9l + 1);
}

void Class::addEtc10(double score, double Stotal)
{
	etc10.push_back(score);
	etc10Total.push_back(Stotal);
	e10l =(e10l + 1);
}

void Class::removeQuiz(unsigned int place)
{
	if(place == (quiz.size() -1 )){
		quiz.pop_back();
		quizTotal.pop_back();
		cout << "Grade was succesfully deleted" << endl;
	}
	else{
		quiz.erase(quiz.begin()+place-1);
		quizTotal.erase(quizTotal.begin()+place-1);
		cout << "Grade was succesfully deleted" << endl;
	}
	ql =(ql - 1);
}

void Class::removeTest(unsigned int place)
{
	if(place == (test.size() -1 )){
		test.pop_back();
		testTotal.pop_back();
		cout << "Grade was succesfully deleted" << endl;
	}
	else{
		test.erase(test.begin()+place-1);
		testTotal.erase(testTotal.begin()+place-1);
		cout << "Grade was succesfully deleted" << endl;
	}
	tl =(tl - 1);
}

void Class::removeAssignments(unsigned int place)
{
	if(place == (assignments.size() -1 )){
		assignments.pop_back();
		assignmentsTotal.pop_back();
		cout << "Grade was succesfully deleted" << endl;
	}
	else{
		assignments.erase(assignments.begin()+place-1);
		assignmentsTotal.erase(assignmentsTotal.begin()+place-1);
		cout << "Grade was succesfully deleted" << endl;
	}
	al =(al - 1);
}

void Class::removeHW(unsigned int place)
{
	if(place == (hw.size() -1 )){
		hw.pop_back();
		hwTotal.pop_back();
		cout << "Grade was succesfully deleted" << endl;
	}
	else{
		hw.erase(hw.begin()+place-1);
		hwTotal.erase(hwTotal.begin()+place-1);
		cout << "Grade was succesfully deleted" << endl;
	}
	hl =(hl + 1);
}

void Class::removeEtc5(unsigned int place)
{
	if(place == (etc5.size() -1)){
		etc5.pop_back();
		etc5Total.pop_back();
		cout << "Grade was succesfully deleted" << endl;
	}
	else{
		etc5.erase(etc5.begin()+place-1);
		etc5Total.erase(etc5Total.begin()+place-1);
		cout << "Grade was succesfully deleted" << endl;
	}
	e5l =(e5l - 1);
}

void Class::removeEtc6(unsigned int place)
{
	if(place == (etc6.size() -1)){
		etc6.pop_back();
		etc6Total.pop_back();
		cout << "Grade was succesfully deleted" << endl;
	}
	else{
		etc6.erase(etc6.begin()+place-1);
		etc6Total.erase(etc6Total.begin()+place-1);
		cout << "Grade was succesfully deleted" << endl;
	}
	e6l =(e6l - 1);
}

void Class::removeEtc7(unsigned int place)
{
	if(place == (etc7.size() -1)){
		etc7.pop_back();
		etc7Total.pop_back();
		cout << "Grade was succesfully deleted" << endl;
	}
	else{
		etc7.erase(etc7.begin()+place-1);
		etc7Total.erase(etc7Total.begin()+place-1);
		cout << "Grade was succesfully deleted" << endl;
	}
	e7l =(e7l - 1);
}

void Class::removeEtc8(unsigned int place)
{
	if(place == (etc8.size() -1)){
		etc8.pop_back();
		etc8Total.pop_back();
		cout << "Grade was succesfully deleted" << endl;
	}
	else{
		etc8.erase(etc8.begin()+place-1);
		etc8Total.erase(etc8Total.begin()+place-1);
		cout << "Grade was succesfully deleted" << endl;
	}
	e8l =(e8l - 1);
}

void Class::removeEtc9(unsigned int place)
{
	if(place == (etc9.size() -1)){
		etc9.pop_back();
		etc9Total.pop_back();
		cout << "Grade was succesfully deleted" << endl;
	}
	else{
		etc9.erase(etc9.begin()+place-1);
		etc9Total.erase(etc9Total.begin()+place-1);
		cout << "Grade was succesfully deleted" << endl;
	}
	e9l =(e9l - 1);
}

void Class::removeEtc10(unsigned int place)
{
	if(place == (etc10.size() -1)){
		etc10.pop_back();
		etc10Total.pop_back();
		cout << "Grade was succesfully deleted" << endl;
	}
	else{
		etc10.erase(etc10.begin()+place-1);
		etc10Total.erase(etc10Total.begin()+place-1);
		cout << "Grade was succesfully deleted" << endl;
	}
	e10l =(e10l - 1);
}

void Class::setQuizPercent()
{
	double sum = 0.0, sumt = 0.0;
	for(unsigned int i = 0; i < quiz.size(); i++)
	{	
		sum = sum + quiz[i];
		sumt = sumt + quizTotal[i];
	}
	qPercent = ((sum/sumt)*quizWeight);
}

void Class::setTestPercent()
{
	double sum = 0.0, sumt = 0.0;
	for(unsigned int i = 0; i < test.size(); i++)
	{	
		sum = sum + test[i];
		sumt = sumt + testTotal[i];
	}
	tPercent = ((sum/sumt)*testWeight);
}

void Class::setAssignmentsPercent()
{
	double sum = 0.0, sumt = 0.0;
	for(unsigned int i = 0; i < assignments.size(); i++)
	{	
		sum = sum + assignments[i];
		sumt = sumt + assignmentsTotal[i];
	}
	aPercent = ((sum/sumt)*assignmentsWeight);
}

void Class::setHWPercent()
{
	double sum = 0.0, sumt = 0.0;
	for(unsigned int i = 0; i < hw.size(); i++)
	{	
		sum = sum + hw[i];
		sumt = sumt + hwTotal[i];
	}
	hPercent = ((sum/sumt)*hwWeight);
}

void Class::setEtc5Percent()
{
	double sum = 0.0, sumt = 0.0;
	for(unsigned int i = 0; i < etc5.size(); i++)
	{	
		sum = sum + etc5[i];
		sumt = sumt + etc5Total[i];
	}
	etc5Percent = ((sum/sumt)*etc5Weight);
}

void Class::setEtc6Percent()
{
	double sum = 0.0, sumt = 0.0;
	for(unsigned int i = 0; i < etc6.size(); i++)
	{	
		sum = sum + etc6[i];
		sumt = sumt + etc6Total[i];
	}
	etc6Percent = ((sum/sumt)*etc6Weight);
}
void Class::setEtc7Percent()
{
	double sum = 0.0, sumt = 0.0;
	for(unsigned int i = 0; i < etc7.size(); i++)
	{	
		sum = sum + etc7[i];
		sumt = sumt + etc7Total[i];
	}
	etc7Percent = ((sum/sumt)*etc7Weight);
}

void Class::setEtc8Percent()
{
	double sum = 0.0, sumt = 0.0;
	for(unsigned int i = 0; i < etc8.size(); i++)
	{	
		sum = sum + etc8[i];
		sumt = sumt + etc8Total[i];
	}
	etc8Percent = ((sum/sumt)*etc8Weight);
}

void Class::setEtc9Percent()
{
	double sum = 0.0, sumt = 0.0;
	for(unsigned int i = 0; i < etc9.size(); i++)
	{	
		sum = sum + etc9[i];
		sumt = sumt + etc9Total[i];
	}
	etc9Percent = ((sum/sumt)*etc9Weight);
}

void Class::setEtc10Percent()
{
	double sum = 0.0, sumt = 0.0;
	for(unsigned int i = 0; i < etc10.size(); i++)
	{	
		sum = sum + etc10[i];
		sumt = sumt + etc10Total[i];
	}
	etc10Percent = ((sum/sumt)*etc10Weight);
}

double Class::getQuiz(unsigned int i) const
{
	return (quiz[i]);
}
double Class::getQuizTotal(unsigned int i) const 
{
	return (quizTotal[i]);
}

double Class::getTest(unsigned int i) const
{
	return (test[i]);
}

double Class::getTestTotal(unsigned int i) const
{
	return (testTotal[i]);
}

double Class::getHw(unsigned int i) const
{
	return (hw[i]);
}

double Class::getHwTotal(unsigned int i) const
{
	return (hwTotal[i]);
}

double Class::getAssignments(unsigned int i) const
{
	return (assignments[i]);
}

double Class::getAssignmentsTotal(unsigned int i) const
{
	return (assignmentsTotal[i]);
}

double Class::getEtc5(unsigned int i) const
{
	return (etc5[i]);
}

double Class::getEtc5Total(unsigned int i) const
{
	return (etc5Total[i]);
}

double Class::getEtc6(unsigned int i) const
{
	return (etc6[i]);
}

double Class::getEtc6Total(unsigned int i) const
{
	return (etc6Total[i]);
}

double Class::getEtc7(unsigned int i) const
{
	return (etc7[i]);
}

double Class::getEtc7Total(unsigned int i) const
{
	return (etc7Total[i]);
}

double Class::getEtc8(unsigned int i) const
{
	return (etc8[i]);
}

double Class::getEtc8Total(unsigned int i) const
{
	return (etc8Total[i]);
}

double Class::getEtc9(unsigned int i) const
{
	return (etc9[i]);
}

double Class::getEtc9Total(unsigned int i) const
{
	return (etc9Total[i]);
}

double Class::getEtc10(unsigned int i) const
{
	return (etc10[i]);
}

double Class::getEtc10Total(unsigned int i) const
{
	return (etc10Total[i]);
}

void Class::statsPrediction(int array[]){

	double sum = 0;
	for(unsigned int i = 0;i<test.size();i++)
	{
		sum+=test[i];
	}
	double mean = (sum/test.size());

	double deviationTemp = 0.0;
	double Dsum = 0.0;
	for(unsigned int i = 0;i<test.size();i++)
	{
		deviationTemp=(test[i]-mean);
		deviationTemp = (deviationTemp*deviationTemp);
		Dsum+=deviationTemp;
	}
	
	double standardDeviation = (pow(((1.0/(test.size()-1))*Dsum),0.5));
	
	double predictorRange = 0.25*array[0]+0.25*array[1]+0.25*array[2]+0.125*array[3]+0.125*array[4];
	double lowRange = 0;
	double highRange = 0;
	if(predictorRange>=0&&predictorRange<1.5)
	{
		lowRange=mean-3*standardDeviation;
		highRange=mean-2*standardDeviation;
	}
	else if(predictorRange>=1.5&&predictorRange<3.5)
	{
		lowRange=mean-2*standardDeviation;
		highRange=mean-1*standardDeviation;
	}
	else if(predictorRange>=3.5&&predictorRange<6.5)
	{
		lowRange=mean-1*standardDeviation;
		highRange=mean+1*standardDeviation;
	}
	else if(predictorRange>=6.5&&predictorRange<8.5)
	{
		lowRange=mean+1*standardDeviation;
		highRange=mean+2*standardDeviation;
	}
	else if(predictorRange>=8.5&&predictorRange<=10)
	{
		lowRange=mean+2*standardDeviation;
		highRange=mean+3*standardDeviation;
	}
	else
	{
		cout<<"Error!"<<endl;
	}
	cout<<"The predicted grade range"<<endl;
	if(lowRange>=100)
	{
		cout<<"You will probably get a 100"<<endl;
	}
	else if(highRange>=100)
	{
		cout<<"The range is"<<lowRange<<" 100"<<endl;
	}
	else if(highRange<=0)
	{
		cout<<"You will most likely get a 0 I am sorry"<<endl;
	}
	else if(lowRange<=0)
	{
		cout<<"The range is 0 - "<<highRange<<endl;
	}
	else
	{
	cout<<lowRange<<"-"<<highRange<<endl;
	}
}
#endif