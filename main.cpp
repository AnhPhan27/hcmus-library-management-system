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
        hoTen[0] = "Nguyen Van A";
        cmnd[0] = "123456789";
        ngaySinh[0] = "01/01/1990";
        gioiTinh[0] = "Nam";
        email[0] = "nguyenvana@email.com";
        diaChi[0] = "Ha Noi";
        ngayLapThe[0] = "01/01/2024";
        ngayHetHan[0] = "01/01/2028";
        
        maDocGia[1] = "DG002";
        hoTen[1] = "Tran Thi B";
        cmnd[1] = "987654321";
        ngaySinh[1] = "15/05/1995";
        gioiTinh[1] = "Nu";
        email[1] = "tranthib@email.com";
        diaChi[1] = "Ho Chi Minh";
        ngayLapThe[1] = "15/01/2024";
        ngayHetHan[1] = "15/01/2028";
        
        soLuongDocGia = 2;
    }
    
    if(soLuongSach == 0) {
        ISBN[0] = "978-604-1-12345-1";
        tenSach[0] = "Lap trinh C++ co ban";
        tacGia[0] = "Nguyen Van X";
        nhaXuatBan[0] = "NXB Giao duc";
        namXuatBan[0] = 2023;
        theLoai[0] = "Cong nghe thong tin";
        giaSach[0] = 150000;
        soQuyen[0] = 5;
        
        ISBN[1] = "978-604-1-12345-2";
        tenSach[1] = "Cau truc du lieu va giai thuat";
        tacGia[1] = "Tran Van Y";
        nhaXuatBan[1] = "NXB Khoa hoc";
        namXuatBan[1] = 2022;
        theLoai[1] = "Cong nghe thong tin";
        giaSach[1] = 200000;
        soQuyen[1] = 3;
        
        ISBN[2] = "978-604-1-12345-3";
        tenSach[2] = "Toan cao cap";
        tacGia[2] = "Le Van Z";
        nhaXuatBan[2] = "NXB Dai hoc";
        namXuatBan[2] = 2021;
        theLoai[2] = "Toan hoc";
        giaSach[2] = 180000;
        soQuyen[2] = 7;
        
        soLuongSach = 3;
    }
}
