#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;
int main(){
    vector<string> item;
    vector<double> price;
    int attempt = 0;
    double billPayment = 0;
    while(attempt < 5){
        cout<<"\n_____WELCOME TO OUR GROCERY STORE_____\n";
        cout<<"1. Add Item to Cart\n2. Delete Item from Cart\n3. Proceed for Payment\n4. Exit\n";
        int op;
        cout<<"Choose any option:\n";
        cin>>op;
        cin.ignore();
        switch(op){
            case 1:{
                string name;
                string wish;
                while(true){
                    cout<<"Enter The item: ";
                    getline(cin, name);
                    item.push_back(name);
                    cout<<"Do You want to add another Item(Yes/No): ";
                    cin>>wish;
                    cin.ignore();
                    for(char &c : wish) c = tolower(c);
                    if(wish == "yes") continue;
                    else if(wish == "no") break;
                    else{
                        cout<<"Invalid!";
                    }
                }
                break;
            }
            case 2:{
                if(item.empty()){
                    cout<<"No items in the cart.\n";
                }
                string name;
                cout<<"Enter the name of the item you want to delete: ";
                cin>>name;
                auto it = find(item.begin(), item.end(), name);
                if(it != item.end()){
                    item.erase(it);
                }
                break;
            }
            case 3:{
                double p;
                for(int i=0; i<item.size(); i++){
                    cout<<"Item "<<i+1<<". "<<item[i]<<" has a price printed: ";
                    cin>>p;
                    price.push_back(p);
                }
                for(int j=0; j<item.size(); j++){
                    billPayment += price[j];
                }
                cout<<"Your total bill is: "<<billPayment<<endl;
                break;
            }
            case 4:
                return 0;
                break;
            default:
                cout<<"Invalid Option Chosen!\n";
        }
        attempt++;
    }
    return 0;
}