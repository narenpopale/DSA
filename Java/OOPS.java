
// Packeages - It contains related type of code or classes
// It has 2 Types - Built In and User Defined

// Importing Bank Package from bank folder
import java.beans.VetoableChangeListener;

import bank.Bank;

// Class 
class Pen {
    // Properties Or Attributes
    String color;
    String type;

    // Methods or Functions
    public void printColor(){
        // this Keyword - It is used for showing which object calls this method.
        System.out.println(this.color);
    }
    
    // Constructors - 3 Types
    // 1. Non - Parameterized Constructor
    // 2. Parameterized Constructor
    // 3. Copy Constructor

    // Destructors - which destroys unused object and variables
    // In java there is no need of Destructors because java has Garbage Collector which automatically destroys unused items


    // Access Modifiers - It defines Accessibility
    // 1. Default - By Default this modifier get applied to any function or property, it is accessible whithin a package only
    // 2. Public - It is accessible within a package as well as outside the package
    // 1. Protected - It is accessible within a package as well as outside the package but only sub class have a access
    // 1. Private - It is accessible within a class only


    private String password;

    // Getters - It is used for Access the private properties
    public String getPassword(){
        return this.password;
    }

    // Setters - It is used for setting the private properties
    public void setPassword(String pass){
        this.password = pass;
    }


    // Parameterized Constructor
    Pen(String color, String type) {
        this.color = color;
        this.type = type;
    }
    
    // Copy Constructor
    Pen(Pen p) {
        this.color = p.color;
        this.type = p.type;
    }
}


// 4 Topics in OOPS
// 1. Abstraction
// 2. Encapsulation
// 3. Inheritance
// 4. Polymorphism


// Encapsulation - It is a set of properties and methods which are in a single unit called class
// It is nothing but classes and Objects


// Polymorphism - It has 2 types
// 1. Function Overloading (Complie Time Polymorphism)
// 2. Function Overriding (Run Time Polymorphism)


// 1. Function Overloading (Complie Time Polymorphism)
// In this type, function names are same but its parameters or its return types should be different
class Student {

    String name;
    int age;

    public void printInfo(String name){
        System.out.println(name);
    }

    public void printInfo(int age){
        System.out.println(age);
    }

    public void printInfo(String name,int age){
        System.out.println(name + " " + age); 
    }

}



// Inheritance - It has 4 Types
// sub class inherits properties or methods from the base class

// 1. Single Level Inheritance and 2. Multi Level Inheritance
class Shape {
    public void printArea(){
        System.out.println("Prints Area");
    }
}

class Triangle extends Shape {
    public void printArea(int l,int h){
        System.out.println(l*h);
    }
}

class EquilateralTriangle extends Triangle {
    public void printArea(int l,int h){
        System.out.println(l*h);
    }    
}


// 3. Hierarchial Inheritance - Base class Inherited by multiple sub classes
class Circle extends Shape {
    public void printArea(int r){
        System.out.println((3.14)*r*r);
    }   
}


// 4. Hybrid Inheritance - It is combination of all Inheritances


// Interfaces - It completely hides unusefull data

// 5. Multiple Inheritance - Single Sub class inherits properties of 2 base classes
// In java Multiple Inheritance implemented by Interfaces


interface Vehicle {
    void wheels();
}

interface Company {
    void name();
}

class Car implements Vehicle, Company {
    public void wheels(){
        System.out.println("Car has 4 wheels");
    }

    public void name(){
        System.out.println("BMW"); 
    }
}


// Abstraction - It hides unimportant information.
// It is just a thought, it exist but it can not be implemented

abstract class Animal {
    Animal(){
        System.out.println("Animal Constructor");
    }

    abstract void walk();
}

class Horse extends Animal {
    // Constructor Chaining - One by One constructor gets called in Inheritance
    Horse(){
        System.out.println("Horse Construcator");
    }

    public void walk(){
        System.out.println("It walks on 4 legs");
    }
}


class OOPS {

    // Static Keyword - It is used for common entities for ex. School is same for all the students

    public static void main(String[] args) {
        
        // Object 1 of Class Pen
        // new Keyword - This keyword reserve space in the heap memory for this object
        Pen pen1 = new Pen("blue", "ball");
        pen1.printColor();

        pen1.setPassword("abcd");
        System.out.println(pen1.getPassword());
        
        // Object 2 of Class Pen
        Pen pen2 = new Pen(pen1);
        pen2.printColor();


        // Object 1 of Class Student
        Student s1 = new Student();
        s1.name = "naren";
        s1.age = 20;
        
        // Function Overloading
        s1.printInfo(s1.name);
        s1.printInfo(s1.age);
        s1.printInfo(s1.name, s1.age);

        // Single Level Inheritance
        Triangle t1 = new Triangle();
        t1.printArea(4,5);
        
        // Object of Imported Class
        Bank b1 = new Bank(); 
        b1.name = "BOM";
        
        // Object of class Horse
        Horse h1 = new Horse();
        h1.walk();
    }
}