#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
void login();
void registr();
void forget();

main()
{
    int choice;
    cout<<"*****************LOGIN************\n";
    cout<<"1.Login";
    cout<<"\n2.Register";
    cout<<"\n.Forget credentials";
    cout<<"\nEnter your choice :";
    cin>>choice;
    switch (choice)
    {
    case 1: 
        login();
        break;
    
    case 2: 
        registr();
        break;

    case 3: 
          forget();
          break;


    case 4:
        cout<<"Thanks for using thw login page\n ";
     
    default :
         cout<<" Wrong choice \n";
         main();


              
    }
}
void registr()
{
    string reguser , regpass;
    system("cls");
    cout<<" Enter the username :";
    cin>>reguser;
    cout<<"Enter Password ";
    cin>>regpass;

    ofstream reg("database.txt",ios::app);
    reg<<reguser<<' '<<regpass<<endl;
    system("cls");
    cout<<"Registration is successful\n";
    main();

}

void login()
{
    int exist;
    string user,pass,u,p;
    system("cls");
    cout<<"Enter the username : ";
    cin>>user;
    cout<<"Enter the Password :";
    cin>>pass;

   ifstream input("database.txt");

   while(input>>u>>p)
  {  
    if(u == user && p == pass)
    {
        exist = 1;

    }
    input.close();
    if(exist ==1)
    {
        cout<<"hello"<<user<<"\n we are glad to have u here\n ";
        cin.get();
        cin.get();
        main();

    }
    else
    {
      cout<<"Sorry, Login error. ";
      cin.get();
      cin.get();
      main();

    } 
 }

 void forget();
 {
     int ch;
     system("cls");
     cout<<"1.Search your accout by username";
     cout<<"\n2.Search your accout password";
     cout<<"\n3.Mainmenu";
     cout<<"\nEnter your choice:";
     cin>>ch;


     switch(ch)
     {
         case 1:
         {
            int ex = 0;
            string searchuser,su,sp;
            cout<<"Enter your remebered username";
            cin>>searchuser;

            ifstream searchu("database.txt");
            while (searchu>>su>>sp)

            {
                if (su == searchuser)
                {
                    ex = 1;
                    break;

                }

            }
            searchu.close();
            if(ex = 1)
            {
                cout<<"Hurray !  account found !\n";
                cout<<"Your Password is "<<sp;
                cin.get();
                cin.get();
                main();


            }
            else
            {
                cout<<"Sorry your account is not found";
                cin.get();
                cin.get();
                main();


            }
        
            break;
         }  
            case 2:
            {
                 int exi = 0;
                 string searchpass, su2,sp2;
                 cout<<"Enter the remebered password :";
                 cin>>searchpass;
                    

                    ifstream searchp("database.txt");
                    while (searchp>>su2>>sp2)
                    {
                        if (sp2 == searchpass) 
                        {
                            exi = 1;
                        }
                        
                    } 
                    searchp.close();
                    if (exi == 1)
                    {
                        cout<<"hurray! the account found \n";
                        cout<<"your username is : "<<su2;
                        cout<<"your password is :"<<sp2;
                        cout<<"\n Your password is :"<<sp2;
                        cin.get();
                        cin.get();
                        main();



                    }
                    break;
            }

                   case 3:
                   {
                     main();
                     break;
                   } 
                   default:
                   {

                   
                        cout<<"you have given a wrong choice. Press a key again. ";
                        cin.get();
                        cin.get();
                        forget(); 
                   }  

                    
                    





            
            

     }

 }   

    

}

