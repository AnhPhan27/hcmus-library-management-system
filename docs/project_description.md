
# ĐỒ ÁN 1 – QUẢN LÝ THƯ VIỆN

**Môn:** Nhập môn lập trình  
**Trường:** Đại học Khoa học Tự nhiên – Khoa CNTT  

## Yêu cầu kỹ thuật

### Công nghệ sử dụng
- Chương trình console với menu lựa chọn
- Chỉ sử dụng kiểu dữ liệu cơ bản và mảng 1 chiều
- Không dùng struct, class, vector, map, file I/O, STL
- Không lưu dữ liệu xuống file

### Cấu trúc mã nguồn
- Mỗi chức năng viết trong hàm riêng với comment
- Tách file: main.cpp, docgia.cpp/.h, sach.cpp/.h, muontra.cpp/.h, thongke.cpp/.h

## Mô tả bài toán

### Quản lý thông tin
Chương trình quản lý 3 loại dữ liệu:

#### Độc giả
- Mã độc giả, họ tên, CMND, năm sinh, giới tính, email, địa chỉ
- Ngày lập thẻ, ngày hết hạn thẻ (+ 48 tháng)

#### Sách  
- ISBN, tên sách, tác giả, nhà xuất bản, năm xuất bản
- Thể loại, giá sách, số lượng

#### Phiếu mượn/trả
- Mã độc giả, ngày mượn, ngày trả dự kiến (7 ngày)
- Ngày trả thực tế, danh sách ISBN

#### Quy định phạt
- Trễ hạn: 5,000 VNĐ/ngày
- Mất sách: 200% giá sách

## Các chức năng chính

### 1. Quản lý độc giả
- Xem danh sách, thêm, sửa, xóa độc giả
- Tìm theo CMND và họ tên

### 2. Quản lý sách
- Xem danh sách, thêm, sửa, xóa sách
- Tìm theo ISBN và tên sách

### 3. Lập phiếu mượn sách
- Chọn độc giả và danh sách sách cần mượn
- Tính ngày trả dự kiến, giảm số lượng sách

### 4. Lập phiếu trả sách
- Nhập thông tin trả sách
- Tính phạt trễ hạn hoặc mất sách
- Cập nhật lại số lượng sách

### 5. Thống kê
- Tổng số sách và độc giả
- Thống kê theo thể loại và giới tính
- Sách đang mượn, độc giả trễ hạn

## Menu chương trình

```
===== QUẢN LÝ THƯ VIỆN =====
1. Quản lý độc giả
2. Quản lý sách  
3. Lập phiếu mượn sách
4. Lập phiếu trả sách
5. Thống kê
0. Thoát
Chọn chức năng: _
```

## Công cụ phát triển
- Ngôn ngữ: C++ (Console App)
- IDE: Visual Studio / Code::Blocks
- Không sử dụng thư viện ngoài
