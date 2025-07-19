#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//! definition
class car
{
private:
    //?properties
    string brand;
    string model;
    int year;

    bool is_expired()
    {
        int current_year = 2025;
        return (current_year - year) > 15;
    }

public:
    //?methods
    void displayinfo()
    {

        cout << "brand : " << brand << endl;
        cout << "model : " << model << endl;
        cout << "yaer : " << year << endl;
        cout << "expired : " << (is_expired() ? "yes" : "no") << endl;
    }
    //! setters // getters
    void set_brand(string n)
    {
        n.erase(remove_if(n.begin(), n.end(), ::isdigitj), n.end());
        brand = n;
    }
    string get_brand()
    {
        return brand;
    }
};

int main()
{

    car car0;
    car car1;

    car0.set_brand("nisan4544845");
    car1.set_brand("mersides");

    car0.displayinfo();
    car1.displayinfo();
    return 0;
}