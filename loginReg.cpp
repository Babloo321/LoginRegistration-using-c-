#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
void login();
void registration();
void forgot();

int main()
{
    system("color 40");
    int choice;
    cout << "\t\t\t\t\t_______________________________________________________\n\n\n";
    cout << "\t\t\t\t\t                Welcome to the Login page              \n\n\n";
    cout << "\t\t\t\t\t___________________________Menu________________________\n\n";
    cout << "                                                                 \n\n";
    cout << "\t\t\t| Press 1 to Login                         |"<<endl;
    cout << "\t\t\t| Press 2 to Registration                  |"<<endl;
    cout << "\t\t\t| Press 3 if you forgot your Password      |"<<endl;
    cout << "\t\t\t| Press 1 to Exit                          |"<<endl;
    cout << "\n\t\t\t\t\t Please enter your choice: ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {
        case 1:
        login();
        break;

        case 2:
        registration();
        break;

        case 3:
        forgot();

        case 4:
        cout <<"\n\t\t\t\t ThankYou! \n\n";
        break;

        default:
        system("cls");
        cout << "\t\t\t\t Please select from the option given above \n" << endl;
        main();

    }
    return 0;
}

void login(){
    system("color 30");
    int count;
    string userId, password, id, pass;
    system("cls");
    cout <<"\n\t\t\t\t Please enter the username and password :"<< endl;
    cout << "\t\t\t\t USERNAME-> ";
    cin>>userId;
    cout << "\t\t\t\t PASSWORD-> ";
    cin>>password;

    ifstream input("C:/Users/Babloo/Desktop/Practice/C++/LoginAndRegistration/record.txt");
    while(input>>id>>pass)
    {
        if(id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if(count == 1)
    {
        cout << userId << "\n Your Login is successfull \n Thanks for Logging in !";
        main();
    }else{
        cout << "\n LOGIN ERROR \n Please check your USERNAME and PASSWORD\n";
        main();
    }
}

void registration()
{
    system("color 60");
    
}
