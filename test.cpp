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
        cout<<"-----------------------------"<<endl;
    }
};

struct Heap{
    vector<patient> patients;

    void heapify_up(int i){
        if (i == 0)return;
        int parent = (i-1)/2;
        if ( patients[parent].severity < patients[i].severity ||
            (patients[parent].severity == patients[i].severity && patients[parent].arrival_time > patients[i].arrival_time ))
        {
            swap(patients[i] , patients[parent]);
            heapify_up(parent);
        }
        
        else 
            return;
    }

    void heapifiy_down(int i){
        if (patients.empty())return;

        if (i > (int)patients.size()/2 - 1)return;
        
        int greater = i;
        int l = 2*i +1;
        if (patients[l].severity > patients[i].severity ||                            //invert sign
            (patients[l].severity == patients[i].severity && patients[l].arrival_time < patients[i].arrival_time) ){
                greater = l;
            }
        
        int r = 2*i + 2;
        if (r < patients.size() && (patients[r].severity > patients[greater].severity ||  //invert sign
            (patients[r].severity == patients[greater].severity && patients[r].arrival_time < patients[greater].arrival_time)) ){
            greater = r;
        }

        if (i != greater){
            swap(patients[i] , patients[greater]);
            heapifiy_down(greater);
        }
        else 
            return;


    }

    void insert(patient p){
        patients.push_back(p);
        heapify_up(patients.size()-1);
    }
    
    void treat_next_patient(){
        swap(patients[0],patients[patients.size()-1]);
        patients.pop_back();
        heapifiy_down(0);
    }

    patient view_next_patient(){
        if (!patients.empty())
            return patients[0]; 
        else{
            cout<<"No patients in the hospital\n";
            return patient(-1 , "" , -1 , -1);
        }
    }

    void update_severity(int idd ,int newSevirity){
                        //O(n)
        for (int i = 0;i<patients.size();i++){
            if (patients[i].id == idd){
                int oldSev = patients[i].severity;
                patients[i].severity = newSevirity;
                if (oldSev < newSevirity)heapify_up(i);
                else heapifiy_down(i);
                break;
            }
        }

    }

    void display_all_patients(){
                      //O(n)
        for (int i = 0;i<patients.size();i++){
            patients[i].print(patients[i]);
        }
    }
};



int main(){

    int id , sevirity , arrival_time;
    string name;

    Heap heap;
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
        heap.insert(p);
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
            patient p = heap.view_next_patient();
            p.print(p);
        }
        else if (choice == 2){
            heap.treat_next_patient();
        }
        else if (choice == 3){
            int id , newSevirity;
            cout<<"Enter Patient id: \n";
            cin>>id;
            cout<<"Enter new severity: \n";
            cin>>newSevirity;
            heap.update_severity(id , newSevirity);
        }
        else if (choice == 4){
            heap.display_all_patients();
        }
        else if (choice == 6){
            break;
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
                heap.insert(p);
        }
    }
    return 0;
}