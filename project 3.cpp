#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//BASE CLASS
class Patient
{
protected:
    int id;
    string name;
    int age;
public:
    Patient()
{
    id =0;
    name ="";
    age =0;
}
    // Function to input data
    void input()
{
    cout<<"\nEnter Patient ID:";
    cin>>id;
    cin.ignore();
    cout<<"Enter Patient Name:";
    getline(cin, name);
    cout<<"Enter Age:";
    cin>>age;
}
    // Virtual Function (Polymorphism)
    virtual void display()
{
    cout<<"\nPatient ID :"<<id;
    cout<<"\nName       :" <<name;
    cout<< "\nAge       :" <<age<<endl;
}
    // Operator Overloading
    bool operator==(Patient p)
{
    return id==p.id;
}
    // Friend Function
    friend void showPrivate(Patient);
    // Friend Class
    friend class Admin;
};
   //DERIVED CLASS
class IndoorPatient : public Patient
{
private:
    int roomNo;
public:
    void input()
{
    Patient::input();
    cout<<"Enter Room Number: ";
    cin>>roomNo;
}
    // Save data in file
    void saveToFile(ofstream &file)
{
    file<<id<<endl;
    file<<name<<endl;
    file<<age<<endl;
    file<<roomNo<<endl;
}
    void display()
{
    Patient::display();
    cout<<"Room Number: "<<roomNo<<endl;
}
};
    //FRIEND FUNCTION 
void showPrivate(Patient p)
{
    cout<<"\n[Friend Function]";
    cout<<"\nPatient Name: "<<p.name<<endl;
}
  //FRIEND CLASS 
class Admin
{
public:
    void access(Patient p)
{
    cout<<"\n[Friend Class Access]";
    cout<<"\nID   : "<<p.id;
    cout<<"\nName : "<<p.name;
    cout<<"\nAge  : "<<p.age<< endl;
}
};
   //HOSPITAL CLASS (Composition) 
class Hospital
{
private:
    // Composition (Hospital has Indoor Patients)
    IndoorPatient patient[10];
    int count;
public:
    Hospital()
{ 
    count= 0;
}
    // Add Patient
    void addPatient()
{
    if (count < 10)
{
    cout << "\n----- Add Patient -----\n";
    patient[count].input();
    count++;
    cout<<"\nPatient Added Successfully!\n";
}
    else
{
    cout<<"\nHospital Record is Full!\n";
}
}
    // Display All Patients
    void displayPatients()
{
    if (count == 0)
{
    cout<<"\nNo Patient Record Found!\n";
    return;
}
    cout<<"\n===== Patient List =====\n";
    for (int i = 0; i < count; i++)
{
    cout<<"\nPatient " << i + 1 << endl;
    patient[i].display();
}
}
    // Save Data in File
    void saveFile()
{
    ofstream file("patients.txt");

    if (!file)
{
    cout << "\nFile Error!\n";
    return;
}
    file << count << endl;
    for (int i = 0; i < count; i++)
{
    patient[i].saveToFile(file);
}
    file.close();
    cout<< "\nData Saved Successfully!\n";
}
    // Search Patient
    void searchPatient()
{
    int n;
    cout<< "\nEnter Patient Number (1-" << count << "): ";
    cin>>n;
    if (n >= 1 && n <= count)
{
    patient[n - 1].display();
}
    else
{
    cout << "\nPatient Not Found!\n";
}
}
    // Friend Function Demo
    void friendDemo()
{
    if (count > 0)
    showPrivate(patient[0]);
}
    // Friend Class Demo
    void adminDemo()
{
    if (count > 0)
{
    Admin a;
    a.access(patient[0]);
}
}
};
int main()
{
    Hospital h;
    int choice = 0;
    while (choice != 7)
    {
    cout<< "\n   HOSPITAL MANAGEMENT SYSTEM";
    cout<< "\n=================================";
    cout<< "\n1. Add Patient";
    cout<< "\n2. Display All Patients";
    cout<< "\n3. Search Patient";
    cout<< "\n4. Save Data to File";
    cout<< "\n5. Friend Function Demo";
    cout<< "\n6. Friend Class Demo";
    cout<< "\n7. Exit";
    cout<< "\nEnter Your Choice: ";
    cin>> choice;
        switch (choice)
        {
        case 1:
            h.addPatient();
            break;
        case 2:
            h.displayPatients();
            break;
        case 3:
            h.searchPatient();
            break;
        case 4:
            h.saveFile();
            break;
        case 5:
            h.friendDemo();
            break;
        case 6:
            h.adminDemo();
            break;
        case 7:
            cout << "\nThank You! Program Closed.\n";
            break;
        default:
            cout << "\nInvalid Choice!\n";
        }
    }
    return 0;
}
