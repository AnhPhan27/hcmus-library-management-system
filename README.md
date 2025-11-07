
# Library Management System (Simple assignment)

Hệ thống quản lý thư viện viết bằng C++ (dành cho bài tập môn nhập môn lập trình).

## Tổng quan ngắn
- Kiểu: procedural (hàm + biến toàn cục).
- Dữ liệu lưu trong RAM (mảng 1 chiều). Ví dụ: `string tenSach[MAX_SACH];`, `int soQuyen[MAX_SACH];`.
- Không dùng cấu trúc dữ liệu phức tạp, không đọc/ghi file.

## Cấu trúc dự án (các file chính)
- `main.cpp`                 — Menu chính và khởi tạo dữ liệu mẫu
- `docgia.h` / `docgia.cpp`  — Quản lý độc giả
- `sach.h` / `sach.cpp`      — Quản lý sách
- `muontra.h` / `muontra.cpp`— Mượn / trả sách
- `thongke.h` / `thongke.cpp`— Thống kê báo cáo
- `Makefile`                 — Build

## Cách build & chạy
Yêu cầu: trình biên dịch C++ (g++/clang++) hỗ trợ C++11.

- Dùng Makefile (khuyến nghị):

```bash
make        # build
make run    # build + run
make clean  # xóa file build
```

- Hoặc biên dịch thủ công:

```bash
g++ -std=c++11 -Wall -o library_manager *.cpp
./library_manager
```

## Hoạt động ngắn gọn
- Chương trình khởi tạo dữ liệu mẫu khi bắt đầu (ví dụ: 2 độc giả, 3 sách).
- Menu gồm: quản lý độc giả, quản lý sách, mượn/trả, thống kê, thoát.
- Hạn mượn mặc định: 7 ngày. Phạt trễ: 5,000 VND/ngày.

## Liên kết

- GitHub: https://github.com/AnhPhan27/hcmus-library-management-system


