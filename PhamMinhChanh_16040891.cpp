#include <windows.h>
#include <stdio.h>
#include <string.h>
#include<math.h>
#include <conio.h>

#define MAX_LEN 50

struct SinhVien
{
	char maSinhVien[MAX_LEN], hoTen[MAX_LEN], lopHocPhan[MAX_LEN];
	SinhVien* next;
};

void xuat1SV(SinhVien* sv)
{
	printf("Ma sinh vien : %s\n", sv->maSinhVien);
	printf("Ho va ten : %s\n", sv->hoTen);
	printf("Lop hoc phan : %s\n", sv->lopHocPhan);
}

SinhVien* head_DSSV = NULL;
SinhVien* tail_DSSV = NULL;
int soLuongSV = 0;

void themSV(SinhVien* sv)
{
	if (head_DSSV == NULL)
	{
		head_DSSV = sv;
		tail_DSSV = sv;
	}
	else
	{
		tail_DSSV->next = sv;
		tail_DSSV = sv;
	}
	soLuongSV++;
}

void xuatDSSV()
{
	printf("DSSV gom tat ca %d sinh vien, cu the la: \n", soLuongSV);
	SinhVien* temp = head_DSSV;
	while (temp != NULL)
	{
		xuat1SV(temp);
		printf("---------------------------------------------------------------\n");
		temp = temp->next;
	}
}

////////////////////* Cac ham tim kiem */////////////////////////
SinhVien* timKiemTheoMaSV(char maSV[30], bool canInRa = true)
{
	int count = 1;
	SinhVien* temp = head_DSSV;

	while (temp != NULL)
	{

		if (strcmp(temp->maSinhVien, maSV) == 0)
		{
			if (canInRa == true)
			{
				printf("Tim thay thong tin sinh vien thu %d :\n", count);
				xuat1SV(temp);
			}

			return temp;
		}

		temp = temp->next;
		count++;
	}

	if (canInRa == true)
		printf("Khong tim thay sinh vien\n");

	return NULL;

}

void timKiemTheoHoTen(char hoTen[30])
{
	int count = 1;
	SinhVien* temp = head_DSSV;
	bool timThay = false;

	while (temp != NULL)
	{

		if (strcmp(temp->hoTen, hoTen) == 0)
		{
			printf("Tim thay thong tin sinh vien thu %d :\n", count);
			xuat1SV(temp);
			timThay = true;
		}
		temp = temp->next;
		count++;
	}
	if (timThay == false)
		printf("Khong tim thay sinh vien\n");
}

void timKiemTheoHocPhan(char lopHocPhan[30])
{
	int count = 1;
	SinhVien* temp = head_DSSV;
	bool timThay = false;
	while (temp != NULL)
	{

		if (strcmp(temp->lopHocPhan, lopHocPhan) == 0)
		{
			printf("Tim thay thong tin sinh vien thu %d :\n", count);
			xuat1SV(temp);
			timThay = true;
		}

		temp = temp->next;
		count++;
	}
	if (timThay == false)
		printf("Khong tim thay sinh vien\n");
}


void capNhatTheoMaSV(char maSV[30], char maSVCapNhat[30])
{
	int count = 1;
	SinhVien* temp = head_DSSV;

	while (temp != NULL)
	{

		if (strcmp(temp->maSinhVien, maSV) == 0)
		{
			strcpy(temp->maSinhVien, maSVCapNhat);
			xuatDSSV();
			break;
		}
		if (temp == tail_DSSV && strcmp(temp->maSinhVien, maSV) != 0)
		{
			printf("Khong tim thay sinh vien\n");
			break;
		}
		temp = temp->next;
		count++;
	}
}

void capNhatTheohoTen(char hoTen[30], char hoTenSVCapNhat[30])
{
	int count = 1;
	SinhVien* temp = head_DSSV;

	while (temp != NULL)
	{

		if (strcmp(temp->hoTen, hoTen) == 0)
		{
			strcpy(temp->hoTen, hoTenSVCapNhat);
			xuatDSSV();
			break;
		}
		if (temp == tail_DSSV && strcmp(temp->hoTen, hoTen) != 0)
		{
			printf("Khong tim thay sinh vien\n");
			break;
		}
		temp = temp->next;
		count++;
	}
}

void capNhatTheohocPhan(char hocPhan[30], char hocPhanCapNhat[30])
{
	SinhVien* temp = head_DSSV;

	while (temp != NULL)
	{

		if (strcmp(temp->lopHocPhan, hocPhan) == 0)
		{
			strcpy(temp->lopHocPhan, hocPhanCapNhat);
			xuatDSSV();
			break;
		}

		if (temp == tail_DSSV && strcmp(temp->lopHocPhan, hocPhan) != 0)
		{
			printf("Khong tim thay sinh vien\n");
			break;
		}
		temp = temp->next;
	}
}




//////////////////////// cap nhat cho 1sv ////////////////////////////////////
void updateTen(SinhVien* sv, char tenMoi[30])
{
	strcpy(sv->hoTen, tenMoi);
}

void updateMaSV(SinhVien* sv, char maSV[30])
{
	strcpy(sv->maSinhVien, maSV);
}

void updateLopHocPhan(SinhVien* sv, char lopHocPhanMoi[30])
{
	strcpy(sv->lopHocPhan, lopHocPhanMoi);
}





struct Diem
{
	char maSinhVien[MAX_LEN], tenMonHoc[MAX_LEN];
	float diemTK, diemGK, diemCK, diemTH;
	float diemTB;
	char xepLoai[3];
	Diem* next;
};

Diem* head_DSDiem = NULL;
Diem* tail_DSDiem = NULL;

float tinhDiemTB(Diem *d)
{

	if (d->diemTH == -1) 
	{
		d->diemTB = (d->diemTK + d->diemGK + d->diemCK) / 3;
	}
	else
	{
		d->diemTB = (d->diemTK + d->diemGK + d->diemCK + d->diemTH) / 4;
	}
	return d->diemTB;
}

void xepLoai(Diem *d)
{
	if (d->diemTB >= 9)
		strcpy(d->xepLoai, "A+");
	else if (d->diemTB >= 8.5)
		strcpy(d->xepLoai, "A");
	else if (d->diemTB >= 8)
		strcpy(d->xepLoai, "B+");
	else if (d->diemTB >= 7)
		strcpy(d->xepLoai, "B");
	else if (d->diemTB >= 6.5)
		strcpy(d->xepLoai, "C+");
	else if (d->diemTB >= 5.5)
		strcpy(d->xepLoai, "C");
	else if (d->diemTB >= 5)
		strcpy(d->xepLoai, "D+");
	else
		strcpy(d->xepLoai, "D");
}

void themDiem(Diem *diem)
{
	if (head_DSDiem == NULL)
	{
		head_DSDiem = diem;
		tail_DSDiem = diem;
	}
	else
	{
		tail_DSDiem->next = diem;
		tail_DSDiem = diem;
	}
}

void nhapDiem(Diem *&d, char maSinhVien[])
{
	d = new Diem;
	strcpy(d->maSinhVien, maSinhVien);
	printf("Nhap ten mon hoc: ");
	gets(d->tenMonHoc);
	printf("Nhap diem thuong ky: ");
	scanf("%f", &d->diemTK);

	printf("Nhap diem giua ky: ");
	scanf("%f", &d->diemGK);
	printf("Nhap diem cuoi ky: ");
	scanf("%f", &d->diemCK);
	printf("Nhap diem thuc hanh (nhap -1 neu khong co diem thuc hanh): ");
	scanf("%f", &d->diemTH);
	d->diemTB = tinhDiemTB(d);
	xepLoai(d);
	printf("\n");
	d->next = NULL;
	themDiem(d);

}


void xuatDiem1SV(Diem* diem)
{
	printf("Ma sinh vien : %s\n", diem->maSinhVien);
	printf("Ten mon hoc : %s\n", diem->tenMonHoc);
	printf("Diem thuong ky: %.2f\n", diem->diemTK);
	printf("Diem giua ky: %.2f\n", diem->diemGK);
	printf("Diem cuoi ky: %.2f\n", diem->diemCK);
	printf("Diem thuc hanh: %.2f\n", diem->diemTH);
	printf("Diem trung binh: %.2f\n", diem->diemTB);
	printf("Xep loai: %s\n", diem->xepLoai);
}



void xuatBangDiem(Diem *diem)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("BANG DIEM SINH VIEN\n");
	Diem* temp = head_DSDiem;
	while (temp != NULL)
	{
		xuatDiem1SV(temp);
		printf("--------------------------------------------------------\n");
		temp = temp->next;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
}






int main()
{

	const char s[2] = ",";
	char *token;
	int i;
	FILE* filePointer = fopen("sinhvien.txt", "r");
	if (filePointer == NULL)
	{
		printf("Khong tim thay file.\n");
		system("PAUSE");
		return 1;
	}

	char output[256];
	char** temp_SV = new char*[3];
	char** temp_Diem = new char*[6];
	SinhVien *sv;
	Diem *diem;

	for (i = 1; fgets(output, sizeof(output), filePointer) != NULL; i++)
	{	

		token = strtok(output, s);

		// neu dong doc vao la 1 SV
		if (strcmp(token, "sv") == 0)
		{
			//tach tiep
			int index = 0;
			while (token != NULL)
			{
				token = strtok(NULL, s);
				temp_SV[index] = token;
				index++;
			}

			//tao 1 bien kieu sv*
			sv = new SinhVien();

			//gan vo bien:
			strncpy(sv->maSinhVien, temp_SV[0], MAX_LEN);
			strncpy(sv->hoTen, temp_SV[1], MAX_LEN);
			strncpy(sv->lopHocPhan, temp_SV[2], MAX_LEN);
			sv->next = NULL;

			// noi bien vao list SV
			themSV(sv);
		}
		else // 1 doi tuong Diem
		{
			int index = 0;
			while (token != NULL)
			{
				token = strtok(NULL, s);
				temp_Diem[index] = token;
				index++;
			}			
			diem = new Diem();

			//gan vao bien, atof doi tu char sang float:
			strncpy(diem->tenMonHoc, temp_Diem[0], MAX_LEN);
			strncpy(diem->maSinhVien, temp_Diem[1], MAX_LEN);
			diem->diemTK = atof(temp_Diem[2]);
			diem->diemGK = atof(temp_Diem[3]);
			diem->diemCK = atof(temp_Diem[4]);
			diem->diemTH = atof(temp_Diem[5]);
			diem->diemTB = tinhDiemTB(diem);
			xepLoai(diem);
			diem->next = NULL;

			// noi bien vao list diem
			themDiem(diem);
		}

	}

	fclose(filePointer);
	xuatDSSV();


	int chon1, chon2, chonMenu;

	char maSV[MAX_LEN], maSVCanCapNhat[MAX_LEN], maSVMoi[MAX_LEN], hoTen[MAX_LEN], hoTenMoi[MAX_LEN], hocPhan[MAX_LEN], hocPhanMoi[MAX_LEN];


	Diem* tempDiem1 = NULL;



	//menu
	do
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		printf("===== Main Menu =====\n");

		printf("1. Tim kiem.\n");
		printf("2. Cap nhat.\n");
		printf("3. Nhap diem cho sinh vien.\n");
		printf("4. In bang diem.\n");
		printf("5. Thoat.\n");
		printf("---------------------\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("Moi ban nhap lua chon: ");
		scanf("%d", &chonMenu);

		switch (chonMenu)
		{
		case 1: //menu Tim Kiem
			do
			{
				printf("===== Menu Tim Kiem =====\n");
				printf("1. Tim kiem theo ma sinh vien.\n");
				printf("2. Tim kiem theo ho ten sinh vien.\n");
				printf("3. Tim kiem theo lop hoc phan.\n");
				printf("4. Quay ve Main Menu.\n");
				printf("--------------------------\n");
				printf("Moi ban nhap lua chon: ");
				scanf("%d", &chon1);
				while (getchar() != '\n');
				switch (chon1)
				{
				case 1:

					printf("Nhap ma so sinh vien ma ban muon tim kiem: ");
					gets(maSV);
					printf("----------------------------------------------\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					timKiemTheoMaSV(maSV);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					break;
				case 2:
					printf("Nhap ho ten sinh vien ma ban muon tim kiem: ");
					gets(hoTen);
					printf("----------------------------------------------\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					timKiemTheoHoTen(hoTen);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					break;
				case 3:
					printf("Nhap lop hoc phan ma ban muon tim kiem: ");
					gets(hocPhan);
					printf("----------------------------------------------\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					timKiemTheoHocPhan(hocPhan);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					break;
				default: chon1 = 4;
				}
			} while (chon1 != 4);
			break;

		case 2: // Menu Cap nhat
			do {
				SinhVien* temp = NULL;
				while (getchar() != '\n');

				printf("========= Menu Cap Nhat =========\n");
				printf("Nhap Ma sinh vien can cap nhat: \n");


				gets(maSVCanCapNhat);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				temp = timKiemTheoMaSV(maSVCanCapNhat, false);

				if (temp != NULL)//tim thay sv can sua
				{
					xuat1SV(temp);

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					printf("========= Menu Cap Nhat =========\n");
					printf("1. Cap nhat ma so sinh vien.\n");
					printf("2. Cap nhat ho ten sinh vien.\n");
					printf("3. Cap nhat hoc phan.\n");
					printf("4. Quay lai Main Menu.\n");
					printf("---------------------------------\n");
					printf("Moi ban nhap lua chon: ");
					scanf("%d", &chon2);

					while (getchar() != '\n');
					switch (chon2)
					{
					case 1:

						printf("Nhap ma SV moi: ");
						gets(maSVMoi);
						printf("----------------------------------------------\n");
						updateMaSV(temp, maSVMoi);
						printf("da cap nhat !\n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
						xuatDSSV();
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						break;

					case 2:
						printf("Nhap ho ten moi: ");
						gets(hoTenMoi);
						printf("----------------------------------------------\n");
						updateTen(temp, hoTenMoi);
						printf("da cap nhat !\n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
						xuatDSSV();
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						break;

					case 3:
						printf("Nhap hoc phan moi: ");
						gets(hocPhanMoi);
						printf("----------------------------------------------\n");
						updateLopHocPhan(temp, hocPhanMoi);
						printf("da cap nhat !\n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
						xuatDSSV();
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						break;

					default: chon2 = 4;
					}
					printf("\nChuong trinh quay lai Main Menu...\n ");
					break; //quay ve main menu
				}
				else
				{
					printf("Khong tim thay SV ! Chuong trinh quay lai Main Menu...\n ");
					break;
				}


			} while (chon2 != 4);
			break;

		case 3: // nhap diem mon hoc
			while (getchar() != '\n');
			printf("Nhap ma so sinh vien ma ban muon nhap diem: ");
			gets(maSV);
			printf("----------------------------------------------\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			timKiemTheoMaSV(maSV);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			nhapDiem(tempDiem1, maSV);
			break;
		case 4:
			xuatBangDiem(tempDiem1);
			break;

		default: chonMenu = 5;
		}
	} while (chonMenu != 5);
	return 0;
}
