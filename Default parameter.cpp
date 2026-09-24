#include <iostream>
#include <string>

using namespace std;

void display(string name,string nationality ="Indian"){
    cout << "Name: " << name << endl;
    cout << "Nationality: " << nationality << endl;
}

int main(){
    string name, nationality;
    int choice;
    cout<<"Enter 1 for name only" <<endl;
    cout<<"Enter 2 for name and nationality" <<endl;
    cin>>choice;
    cin.ignore();
    cout <<"Name: ";
    getline(cin,name);
    if(choice == 1) {
        display(name);
    }
    else if(choice == 2){
        cout << "Nationality: ";
        getline(cin, nationality);

        display(name, nationality);
    }
    else {
        cout << "Invalid choice";
    }

    return 0;
}