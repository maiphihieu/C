#include<iostream.h>
#include<iomanip.h>
#include<fstream.h>
#include<windows.h>
struct cautruc{
	char mact[20];
	char tenct[20];
	int tuoict;
	int sohuychuong,soluong, thuong;
};
cautruc cauthu[5];
void thongtin(int i){
		fflush(stdin);
	cout<<"Ma cau thu: ";cin.getline(cauthu[i].mact,20);fflush(stdin);
	cout<<"Ten cau thu: ";cin.getline(cauthu[i].tenct,20);fflush(stdin);
	cout<<"Tuoi cau thu: ";cin>>cauthu[i].tuoict;fflush(stdin);
	cout<<"So huy chuong: ";cin>>cauthu[i].sohuychuong;fflush(stdin);
	if(cauthu[i].sohuychuong>5)
		cauthu[i].thuong=500000;
	else if(cauthu[i].sohuychuong>3)
		cauthu[i].thuong=300000;
	else if(cauthu[i].sohuychuong>2)
		cauthu[i].thuong=200000;
	else
		cauthu[i].thuong=0;
}
void menu(){
	cout<<"\t\t MENU \n";
	cout<<"[1] Nhap thong tin cau thu \n";
	cout<<"[2] In danh sach duoi dang bang\n";
	cout<<"[3] Sap xep va in danh sach theo thu tu giam dan\n";
	cout<<"[4] Ghi du lieu\n";
	cout<<"[5] Doc du lieu\n";
}
void kebang(){
	for(int i=1;i<92;i++)
		cout<<"-";
	cout<<"\n";
}
void tieude(){
	cout<<"|"<<setw(20)<<"ma cau thu";
	cout<<"|"<<setw(20)<<"ten cau thu";
	cout<<"|"<<setw(15)<<"tuoi cau thu";
	cout<<"|"<<setw(15)<<"so huy chuong";
	cout<<"|"<<setw(15)<<"thuong"<<"|\n";
}
void inds(int i){
	cout<<"|"<<setw(20)<<cauthu[i].mact;
	cout<<"|"<<setw(20)<<cauthu[i].tenct;
	cout<<"|"<<setw(15)<<cauthu[i].tuoict;
	cout<<"|"<<setw(15)<<cauthu[i].sohuychuong;
	cout<<"|"<<setw(15)<<cauthu[i].thuong<<"|\n";	
}
void dsfull(int n){
	kebang();
	tieude();
	kebang();
	for(int i=0;i<n;i++)
	inds(i);
	kebang();
}
void sapxep(int n){
	cautruc tam;
	 	for(int i=0;i<n;i++)
	 		for(int j=i+1;j<n;j++)
	 		if(cauthu[i].tuoict	<cauthu[j].tuoict){
	 			tam=cauthu[i];
	 			cauthu[i]=cauthu[j];
	 			cauthu[j]=tam;
			 }
			dsfull(n);
}
void ghitep(ofstream &vitri){
	vitri<<cauthu[0].soluong<<"\n";
		for(int i=0;i<3;i++){
			vitri<<cauthu[i].mact<<"\n";
			vitri<<cauthu[i].tenct<<"\n";
			vitri<<cauthu[i].tuoict<<"\n";
			vitri<<cauthu[i].sohuychuong<<"\n";
			vitri<<cauthu[i].thuong<<"\n";
		}
		cout<<"\n\tGHI TEP THANH CONG\n"<<endl;
}
void doctep(ifstream & vitri){
	vitri>>cauthu[0].soluong;vitri.ignore();
		for(int i=0;i<3;i++){
			vitri.getline(cauthu[i].mact,20);
			vitri.getline(cauthu[i].tenct,20);
			vitri>>cauthu[i].tuoict;
			vitri>>cauthu[i].sohuychuong;
			vitri>>cauthu[i].thuong;
			vitri.ignore();
		}
		cout<<"\n\t DOC TEP THANH CONG\n";
}
main(){	
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	int luachon;
	int n=3;
	for(;;){
		system("cls");
		menu();
		cout<<"   nhap lua chon: ";cin>>luachon;
		switch(luachon){
		case 1:SetConsoleTextAttribute(h,6);
			for(int i=0;i<n;i++)
			thongtin(i);
			SetConsoleTextAttribute(h,11);
			break;
		case 2:
		
			SetConsoleTextAttribute(h,6);
		 cout<<"\t\t\t\t    DANH SACH CAC CAU THU \n";
		 	SetConsoleTextAttribute(h,3);
				dsfull( n);
			break;
		case 3:	SetConsoleTextAttribute(h,6);
			cout<<"\t\t\t   DANH SACH CAC CAU THU DA DUOC SAP XEP \n";
				SetConsoleTextAttribute(h,10);
				sapxep(n);
			break;
		case 4:{
			cauthu[0].soluong=n;
			ofstream ghi("data.txt");
			ghitep(ghi);
			ghi.close();
			break;}
		case 5:{
			ifstream doc("data.txt");
			doctep(doc);
			n=cauthu[0].soluong;
			doc.close();
			break;}
		}
		system("pause");
	}
}