# Library Management System

Hệ thống quản lý thư viện bằng C++ cho môn Nhập môn lập trình. Sử dụng mảng 1 chiều và kiểu dữ liệu cơ bản, không dùng class/struct/vector/file I/O.

## Cấu trúc dự án

```
library_manager/
├── main.cpp                 # Menu chính và dữ liệu mẫu
├── docgia.h/docgia.cpp      # Quản lý độc giả
├── sach.h/sach.cpp          # Quản lý sách  
├── muontra.h/muontra.cpp    # Mượn/trả sách
├── thongke.h/thongke.cpp    # Thống kê
├── Makefile                 # Build system
├── build/                   # Thư mục build
├── .gitignore               # Git ignore
└── README.md                # Tài liệu
```

### Thiết kế
- Procedural programming với mảng 1 chiều
- Extern declarations cho data sharing
- Modular design với 5 files riêng biệt

## Tính năng chính

### 1. Quản lý độc giả
- Xem, thêm, sửa, xóa độc giả
- Tìm kiếm theo CMND và họ tên
- Tính ngày hết hạn thẻ (4 năm)

### 2. Quản lý sách
- Xem, thêm, sửa, xóa sách
- Tìm kiếm theo ISBN, tên sách, tác giả  
- Quản lý số lượng sách

### 3. Mượn trả sách
- Lập phiếu mượn, tự động tính ngày trả
- Xử lý trả sách, tính tiền phạt trễ hạn
- Tìm sách quá hạn

### 4. Thống kê
- Tổng số sách, độc giả
- Thống kê theo thể loại, giới tính
- Sách đang mượn, doanh thu phạt

## Yêu cầu kỹ thuật

- Chỉ sử dụng: `int`, `float`, `string`, `char`, `bool`
- Chỉ sử dụng mảng 1 chiều
- Không dùng: `struct`, `class`, `vector`, `map`, file I/O
- Dữ liệu lưu trong RAM, không lưu file
- Mỗi chức năng viết trong hàm riêng

## Build và chạy

### Yêu cầu hệ thống
- C++ compiler (GCC/Clang) với C++11+
- Make tool (optional)

### Cách chạy
```bash
# Cách 1: Sử dụng Makefile
make run

# Cách 2: Build thủ công
g++ -std=c++11 -Wall -o library_manager *.cpp
./library_manager
```

### Makefile commands
```bash
make          # Build
make run      # Build + run
make clean    # Clean build files
```

## Hướng dẫn sử dụng

### Khởi động
Chương trình tự động tạo dữ liệu mẫu: 2 độc giả và 3 sách.

### Menu chính
```
====== HỆ THỐNG QUẢN LÝ THƯ VIỆN ======
1. Quản lý độc giả
2. Quản lý sách
3. Lập phiếu mượn sách  
4. Lập phiếu trả sách
5. Thống kê
0. Thoát
=====================================
```

### Workflow
1. Quản lý độc giả: Thêm/sửa/xóa/tìm độc giả
2. Quản lý sách: Thêm/sửa/xóa/tìm sách
3. Mượn sách: Chọn độc giả và sách, tự động tính ngày trả
4. Trả sách: Tính phạt trễ hạn (5k/ngày) hoặc mất sách (200% giá)
5. Thống kê: Báo cáo tổng quan hệ thống

## Dữ liệu mẫu

### Sách mẫu (3 cuốn):
| ISBN | Tên sách | Tác giả | Giá | Số lượng |
|------|----------|---------|-----|----------|
| 978-0-06-112008-4 | To Kill a Mockingbird | Harper Lee | 150,000₫ | 5 |
| 978-0-452-28423-4 | 1984 | George Orwell | 120,000₫ | 3 |
| 978-0-7432-7356-5 | The Great Gatsby | F. Scott Fitzgerald | 180,000₫ | 4 |

### Độc giả mẫu (2 người):
| Mã DG | Họ tên | CMND | Giới tính | Năm sinh |
|-------|--------|------|-----------|----------|
| DG001 | Phan Duc Anh | 092******492 | Nam | 1995 |
| DG002 | Nguyen Thanh Ngan | 092******369 | Nu | 1998 |

## Quy định hệ thống

- Thời hạn mượn: 7 ngày
- Một độc giả chỉ mượn một lần (phải trả hết mới mượn tiếp)
- Tối đa 10 cuốn/phiếu mượn
- Phạt trễ hạn: 5,000 VND/ngày
- Phạt mất sách: 200% giá sách

## Lưu ý quan trọng

### Theo yêu cầu đề bài:
- Chỉ dùng kiểu dữ liệu cơ bản và mảng 1 chiều
- Không dùng struct, class, vector, map, file I/O
- Dữ liệu chỉ lưu trong RAM
- Mỗi lần chạy khởi tạo dữ liệu mẫu từ đầu

### Troubleshooting:
- Lỗi compilation: Dùng `g++ -std=c++11`
- Build bị lỗi: Chạy `make clean` rồi `make`

## Thông tin dự án

**Library Management System**  
- Môn học: Nhập môn lập trình (C++)
- Đồ án 1 - Hệ thống quản lý thư viện  
- Trường: Đại học Khoa học Tự nhiên - Khoa CNTT
- Năm: 2024

### Đặc điểm:
- Tuân thủ 100% yêu cầu đề bài về kiểu dữ liệu
- Modular design với 5 modules riêng biệt
- Clean code với comments đơn giản
- Build system hoàn chỉnh với Makefile
- Console UI với menu navigation
- Dữ liệu mẫu sẵn sàng để test