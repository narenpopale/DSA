#include<bits/stdc++.h>
using namespace std;


// Encapsulation
class Student {
    private:
    string name;
    int rollNo;

    public:
    string getName() {
        return this -> name;
    }
};


// Inheritance

// 1. Single inheritance
class Human {
    public:
    int height;
    int weight;

    private:
    int age;

    public:
    int getAge() {
        return this -> age;
    }
};

class Male: public Human {
    public:
    string color;

    public:
    void sleep() {
        cout << "Male is sleeping" << endl;
    }

};


// 2. Multi-level inheritance
class A {

};

class B: public A {

};

class C: public B {

};


// 3. Multiple inheritance
class A {

};

class B {

};

class C: public A, public B {

};


// 4. Hierarchical inheritance
class A {

};

class B: public A {

};

class C: public A {

};


// 5. Hybrid inheritance
class A {

};

class D {

};

class B: public A {

};

class C: public A, public D {

};


// Inheritance Ambiguity
class One {
    public:
    void func() {
        cout << "One" << endl;
    }
};

class Two {
    public:
    void func() {
        cout << "Two" << endl;
    }
};

class Three: public One, public Two {

};



// Polymorphism

// 1.Compile Time 

class Function_Overloading {

    public:
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }

};

class Operator_Overloading {

    public:
    int a = 0;

    int operator+ (Operator_Overloading &obj) {
        int value1 = this -> a;
        int value2 = obj.a;

        cout << value2 - value1 << endl;
    }

};


// 2. Run Time 

class Numbers {
    public:
    int add(int a, int b) {

    }
};

class Method_Overriding {

    public:
    int add(int a, int b) {
        return a + b;
    }
    
};


int main() {

    Male m1;
    cout << m1.height << endl;
    m1.sleep();


    // Inheritance Ambiguity
    Three obj;
    // Ambiguity
    // obj.func();
    obj.One::func();


    // Operator Overloading
    Operator_Overloading obj1, obj2;
    obj1.a = 3;
    obj2.a = 4;

    obj1 + obj2;

    return 0;
}