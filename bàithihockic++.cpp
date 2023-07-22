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
/* Vi?t chýõng tr?nh qu?n l? h? dân trong m?t phý?ng v?i thông tin c?a m?i h? bao 
g?m: 
? m? h? (ki?u xâu); 
? tên ch? h? (ki?u xâu); 
? s? thành viên (s? nguyên); 
? m?c thu nh?p (s? th?c); 
? h? nghèo (ki?u bool, true là h? nghèo, false: không)
? tr? c?p (s? th?c). 
Trong ðó {m? h?; tên ch? h?; s? thành viên; m?c thu nh?p} ðý?c nh?p vào t? bàn 
phím. 
1. Xây d?ng menu th?c hi?n các ch?c nãng dý?i ðây
2. Nh?p thông tin các h? dân t? bàn phím
3. Tính tr? c?p cho các h? bi?t:
N?u là h? nghèo và s? thành viên >=5 th? tr? c?p là 1trieu/1 nguoi
N?u là h? nghèo và 3<= s? thành viên <5 th? tr? c?p là 800nghin/1 nguoi
N?u là h? nghèo và 1<= s? thành viên <3 th? tr? c?p là 500nghin/1 nguoi
N?u không là h? nghèo tr? c?p = 0
4. In danh sách thông tin các h? dân v?i ð?y ð? thông tin dý?i d?ng b?ng
5. In thông tin các h? dân thu nh?p nh? nh?t
6. S?p x?p các h? dân theo th? t? gi?m d?n c?a s? thành viên
7. Thêm vào danh sách m?t h? dân có thông tin ðý?c nh?p vào t? bàn phím
8. Xóa kh?i danh sách h? dân h? có tên ch? h? là ten, v?i ten nh?p vào t? bàn phím 
9. Lýu danh sách các h? dân ra t?p ho_dan.dat
10. Ð?c danh sách các h? dân t? t?p ho_dan.dat và in thông tin ra màn h?nh*/