#include <iostream>
using namespace std;
struct rectangle {
double length;
double width;

   double calculateArea(){
        return length * width;
   }
   double calculatePerimeter(){
        return 2*(length+width);
   }
};
int main(){
    rectangle ret;
    ret.length =4.5;
    ret.width = 3.2;
    cout<<ret.calculateArea();
    return 0;
}


--------------------------------------

Write a C++ program using hybrid inheritance to create a base class 
called Person with common attributes, derive two classes Student and 
Employee from it, and create a class Manager that inherits from both 
Student and Employee, representing a person who is both a student 
and an employee?______________________________________


#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string _name, int _age) : name(_name), age(_age) {}

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
protected:
    int studentId;

public:
    Student(string _name, int _age, int _studentId) : Person(_name, _age), studentId(_studentId) {}

    void displayInfo() {
        Person::displayInfo();
        cout << "Student ID: " << studentId << endl;
    }
};

class Employee : public Person {
protected:
    string companyId;

public:
    Employee(string _name, int _age, string _companyId) : Person(_name, _age), companyId(_companyId) {}

    void displayInfo() {
        Person::displayInfo();
        cout << "Company ID: " << companyId << endl;
    }
};

class Manager : public Student, public Employee {
public:
    Manager(string _name, int _age, int _studentId, string _companyId)
        : Student(_name, _age, _studentId), Employee(_name, _age, _companyId) {}

    void displayInfo() {
        Student::displayInfo();
        Employee::displayInfo();
    }
};

int main() {
    Manager manager("Mohamed", 21, 10, "CC");

    cout << "Manager Information:" << endl;
    manager.displayInfo();

    return 0;
}



----------------------------------------------------------------



Write a C++ program that takes an array of floating-point numbers 
as input and finds the average of the values using a separate 
function?____________________________________



#include <iostream>
using namespace std;


float calculateAverags (float arr[], int size){
    float sum =0.0;
    for (int i = 0; i< size; i++){
    sum+=arr[i];
    }
    return sum /size;
}
int main(){
    int SIZE = 5;
    float numbers[SIZE];

    cout <<"Enter " << SIZE  <<" floating-point numbers:" <<endl;
    for (int i=0;i<SIZE;i++){
    cout<< "Number "<<i+1<<":";
    cin>>numbers[i];
    }

    float average = calculateAverags (numbers, SIZE);
    cout << "The average of the numbers is : " << average<<endl;
    return 0;
}




-------------------------------------------------------------------


Write a C++ program to find the largest element in an array?
_____________________________________


#include <iostream>
using namespace std;

int main() {
    int arr[20],largest =  arr[0],size;
    cout << " Enter the size of the array : ";
    cin >> size;
    cout << " Enter the elements of the array : ";
    for(int i=0;i<=4;i++){
        cin >> arr[i];
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
     cout <<"largest number is : "<< largest;

    return 0;
}



--------------------------------------------------------------------

Write a C++ program to model a bank account using a class. Include 
member functions to deposit and withdraw money and to display 
the current balance?_____________________________


#include <iostream>
using namespace std;
class BankAccount {
private:
    string accountNumber;
    double balance;
public:
BankAccount (string accNum, double initBalance) {

     accountNumber = accNum;
     balance = initBalance;
}
void deposit (double amount) {

    balance += amount;
    cout<<"Deposit of $"<< amount <<"successful." << endl;
}
void withdraw (double amount) {

    if (amount <= balance) {
    balance -=amount;
    cout<<"Withdrawal of $" << amount << " successful." << endl;
    }
    else {
        cout<<"Insufficient balance. Withdrawal failed." << endl;
    }
}
void displayBalance () {
    cout<<"Current balance: $" << balance << endl;
}
};
int main() {
    string accountNumber;
    double initialBalance;
    cout<<"Enter the account number: ";
    cin >> accountNumber;

    cout<<"Enter the initial balance: $";
    cin>> initialBalance;

    BankAccount account (accountNumber, initialBalance);

    double depositAmount, withdrawAmount;
    cout<<"Enter the amount to deposit: $";
    cin >> depositAmount;
    account.deposit (depositAmount);
    cout << "Enter the amount to withdraw: $"; cin>> withdrawAmount;
    account.withdraw (withdrawAmount);
    account.displayBalance ();
    return 0;
}

----------------------------------------------------------------
Write A C++ program that calculate the area of 2 circles with 
radiuses 5,3 by Creating a Class and Objects?___________________

#include <iostream>
class Circle{

private:
    double radius;

public:
    void setRadius(double radius){
        this->radius = radius;
    }
    double getArea(){
        return 3.14 * radius * radius;

    }

};
using namespace std;

int main()
{
    Circle circle1;
    Circle circle2;

    circle1.setRadius(5);
    circle2.setRadius(3);

    cout << circle1.getArea() <<endl;
    cout << circle2.getArea() <<endl;
    return 0;
}

----------------------------------------------------------------
Write Ac++ program that calculate the area of 2 Shapes
(rectagle&triangle) from class Shape?___________________

#include <iostream>
class Shape{
protected:
    double width;
    double height;

public:
    void setWidth(double width){
        this->width = width;
    }
    void setHeight(double height){
        this->height = height;
    }
    double getArea(){
        return 0.0;
    }
};
class Rectangle : public Shape{
public:
    double getArea(){
        return width * height;
    }
};
class Treangle : public Shape{
public:
    double getArea(){
        return 0.5 * width * height;
    }

};

using namespace std;

int main()
{
    Rectangle rectangle;
    Treangle treangle;

    treangle.setWidth(5);
    rectangle.setWidth(5);
    treangle.setHeight(3);
    rectangle.setHeight(3);

    cout << treangle.getArea() <<endl;
    cout << rectangle.getArea() <<endl;
    return 0;
}

----------------------------------------------------------------

Write a C++ program that represents a book using a class called 
"Book." The class should have data members for the book title, 
author, and publication year. Include a constructor to initialize these 
values and a member function to display the book details? ____________________________

#include <iostream>
#include <string>
using namespace std;
class Book{
private:
    string title;
    string author;
    int publicationYear;

public:
    Book(string title,string author,int publicationYear){
        this->title = title;
        this->author = author;
        this->publicationYear = publicationYear;
    }
    void setTitle( string title){
        this->title = title;
    }
    void setAuthor( string author){
        this->author = author;
    }
    void setPublicationYear( int publicationYear){
        this->publicationYear = publicationYear;
    }
    void getDetails(){
        cout<< "Title is : " << title << endl;
        cout<< "Author is : " << author << endl;
        cout<< "PublicationYear is : " << publicationYear << endl;
    }
};


int main()
{
    cout << "--------------- before Update -------------" << endl;
    //before update
    Book book("Death" , "Mido" , 2003 );
    book.getDetails();
    cout << "--------------- after Update -------------" << endl;
    //after update
    book.setAuthor("Mohamed");
    book.setTitle("Live");
    book.setPublicationYear(2002);
    book.getDetails();



    return 0;
}

----------------------------------------------------------------

Write a C++ program that demonstrates the use of the scope 
resolution operator to access a member function of a base class from 
a derived class? __________________

#include <iostream>
#include <string>
using namespace std;
class Base{

public:

    void baseFunction(){
        cout << "member of base function" << endl;
    }
};

class Derived : Base {

public:

    void derivedFunction(){
        cout << "member of derived function" << endl;
        Base::baseFunction();
    }
};

int main()
{

    Derived dobj;
    dobj.derivedFunction();
    
    return 0;
}

-----------------------------------------------------------------
Write a C++ program that takes an array of floating-point numbers 
as input and finds the average of the values using a separate 
function?______________________________


#include <iostream>
#include <string>
using namespace std;
class Student{

private:

    string name;
    int age;
    char grade;

public:

    Student(string name,int age,char grade){

        this->name = name;
        this->age = age;
        this->grade = grade;
    }

    void setName(string name){
        this->name = name;
    }

    void setAge(int age){
        this->age = age;
    }

    void setGrade(char grade){
        this->grade = grade;
    }

    void getDetails(){

        cout << "your name is : " << name << endl;
        cout << "your age is : " << age << endl;
        cout << "your grade is : " << grade << endl;
    }

};

int main()
{

    Student student("mido",21,'E');
    student.getDetails();

    return 0;
}


------------------------------------------------------------

Can you provide an example of using an enum to represent 
different colors, including constants for common colors, and a 
function to print the color name based on user input?_________x


#include <iostream>
#include <string>
using namespace std;

enum Colors{

    RED,
    YELLOW,
    GREEN,
};
void printColorName(Colors colors){
        switch (colors){

        case RED:
            cout << " Red" << endl;
            break;
        case YELLOW:
            cout << " YELLOW" << endl;
            break;
        case GREEN:
            cout << " GREEN" << endl;
            break;
        default:
            cout << " Unknown color" << endl;
            break;
        }
    }
int main()
{
    cout << " 0 : red | 1 : YELLOW | 2 : GREEN "<<endl;
    cout << " enter number from 0 to 2 : "<<endl;

    int colorNum;
    cin >> colorNum;

    Colors selectedColor = static_cast<Colors>(colorNum);
    cout << "color is : ";
    printColorName(selectedColor);
    return 0;
}

--------------------------------------------------------------
