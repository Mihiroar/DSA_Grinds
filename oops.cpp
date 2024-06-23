// #include <iostream>
// #include <string>
// using namespace std;

// class Teacher {
//   private:
//   double salary;

//   public:
//   string name;
//   string dept;
//   string subject;
//   // non-parameterized constructor
//   Teacher() {
//     // cout << "Hello, I am constructur\n";
//     dept = "Computer Science";
//   }

//   //parameterized constructor
//   Teacher(string name, string dept, string subject, double salary) {
//     this->name = name;
//     this->dept = dept;
//     this->subject = subject;
//     this->salary = salary;
//   }

//   //copy constructor
//   Teacher(Teacher &orgObj) {
//     cout << "i am custom copy constructor\n";
//     this->name = orgObj.name;
//     this->dept = orgObj.dept;
//     this->subject = orgObj.subject;
//     this->salary = orgObj.salary;
//   }

//   void changeDept(string newDept) {
//     dept = newDept;
//   }
// //setter fn
//   void setSalary(double s){
//     salary = s;
//   }
// //getter fn
//   double getSalary() {
//     return salary;
//   }

//   void getInfo() {
//     cout << "name : " << name << endl;
//     cout << "dept : " << dept << endl;
//     cout << "subject : " << subject << endl;
//     cout << "salary : " << salary << endl;
//   }
// };

// int main() {
//   Teacher t1("David","Computer Science","C++",25000); //constructor call
//   // Teacher t2(t1); // default copy constructor call
//   //t1.getInfo();
//   Teacher t2(t1); //custom copy constructor call
//   t2.getInfo();
//   // t1.name = "David";
//   // t1.dept = "Computer Science";
//   // t1.subject = "C++";
//   // t1.setSalary(25000);

//   // cout << t1.name << endl;
//   // cout << t1.getSalary() << endl;
//   // cout << t1.dept << endl;
//   return 0;
// }

// Above all we learnt class(inside this data/props/attributes and methods/member functions),objects,access specifiers, setter and getter functions in C++.

// Encapsulation concept beloe:
//  #include <iostream>
//  #include <string>
//  using namespace std;

// class Account {
//   private:
//   double balance;
//   string password; //data hiding

//   public:
//   string accountId;
//   string username;
// };

// Shallow and Deep Copy
//  #include <iostream>
//  #include <string>
//  using namespace std;

// class Student {
//   public:
//   string name;
//   double *cgpaPtr;

//   Student(string name, double cgpa) {
//     this->name = name;
//     cgpaPtr = new double;
//     *cgpaPtr = cgpa;
//   }

//   Student(Student &obj) {
//     cout << "i am custom copy constructor\n";
//     this->name = obj.name;
//     cgpaPtr = new double;
//     *cgpaPtr = *obj.cgpaPtr;
//   }

//   void getInfo() {
//     cout << "name : " << name << endl;
//     cout << "cgpa : " << *cgpaPtr << endl;
//   }
// };

// int main() {
//   Student s1("Rahul Kumar", 8.9);
//   Student s2(s1); //neha kumar

//   s1.getInfo();
//   *(s2.cgpaPtr) = 9.5;
//   s1.getInfo();

//   s2.name = "neha kumar";
//   s2.getInfo();
//   return 0;
// }

// Destructor

// #include <iostream>
// #include <string>
// using namespace std;

// class Student {
//   public:
//   string name;
//   double *cgpaPtr;

//   Student(string name, double cgpa) {
//     this->name = name;
//     cgpaPtr = new double;
//     *cgpaPtr = cgpa;
//   }

//   ~Student() {
//     cout << "Hii, I am destructor\n";
//     delete cgpaPtr;
//   }

//   void getInfo() {
//     cout << "name : " << name << endl;
//     cout << "cgpa : " << *cgpaPtr << endl;
//   }
// };

// int main() {
//   Student s1("Rahul Kumar", 8.9);
//   s1.getInfo();
//   return 0;
// }

// Inheritance

// #include <iostream>
// #include <string>
// using namespace std;

// class Person
// {
// public:
//   string name;
//   int age;

//   Person(string name, int age)
//   {
//     this->name = name;
//     this->age = age;
//   }

//   //   Person() {
//   //     cout << "I am parent constructor\n";
//   //   }
// };

// class Student : public Person
// {
// public:
//   int rollno;

//   Student(string name, int age, int rollno) : Person(name, age)
//   {
//     this->rollno = rollno;
//   }

//   void getInfo()
//   {
//     cout << "name : " << name << endl;
//     cout << "age : " << age << endl;
//     cout << "rollno : " << rollno << endl;
//   }
// };

// int main()
// {
//   // s1.name = "rahul kumar";
//   // s1.age = 22;
//   // s1.rollno = 1234;
//   Student s1("rahul kumar", 21, 1234);

//   s1.getInfo();
//   return 0;
// }

// Multi - level

// #include <iostream>
// #include <string>
// using namespace std;

// class Person
// {
// public:
//   string name;
//   int age;
// };

// class Student : public Person
// {
// public:
//   int rollno;
// };

// class GradStudent : public Student{
//   public:
//   string researchArea;
// };

// int main()
// {
//   GradStudent s1;
//   s1.name = "tony stark";
//   s1.researchArea = "AI";
//   cout << s1.name << endl;
//   cout << s1.researchArea << endl;
//   return 0;
// }


// multiple inheritance

// #include <iostream>
// #include <string>
// using namespace std;


// class Student{
//   public:
//   string name;
//   int rollno;
// };

// class Teacher {
//   public:
//   string subject;
//   double salary;
// };

// class TA : public Student, public Teacher {
// };

// int main()
// {
//   TA t1;
//   t1.name = "tony stark";
//   t1.subject = "engg";

//   cout << t1.name << endl;
//   cout << t1.subject << endl;
//   return 0;
// }

//Hierarchical Inheritance

// #include <iostream>
// #include <string>
// using namespace std;

// class Person {
//   public:
//   string name;
//   int age;
// };

// class Student : public Person {
//   public:
//   int rollno;
// };

// class Teacher : public Person {
//   public:
//   string subject;
// };


//Polymorphism (Covering  example of constructor overloading which is compile time polymorphism)
// #include <iostream>
// #include <string>
// using namespace std;

// class Student {
//   public:
//   string name;

//   Student() {
//     cout << "non-parameterized constructor\n";
//   }
//   Student(string name){
//     this->name = name;
//     cout << "parameterized constructor\n";
//   }

// };


// int main()
// {
//   Student s1("rahul");
//   return 0;
// }

// Function Overloading Example

// #include <iostream>
// #include <string>
// using namespace std;

// class Print{
//   public:
//   void show(int x){
//     cout << "int: " << x << endl;
//   }

//   void show(char ch){
//     cout << "char: " << ch << endl;
//   }
// };


// int main()
// {
//   Print p1;
//   p1.show(10);
//   p1.show('a');
//   return 0;
// }

// Function Overriding Example of Run TIme Polymorphism

// #include <iostream>
// #include <string>
// using namespace std;

// class Parent{
//   public:
//   void getInfo(){
//     cout << "I am parent class\n";
//   }
// };

// class Child : public Parent{
//   public:
//   void getInfo(){
//     cout << "I am child class\n";
//   }
// };

// int main(){
//   // Child c1;
//   // c1.getInfo();
//   Parent p1;
//   p1.getInfo();
//   return 0;
// }

// Virtual Function example

// #include <iostream>
// #include <string>
// using namespace std;

// class Parent{
//   public:
//   void getInfo(){
//     cout << "I am parent class\n";
//   }

//   virtual void hello() {
//     cout << "Hello from parent\n";
//   }
// };

// class Child : public Parent{
//   public:
//   void getInfo(){
//     cout << "I am child class\n";
//   }

//   void hello() {
//     cout << "Hello from child\n";
//   }
// };

// int main(){
//   Child c1;
//   c1.hello();
//   return 0;
// }

// Abstract Class Implementation

// #include <iostream>
// #include <string>
// using namespace std;

// class Shape {
//   virtual void draw() = 0; //pure virtual function turns automatically class into abstract class
// };

// class Circle : public Shape {
//   public:
//   void draw(){
//     cout << "Drawing Circle\n";
//   }
// };

// int main(){
//   Circle c1;
//   c1.draw();
//   return 0;
// }

// Static Keyword