/*
Sample Input:
4
1
Walter 56 99
2
Jesse 18 50 48 97 76 34 98
2
Pinkman 22 10 12 0 18 45 50
1
White 58 87

Sample Output:
Walter 56 99 1
Jesse 18 403 1
Pinkman 22 135 2
White 58 87 2
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{

public:
    string name;
    int age;
    
    virtual void getdata() {
        cin >> name >> age;    
    }
    
    virtual void putdata() {
        cout << name << " " << age << " ";
    }
};

class Professor:public Person {

private:
    int publications;
    static int cur_id;
    int id;
public:
    
    void getdata(){
        Person::getdata();
        cin >> publications;
        id = ++cur_id;
    
    }
    void putdata(){
        Person::putdata();
        cout << publications << " " << id << endl;
    }
    
};

int Professor::cur_id = 0;

class Student:public Person {
private:
    int mark[6];
    static int cur_id;
    int id;
public:
    void getdata() {
       Person::getdata();
       for(int i=0; i<6; i++){
           cin >> mark[i];
       }
    
       id = ++cur_id;
    }
    
    void putdata() {
        int sum = 0;
        for(int i=0; i<6; i++){
            sum += mark[i];
        }
        
        Person::putdata();
        cout << sum << " " << id << endl;
    }
    
};
int Student::cur_id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}