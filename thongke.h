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

// Thống kê theo nhóm
void thongKeSachTheoTheLoai();
void thongKeDocGiaTheoGioiTinh();

// Thống kê mượn trả
void thongKeSoSachDangMuon();
void danhSachDocGiaTreHan();

// (Các hàm tiện ích cũ đã bị loại bỏ để đơn giản hóa theo yêu cầu)

#endif