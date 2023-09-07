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
    cout << "\t\t\t_______________________________________________________\n\n\n";
    cout << "\t\t\t                Welcome to the Login page              \n\n\n";
    cout << "\t\t\t___________________________Menu________________________\n\n";
    cout << "                                                              \n\n";
    cout << "\t\t\t| Press 1 to Login                         |"<<endl;
    cout << "\t\t\t| Press 2 to Registration                  |"<<endl;
    cout << "\t\t\t| Press 3 if you forgot your Password      |"<<endl;
    cout << "\t\t\t| Press 4 to Exit                          |"<<endl;
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
    string regUserId, regUserPassword, regId, regPass;
    system("cls");
    cout << "\n\t\t\t Enter the USERNAME : ";
    cin>>regUserId;
    cout << "\n\t\t\t Enter the PASSWORED : ";
    cin>>regUserPassword;

    ofstream write("C:/Users/Babloo/Desktop/Practice/C++/LoginAndRegistration/record.txt", ios::app);
    write<<regUserId << "\t" << regUserPassword<<endl;
    system("cls");
    cout << "\n\t\t\t Registration is successfull! \n";
    main();
}

void forgot()
{
    system("color 20");
    int option;
    system("cls");
    cout << "\t\t\t You forgot the password? No worries \n";
    cout << "\t\tPress 1 to search your id by username "<<endl;
    cout << "\t\tPress 2 to go to the main menu "<<endl;
    cout << "\t\t\t Enter Your Choice : ";
    cin>>option;
    switch (option)
    {
        case 1:
        {
            int count = 0;
            string uId, uPass, user;
            cout << "\n\t\t\tEnter the username which you remembered : ";
            cin>>user;

            ifstream fin("C:/Users/Babloo/Desktop/Practice/C++/LoginAndRegistration/record.txt");
            while(fin>>uId>>uPass)
            {
                if(uId == user){
                    count = 1;
                }
            }
            fin.close();
            if(count == 1){
                cout << "\n\n\t\t\t Your account is found! \n";
                cout << "\n\t\t\t Your password is : " << uPass;
                main();
            }else{
                cout << "\n\n\t\t\t Sorry Your Account is not found! \n";
                main();
            }
            break;
        }
        case 2:
        main();
        break;

        default:
        {
        cout << "\n\t\t\t Wrong choice ! Please try again " << endl;
        forgot();
        }
    }
}
