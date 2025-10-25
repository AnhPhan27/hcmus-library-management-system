
# 📘 ĐỒ ÁN 1 – QUẢN LÝ THƯ VIỆN (Library Manager)

**Môn:** Nhập môn lập trình  
**Trường:** Đại học Khoa học Tự nhiên – Khoa CNTT  
**Giảng viên:** Phạm Minh Tuấn  

---

## ⚙️ Yêu cầu kỹ thuật

### 🔧 Công nghệ sử dụng
- Chương trình chạy **trên console** dạng **menu lựa chọn**
- **Chỉ sử dụng:**
  - Kiểu dữ liệu cơ bản (`int`, `float`, `string`, `char`, `bool`)
  - **Mảng 1 chiều** để lưu dữ liệu
- **Không được dùng:**
  - `struct`, `class`, `vector`, `map`, `file I/O`, `STL`
- **Không cần lưu trữ dữ liệu xuống file**

### 📁 Cấu trúc mã nguồn
- **Mỗi chức năng phải được viết trong hàm riêng** với comment rõ ràng:
  - Mục đích của hàm
  - Tham số truyền vào  
  - Giá trị trả về
- **Tách file hợp lý:**
  ```
  main.cpp
  ├── docgia.cpp/.h
  ├── sach.cpp/.h
  ├── muontra.cpp/.h
  └── thongke.cpp/.h
  ```

---

## 📚 Mô tả bài toán

### 🗃️ Quản lý thông tin
Chương trình quản lý 3 loại dữ liệu chính:

#### � Độc giả (Reader)
- Mã độc giả
- Họ tên
- CMND
- Ngày tháng năm sinh
- Giới tính
- Email
- Địa chỉ
- Ngày lập thẻ
- Ngày hết hạn thẻ = Ngày lập thẻ + 48 tháng

#### � Sách (Book)
- ISBN (mã sách)
- Tên sách
- Tác giả
- Nhà xuất bản
- Năm xuất bản
- Thể loại
- Giá sách
- Số lượng quyển

#### � Phiếu mượn/trả sách
- Mã độc giả
- Ngày mượn
- Ngày trả dự kiến (tối đa 7 ngày)
- Ngày trả thực tế
- Danh sách ISBN các sách được mượn

#### 💰 Quy định phạt
- **Trễ hạn:** 5.000 VNĐ/ngày
- **Mất sách:** 200% giá sách

---

## 🧱 Các chức năng chính

### 1️⃣ Quản lý độc giả
| Chức năng | Mô tả |
|-----------|-------|
| **Xem danh sách** | Hiển thị toàn bộ độc giả |
| **Thêm độc giả** | Nhập thông tin mới, lưu vào mảng |
| **Chỉnh sửa** | Tìm và cập nhật thông tin độc giả |
| **Xóa độc giả** | Xóa phần tử trong mảng |
| **Tìm theo CMND** | Duyệt mảng CMND |
| **Tìm theo họ tên** | Duyệt và so sánh chuỗi |

### 2️⃣ Quản lý sách
| Chức năng | Mô tả |
|-----------|-------|
| **Xem danh sách** | Hiển thị toàn bộ sách |
| **Thêm sách** | Nhập dữ liệu mới |
| **Chỉnh sửa** | Tìm và sửa thông tin sách |
| **Xóa sách** | Xóa phần tử khỏi mảng |
| **Tìm theo ISBN** | Duyệt mảng ISBN |
| **Tìm theo tên** | Duyệt mảng tên sách |

### 3️⃣ Lập phiếu mượn sách
- Chọn mã độc giả, nhập danh sách ISBN cần mượn
- Ghi ngày mượn, tính ngày trả dự kiến
- Giảm số lượng sách tương ứng

### 4️⃣ Lập phiếu trả sách
- Nhập mã độc giả, ngày trả thực tế
- Tính số ngày trễ, phạt 5.000đ/ngày nếu có
- Nếu mất sách: phạt 200% giá
- Cập nhật lại số lượng sách

### 5️⃣ Thống kê
| Nội dung | Cách tính |
|----------|-----------|
| **Tổng số sách** | Tổng `soLuong[i]` |
| **Sách theo thể loại** | Đếm theo `theLoai` |
| **Tổng số độc giả** | Biến `soLuongDocGia` |
| **Độc giả theo giới tính** | Đếm `Nam`, `Nữ` |
| **Sách đang mượn** | Tổng mượn – đã trả |
| **Độc giả trễ hạn** | So sánh ngày trả |

---

## 🧮 Menu chương trình

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

---

## 💻 Công cụ phát triển
- **Ngôn ngữ:** C++ (Console App)
- **IDE:** Visual Studio / Code::Blocks
- **Yêu cầu:** Không sử dụng thư viện ngoài

---

## 💬 7. Gợi ý công cụ
- Ngôn ngữ: **C++ (Console App)**  
- IDE: **Visual Studio / Code::Blocks**  
- Không dùng thư viện ngoài.
