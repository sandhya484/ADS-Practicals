#include<iostream>
#include<fstream>
using namespace std;

struct Emp {
    int id;
    string name, desig;
    float salary;
};

// INSERT
void add() {
    Emp e;
    ofstream f("emp.txt", ios::app);

    cout<<"Enter id name desig salary: ";
    cin>>e.id>>e.name>>e.desig>>e.salary;

    f<<e.id<<" "<<e.name<<" "<<e.desig<<" "<<e.salary<<"\n";
    f.close();
}

// DISPLAY
void display() {
    Emp e;
    ifstream f("emp.txt");

    while(f>>e.id>>e.name>>e.desig>>e.salary) {
        cout<<e.id<<" "<<e.name<<" "<<e.desig<<" "<<e.salary<<endl;
    }
    f.close();
}

// SEARCH
void search(string name) {
    Emp e;
    ifstream f("emp.txt");

    while(f>>e.id>>e.name>>e.desig>>e.salary) {
        if(e.name == name) {
            cout<<"Found: "<<e.id<<" "<<e.name<<" "<<e.desig<<" "<<e.salary<<endl;
            return;
        }
    }
    cout<<"Not Found\n";
    f.close();
}

// DELETE
void del(string name) {
    Emp e;
    ifstream f("emp.txt");
    ofstream temp("temp.txt");

    while(f>>e.id>>e.name>>e.desig>>e.salary) {
        if(e.name != name)
            temp<<e.id<<" "<<e.name<<" "<<e.desig<<" "<<e.salary<<"\n";
    }
    f.close();
    temp.close();

    remove("emp.txt");
    rename("temp.txt","emp.txt");
}

// UPDATE
void update(string name) {
    Emp e;
    ifstream f("emp.txt");
    ofstream temp("temp.txt");

    while(f>>e.id>>e.name>>e.desig>>e.salary) {
        if(e.name == name) {
            cout<<"Enter new data: ";
            cin>>e.id>>e.name>>e.desig>>e.salary;
        }
        temp<<e.id<<" "<<e.name<<" "<<e.desig<<" "<<e.salary<<"\n";
    }
    f.close();
    temp.close();

    remove("emp.txt");
    rename("temp.txt","emp.txt");
}

int main() {
    int ch;
    string name;

    do {
        cout<<"\n1.Add 2.Display 3.Search 4.Update 5.Delete 6.Exit\n";
        cin>>ch;

        switch(ch) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: cout<<"Enter name: "; cin>>name; search(name); break;
            case 4: cout<<"Enter name: "; cin>>name; update(name); break;
            case 5: cout<<"Enter name: "; cin>>name; del(name); break;
        }
    } while(ch!=6);

    return 0;
}
