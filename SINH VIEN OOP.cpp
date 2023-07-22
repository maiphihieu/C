#include<iostream.h>
using namespace std;

class sinhvien{
	private:
		string hoten,gioitinh;
		int namsinh, diemtoan,diemly, diemhoa;
	public :
	void nhapthongtin(){	
		cin.ignore();
		cout<<"HO TEN: "; getline(cin,hoten);
		cout<<"NAM SINH: ";cin>>namsinh;
		cin.ignore();
		cout<<"GIO TINH: "; getline(cin,gioitinh);	
		cout<<"DIEM TOAN: "; cin>>diemtoan;	
		cout<<"DIEM LY: "; cin>>diemly;	
		cout<<"DIEM HOA: "; cin>>diemhoa;	
		cout<<endl;
	}
	double diemtrungbinh(){
		return	(diemhoa+diemly+diemtoan)/3.0;
	}
	void inthongtin(){
		cout<<"ho ten: "<<hoten<<endl;
		cout<<"gioi tinh: "<<gioitinh<<endl;
		cout<<"nam sinh: "<<namsinh<<endl;
		cout<<"diem toan: "<<diemtoan<<endl;
		cout<<"diem ly: "<<diemly<<endl;
		cout<<"diem hoa: "<<diemhoa<<endl;
		cout<<"diem trung binh: "<<diemtrungbinh()<<endl;
		cout<<endl;
	}
	
		
};
int main(){
	sinhvien sv[20];
	int n;
	cout<<"nhap so sinh vien: ";cin>>n;
	for(int i=0;i<n;i++)
	sv[i].nhapthongtin();
	cout<<"IN THONG TIN"<<endl;
	cout<<endl;
	for(int i=0;i<n;i++)
	sv[i].inthongtin();
	return 0;
}