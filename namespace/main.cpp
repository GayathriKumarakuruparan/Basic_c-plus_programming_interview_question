#include <iostream>
using namespace std;

/* NAMESPACE:
      which is used to create a global variable to work with first priority...
*/

//normal global variable
int x=20;


//namespace 
namespace global{
	int a=100;
}


//example 2
namespace Myfunc{
	class employee{
		public:
			string name;
	};
}
class employee{
	public:
	string name;
};


int main() {
	int x=10,a=40;
	
	
	cout<<"x : "<<x<<endl;   //this x will execute the block value as 10 not global variable as 20.
	
	//to acess the global variable we can access outer variable..
	
	
	 cout<<"a : "<<global::a<<endl;
	 
	 employee e1;
	 Myfunc::employee e2;
	 e1.name="HAI";
	 e2.name="HELLO";
	 cout<<e1.name<<endl;
	 cout<<e2.name<<endl;
	return 0;
}
