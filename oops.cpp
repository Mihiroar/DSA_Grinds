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

//Above all we learnt class(inside this data/props/attributes and methods/member functions),objects,access specifiers, setter and getter functions in C++.

//Encapsulation concept beloe:
// #include <iostream>
// #include <string>
// using namespace std;

// class Account {
//   private:
//   double balance;
//   string password; //data hiding

//   public:
//   string accountId;
//   string username;
// };


//Shallow and Deep Copy
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

//Destructor

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
