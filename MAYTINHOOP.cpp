#include<iostream>
#include<string>
using namespace std;
class MAYTINH{
	private:
		string mahang,tenhang;
		int dlram,trongluong;
	public:
		MAYTINH();
		~MAYTINH(){};
		void nhap();
		void xuat();
		int vanchuyen();
		friend istream & operator>>(istream & in , MAYTINH & tam);
		friend ostream & operator<<(ostream & out, MAYTINH & tam);
		void them();
		void xoa();
};
MAYTINH::MAYTINH(){
	this->mahang="";
	this->tenhang="";
	this->dlram=0;
	this->trongluong=0;
}
void MAYTINH::nhap(){
	cout<<"nhap ma hang: ";cin.ignore();getline(cin,mahang);
	cout<<"nhap trong luong may tinh: ";cin>>trongluong;
	cout<<"nhap ten hang may tinh: ";cin.ignore();getline(cin,tenhang);
	cout<<"nhap dung luong RAM: ";cin>>dlram;
	cout<<endl;
}
void MAYTINH::xuat(){
	if(dlram==16){
		cout<<"ma hang: "<<mahang<<endl;
		cout<<"trong luong may: "<<trongluong<<endl;
		cout<<"ten may: "<<tenhang<<endl;
		cout<<"dung luong RAM: "<<dlram<<endl<<endl;
	}
}
istream & operator>>(istream & in , MAYTINH & tam){
	cout<<"nhap ma hang: ";in.ignore();getline(in,tam.mahang);
	cout<<"nhap trong luong may tinh: ";in>>tam.trongluong;
	cout<<"nhap ten hang may tinh: ";in.ignore();getline(in,tam.tenhang);
	cout<<"nhap dung luong RAM: ";in>>tam.dlram;
}
int MAYTINH::vanchuyen(){
	if(trongluong>2)
		return 100000;
	else if(trongluong>1)
		return 50000;
	else
		return 30000;
}
ostream & operator<<(ostream & out , MAYTINH & tam){
	if(tam.dlram==16){
		out<<"ma hang: "<<tam.mahang<<endl;
		out<<"trong luong: "<<tam.trongluong<<endl;
		out<<"ten hang: "<<tam.tenhang<<endl;
		out<<"dung luong RAM: "<<tam.dlram<<endl;
	}
}
void menu(){
 	cout<<"<1> NHAP THONG TIN MAY"<<endl;
 	cout<<"<2> XUAT THONG TIN MAY"<<endl;
 	cout<<"<3> TIEN VAN CHUYEN"<<endl;
 }
void MAYTINH::them(){
 
 	}
 void MAYTINH::xoa(){
 
 	}
int main(){
	int luachon;
	int n;
	cout<<"nhap so may tinh: ";cin>>n;
	MAYTINH MT[10];
		while(luachon){
			system("cls");
			menu();
			cout<<"nhap lua chon: ";
			cin>>luachon;
		switch(luachon){
		case 1:
			cout<<"-----NHAP THONG TIN MAY-----\n";
			for(int i=1;i<=n;i++)
				MT[i].nhap();
			break;
		case 2:
			cout<<"-----XUAT THONG TIN MAY-----\n";
			cout<<" May co RAM = 16 "<<endl;
			for(int i=1;i<=n;i++)
				MT[i].xuat();
			break;
		case 3:
			for(int i=1;i<=n;i++)
				cout<<"TIEN VAN CHUYEN LA: "<<MT[i].vanchuyen()<<endl;
			break;
			}
			system("pause");
		}
}