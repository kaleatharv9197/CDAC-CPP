#include <iostream>
using namespace std;
class Inches;   // Forward declaration
class Feet{
private:
    int feet;
public:
    Feet(int f){
        feet = f;
    }
    friend void addDistance(Feet, Inches);
};
class Inches{
private:
    int inches;
public:
    Inches(int i){
        inches = i;
    }
    friend void addDistance(Feet, Inches);
};
void addDistance(Feet f, Inches i){
    // Accessing private members of both classes
    int totalFeet = f.feet;
    int totalInches = i.inches;
    // Convert every 12 inches into 1 foot
    totalFeet = totalFeet + (totalInches / 12);
    totalInches = totalInches % 12;
    cout << "Distance: " << totalFeet
         << " Feet " << totalInches
         << " Inches" << endl;
}
int main(){
    Feet f(8);
    Inches i(15);
    addDistance(f, i);
    return 0;
}