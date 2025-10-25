#ifndef SACH_H
#define SACH_H

#include <iostream>
#include <string>
using namespace std;

// Khai báo hằng số
const int MAX_SACH = 100;

// Khai báo mảng toàn cục cho sách
extern string ISBN[MAX_SACH];
extern string tenSach[MAX_SACH];
extern string tacGia[MAX_SACH];
extern string nhaXuatBan[MAX_SACH];
extern int namXuatBan[MAX_SACH];
extern string theLoai[MAX_SACH];
extern float giaSach[MAX_SACH];
extern int soQuyen[MAX_SACH];
extern int soLuongSach;

// Khai báo các hàm quản lý sách

// Menu và hiển thị
void menuSach();
void xemDanhSachSach();
void hienThiThongTinSach(int index);

// Thêm, sửa, xóa sách
void themSach();
void chinhSuaSach();
void xoaSach();

// Tìm kiếm sách
void timSachTheoISBN();
void timSachTheoTen();
void timSachTheoTacGia();
int timViTriSach(string ma);

// Quản lý số lượng sách
bool kiemTraSachCoSan(string isbnInput);
void giamSoLuongSach(string isbnInput);
void tangSoLuongSach(string isbnInput);
bool capNhatSoLuongSach(string isbn_input, int soLuongThayDoi);

#endif