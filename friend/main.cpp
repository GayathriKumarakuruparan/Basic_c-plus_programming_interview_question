#include <iostream>
using namespace std;
/* friend -->to access the private data in outside of the class */
class student{
	int id;
	string name;
	float attendance;
	public:
	student(int id,string name,float attendance):id(id),name(name),attendance(attendance)
	{
		
	}
	
	//now the friend to this class for function
	friend void display_attendance(student);
	
	//for class
	friend class test;
};
class test{};

void display_attendance(student st)
{
	cout<<"attendance : "<<st.attendance<<endl;
}

int main() {
	
	student s1(100,"gayathri",90.9);
	display_attendance(s1);
	return 0;
}
