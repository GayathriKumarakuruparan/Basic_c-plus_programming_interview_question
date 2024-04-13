/*     NAME: GAYATHRI K      
*/
#include <iostream>
#include <cstring>
using namespace std;
/*Pillar of c++

1.encapsulation
2.abstraction
3.inheritance
4.polymorphism

*/

/*1.ENCAPSULATION ---->The process of binding the data and a member function together in single entity or unit, achieved by class*/

class student{
	
	//2.ABSTRACTION ----->shows only relevant data and hide unnecessary data of an object from an user.
	private:
		string admin;
	public:
		int id;
		string name;
		string add;
		char *admin_name;
		//constructor
		student(int sid,string sname, string sadd);
		~student(void);
		student(student &ref);
		void display();
		void display_admin();
};

//initializer list
student::student(int sid=0,string sname="unknown", string sadd="india"):id(sid),name(sname),add(sadd){};


//destructor
student::~student(void)
{
	cout<<"destructor"<<endl;
}
void student::display(){
	cout<<"ID : "<<id<<endl;
	cout<<"NAME: "<<name<<endl;
	cout<<"ADDRESS: "<<add<<endl;
}


/*3.INHERITANCE ----->create a new class from existing class

    existing class - base/parent class
    new class - child class
    
    
    TYPES:
    1.single inheritance 
    2.multilevel inheritance
    3.multiple inheritance
    4.herarchical inheritance
    4.hybrid inheritance
    
*/

//single inheritance
class employee{
	public:
	int ID;
	string name;
	string address;
	employee(int id=0,string name="unkown",string address="india"):ID(id),name(name),address(address)
	{
		cout<<"parent class is called"<<endl;
		
	}
	void display_detail();
};
class employee1:public employee
{
	public:
	employee1(int id=1,string name="unknown2",string address="india"):employee(id,name,address)
	{
		cout<<"child class is called"<<endl;
	}
	

};
void employee::display_detail()
{
	cout<<"ID : "<<ID<<endl;
	cout<<"NAME: "<<name<<endl;
	cout<<"ADDRESS: "<<address<<endl;
}

int main() {
	
	//1.encapsulation
	cout<<"-------------ENCAPSULATION---------------"<<endl;
	student st1,st2(100,"gayathri","banglore");
	st1.display();
	st2.display();
	cout<<"-------------SINGLE INHERITANCE-----------"<<endl;
	//3.inheritance
	employee E1;
	employee1 e1(100,"FUCK","india");
	E1.display_detail();
	e1.display_detail();
	cout<<"-------------copy consrtuctor-------------"<<endl;
	student st4=st2;
	st4.display_admin();
		return 0;
}
