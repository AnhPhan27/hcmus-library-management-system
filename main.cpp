#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#include "docgia.h"
#include "sach.h"
#include "muontra.h"
#include "thongke.h"

void hienThiMenuChinh();
void khoiTaoDuLieuMau();

int main() {
    khoiTaoDuLieuMau();
    
    int luaChon;
    do {
        hienThiMenuChinh();
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();
        
        switch(luaChon) {
            case 1:
                menuDocGia();
                break;
            case 2:
                menuSach();
                break;
            case 3:
                menuMuonTra();
                break;
            case 4:
                menuThongKe();
                break;
            case 0:
                cout << "Cam on ban da su dung he thong!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                cout << "Nhan Enter de tiep tuc...";
                cin.ignore();
        }
    } while(luaChon != 0);
    
    return 0;
}

void hienThiMenuChinh() {
    system("clear");
    cout << "\n========================================" << endl;
    cout << "    HE THONG QUAN LY THU VIEN" << endl;
    cout << "========================================" << endl;
    cout << "1. Quan ly doc gia" << endl;
    cout << "2. Quan ly sach" << endl;
    cout << "3. Muon tra sach" << endl;
    cout << "4. Thong ke bao cao" << endl;
    cout << "0. Thoat chuong trinh" << endl;
    cout << "========================================" << endl;
}

void khoiTaoDuLieuMau() {
    if(soLuongDocGia == 0) {
        maDocGia[0] = "DG001";
        hoTen[0] = "Phan Duc Anh";
        cmnd[0] = "092095004492";
        ngaySinh[0] = "27/12/1995";
        gioiTinh[0] = "Nam";
        email[0] = "ducanh271295@gmail.com";
        diaChi[0] = "Can Tho";
        ngayLapThe[0] = "25/10/2025";
        ngayHetHan[0] = "24/10/2028";
        
        maDocGia[1] = "DG002";
        hoTen[1] = "Nguyen Thanh Ngan";
        cmnd[1] = "0123456789";
        ngaySinh[1] = "21/04/1999";
        gioiTinh[1] = "Nu";
        email[1] = "sarangan@email.com";
        diaChi[1] = "Ho Chi Minh";
        ngayLapThe[1] = "25/10/2025";
        ngayHetHan[1] = "24/10/2028";
        
        soLuongDocGia = 2;
    }
    
    if(soLuongSach == 0) {
        ISBN[0] = "978-604-1-12345-1";
        tenSach[0] = "Nhap mon lap trinh";
        tacGia[0] = "Tran Dan Thư";
        nhaXuatBan[0] = "NXB Truong DHKHTN";
        namXuatBan[0] = 2023;
        theLoai[0] = "Cong nghe thong tin";
        giaSach[0] = 150000;
        soQuyen[0] = 5;
        
        ISBN[1] = "978-604-1-12345-2";
        tenSach[1] = "Toi Thay Hoa Vang Tren Co Xanh";
        tacGia[1] = "Nguyen Nhat Anh";
        nhaXuatBan[1] = "NXB Tre";
        namXuatBan[1] = 2022;
        theLoai[1] = "Van hoc";
        giaSach[1] = 200000;
        soQuyen[1] = 3;
        
        ISBN[2] = "978-604-1-12345-3";
        tenSach[2] = "Rung Na Uy";
        tacGia[2] = "Haruki Murakami";
        nhaXuatBan[2] = "Nha Nam";
        namXuatBan[2] = 2021;
        theLoai[2] = "Van hoc";
        giaSach[2] = 180000;
        soQuyen[2] = 7;
        
        soLuongSach = 3;
    }
}
