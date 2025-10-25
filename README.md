# 📚 Library Management System

Hệ thống quản lý thư viện được viết bằng C++ theo yêu cầu đề bài môn **Nhập môn lập trình**. Chương trình sử dụng **modular design** với mảng 1 chiều và các kiểu dữ liệu cơ bản, không sử dụng class, struct, vector hay file I/O.

## 📁 Cấu trúc dự án

```
library_manager/
├── 📄 main.cpp                 # Entry point - Menu chính & khởi tạo dữ liệu mẫu
├── 🧑‍💼 docgia.h/docgia.cpp      # Module quản lý độc giả (CRUD, tìm kiếm)
├── 📚 sach.h/sach.cpp          # Module quản lý sách (inventory, tìm kiếm)  
├── 📋 muontra.h/muontra.cpp    # Module mượn/trả sách (transactions)
├── 📈 thongke.h/thongke.cpp    # Module thống kê & báo cáo
├── 🛠️  Makefile                 # Build system tự động
├── 🏗️  build/                   # Thư mục chứa file build
├── 🚫 .gitignore               # Loại trừ build artifacts
└── 📖 README.md                # Tài liệu hướng dẫn dự án
```

### 🎯 Thiết kế modular
- **Procedural programming**: Tuân thủ yêu cầu chỉ dùng kiểu dữ liệu cơ bản
- **Mảng 1 chiều**: Lưu trữ dữ liệu với extern declarations
- **Header files**: Comments nhóm theo chức năng để dễ đọc
- **Build system**: Makefile với target clean/build/run

## ⚡ Tính năng chính

### 🙋 1. Quản lý độc giả
- **Menu & hiển thị**: Xem danh sách, hiển thị thông tin chi tiết
- **CRUD operations**: Thêm, sửa, xóa độc giả
- **Tìm kiếm**: Theo CMND và họ tên
- **Tiện ích**: Tính toán ngày hết hạn thẻ (4 năm)

### 📖 2. Quản lý sách
- **Menu & hiển thị**: Xem danh sách sách, thông tin chi tiết
- **CRUD operations**: Thêm, sửa, xóa sách
- **Tìm kiếm**: Theo ISBN, tên sách, tác giả  
- **Quản lý số lượng**: Kiểm tra còn sách, tăng/giảm số lượng

### 📝 3. Mượn trả sách
- **Menu & hiển thị**: Xem danh sách phiếu mượn
- **Mượn sách**: Tạo phiếu mượn, kiểm tra điều kiện
- **Trả sách**: Xử lý trả sách, tính tiền phạt
- **Tìm kiếm**: Theo độc giả, sách quá hạn
- **Tiện ích**: Tính ngày trả, so sánh ngày, tiền phạt

### 📊 4. Thống kê báo cáo
- **Tổng quan**: Số sách, độc giả, phiếu mượn
- **Theo nhóm**: Sách theo thể loại, độc giả theo giới tính
- **Mượn trả**: Sách đang mượn, trễ hạn, doanh thu phạt
- **Tiện ích đếm**: Các hàm helper cho thống kê

## Yêu cầu kỹ thuật

### 🔧 Công nghệ sử dụng (theo đề bài)
- **Chỉ sử dụng:**
  - Kiểu dữ liệu cơ bản (`int`, `float`, `string`, `char`, `bool`)
  - **Mảng 1 chiều** để lưu trữ dữ liệu
- **Không được dùng:**
  - `struct`, `class`, `vector`, `map`, `file I/O`, `STL`
- **Không lưu trữ dữ liệu xuống file** (chỉ lưu trong RAM)
- **Mỗi chức năng được viết trong hàm riêng** với comment đầy đủ

## 🚀 Build và chạy dự án

### 💻 Yêu cầu hệ thống
- **Compiler**: GCC/Clang với C++11+ support
- **Platform**: macOS, Linux (tối ưu cho macOS)
- **Tools**: Make (khuyến nghị) hoặc build thủ công
- **Memory**: 64MB RAM (dữ liệu lưu trong bộ nhớ)

### ⚡ Cách chạy nhanh

```bash
# Clone/download dự án
cd library_manager

# Build và chạy một lệnh
make run
```

### 🛠️ Build chi tiết

```bash
# Build dự án (tạo executable trong build/)
make

# Chạy chương trình đã build
./build/library_manager

# Hoặc build và chạy trực tiếp
make run

# Clean build artifacts
make clean
```

### 🔧 Build thủ công (không dùng Makefile)

```bash
# Tạo thư mục build
mkdir -p build

# Compile all source files  
g++ -std=c++11 -Wall -Wextra -o build/library_manager *.cpp

# Run
./build/library_manager
```

### 📋 Makefile targets

```bash
make          # Build dự án
make run      # Build + chạy
make clean    # Xóa build files  
make rebuild  # Clean + build lại
```

## 📖 Hướng dẫn sử dụng

### 🚀 Khởi động
- Chương trình tự động khởi tạo **dữ liệu mẫu**:
  - 2 độc giả (Nguyễn Văn A, Trần Thị B)
  - 3 sách (Lập trình C++, Cấu trúc dữ liệu, Toán cao cấp)

### 🎯 Menu chính
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

### 📱 Workflow sử dụng

1. **🧑‍💼 Quản lý độc giả**: CRUD operations, tìm kiếm theo CMND/tên
2. **📚 Quản lý sách**: Inventory management, tìm kiếm theo ISBN/tên
3. **📝 Mượn sách**: 
   - Chọn độc giả → chọn sách → tự động tính ngày trả
   - Kiểm tra điều kiện: sách còn, độc giả hợp lệ
4. **📋 Trả sách**: 
   - Nhập thông tin → tính phạt trễ hạn (5k/ngày)
   - Xử lý sách mất (phạt 200% giá sách)
5. **📊 Thống kê**: Báo cáo tổng quan, theo nhóm, doanh thu phạt

## 📊 Dữ liệu mẫu khởi tạo

### 📚 Sách mẫu (3 cuốn):
| ISBN | Tên sách | Tác giả | Thể loại | Giá | Số lượng |
|------|----------|---------|----------|-----|----------|
| 978-0-06-112008-4 | To Kill a Mockingbird | Harper Lee | Van Hoc | 150,000₫ | 5 |
| 978-0-452-28423-4 | 1984 | George Orwell | Khoa Hoc Vien Tuong | 120,000₫ | 3 |
| 978-0-7432-7356-5 | The Great Gatsby | F. Scott Fitzgerald | Van Hoc | 180,000₫ | 4 |

### 🧑‍💼 Độc giả mẫu (2 người):
| Mã DG | Họ tên | CMND | Giới tính | Năm sinh | Địa chỉ |
|-------|--------|------|-----------|----------|---------|
| DG001 | Nguyen Van An | 123456789 | Nam | 1995 | Ha Noi |
| DG002 | Tran Thi Binh | 987654321 | Nu | 1998 | Ho Chi Minh |

## Quy định hệ thống

### Mượn sách:
- Thời hạn mượn: **7 ngày**
- Một độc giả chỉ được mượn một lần (phải trả hết mới được mượn tiếp)
- Tối đa **10 cuốn sách** trong một phiếu mượn

### Tiền phạt:
- **Trễ hạn**: 5.000 VND/ngày
- **Mất sách**: 200% giá sách gốc

## ⚠️ Lưu ý quan trọng

### 📋 Theo yêu cầu đề bài:
- ✅ **Chỉ dùng kiểu dữ liệu cơ bản**: `int`, `float`, `string`, `char`, `bool`
- ✅ **Chỉ dùng mảng 1 chiều** để lưu trữ dữ liệu
- ❌ **Không dùng**: `struct`, `class`, `vector`, `map`, STL containers
- ❌ **Không lưu file**: Dữ liệu chỉ tồn tại trong RAM
- 🔄 **Mỗi lần chạy**: Khởi tạo dữ liệu mẫu từ đầu

### 💾 Về dữ liệu:
- Tất cả dữ liệu lưu trong **extern arrays** toàn cục
- Khi thoát chương trình → **dữ liệu mất hoàn toàn**
- Design được tối ưu cho **học tập** chứ không phải production

## 🔧 Troubleshooting

| Vấn đề | Nguyên nhân | Giải pháp |
|--------|-------------|-----------|
| ❌ Compilation error | Thiếu C++11 support | `g++ -std=c++11` |
| ❌ Build files mess | Cũ/conflict files | `make clean` rồi `make` |
| ⚠️ System commands | macOS/Linux khác Windows | Đã fix với `system("clear")` |
| 🐌 Slow compile | Nhiều warnings | Đã tối ưu với `-Wall -Wextra` |

## 🎓 Thông tin dự án

**📚 Library Management System**  
- **Môn học**: Nhập môn lập trình (C++)
- **Mã đồ án**: Đồ án 1 - Hệ thống quản lý thư viện  
- **Trường**: Đại học Khoa học Tự nhiên - Khoa CNTT
- **Năm**: 2024

### 🏆 Đặc điểm nổi bật:
- ✅ **Tuân thủ 100%** yêu cầu đề bài về kiểu dữ liệu
- 🧩 **Modular design** với 5 modules chức năng riêng biệt
- 📝 **Clean code** với comments nhóm theo chức năng  
- 🛠️ **Build system** hoàn chỉnh với Makefile
- 🎯 **Console UI** thân thiện với menu navigation
- 📊 **Dữ liệu mẫu** phong phú để test ngay

### 📈 Version history:
- **v1.0**: Cấu trúc cơ bản với 5 modules
- **v1.1**: Tối ưu comment structure và build system  
- **v1.2**: Clean documentation và folder organization

---
*"Code clean, architecture đẹp, comments clear - ready to impress! 🚀"*