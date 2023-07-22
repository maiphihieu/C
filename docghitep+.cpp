#include<iostream.h>
#include<fstream.h>
main(){
	ifstream file;
	file.open("docghitep.txt");
	int a[20];
	int n;
	file>>n;
	cout<<"so phan tu cua n la: "<<n <<endl;
	for(int i=0;i<n;i++){
		file>>a[i]; 
	} 
	for(int i=0;i<n;i++){
		cout<<"phan tu thu "<<i+1<<"la: "<<a[i]<<endl; 
	} 
	
	ofstream file1 ("giatri.txt");
	for(int i=n-1;i>=0;i--) 
		file1<<a[i]<<" "; 
		cout<<"ghi tep thanh cong" << endl;
	
	file1.close(); 
	file.close(); 
} 