#include "thongke.h"

// Hiển thị menu thống kê và xử lý lựa chọn
void menuThongKe() {
    int luaChon;
    do {
        system("clear");
        cout << "\n===== THONG KE =====" << endl;
        cout << "1. Thong ke tong quan" << endl;
        cout << "2. Thong ke sach theo the loai" << endl;
        cout << "0. Quay lai menu chinh" << endl;
        cout << "====================" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();
        
        switch(luaChon) {
            case 1:
                thongKeTongQuan();
                break;
            case 2:
                thongKeSachTheoTheLoai();
                break;
            case 0:
                cout << "Quay lai menu chinh..." << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                cout << "Nhan Enter de tiep tuc...";
                cin.ignore();
        }
    } while(luaChon != 0);
}

// Hiển thị thống kê tổng quan hệ thống (số sách, độc giả, phiếu mượn)
void thongKeTongQuan() {
    system("clear");
    cout << "\n===== THONG KE TONG QUAN =====" << endl;
    
    cout << "Tong so sach: " << soLuongSach << endl;
    cout << "Tong so doc gia: " << soLuongDocGia << endl;
    cout << "Tong so phieu muon: " << soLuongPhieu << endl;
    
    cout << "Nhan Enter de tiep tuc...";
    cin.ignore();
}

// Thống kê số lượng sách theo từng thể loại
void thongKeSachTheoTheLoai() {
    system("clear");
    cout << "\n===== THONG KE SACH THEO THE LOAI =====" << endl;
    
    string danhSachTheLoai[MAX_SACH];
    int soLuongTheoTheLoai[MAX_SACH];
    int soTheLoai = 0;
    
    for(int i = 0; i < soLuongSach; i++) {
        bool timThay = false;
        for(int j = 0; j < soTheLoai; j++) {
            if(danhSachTheLoai[j] == theLoai[i]) {
                soLuongTheoTheLoai[j]++;
                timThay = true;
                break;
            }
        }
        
        if(!timThay) {
            danhSachTheLoai[soTheLoai] = theLoai[i];
            soLuongTheoTheLoai[soTheLoai] = 1;
            soTheLoai++;
        }
    }
    
    for(int i = 0; i < soTheLoai; i++) {
        cout << "The loai: " << danhSachTheLoai[i] << " - So luong: " << soLuongTheoTheLoai[i] << endl;
    }
    
    cout << "Nhan Enter de tiep tuc...";
    cin.ignore();
}

// Thống kê số lượng độc giả theo giới tính (Nam/Nữ)
void thongKeDocGiaTheoGioiTinh() {
    cout << "Chua thuc hien" << endl;
}

// Thống kê tình trạng mượn sách (đã trả, chưa trả, quá hạn)
void thongKeTinhTrangMuonSach() {
    cout << "Chua thuc hien" << endl;
}

// Thống kê top 5 sách được mượn nhiều nhất
void thongKeTop5SachMuonNhieu() {
    cout << "Chua thuc hien" << endl;
}

// Thống kê tổng doanh thu từ tiền phạt (trễ hạn, mất sách)
void thongKeDoanhThuPhat() {
    cout << "Chua thuc hien" << endl;
}
