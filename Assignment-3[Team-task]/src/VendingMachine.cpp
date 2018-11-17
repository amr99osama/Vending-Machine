#include "VendingMachine.h"
#include <iostream>
#include <string>
using namespace std;


VendingMachine::VendingMachine()
{

}
 bool VendingMachine::check_for_availabilty(int index)
{
if(quantity[index]!=0)
        {
        --quantity[index];
        --available;
        return true;
        }
     else{return false;}

}

int VendingMachine::available=100;
int VendingMachine::quantity[10]={10,10,10,10,10,10,10,10,10,10};

VendingMachine::~VendingMachine()
{
}

Customer::Customer(int paperbill,float change)
{
   total_money=paperbill+change;
}

float Customer::continue_billing()
{
  restmoneybill=total_money-prices[choice2];
       cout<<"outputing your item."<<endl;
       if(restmoneybill<0)
        {
            cout<<"not enough money will return your money now."<<endl<<endl;
            return total_money;
        }
        cout<<"your money: ";
        coinhandler(restmoneybill);
        cout<<endl<<endl;
        return restmoneybill;
}




int Customer::choose_item()
{
int choice;
     cout<<"choose your item: ";cin>>choice;
     choice2=choice-1;
     return choice2;
}

void Customer::total_interface()
{
if(available!=0)
     {
      cout<<"your money: "<<total_money<<endl;
      showitems();
     if(
        check_for_availabilty(choose_item()))
            continue_billing();
     else{fail();}
     }
     else
     {
        cout<<"the machine is not available now for service."<<endl;cout<<"outputing your money";
     }
}

float Customer::return_money()
{
    cout<<"your money: "<<total_money<<endl;return total_money;
}

void Customer::fail()
{
int choice;
    cout<<"item is not available"<<endl<<"press 1 to choose another item or 0 to exit your money: ";
    cin>>choice;
    if(choice==1)total_interface();
    else {return_money();}
}

void Customer::showitems()
     {
     for(int i=0;i<10;i++)
        cout<<i+1<<"- "<<names[i]<<endl;
     }

     void Customer::coinhandler(float restofmoney)
     {
      int bill20 = 0, bill10 = 0, bill5 = 0;

     int changehalf = 0 , changeone = 0;

     bill20 = (int)restofmoney / 20.0;

     restofmoney -= bill20 * 20;
     bill10 = (int)restofmoney / 10.0;
     restofmoney -= bill10 * 10;
     bill5=(int)restofmoney / 5.0;
     restofmoney -= bill5 * 5;
     changeone = (int)restofmoney / 1.0;
     restofmoney -= changeone;
     changehalf = (int)restofmoney / 0.5;
     bill20 != 0 ? cout<<bill20<<" 20 bill "<<endl:cout<<"";
     bill10 != 0 ? cout<<bill10<<" 10 bill "<<endl:cout<<"";
     bill5  != 0 ? cout<<bill5<<" 5 bill "<<endl:cout<<"";
     changeone ! = 0 ? cout<<changeone<<" pounds "<<endl:cout<<"";
     changehalf != 0 ?cout<<changehalf<<" half pounds "<<endl:cout<<"";

     }

Customer::~Customer(){};





