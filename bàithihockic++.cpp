#include <iostream.h>
#include <iomanip.h>
#include <fstream.h> 
struct ho_dan{
	char maho[20];
	char tenchuho[30];
	bool hongheo; 
	float trocap;
	float thunhap; 
	int thanhvien; 
};
ho_dan giadinh[3];
// ke bang
void ke_bang(){
	for(int i=1;i<93;i++)
		cout<<"-";
	cout<<"\n"; 
} 
// Tao menu
void menu(){
	cout<<"\n\t\t\t\t\t\t\t----[ Menu ]---- \n";
		cout<<" \t\t\t\t[1] Nhap thong tin ho dan \n"; 
		cout<<" \t\t\t\t[2] Tinh tro cap cho cac ho \n";
		cout<<" \t\t\t\t[3] In danh sach thong tin cac ho dan duoi dang bang \n";
		cout<<" \t\t\t\t[4] In thong tin cac ho dan thu nhap nho nhat \n";
		cout<<" \t\t\t\t[5] Sap xep cac ho dan theo thu tu giam dan so thanh vien \n";
		cout<<" \t\t\t\t[6] Them vao danh sach mot ho dan co thong tin duoc nhap vao tu ban phim \n";
		cout<<" \t\t\t\t[7] Xoa khoi danh sach ho dan ho la ten,voi ten dcnhap tu ban phim \n";
		cout<<" \t\t\t\t[8] Luu danh sach cac ho dan ra tep ho_dan.dat \n";
		cout<<" \t\t\t\t[9] Doc danh sach cac ho dan ra tep ho_dan.dat va in thong tin ra man hinh \n";
		cout<<" \t\t\t\t[#] Thoatn\n";
		cout<<" \t\t\t\t[?] Lua chon->\n";
} 		
//nhap thong tin cac ho dan
void thong_tin(int i){
			fflush(stdin);
		cout<<"Nhap ma ho: ";cin.getline(giadinh[i].maho,20);
		cout<<"Nhap ten chu ho: ";cin.getline(giadinh[i].tenchuho,30);
		cout<<"Nhap so thanh vien: ";cin>>giadinh[i].thanhvien; 
		cout<<"Nhap muc thu nhap: ";cin>>giadinh[i].thunhap;
		if(giadinh[i].thunhap>6000){
			giadinh[i].hongheo=0; 
		}
		else{
			giadinh[i].hongheo=1; 
		} 	
}
// tinh tro cap cho cac ho
void tinhtrocap(int n){	
	for(int i=0;i<n;i++){
		if(giadinh[i].hongheo==true & giadinh[i].thanhvien>=5)
			giadinh[i].trocap=1000 * giadinh[i].thanhvien; 
		else if(giadinh[i].hongheo==true & 3<= giadinh[i].thanhvien)
			giadinh[i].trocap=800 * giadinh[i].thanhvien; 
		else if(giadinh[i].hongheo==true & 1<=giadinh[i].thanhvien)
			giadinh[i].trocap=500 * giadinh[i].thanhvien;
		else
			giadinh[i].trocap=0;
	cout<<"ho gia dinh "<<giadinh[i].maho<<" co tro cap la: "<<giadinh[i].trocap<<endl; 
	}
	
}
// tieu de bang
void tieude (){
		cout << "|" << setw(15)<< "ma ho";
		cout << "|" << setw(20)<< "ten chu ho";
		cout << "|" << setw(15)<< "so tv";
		cout << "|" << setw(15)<< "tro cap";
		cout << "|" << setw(10)<< "thu nhap"; 
		cout << "|" << setw(10)<< "ho ngheo"<< "|\n";
}
// In danh sach thong tin cac ho dan duoi dang bang
void in_dshd(int i){
		
			cout << "|" << setw(15)<<giadinh[i].maho;
			cout << "|" << setw(20)<<giadinh[i].tenchuho;
			cout << "|" << setw(15)<<giadinh[i].thanhvien;
			cout << "|" << setw(15)<<giadinh[i].trocap;
			cout << "|" << setw(10)<<giadinh[i].thunhap;
			cout << "|" << setw(10)<<giadinh[i].hongheo<<"|\n"; 	 
}
//in thong tin ho dan co thu nhap nho nhat
//
void thu_nhapmin(int n){
	int min=giadinh[2].thunhap,tam=0;
	for(int i=0;i<n;i++)
		if(min>giadinh[i].thunhap){
			min = giadinh[i].thunhap;
		tam=i; 	
	}
	in_dshd(tam); 	 
}
//sap xep cac ho dan theo thu tu giam dan
void sap_xep(int n){
		ho_dan tem; 
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(giadinh[i].thanhvien<giadinh[j].thanhvien){
						tem = giadinh[i];
						giadinh[i]=giadinh[j];
						giadinh[j] = tem; 
			} 
		cout<<"Xap xep he so giam dan so thanh vien "<<endl;
}

// xoa
// strcmp so sanh chuoi 
void xoa(int n){
	char ma[5];
	cout<<"Nhap ma ho can xoa -> ";fflush(stdin);
	cin.getline(ma,5);
	for(int i=0;i<n;i++)
		if(strcmp(giadinh[i].maho,ma)==0){
			strcpy(giadinh[i].maho,"0");
			strcpy(giadinh[i].tenchuho,"0");
			giadinh[i].trocap=0;
			giadinh[i].thunhap=0;
			giadinh[i].thanhvien=0;				
		}	
		cout<<"  Xoa thanh cong ma ho "<<ma<<endl;
}
// them ho gia dinh
void them_hogd(int n){fflush(stdin);
		thong_tin(n);
		tinhtrocap(n+1);
		in_dshd(n); 
				
} 
// danh sach full
void ds_full(int n){
	tieude();
	ke_bang(); 
	for(int i=0;i<n;i++)
		in_dshd(i); 
} 
//luu danh sach cac ho dan
void ghitep(ofstream &vt){
	vt.write((char*)giadinh,sizeof(giadinh));
	cout<<" Ghi tep thanh cong \n";
}
// doc tep
void doctep(ifstream &vt){	
	vt.read((char*)giadinh,sizeof(giadinh));
	cout<<"  Doc tep thanh cong \n";		
}
main(){
	  char luachon;
	  int n=3; 
 while(luachon !='12'){
 	system("cls");
	  
	menu();
	cout<<"nhap lua chon: ";
	cin>>luachon;
	switch(luachon){
		case '1':
			for(int i=0;i<n;i++)
         	thong_tin(i);
			break;
		case '2':cout<<"TRO CAP CAC HO GIA DINH LA:"<<endl; 
         	tinhtrocap(n);
			break;
		case '3':	cout<<"\t\t\t\t   DANH SACH CAC HO DAN"<<endl;
			ke_bang(); 
			ds_full(n);
			ke_bang(); 
			break;
		case '4':	cout<<"\t\t\t\tHO DAN CO THU NHAP NHO NHAT"<<endl;
			ke_bang();
			tieude();
			ke_bang(); 
	  		thu_nhapmin(n);
	    	ke_bang();
			break;
		case '5':
 			sap_xep(n);
 			ke_bang();
 			ds_full(n); 
   			ke_bang();
			break;
		case '6':
			them_hogd(n);
			n++;
			break; 
		case '7':
		   	xoa(n);
			break; 
		case '8':{
			ofstream ghi("ho_dan.dat",ios::binary);	
			ghitep(ghi);
			ghi.close();}
			break;
		case '9':{
			ifstream doc("ho_dan.dat",ios::binary);	
			doctep(doc);
			doc.close();}
			break;	
	}
	system ("pause");} 
} 
/* Vi?t ch��ng tr?nh qu?n l? h? d�n trong m?t ph�?ng v?i th�ng tin c?a m?i h? bao 
g?m: 
? m? h? (ki?u x�u); 
? t�n ch? h? (ki?u x�u); 
? s? th�nh vi�n (s? nguy�n); 
? m?c thu nh?p (s? th?c); 
? h? ngh�o (ki?u bool, true l� h? ngh�o, false: kh�ng)
? tr? c?p (s? th?c). 
Trong �� {m? h?; t�n ch? h?; s? th�nh vi�n; m?c thu nh?p} ��?c nh?p v�o t? b�n 
ph�m. 
1. X�y d?ng menu th?c hi?n c�c ch?c n�ng d�?i ��y
2. Nh?p th�ng tin c�c h? d�n t? b�n ph�m
3. T�nh tr? c?p cho c�c h? bi?t:
N?u l� h? ngh�o v� s? th�nh vi�n >=5 th? tr? c?p l� 1trieu/1 nguoi
N?u l� h? ngh�o v� 3<= s? th�nh vi�n <5 th? tr? c?p l� 800nghin/1 nguoi
N?u l� h? ngh�o v� 1<= s? th�nh vi�n <3 th? tr? c?p l� 500nghin/1 nguoi
N?u kh�ng l� h? ngh�o tr? c?p = 0
4. In danh s�ch th�ng tin c�c h? d�n v?i �?y �? th�ng tin d�?i d?ng b?ng
5. In th�ng tin c�c h? d�n thu nh?p nh? nh?t
6. S?p x?p c�c h? d�n theo th? t? gi?m d?n c?a s? th�nh vi�n
7. Th�m v�o danh s�ch m?t h? d�n c� th�ng tin ��?c nh?p v�o t? b�n ph�m
8. X�a kh?i danh s�ch h? d�n h? c� t�n ch? h? l� ten, v?i ten nh?p v�o t? b�n ph�m 
9. L�u danh s�ch c�c h? d�n ra t?p ho_dan.dat
10. �?c danh s�ch c�c h? d�n t? t?p ho_dan.dat v� in th�ng tin ra m�n h?nh*/