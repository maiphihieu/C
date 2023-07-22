#include <iostream>
using namespace std;

class truong{
	private:
		string matruong,malop;
		int solop,sosv;
	public:
		truong();
		~truong();
		void nhap();
		void xuat();
		int laysosv(){return sosv;};
};
class truongdaihoc : public truong{
	private:
		string tentruong;
		int sochuyennganh;
	public:
		truongdaihoc();
		~truongdaihoc(){};
		friend istream & operator>>(istream & in,truongdaihoc & tam);
		friend ostream & operator<<(ostream & out,truongdaihoc & tam);
		int coso();
};
truong::truong(){
	this->matruong="";
	this->malop="";
	this->solop=0;
	this->sosv=0;
}
truong::~truong(){}
void truong::nhap(){	cin.ignore();
	cout<<"nhap ma truong: ";getline(cin,matruong);
	cout<<"nhap ma lop: ";getline(cin,malop);
	cout<<"nhap so lop: ";cin>>solop;
	cout<<"nhap so sinh vien: ";cin>>sosv;
}
void truong::xuat(){
	cout<<"\n";
	cout<<"ma truong la: "<<matruong<<endl;
	cout<<"ma lop la: "<<malop<<endl;
	cout<<"so lop la: "<<solop<<endl;
	cout<<"so sinh vien la: "<<sosv<<endl;
}

truongdaihoc::truongdaihoc(){
	this->tentruong="";
	this->sochuyennganh=0;
}
istream & operator>>(istream & in,truongdaihoc & tam){
	in.ignore();
	cout<<"nhap ten truong:";getline(in,tam.tentruong);
	cout<<"nhap so chuyen nghanh: ";in>>tam.sochuyennganh;
}
ostream & operator<<(ostream & out,truongdaihoc & tam){
	out<<"ten truong la: "<<tam.tentruong<<endl;
	out<<"so chuyen nganh la: "<<tam.sochuyennganh<<endl;
}

int truongdaihoc::coso(){
	if(laysosv()>1000)
		return 1;
	else if(laysosv()>600)
		return 2;
	else
		return 3;
}



int main(){
	truong a;
	a.nhap();
	a.xuat();
	truongdaihoc b;
	cin>>b;
	cout<<b;
	cout<<"co so : "<<b.coso()<<endl;
//	void themtr(a, n);
	return 0;
}