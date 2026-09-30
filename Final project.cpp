#include<iostream>
using namespace std;
struct Employe{
	int id;
	string name;
	string address;
};
Employe arr[3];
void addemploye();
void empdata();
int main(){
	int n,choice=0;
	for(n=2;n>=choice;){
	cout<<"Enter 1 for add employe data 2 for fetch employe data  :";
	cin>>choice;
	switch(choice){
	case 1:
	addemploye();
	break;
	case 2:
		empdata();
		break;
		default:
			cout<<"invalid choice";
}
}
}
void addemploye(){
int i;
for(i=0;i<=2;i++){
cout<<"enter a id  :";
cin>>arr[i].id;
cout<<"enter name  :";
cin>>arr[i].name;
cout<<"enter address  :";
cin>>arr[i].address;
}
}
void empdata(){
	int i,id;
		cout<<"enter employe id  :";
		cin>>id;
		for(i=0;i<=2;i++){
		if(id==arr[i].id){
		cout<<arr[i].name<<"    "<<arr[i].address<<endl;
		break;
		}
		else
		cout<<"Data not available"<<endl;
		break;
		}
}


