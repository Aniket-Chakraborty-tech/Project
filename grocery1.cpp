#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<string> items = {"Spicy McCrispy", "Maharaja Mac", "4 piece Chicken Nuggets", "Big Mac", "Quarter Pounder with Cheese", "McCafe Iced coffee", "Sausage Burrito", "Egg mac Muffin"};
    vector<double> prices = {250, 400, 200, 350, 200, 150, 450, 300};
    vector<string> myOrder = {};
    double totalBill = 0;
    int gst = 8;
    int attempt = 0;
    while(attempt < 5){
        int op;
        cout<<"\n_____OUR MENU_____\n";
        for(int i=0; i<items.size(); i++){
            cout<<i+1<<". "<<items[i]<<": "<<prices[i]<<endl;
        }
        cout<<endl;
        cout<<"1. Order Your Item\n2. Display Your Ordered Items\n3. Payment\n4. Exit\n";
        cout<<"Choose an option: ";
        cin>>op;
        switch(op) {
        case 1:{
            string order;
            string wish;
            while(true){
                cin.ignore();
                cout<<"Enter Item name: ";
                getline(cin, order);
                auto it = find(items.begin(), items.end(), order);
                if(it != items.end()){
                    cout<<"Item Found.\n";
                    myOrder.push_back(order);
                }
                else{
                    cout<<"Item not found.\n";
                    continue;
                }
                cout<<"Do you want to order something(Yes/No): ";
                cin>>wish;
                for(char &c: wish) c = tolower(c);
                if(wish == "yes") continue;
                else if(wish == "no") break;
                else{
                    cout<<"Invalid!\n";
                }
            }
            break;
        }
        case 2:
            cout<<"\nMy Order:\n";
            for(int k=0; k<myOrder.size(); k++){
                cout<<k+1<<". "<<myOrder[k]<<endl;
            }
            break;
        case 3:{
            for(int j=0; j<myOrder.size(); j++){
                string target = myOrder[j];
                auto it = find(items.begin(), items.end(), target);
                if(it != items.end()){
                    int index = distance(items.begin(), it);
                    totalBill += prices[index];
                }
            }
            totalBill += totalBill * 8 / 100;
            cout<<"Your Total Bill is: "<<totalBill<<endl;
            break;
        }
        case 4:
            return 0;
        default:
            cout<<"Choose a valid option!\n";
        }
        attempt++;
    }
    return 0;
}