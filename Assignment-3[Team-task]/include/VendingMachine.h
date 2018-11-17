#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
using namespace std;
#include <string>

// Vending Machine Class
class VendingMachine
{
    public:
        VendingMachine();
         ~VendingMachine();
         // Static Bool Variable for check if the product is available or not
           static bool check_for_availabilty(int index);
           // display the items in machine
                void showitems();

    protected:
        // Number of products available
         static int available;
         // Number of products in the machine
    static int quantity[10];
    // names of the products
    string names[10]={"pepsi","fanta","coffe","tea","coke"
    ,"chepsi","snickers","more","galaxy","mountain dew"};
    // prices of the products
    float prices[10]={5.5,6,7,8.5,9,3.5,4,10,12,4.5};

};


// customer class derived from Vending Machine
class Customer : public VendingMachine
{
protected:

        float total_money;
        int choice2;
        float restmoneybill;
public:
    Customer(int paperbill,float change=0);
    float continue_billing();
        int choose_item();
    void total_interface();
    void coinhandler(float restofmoney);
        void fail();
     float return_money();
     void showitems();
     ~Customer();
};

#endif // VENDINGMACHINE_H
