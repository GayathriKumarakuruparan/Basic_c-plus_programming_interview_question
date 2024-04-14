#include <iostream>
using namespace std;
/* POLYMORPHISM
   ....its make the class with convinience stage.
   TYPES
   1.Run time
   2.complier time
   
   Run time :
   1.function overloading
   2.operator overloading
   
   Complier time :
   1.Function overriding
   
*/



//pointer to base class
class polygon{
	protected:
		int width;
		int height;
		public:
			void set_value(int a,int b)
			{
				width=a;height=b;
			}
};

class rectangle:public polygon{
	
	public:
		int area()
		{
			return width*height;
		}
};
class triangle:public polygon{
	public:
		int area()
		{
			return width*height/2; 
		}
};

//RUN TIME:
//Function overloading-------->same class name with different types of argument not only return type also arugments type
int add(int a,int b)
{
	return a+b;
}
string add(string a,string b)
{
	return a+b;
}
double add(double a, int b)
{
	return a+b;
}


/*Operator overloading--------->writing our own function to work with operator and object together.
		restrictions:
		-------------
		1.::scope
		2.sizeof
		3.(.)(member)
		4.*
		5.ternary
*/


 
//unary overloading--> ++,--,+,-....
class unary{
	public:
	int n1,n2;
	unary(int n1=1,int n2=2):n1(n1),n2(n2)
	{
		
	}
	void display();
	void operator -()
	{
		n1=-n1;
		n2=-n2;
	}
	void operator --()
	{
		n1=--n1;
		n2=--n2;
	}
	void operator ++()
	{
		n1=++n1;
		n2=n2+3;
	}
	void operator ++(int)//for post increment to differenciate
	{
		n1=++n1;
		n2=n2+3;
	}
};



//BINARY OPERATION----->&&,||,!
class binary{
	public:
		int n1,n2;
		binary(int n1=1,int n2=2):n1(n1),n2(n2)
		{
		};
		void display2(){
			cout<<"n1: "<<n1<<endl;
	        cout<<"n2: "<<n2<<endl;
		}
		
		//by integer
		void operator +(int num)
		{
			n1+=num;
			n2+=num;
		}	
		
		//by class
		void operator +(unary ov)
		{
			n1+=ov.n1;
			n2+=ov.n2;
		}	
};

void unary::display()
{
	cout<<"n1: "<<n1<<endl;
	cout<<"n2: "<<n2<<endl;
}


//COMPILE TIME:
//Function overriding-------->replacing the already existing behaviour with new logic/body
class override{
	protected:
		int width;
		int height;
		
	
		override(int width=20,int height=40):width(width),height(height){
		};
		public:
				
		    int area()
			{
				cout<<"area of override"<<endl;
				return width*height;
			}
};

class rect:public override{
	
	public:
		int area()
		{
			cout<<"area of rectangle"<<endl;
			return width*height;
		}
};
class tri:public override{
	public:
		int area()
		{
			cout<<"area of triangle"<<endl;
			return width*height/2; 
		}
};


//this shape class is called as abstract class due to pure virtual due to incomplete and it;s not possible to create object for this class

class shape{
	protected:
		int width;
		int height;
		
	
		shape(int width=10,int height=40):width(width),height(height){
		};
		public:
				//to overcome the early binding
		    virtual int area()
			{
				cout<<"area of shape"<<endl;
				return width*width; //don;t bother about formula
			}
			
			//if the classs has no function then,
			//virtual int h1()=0 // pure virtual function-- function withot implement
};

class circle:public shape{
	
	public:
		int area()
		{
			cout<<"area of circle"<<endl;
			return width*height; //don't bother about formula
		}
};




int main() {
	rectangle r1;
	triangle t1;
	polygon *p1=&r1;
	polygon *p2=&t1;
	p1->set_value(10,20);
	p2->set_value(10,10);
	
	
	cout<<"---------POINTER TO BASE CLASS------------"<<endl;
	cout<<"rectangle value is: "<<r1.area()<<endl;
	cout<<"triangle value is:  "<<t1.area()<<endl;
	
	
	cout<<endl<<"--------------POLYMORPHISM----------------"<<endl;
		cout<<endl<<"--------------Run time---------"<<endl;
	cout<<endl<<"--------------1.Function overloading---------"<<endl;
	cout<<"fun1 output: "<<add(10,20)<<endl;
	cout<<"fun2 output: "<<add("hello","hai")<<endl;
	cout<<"fun3 output: "<<add(20.4,8)<<endl;
	
	
	
	cout<<endl<<"------------2.Operator overloading---------"<<endl;
	unary o1,o2(10,20);
	cout<<"before unary"<<endl;
	o1.display();
	-o1;
	cout<<"after unary -"<<endl;
	o1.display();
	--o1;
	cout<<"after unary --"<<endl;
	o1.display();
	++o1;
	cout<<"after unary ++"<<endl;
	o1.display();
	o1++;
	cout<<"after unary post increment++"<<endl;
	o1.display();
	
	binary B1(10,20),b2(12,22);
	cout<<"before binary"<<endl;
	B1.display2();
	B1+10;
	cout<<"after binary + using int"<<endl;
	B1.display2();
	b2+o2;
	cout<<"after binary + using class"<<endl;
	b2.display2();
	
	cout<<endl<<"------------complie time---------"<<endl;
	cout<<endl<<"--------------Function overriding---------"<<endl;
	rect rc1;
	tri tc1;
	cout<<rc1.area()<<endl;
	cout<<tc1.area()<<endl;
	
	//pointer in complie time
	override *ptr=new tri();
	cout<<"----early binding----"<<endl;/*this will not give the area from the given func..
	                                      because the earlybinding is bind the pointer with base class...
										  to aviod this we using late binding, i.e virtual*/
	                                    
	cout<<ptr->area()<<endl;
	cout<<"----late binding----"<<endl;
	cout<<"----virtual----"<<endl;
//	virtual pointer
	shape *s1=new circle();
	cout<<s1->area()<<endl;
	
	
	
	
	return 0;
}
