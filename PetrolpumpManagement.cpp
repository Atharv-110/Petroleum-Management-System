/* 
                                       Date - 01/08/21
                        Project Name - Petrolpump Management System
                                    Author - Atharv Vani
                                        C++ - Language
*/
#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
class Petroleum
{
private:
    float curr_petrol_prc, curr_diesel_prc;
    double petrol_capacity = 20000, diesel_capacity = 20000;
    double refill_ptrl_price, refill_disl_price, refill_ptrl_litres, refill_disl_litres;
    double total_ptrl_amt = 0, total_disl_amt = 0, total_ptrl_lit = 0, total_disl_lit = 0;

public:
    Petroleum(); //Constructor of this prog.

    //Declarations of Member Function in the following

    void Menu(); //This will show the options which are provided to a user to be operated

    void petrol_Refilling(); //This is for refilling for the petrol

    void diesel_Refilling(); //This is for refilling for the diesel

    void show_Details(); //This will show user the whole info of the Petrolpump

    void clear_Details(); //This will clear the information to default
};

//Definitions of Member Function of class Petroleum

Petroleum::Petroleum()  //This will set current price of petrol & diesel
{
    cout << "Enter Today's Petrol Price : ";
    cin >> curr_petrol_prc;
    cout << "Enter Today's Diesel Price : ";
    cin >> curr_diesel_prc;
}
void Petroleum::Menu()
{
    cout << endl
         << "Today's Prices : " << endl
         << endl
         << "Petrol : " << curr_petrol_prc << endl
         << "Diesel : " << curr_diesel_prc << endl
         << endl;
    cout << "-----------Menu-----------" << endl
         << endl;
    cout << "1 -> Petrol Refilling" << endl;
    cout << "2 -> Diesel Refilling" << endl;
    cout << "3 -> Details of Management" << endl;
    cout << "4 -> Delete details" << endl;
    cout << "5 -> Exit Program" << endl;
}
void Petroleum::petrol_Refilling()
{
    cout << endl
         << "Enter Price of Petrol you want to refill : ";
    cin >> refill_ptrl_price;

    refill_ptrl_litres = refill_ptrl_price / curr_petrol_prc;

    cout << endl
         << setprecision(6)
         << refill_ptrl_litres << " litre petrol have been refilled in your vehicle." << endl;

    total_ptrl_amt += refill_ptrl_price;
    total_ptrl_lit += refill_ptrl_litres;
}
void Petroleum::diesel_Refilling()
{
    cout << endl
         << "Enter Price of Diesel you want to refill : ";
    cin >> refill_disl_price;

    refill_disl_litres = refill_disl_price / curr_diesel_prc;

    cout << endl
         << setprecision(6)
         << refill_disl_litres << " litre diesel have been refilled in your vehicle." << endl;

    total_disl_amt += refill_disl_price;
    total_disl_lit += refill_disl_litres;
}
void Petroleum::show_Details()
{
    cout << endl
         << "----------------------------------------------------------------------------------" << endl;

    cout << "Petrol Details : " << endl;
    cout << "Petrol Dispatched from Pump : " << setprecision(6) << total_ptrl_lit << " litres" << endl;
    cout << "Petrol left in Tank : " << setprecision(6) << petrol_capacity - total_ptrl_lit << " litres" << endl;
    cout << "Total amount Collected through Petrol : " << total_ptrl_amt << endl;

    cout << "----------------------------------------------------------------------------------" << endl;

    cout << "Diesel Details : " << endl;
    cout << "Diesel Dispatched from Pump : " << setprecision(6) << total_disl_lit << " litres" << endl;
    cout << "Diesel left in Tank : " << setprecision(6) << diesel_capacity - total_disl_lit << " litres" << endl;
    cout << "Total amount Collected through Diesel : " << total_disl_amt << endl;

    cout << "----------------------------------------------------------------------------------" << endl;

    cout << "Total amount Collected by Pump : " << total_disl_amt + total_ptrl_amt << endl;
}
void Petroleum::clear_Details()
{
    refill_ptrl_price = 0;
    refill_disl_price = 0;

    refill_ptrl_litres = 0;
    refill_disl_litres = 0;

    total_ptrl_amt = 0;
    total_disl_amt = 0;

    total_ptrl_lit = 0;
    total_disl_lit = 0;
}
int main()
{
    Petroleum pobj; //Class called & object created for respective class
    while (1)
    {
        char option;

        pobj.Menu();

        cout << "\nPlease Select a suitable Option from Menu : ";
        cin >> option;
        switch (option)
        {
        case '1':
            pobj.petrol_Refilling();
            break;
        case '2':
            pobj.diesel_Refilling();
            break;
        case '3':
            pobj.show_Details();
            break;
        case '4':
            char cnfrm;
            cout << "Are you sure, you want to clear details : \nIf yes press y/Y : ";
            getchar();
            cin >> cnfrm;
            if (cnfrm == 'y' || cnfrm == 'Y')
            {
                pobj.clear_Details();
            }
            break;
        case '5':
            char ext;
            cout << "Are you sure, you want to Exit program : \nIf yes press y/Y : ";
            getchar();
            cin >> ext;
            if (ext == 'y' || ext == 'Y')
            {
                exit(0);
            }
        default:
            cout << "Please select Appropriate option from the Menu Again.";
            break;
        }
        getchar();
    }
    return 0;
}