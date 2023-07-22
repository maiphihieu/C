#include<iostream.h>
#include <unistd.h>
// nhap phan tu vao mang
void nhap(	int n ,int a[]){
	for(int i=0 ; i<n ; i++){
	cout<<"phan tu "<<i<<" la: ";
	cin>>a[i];
	}
}

//xuat phan tu co trong mang
void xuat(int n,int a[]){
	for(int i=0 ; i<n ; i++)
	cout<<"a["<<i<<"]= "<<a[i]<<endl;
}

//menu
void menu(){
cout<<"\t\t\tMENU\n";
cout<<"\t[1] Nhap cac gia tri trong mang\n";
cout<<"\t[2] Xuat cac phan tu co trong mang\n";
cout<<"\t[3] Thêm phan tu vao trong mang\n";
cout<<"\t[4] Xóa phan tu bat ki trong mang\n";
}

//them phan tu vao mang
void thempt(int n,int vtthem,int x,int a[]){
	for(int i=n-1 ; i>=vtthem ; i--)
	a[i+1]=a[i];
	a[vtthem]=x;
	n++;
	xuat(n,a);
}

// xoa phan tu co trong mang
void xoapt(int n,int vtxoa,int a[]){
	for(int i=vtxoa+1;i<n;i++)
	a[i-1]=a[i];
	n--;
	for(int i=0 ; i<n ; i++)
	cout<<"a["<<i<<"]= "<<a[i]<<endl;
}
main(){
	int luachon,n,a[20],vtthem,x,vtxoa;
	/*int n;
	int a[20];
	int vtthem;
	int x;// phan tu can in	
	int vtxoa;*/
	cout<<"nhap so phan tu cua mang: ";cin>>n;
	while(luachon!=12){
		system("cls");
		menu();
		cout<<"Nhap lua chon cua ban\n";cin>>luachon;
	
		switch(luachon	){
			case 1:
				nhap(n,a);
				break;
			case 2:
				xuat(n,a);
				break;
			case 3:
				cout<<"Nhap vi tri can them: ";cin>>vtthem;
				cout<<"Nhap phan tu can thêm: ";cin>>x;
			
				cout<<"Phan tu duoc them thanh cong.";
				thempt(n,vtthem,x,a);	
				break;
			case 4:
				cout<<"Nhap vi tri can xóa: ";cin>>vtxoa;
				xoapt(n,vtxoa,a);
				break;
			default:
				cout<<"\nXin vui long nhap lai.\n\n";
		}
		system("pause");
	}

}