#ifndef THONGKE_H
#define THONGKE_H

#include <iostream>
#include <string>
#include "docgia.h"
#include "sach.h"
#include "muontra.h"
using namespace std;

// Khai báo các hàm thống kê

// Menu thống kê
void menuThongKe();

// Thống kê tổng quan
void thongKeTongQuan();
void thongKeTongSoSach();
void thongKeTongSoDocGia();

// Thống kê theo nhóm
void thongKeSachTheoTheLoai();
void thongKeDocGiaTheoGioiTinh();

// Thống kê mượn trả
void thongKeSachDangMuon();
void danhSachDocGiaTreHan();
void thongKeDoanhThuPhat();

// Hàm tiện ích đếm
int demSachTheoTheLoai(string theLoaiCanDem);
int demDocGiaTheoGioiTinh(string gioiTinhCanDem);
int tinhTongSachDangMuon();
bool kiemTraDocGiaTreHan(string maDocGia);
float tinhTongTienPhat();

#endif