#include <iostream.h>
#include <string>
#include <fstream>
#include "windows.h" 
using namespace std;

int main(){
	for(;;){
		system("cls");
		cout << endl << endl;
			HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h,6);Sleep(20);
	
				ifstream file1;
				file1.open("mphieu1.txt", ios_base::in);
				string line1;
				while (getline(file1, line1)) {
					cout <<"\t\t\t\t\t\t\t\t\t\t\t\t"<< line1 << endl;
					Sleep(60);
			}
				file1.close();
				
				ifstream file2;
				file2.open("mphieu2.txt", ios_base::in);
				string line2;
				while (getline(file2, line2)) {
					cout <<"\t\t\t\t\t\t\t\t\t\t\t\t"<< line2 << endl;
					Sleep(60);
			}
				file2.close();
				
					ifstream file3;
				file3.open("mphieu3.txt", ios_base::in);
				string line3;
				while (getline(file3, line3)) {
					cout <<"\t\t\t\t\t\t\t\t\t\t\t\t"<< line3 << endl;
					Sleep(10);
			}
				file3.close();
			
				ifstream file;
				file.open("mphieu.txt", ios_base::in);
				string line;
				while (getline(file, line)) {
					cout <<"\t\t\t\t\t"<< line << endl;
					Sleep(120);}
				file.close();
				break;
			
			}
				HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h,7);Sleep(20);
	system("pause");
			}				
	
	
