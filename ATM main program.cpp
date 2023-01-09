

#include <iostream>
#include <cstring>
using namespace std;

class ATM
{
    char more_than_ten[100];
   
    char acount_name[101];

    int account_number[10];

    double amount;
    


public:

    void create_new_acc()
    {
       
         cout << "please enter the account name : ";
        name_correction:
        cin.ignore();
        cin.getline(acount_name,101 );  cout << endl;

        for (int i = 0;i < 101;i++)
        {
            if (acount_name[i] != NULL)
            {
                int x;
                x = acount_name[i];
               
                if ((!(x<123 && x>96)) &&(x!=32) && (!(x<91 && x>64)))
                {
                    
                        cout << "plz enter a valid name using small letters only (a-z)" << endl;

                        goto name_correction;
                    
                }
                else
                    continue;
            }
            else
               break;
        }
       
        cout << "Please enter the account number (10 numbers each separated by space): ";
        amount = 0;
        label:                                                   //labellllll here

        for (int i = 0;i < 10;i++)
        {
            cin >> account_number[i];
            if (account_number[i] > 9 || account_number[i] < 0)
            {
                cout << "plz enter a right number (10 positive numbers each one is less than ten separated by space): "<<endl;
                goto  label;
               
            }

        }

        cin.getline(more_than_ten,100);
        if (more_than_ten[0] != NULL)
        {
            cout << "Please enter 10 numbers only: " << endl;
            goto label;
           
        }

        if (Check_New_Acc_Num(account_number)) {
            cout << "This account number is already taken please try another one." << endl;
            goto label;
        }

        if (!Check_Num_Validity(account_number)) {

            cout << "This number is not valid(too easy to guess), Please enter a valid number. " << endl;
            goto label;
        }
       
       
        print_acc_data();
       

    }



    void deposit(double money)
    {
        amount += 1.01 * money;
    }
    void withdrowal()
    {
        double money;
        cout << endl << "Please enter the amount to be withdrawn: ";
        label0:
        cin >> money; cout << endl;

      
        if (money <= 0)
        {
            cout << "please  enter a valid amount of money" << endl;
            goto label0;

        }
        
        
        
        if (money > amount / 1.03)
        {
            cout << "u can not withdrow this amont of money, ur maximume amount u can withdrow is: " << amount / 1.03 << endl;
            cout << "plz enter a valid amount (less than" << amount / 1.03 << "): ";
            goto label0;

        }
        else
        amount -=  1.03 * money;
       
        
        
    }






    void transfare(ATM &reciver)
    {
        double money;
        cout << "please enter the amount to be transferred: ";
        money_correction:
        cin >> money; cout << endl;


        if (money <= 0)
        {
            cout << "please  enter a valid amount of money" << endl;
            goto money_correction;

        }

        if (money > amount / 1.015)
        {
            cout << "u can not tranfare this amont of money, ur maximume amount u can tranfare is: " << amount / 1.015 << endl;
            cout << "please enter the amount again: ";
            goto money_correction;
        }
        else
        {
            amount -= 1.015 * money;
            reciver.amount += 0.985 * money;
        }

    }
    void print_acc_data()
    {
        cout << "name : "<< acount_name << endl;
        cout << "Card number: "; for (int i = 0;i < 10;i++) cout << account_number[i];
        cout << endl;
        cout << "amount: " << amount << endl;
    }





   bool compare(int x[10])
    {
       bool l;
        for (int p = 0;p < 10;p++)
        {
            if (x[p] == account_number[p])
            {
                l = true;
                continue;
            }
            else
            {
                l =false;
                break;
            }
            
        }
        return l;
    }


   bool Check_New_Acc_Num(int x[10]);
   bool Check_Num_Validity(int x[10]);
  

};



ATM clint[100];
int clint_number = -1;


int main()
{
   


    int number_of_operation,o ,a;
    bool check;
    double deposit_amonut,tranfered_amount,withdrowal_amount;
    char more_than_ten[100];



puplic_menu:                                             //puplic menu hereeeeeeeeeeeeee

    cout << "1----Create new account" << endl <<
        "2----Deposit" << endl <<
        "3----transfer to another account" << endl <<
        "4----withdrawal" << endl <<
        "5----exit" << endl;




    cout << "Please enter the number of operation:";
label2:                                                  //label2 hereeeeeee
    cin >> number_of_operation; cout << endl;
   
    
    
    if (number_of_operation < 1 || number_of_operation>5)
    {
        cout << "plz enter a valid number of operation";
        goto label2;
    }

    if (number_of_operation == 1)                                 //creat new acount operatioon
    {
        clint_number++;
        clint[clint_number].create_new_acc();

       


        goto puplic_menu;
    }

    if (number_of_operation == 2)                                     //Deposit opiration
    {
        int acount_number_for_deposit[10];
        cout << "Please enter the account number (10 numbers each separated by space):";
        label3:                                                         //label3 hereeeeeeeeeeeee
        for (int i = 0;i < 10;i++)
        {
            cin >> acount_number_for_deposit[i];
            if (acount_number_for_deposit[i] > 9 || acount_number_for_deposit[i] < 0)
            {
                cout <<endl<< "please enter a right number (10 positive numbers each one is less than ten separated by space): " << endl;
                goto  label3;

            }

        }

        cin.getline(more_than_ten, 100);
        if (more_than_ten[0] != NULL)
        {
            cout << " Please enter 10 numbers only: " << endl;
            goto label3;
        }



        for (o = 0;o <= clint_number;o++)
        {
           check= clint[o].compare(acount_number_for_deposit);

           if (check)
           {
              
              cout << endl << "Please enter the amount to be deposited: ";
              deposit_amonut_correction:

              cin >> deposit_amonut;

              if (deposit_amonut <= 0)
              {
                  cout << "please  enter a valid amount of money: " << endl;
                  goto deposit_amonut_correction;

              }


               clint[o].deposit(deposit_amonut);
               clint[o].print_acc_data();
               break;
           }
        }
       
            
        if(!check)
        {
            cout << endl << "this acount number does not exsist !!" << endl << "plz enter a true acount number (10 numbers each separated by space): ";
            goto label3;
        }
        goto puplic_menu;
    }

    if (number_of_operation == 3)                                      
    {
        int tranfasrer_acount_number[10],reciver_acc_number[10];

        cout << "please enter the number of the sending account (10 numbers each separated by space):";
    label4:                                                         //label4 hereeeeeeeeeeeee
        for (int i = 0;i < 10;i++)
        {
            cin >> tranfasrer_acount_number[i];
            if (tranfasrer_acount_number[i] > 9 || tranfasrer_acount_number[i] < 0)
            {
                cout << "plz enter a right number of sender account (10 numbers each separated by space): " << endl;
                goto  label4;

            }

        }
        cin.getline(more_than_ten, 100);
        if (more_than_ten[0] != NULL)
        {
            cout << "Please enter 10 numbers only: " << endl;
            goto label4;
        }

        for (o = 0;o <= clint_number;o++)
        {
            check = clint[o].compare(tranfasrer_acount_number);
            if (check)
                break;
        }
        if (!check)
        {
            cout << endl << "this acount does not exsist" << endl << "plz enter a true sending acount number (10 numbers each separated by space): ";
            goto label4;
        }






        cout << "please enter the number of the receiving account (10 numbers each separated by space):";
    label5:                                                         //label5 hereeeeeeeeeeeee
        for (int i = 0;i < 10;i++)
        {
            cin >> reciver_acc_number[i];
            if (reciver_acc_number[i] > 9 || reciver_acc_number[i] < 0)
            {
                cout << "plz enter a right number of reciver account (10 numbers each separated by space): " << endl;
                goto  label5;

            }

        }

        cin.getline(more_than_ten, 100);
        if (more_than_ten[0] != NULL)
        {
            cout << "Please enter 10 numbers only: " << endl;
            goto label5;
        }

        
        for (a = 0;a <= clint_number;a++)
        {
            check = clint[a].compare(reciver_acc_number);
            if (check)
                break;
        }
        if (!check)
        {
            cout << endl << "this account does not exsist" << endl << "plz enter a true reciving acount number (10 numbers each separated by space): ";
            goto label5;
        }

        clint[o].transfare(clint[a]);

        cout << "sending acount: " << endl;
        clint[o].print_acc_data();
        cout << endl << "reciving account; " << endl;
        clint[a].print_acc_data();
        cout << endl;

        goto puplic_menu;
    }

    
    if (number_of_operation == 4)
    {
        int withdrowal_acount_number[10];
        cout << "please enter the number of the  account (10 numbers each separated by space):";
    label6:                                                         //label6 hereeeeeeeeeeeee
        for (int i = 0;i < 10;i++)
        {
            cin >> withdrowal_acount_number[i];
            if (withdrowal_acount_number[i] > 9 || withdrowal_acount_number[i] < 0)
            {
                cout << "plz enter a right account number  (10 numbers each separated by space): " << endl;
                goto  label6;

            }

        }

        cin.getline(more_than_ten, 100);
        if (more_than_ten[0] != NULL)
        {
            cout << "Please enter 10 numbers only: " << endl;
            goto label5;
        }




        for (o = 0;o <= clint_number;o++)
        {
            check = clint[o].compare(withdrowal_acount_number);
            if (check)
                break;
        }
        if (!check)
        {
            cout << endl << "this account number does not exsist" << endl << "plz enter a true acount number (10 numbers each separated by space): ";
            goto label4;
        }
       
        clint[o].withdrowal();
        clint[o].print_acc_data();
        goto puplic_menu;
    }


    if (number_of_operation == 5)
        return 0;

}



bool ATM::Check_New_Acc_Num(int x[10]) {

    for (int i = 0; i < clint_number;i++) {
        int score = 0;
        for (int j = 0;j < 10;j++)
            if (x[j] == clint[i].account_number[j])
                score++;
        if (score == 10) return 1;


    }
    return 0;
}
bool ATM::Check_Num_Validity(int x[10])
{
    int total = 0;
    int are_all_same = 1;

    for (int i = 0;i < 10;i++)
    {
        total += x[i];
        if (i < 9)
        {                                                    // We only want up to i=8, We did this so we don't have to make another loop.
            if (x[i] != x[i + 1]) are_all_same = 0;
        }




    }
    if (total == 0 || are_all_same)
    {
        cout << "The entered account number is a series of the number (" << x[1] << ")." << endl;
        return 0;
    }
    return 1;



}