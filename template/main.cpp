#include <iostream>
using namespace std;
/* Template:
   that we can use any type of data by using template
*/

template <typename X>
X add(X num1,X num2){
	return num1>num2?num1:num2;
}


//for class
template <class C>
class calculator{
	public:
	C num1,num2;
	calculator(C num1=1,C num2=2):num1(num1),num2(num2)
	{
		
	}
	void display()
	{
		cout<<"num1: "<<num1<<endl;
		cout<<"num2: "<<num2<<endl;
	}
	
};

int main() {
	cout<<add(10,20)<<endl;
	cout<<add(10.5,20.4)<<endl;
	cout<<add('g','a')<<endl;
	
	
	cout<<"-----in class-----"<<endl;
	calculator <int>c1(100,200);
	c1.display();
	
	return 0;
}
