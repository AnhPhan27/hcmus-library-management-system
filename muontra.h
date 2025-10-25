#ifndef MUONTRA_H
#define MUONTRA_H

#include <iostream>
#include <string>
#include "docgia.h"
#include "sach.h"
using namespace std;

// Khai báo hằng số
const int MAX_PHIEU = 200;

// Khai báo mảng toàn cục cho phiếu mượn/trả
extern string maPhieuMuon[MAX_PHIEU];
extern string maDocGiaMuon[MAX_PHIEU];
extern string ISBNMuon[MAX_PHIEU];
extern string ngayMuon[MAX_PHIEU];
extern string ngayTraDuKien[MAX_PHIEU];
extern string ngayTraThucTe[MAX_PHIEU];
extern int soLuongPhieu;

// Khai báo các hàm mượn trả

// Menu và hiển thị
void menuMuonTra();
void xemDanhSachPhieuMuon();
void hienThiThongTinPhieuMuon(int index);

// Mượn và trả sách
void muonSach();
void traSach();

// Tìm kiếm và báo cáo
void timPhieuMuonTheoDocGia();
void xemSachQuaHan();

// Hàm tiện ích
string tinhNgayTraDuKien(string ngayMuon);
float tinhTienPhat(string ngayTraDuKien, string ngayTraThucTe);
int soSanhNgay(string ngay1, string ngay2);

#endif