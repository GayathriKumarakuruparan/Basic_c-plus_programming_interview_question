#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;
void login();
void registrator();
void forgetten();

int main()
{
    int option;
    cout<<"--------------WELCOME TO LOGIN PAGE------------------"<<endl;
    cout<<"                       MENU                          "<<endl;
    cout<<"Press 1 to Login the page   |\nPress 2 to register to the page   |\nPress 3 if you forget the password   |\nPress 4 to exit\n"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Enter the option:  "<<endl;
    cin>>option;
    switch(option)
    {
        case 1:
        {
            login();
            break;
        }
        case 2:
        {
            registrator();
            break;
        }
        case 3:
        {
            forgetten();
            break;
        }
        case 4:
        {
            cout<<"-----Thank you-----"<<endl;
            break;
        }
        default:
        {
            system("cls");
            cout<<"please enter the valid option!!!!!!"<<endl;
            main();
        }
    }

    return 0;
}
void login()
{
    int count=0;
    string username,id,password,pass;
    system("CLS");
    cout<<"Please enter the username and password"<<endl;
    cout<<"USERNAME: "<<endl;
    cin>>username;
    cout<<"PASSWORD: "<<endl;
    cin>>password;
    ifstream input("records.txt");
    while(input>>id>>pass)
    {
        if(id==username && pass==password)
        {
            count=1;
            system("CLS");
        }
        
    }
    input.close();
        if(count==1)
        {
            cout<<username<<" Your login successfully completed!!!\n Thanks foe login\n";
            main();
        }
        else
        {
            cout<<"LOGIN ERROR: \nPlease check the username\n";
            main();
        }
}
void registrator()
{
    string rusername,rid,rpass,rpassword;
    system("cls");
    cout<<"Please enter the username and password"<<endl;
    cout<<"USERNAME: ";
    cin>>rusername;
    cout<<"PASSWORD: ";
    cin>>rpassword;
    ofstream reg("records.txt", ios::app);//ios->input output stream app->append
    reg<<rusername<<" "<<rpassword<<endl;
    system("cls");
    cout<<"Registration is successfully"<<endl;
    main();
}
void forgetten()
{
    int choose;
    system("CLS");
    cout<<"Oops!!!!you forgot your password!!NO WORRIES;)))"<<endl;
    cout<<"Press 1 to search for id\nPress 2 ->go back to main menu\n"<<endl;
    cout<<"Enter your choose: "<<endl;
    cin>>choose;
    switch(choose)
    {
        case 1:
        {
            int count=0;
            string susername,sid,spass,spassword;
            cout<<"please enter the username which you remember:"<<endl;
            cin>>susername;
            ifstream search("records.txt");
            while(search>>sid>>spass)
            {
                if(sid==susername)
                {
                    count=1;
                    
                }
            }
            search.close();
            if(count==1)
            {
                cout<<"Your account is found"<<endl;
                cout<<"Your password is: "<<spass<<endl;
                main();
            }
            else
            {
                cout<<"SORRY !!!! Your account is not found"<<endl;
                main();
            }
            break;
            
        }
        case 2:
        {
            main();
            
        }
        default:
        {
            cout<<"wrong choose!!! Please enter the correct choose"<<endl;
            forgetten();
        }
    }
}
