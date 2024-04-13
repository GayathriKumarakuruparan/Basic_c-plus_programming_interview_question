#include <iostream>
using namespace std;
/* inhritance has five types as
  1.single inheritance
  2.multilevel inheritance
  3.multiple inheritance
  4.herarchical inheritance
  5.hybrid inheritance
*/

//single inheritance
class company{
	public:
		int id;
		string name;
		string add;
		company(int id=000,string name="unknown",string add="XXXXX"):id(id),name(name),add(add){ cout<<"parent class is called"<<endl; };
		~company()
		{
			cout<<"parents class destructor"<<endl;
		}
		void display();
};
class employee:public company
{
	public:
		employee(int id=000,string name="unknown",string add="xxxx"):company(id,name,add){	cout<<"child class is called"<<endl; }
		~employee()
		{
			cout<<"child class destructor"<<endl;
		}
};


//MULTILEVEL INHERITANCE
class workers:public employee
{
	public:
		workers(int id=111,string name="default name",string add="zzzz"):employee(id,name,add)
		{
			cout<<"grandchild class called"<<endl;
		}
		~workers()
		{
			cout<<"grandchild class destructor"<<endl;
		}
};



void company::display()
{
	cout<<"id is: "<<id<<endl;
	cout<<"name is: "<<name<<endl;
	cout<<"address is: "<<add<<endl;
}


//HIRARCHICAL INHERITANCE
class manager:public company{//<------------HIRARCHICAL INHERITANCE- which has single parent with multi child class
	public:
	int id;
	int salary;
	void display2();
};

//MULTIPLE INHERITANCE
class hod:public company,public manager //hybrid inheritance--->more than one type inheritance...
{
	
};

void manager::display2()
{
	cout<<"id : "<<id<<endl;
	cout<<"salary : "<<salary<<endl;
	
}

int main() {
	cout<<"_________SINGLE INHERITANCE________"<<endl;	
	cout<<"|                                             |"<<endl;
	cout<<"!!!!!construction called for first object!!!!!"<<endl;
	
	employee e1;//default constructor
	
	
	cout<<"|                                             |"<<endl;
	cout<<"!!!!construction called for second object!!!!!"<<endl;
	
	employee E1(100,"gayathri","banglore");//parametrized constructor
	
	//to display
	cout<<"--------Default constructor----------"<<endl;
	e1.display();
	cout<<"--------parametrized constructor----------"<<endl;
	E1.display();
	
	
	
	
	cout<<"____________MULTILEVEL INHERITANCE___________"<<endl;
	cout<<"|                                             |"<<endl;
	cout<<"!!!!!construction called for object m1!!!!!"<<endl;
	workers m1;
	
	
	cout<<"--------Default constructor----------"<<endl;
	m1.display();
	
	cout<<"_____________MULTIPLE INHERITANCE______________"<<endl;
	cout<<"|                                              |"<<endl;
	cout<<"!!!!!construction called for object M1!!!!!"<<endl;
	hod M1;
	
	//manager class is initializing
	M1.manager::id=1;
	M1.manager::salary=100000;
	
	
	//to display

	M1.display2();
	
	
	
	
	
	cout<<"--------DESTRUCTOR----------"<<endl;   //destructor is function that destroy from child to base
	return 0;
	
}
