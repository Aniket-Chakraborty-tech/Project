#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<random>
#include<fstream>
#include<sstream>
using namespace std;

int main() {
    vector<int> nonACRoom;
    vector<int> acRoom;
    vector<string> customerName;
    vector<string> customerId;
    vector<int> bookedRoom;
    int attempt = 1;
    int totalBill = 0;

    // CREATE HOTEL ROOMS FOR BOTH AC AND NON-AC
    for(int a=1; a<=500; a++) {
        nonACRoom.push_back(a);
    }
    for(int b=501; b<=1000; b++) {
        acRoom.push_back(b);
    }
    // RANDOM NUBER GENERATOR
    random_device rd;
    mt19937 gen(rd());

    // NOW MOVE TO THE MAIN STRUCTUE
    while(attempt <= 10) {
        cout<<"\n_____WELCOME TO OUR HOTEL_____\n";
        cout<<"1. Book a Room\n2. Check Out\n3. Total Bill\n4. Booking Details\n5. Exit\n";
        int op;
        cout<<"Enter an Option: ";
        cin>>op;
        switch(op) {
            case 1:{
                // RENT FOR AC ROOM IS 2500 PER DAY AND FOR NON-AC IS 1500 PER DAY
                string room;
                cin.ignore();
                cout<<"Which Room you wanted(AC/ Non-AC)? ";
                getline(cin, room);
                for(auto &c : room) c = tolower(c);
                if(room == "ac"){
                    string name, id;
                    cout<<"Enter Your Name: ";
                    getline(cin, name);
                    customerName.push_back(name);
                    cout<<"Enter your Unique Id: ";
                    getline(cin, id);
                    customerId.push_back(id);
                    uniform_int_distribution<> distrib(0, acRoom.size() - 1);
                    int randomNo = distrib(gen);
                    int roomNumber = acRoom[randomNo];
                    cout<<"Your room number is "<<roomNumber<<"."<<endl;
                    bookedRoom.push_back(roomNumber);
                }
                else if(room == "non-ac"){
                    string name, id;
                    cout<<"Enter Your Name: ";
                    getline(cin, name);
                    customerName.push_back(name);
                    cout<<"Enter your Unique Id: ";
                    getline(cin, id);
                    customerId.push_back(id);
                    uniform_int_distribution<> distrib(0, nonACRoom.size() - 1);
                    int randomNo = distrib(gen);
                    int roomNumber = nonACRoom[randomNo];
                    cout<<"Your room number is "<<roomNumber<<"."<<endl;
                    bookedRoom.push_back(roomNumber);
                }
                else {
                    cout<<"Choose a valid Room."<<endl;
                }
            }
            break;
            
            case 2:{
                if(bookedRoom.empty()){
                    cout<<"No Room is currently Booked.\n";
                    break;
                }
                int no;
                cout<<"Enter Your Room Number for Check Out: ";
                cin>>no;
                auto it = find(bookedRoom.begin(), bookedRoom.end(), no);
                if(it != bookedRoom.end()){
                    bookedRoom.erase(it);
                }
                else{
                    cout<<"Room Number did not find.\n";
                }
                break;
            }

            case 3:{
                string roomType;
                int totalTimeSpend;
                cin.ignore();
                cout<<"Enter Your Room Type(AC/NON-AC): ";
                getline(cin, roomType);
                for(auto &c : roomType) c = tolower(c);
                if(roomType == "ac"){
                    cout<<"How many days you spend here? ";
                    cin>>totalTimeSpend;
                    totalBill += totalTimeSpend * 2500;
                }
                else if(roomType == "non-ac"){
                    cout<<"How many days you spend here? ";
                    cin>>totalTimeSpend;
                    totalBill += totalTimeSpend * 1500;
                }
                else{
                    cout<<"Invalid Room Type!\n";
                }
                cout<<"Your total Bill is: "<<totalBill<<"Rs.\n";
                break;
            }

            case 4: {
                if (customerName.empty()) {
                    cout << "No Bookings are done yet!\n";
                    break;
                }

                // Create or open file in append mode
                ofstream outFile("BookingDetails.txt");
                if (!outFile) {
                    cout << "Error opening file for writing.\n";
                    break;
                }

                cout << "\n_____BOOKING DETAILS_____\n";
                outFile << "\n_____BOOKING DETAILS_____\n";

                for (int a = 0; a < customerId.size(); a++) {
                    cout << "Customer Name: " << customerName[a]
                        << ", Customer Id: " << customerId[a]
                        << ", Room Number: " << bookedRoom[a] << endl;

                    outFile << "Customer Name: " << customerName[a]
                            << ", Customer Id: " << customerId[a]
                            << ", Room Number: " << bookedRoom[a] << "\n";
                }

                outFile.close();
                cout << "\nBooking details have been saved to 'BookingDetails.txt'.\n";

                // Automatically open the file (works on Windows)
                system("start BookingDetails.txt");
                break;
            }


            case 5:
                return 0;

            default:
                cout<<"Choose a valid option.\n";
        }
        attempt++;
    }
    return 0;
}