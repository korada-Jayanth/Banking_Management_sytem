#include<bits/stdc++.h>
using namespace std;
class BankAccount{
    private: 
        string Name;
        int accountNum;
        double balance;
    public:
        BankAccount(string n,int account,double bal){
            Name = n;
            accountNum = account;
            balance = bal;
        }
        string  getName(){
            return Name;
        }
        int getaccountNum(){
            return accountNum;
        }
        double getbalance(){
            return balance;
        }
        void Deposit(double amount){
            balance = balance + amount;
        }
        void withdraw(double amount){
           if(balance >= amount){
                balance = balance - amount;
                cout<<"\t\t Withdraw Successfully"<<endl;
           }
           else{
                cout<<"\t\t Insufficient Balance"<<endl;
           }
        }
};
class BankManagement{
    vector<BankAccount>accounts;
    public:
        void addAccount(string Name,int accountNum,double balance){
            accounts.push_back(BankAccount(Name,accountNum,balance));
        }
        void ShowAllAccounts(){
            cout<<"\t\t All Accounts Holder"<<endl;
            for(int i=0;i<accounts.size();i++){
                cout<<"Name :"<<accounts[i].getName()<<"  Account Number: "<<accounts[i].getaccountNum()<<"  Balance: "<<accounts[i].getbalance()<<endl;
            }
        }
        void SearchAccount(int account){
            cout<<"\t\t Account Holder"<<endl;
            for(int i=0;i<accounts.size();i++){
                if(accounts[i].getaccountNum() == account){
                    cout<<"Name :"<<accounts[i].getName()<<"  Account Number: "<<accounts[i].getaccountNum()<<"  Balance: "<<accounts[i].getbalance()<<endl;
                }
            }
        }
        BankAccount* findAccount(int accountNum){
            for(int i=0;i<accounts.size();i++){
                if(accounts[i].getaccountNum() == accountNum){
                    return &accounts[i];
                }
            }
        }
};
int main(){
    BankManagement bank;
    int choice;
    char option;
    do{
    cout<<"\t\t Banking Management System"<<endl;
    cout<<"\t\t\t Main Menu"<<endl;
    cout<<"\t\t 1.Create New Account"<<endl;
    cout<<"\t\t 2.Show All Accounts"<<endl;
    cout<<"\t\t 3.Search Account"<<endl;
    cout<<"\t\t 4.Deposit Money"<<endl;
    cout<<"\t\t 5.Withdraw Money"<<endl;
    cout<<"\t\t 6.Exit"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"\t\t Enter Your Choice: ";
    cin>>choice;
    switch(choice){
        case 1:{
            string Name;
            int accountNum;
            double balance;
            cout<<"\t\t Enter Name: ";
            cin>>Name;
            cout<<"\t\t Enter Account Number: ";
            cin>>accountNum;
            cout<<"\t\t Enter Bank Balance: ";
            cin>>balance;
            bank.addAccount(Name,accountNum,balance);
            cout<<"\t\t Account Created Succesfully"<<endl;
            break;
        }
        case 2:{
            bank.ShowAllAccounts();
            break;
        }
        case 3:{
            int accountNum;
            cout<<"\t\t Enter Account Number: ";
            cin>>accountNum;
            bank.SearchAccount(accountNum);
            break;
        }
        case 4:{
            int accountNum;
            double amount;
            cout<<"\t\t Enter Account number to Deposit Money: ";
            cin>>accountNum;
            BankAccount* account = bank.findAccount(accountNum);
            if(account != NULL){
                cout<<"\t\t Enter Amount to Deposit: ";
                cin>>amount;
                account->Deposit(amount);
                cout<<amount<<"Deposited Succesfully"<<endl;
            }else{
                cout<<"\t\t Account Not Found"<<endl;
            }
            break;
        }
        case 5:{
            int accountNum;
            double amount;
            cout<<"\t\t Enter Account number to withdraw Money: ";
            cin>>accountNum;
            BankAccount* account = bank.findAccount(accountNum);
            if(account != NULL){
                cout<<"\t\t Enter Amount to withdraw: ";
                cin>>amount;
                account->withdraw(amount);
            }else{
                cout<<"\t\t Account Not Found"<<endl;
            }
            break;
        }
        case 6:{
            exit(1);
            break;
        }
    }
    cout<<"\t\t Do You Want to Continue or Not [YES/NO]: ";
    cin>>option;
}while(option == 'y' || option == 'Y');
return 0;
}