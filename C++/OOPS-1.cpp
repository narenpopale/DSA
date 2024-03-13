#include<bits/stdc++.h>
using namespace std;


class Hero {

    public:
    int health;
    char *address;

    // Static Data Members
    static string gameName;

    // Static Functions
    static string random() {
        return gameName;
    }

    // Constructor
    Hero() {
        cout << "constructor called" << endl;
        address = new char[10];
    }

    // Parameterized Constructor
    Hero(int health) {
        cout << "Address of this : " << this << endl;
        this -> health = health;
    }

    // Copy Constructor
    Hero(Hero &h) {

        // Deep Copy
        char *temp = new char[10];
        strcpy(temp, h.address);
        this -> address = temp;

        this -> health = h.health;
        this -> name = h.name;
        this -> level = h.level;
    }

    // Access Modifiers
    // 1. Public
    public:
    int level;

    // 2. Private - default
    private:
    string name;


    public:
    // Getter Method 
    string getName() {
        return name;
    }

    // Setter Method 
    void setName(string n) {
        name = n;
    }

    // Destructor
    ~Hero() {
        cout << "Destructor Called" << endl;
    }

};


// Initializing static data members
string Hero::gameName = "PUBG";
// (::) scope resolution operator


int main() {

    // Object of Hero class
    Hero h1(2);

    cout << "address of current object : " << &h1 << endl;

    // Empty class always have size 1 byte
    cout << "size : " << sizeof(h1) << endl;


    // (.) is used to access properties
    h1.level = 1;
    cout << h1.level << endl;


    // Using Getters and Setters
    h1.setName("aluva");
    cout << "Name : " << h1.getName() << endl;


    // Dynamic allocation in heap
    Hero *h2 = new Hero;

    (*h2).setName("chiru");
    cout << "Name : " << (*h2).getName() << endl;

    // or

    h2 -> setName("vyankat");
    cout << "Name : " << h2 -> getName() << endl;

    delete h2;


    // Copy Constructor
    Hero ram;
    ram.setName("Ram");
    Hero sham(ram);
    
    cout << sham.getName() << endl;


    // Shallow Copy - for default copy constructor
    // Hero R;
    // char address[5] = "pune";
    // R.address = address;
    // Hero S(R);

    // R.address[0] = 'b';

    // cout << S.address << endl;


    // Deep Copy - for manul copy constructor
    Hero R;
    char address[5] = "pune";
    R.address = address;

    Hero S(R);

    R.address[0] = 'b';

    cout << S.address << endl;


    // Copy Assignment Operator
    Hero a;
    Hero b;
    a = b;


    // Destructor
    Hero hero1; // Static Allocation
    Hero *hero2 = new Hero(); // Dynamic Allocation

    // manually destructor call
    delete hero2;


    // Accessing static data members
    cout << Hero::gameName << endl;

    // Accessing static functions
    cout << Hero::random() << endl;

    return 0;
}