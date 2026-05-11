#include <bits/stdc++.h>

using namespace std;


struct patient {
    int id;
    string name;
    int severity;
    int arrival_time;

    patient(int idd , string namee , int sevirity , int arrival_timee){
        id = idd;
        name = namee;
        severity = sevirity;
        arrival_time = arrival_timee;
    }

    void print(patient p){
        cout << "ID: " << p.id << endl;
        cout << "Name: " << p.name << endl;
        cout << "Severity: " << p.severity << endl;
        cout << "Arrival Time: " << p.arrival_time << endl;
    }
    bool operator<(const patient& other) const {
        if (severity != other.severity)
            return severity < other.severity;
        else
            return arrival_time > other.arrival_time;
    }
};


   


int main(){

     int id , sevirity , arrival_time;
    string name;
    priority_queue<patient>patients;

    for (int i = 0 ; i < 6;i++){
        cout<<"Enter Patient id: \n";
        cin>>id;
        cout<<"Enter Patient name: \n";
        cin>>name;
        cout<<"Enter Patient severity: \n";
        cin>>sevirity;
        cout<<"Enter Patient arrival time: \n";
        cin>>arrival_time;
        patient p(id , name , sevirity , arrival_time);
        patients.push(p);
    }
    while(true){
        cout<<"1- View next patient\n";
        cout<<"2- Treat next patient\n";
        cout<<"3- Update severity\n";
        cout<<"4- Display all patients\n";
        cout<<"5- Insert new patient\n";
        cout<<"6- Exit\n";
        int choice;
        cin>>choice;
        if (choice == 1){
            patient p = patients.top();
            p.print(p);
        }
        else if (choice == 2){
            patients.pop();
        }
        else if (choice == 3){
            int id , newSevirity;
            cout<<"Enter Patient id: \n";
            cin>>id;
            cout<<"Enter new severity: \n";
            cin>>newSevirity;
            priority_queue<patient>temp;
            while (!patients.empty()) {
                patient p = patients.top();
                patients.pop();
                if (p.id == id) {
                    p.severity = newSevirity;
                }
                temp.push(p);
            }
            patients = temp;
        }
        else if (choice == 4){
            priority_queue<patient>temp = patients;
            while (!temp.empty()) {
                patient p = temp.top();
                temp.pop();
                p.print(p);
            }
        }
        else if (choice == 5){
            cout<<"Enter Patient id: \n";
            cin>>id;
            cout<<"Enter Patient name: \n";
            cin>>name;
            cout<<"Enter Patient severity: \n";
            cin>>sevirity;
            cout<<"Enter Patient arrival time: \n";
            cin>>arrival_time;
            patient p(id , name , sevirity , arrival_time);
            patients.push(p);
        }
        else if (choice == 6){
            break;
        }
    }

    return 0;
}