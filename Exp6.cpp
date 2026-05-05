#include<iostream>
using namespace std;

#define SIZE 5

struct Client {
    long int phone;
    string name;
};

Client LP[SIZE], QP[SIZE];

// initialize
void init() {
    for(int i=0;i<SIZE;i++) {
        LP[i].phone = -1;
        QP[i].phone = -1;
    }
}

// LINEAR INSERT
void insertLP(long int phone, string name) {
    int i = phone % SIZE;

    while(LP[i].phone != -1)
        i = (i + 1) % SIZE;

    LP[i] = {phone, name};
}

// LINEAR SEARCH
void searchLP(long int phone) {
    int i = phone % SIZE, count = 0;

    while(LP[i].phone != -1) {
        count++;
        if(LP[i].phone == phone) {
            cout<<"Found in "<<count<<" comparisons\n";
            return;
        }
        i = (i + 1) % SIZE;
    }
    cout<<"Not Found\n";
}

// QUADRATIC INSERT
void insertQP(long int phone, string name) {
    int i = phone % SIZE, j = 1;

    while(QP[i].phone != -1) {
        i = (i + j*j) % SIZE;
        j++;
    }

    QP[i] = {phone, name};
}

// QUADRATIC SEARCH
void searchQP(long int phone) {
    int i = phone % SIZE, j = 1, count = 0;

    while(QP[i].phone != -1) {
        count++;
        if(QP[i].phone == phone) {
            cout<<"Found in "<<count<<" comparisons\n";
            return;
        }
        i = (i + j*j) % SIZE;
        j++;
    }
    cout<<"Not Found\n";
}

// DISPLAY
void display(Client A[]) {
    for(int i=0;i<SIZE;i++)
        cout<<i<<" -> "<<A[i].phone<<" "<<A[i].name<<endl;
}

int main() {
    init();
    int ch;
    long int p;
    string n;

    do {
        cout<<"\n1.Add 2.Display 3.Search 4.Exit\n";
        cin>>ch;

        switch(ch) {
            case 1:
                cout<<"Enter phone & name: ";
                cin>>p>>n;
                insertLP(p,n);
                insertQP(p,n);
                break;

            case 2:
                cout<<"\nLinear:\n";
                display(LP);
                cout<<"\nQuadratic:\n";
                display(QP);
                break;

            case 3:
                cout<<"Enter phone: ";
                cin>>p;
                cout<<"Linear -> "; searchLP(p);
                cout<<"Quadratic -> "; searchQP(p);
                break;
        }
    } while(ch!=4);

    return 0;
}
