#ifndef DOCGIA_H
#define DOCGIA_H

#include <iostream>
#include <string>
using namespace std;

// Khai báo hằng số
const int MAX_DOCGIA = 100;

// Khai báo mảng toàn cục cho độc giả
extern string maDocGia[MAX_DOCGIA];
extern string hoTen[MAX_DOCGIA];
extern string cmnd[MAX_DOCGIA];
extern string ngaySinh[MAX_DOCGIA];
extern string gioiTinh[MAX_DOCGIA];
extern string email[MAX_DOCGIA];
extern string diaChi[MAX_DOCGIA];
extern string ngayLapThe[MAX_DOCGIA];
extern string ngayHetHan[MAX_DOCGIA];
extern int soLuongDocGia;

// Khai báo các hàm quản lý độc giả

// Menu và hiển thị
void menuDocGia();
void xemDanhSachDocGia();
void hienThiThongTinDocGia(int index);

// Thêm, sửa, xóa độc giả
void themDocGia();
void chinhSuaDocGia();
void xoaDocGia();

// Tìm kiếm độc giả
void timDocGiaTheoCMND();
void timDocGiaTheoHoTen();
int timViTriDocGia(string ma);

// Hàm tiện ích
string tinhNgayHetHan(string ngayLap);

#endif