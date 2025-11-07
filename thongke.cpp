#include "thongke.h"
#include "utils.h"

// Hiển thị menu thống kê và xử lý lựa chọn
void menuThongKe() {
    int luaChon;
    do {
        system("clear");
        cout << "\n===== THONG KE =====" << endl;
        cout << "1. Thong ke tong so sach" << endl;
        cout << "2. Thong ke so luong sach theo the loai" << endl;
        cout << "3. Thong ke so luong doc gia" << endl;
        cout << "4. Thong ke so luong doc gia theo gioi tinh" << endl;
        cout << "5. Thong ke so sach dang duoc muon" << endl;
        cout << "6. Danh sach doc gia bi tre han" << endl;
        cout << "0. Quay lai menu chinh" << endl;
        cout << "====================" << endl;
    cout << "Nhap lua chon: ";
    cin >> luaChon;
    discardLine();
        
        switch(luaChon) {
            case 1:
                thongKeTongQuan();
                break;
            case 2:
                thongKeSachTheoTheLoai();
                break;
            case 3:
                cout << "\n===== THONG KE DOC GIA =====" << endl;
                cout << "Tong so doc gia: " << soLuongDocGia << endl;
                waitForEnter();
                break;
            case 4:
                thongKeDocGiaTheoGioiTinh();
                break;
            case 5:
                thongKeSoSachDangMuon();
                break;
            case 6:
                danhSachDocGiaTreHan();
                break;
            case 0:
                cout << "Quay lai menu chinh..." << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                waitForEnter();
        }
    } while(luaChon != 0);
}

// Hiển thị thống kê tổng quan hệ thống (số sách, độc giả, phiếu mượn)
void thongKeTongQuan() {
    system("clear");
    cout << "\n===== THONG KE TONG QUAN =====" << endl;
    
    int tongSoQuyen = 0;
    for(int i = 0; i < soLuongSach; ++i) tongSoQuyen += soQuyen[i];
    cout << "Tong so dau sach (tua): " << soLuongSach << endl;
    cout << "Tong so quyen (tong sach): " << tongSoQuyen << endl;
    cout << "Tong so doc gia: " << soLuongDocGia << endl;
    cout << "Tong so phieu muon: " << soLuongPhieu << endl;
    
    waitForEnter();
}

// Thống kê số lượng sách theo từng thể loại
void thongKeSachTheoTheLoai() {
    system("clear");
    cout << "\n===== THONG KE SACH THEO THE LOAI =====" << endl;
    string danhSachTheLoai[MAX_SACH];
    int soLuongTheoTheLoai[MAX_SACH] = {0}; // tổng số quyển (bản sao) theo thể loại
    int soTuaTheoTheLoai[MAX_SACH] = {0};   // số đầu sách (tựa) theo thể loại
    int soTheLoai = 0;

    for(int i = 0; i < soLuongSach; i++) {
        bool timThay = false;
        for(int j = 0; j < soTheLoai; j++) {
            if(danhSachTheLoai[j] == theLoai[i]) {
                // cộng số quyển của tựa sách này vào tổng của thể loại
                soLuongTheoTheLoai[j] += soQuyen[i];
                // tăng số tựa sách của thể loại lên 1
                soTuaTheoTheLoai[j] += 1;
                timThay = true;
                break;
            }
        }

        if(!timThay) {
            danhSachTheLoai[soTheLoai] = theLoai[i];
            // khởi tạo bằng số quyển và 1 tựa sách của tựa sách i
            soLuongTheoTheLoai[soTheLoai] = soQuyen[i];
            soTuaTheoTheLoai[soTheLoai] = 1;
            soTheLoai++;
        }
    }

    for(int i = 0; i < soTheLoai; i++) {
        cout << "The loai: " << danhSachTheLoai[i]
             << " - So luong (tua): " << soTuaTheoTheLoai[i]
             << " - So luong (quyen): " << soLuongTheoTheLoai[i] << endl;
    }
    
    waitForEnter();
}

// Thống kê số lượng độc giả theo giới tính (Nam/Nữ)
void thongKeDocGiaTheoGioiTinh() {
    system("clear");
    cout << "\n===== THONG KE DOC GIA THEO GIOI TINH =====" << endl;
    
    int soDocGiaNam = 0;
    int soDocGiaNu = 0;
    
    for(int i = 0; i < soLuongDocGia; i++) {
        if(gioiTinh[i] == "Nam") {
            soDocGiaNam++;
        } else if(gioiTinh[i] == "Nu") {
            soDocGiaNu++;
        }
    }
    
    cout << "Tong so doc gia: " << soLuongDocGia << endl;
    cout << "So doc gia nam: " << soDocGiaNam << endl;
    cout << "So doc gia nu: " << soDocGiaNu << endl;    
    waitForEnter();
}

// Thống kê số sách đang được mượn (dựa trên số phiếu chưa trả)
void thongKeSoSachDangMuon() {
    system("clear");
    cout << "\n===== THONG KE SO SACH DANG DUOC MUON =====" << endl;
    int soSachDangMuon = 0;
    for(int i = 0; i < soLuongPhieu; ++i) {
        if(ngayTraThucTe[i].empty()) {
            // mỗi phiếu tương ứng 1 cuốn đang được mượn
            soSachDangMuon++;
        }
    }
    cout << "So sach dang duoc muon (so phieu chua tra): " << soSachDangMuon << endl;
    waitForEnter();
}


// Hiển thị danh sách độc giả trễ hạn
void danhSachDocGiaTreHan() {
    system("clear");
    cout << "\n===== DANH SACH DOC GIA TRE HAN =====" << endl;
    
    bool coDocGiaTreHan = false;
    
    for(int i = 0; i < soLuongPhieu; i++) {
        if(ngayTraThucTe[i].empty()) { // Chưa trả sách
            // Tìm thông tin độc giả
            for(int j = 0; j < soLuongDocGia; j++) {
                if(maDocGia[j] == maDocGiaMuon[i]) {
                    cout << "Ma doc gia: " << maDocGia[j] << endl;
                    cout << "Ho ten: " << hoTen[j] << endl;
                    cout << "CMND: " << cmnd[j] << endl;
                    cout << "Ngay muon: " << ngayMuon[i] << endl;
                    cout << "Ngay tra du kien: " << ngayTraDuKien[i] << endl;
                    cout << "Trang thai: Chua tra sach" << endl;
                    cout << "--------------------------------" << endl;
                    coDocGiaTreHan = true;
                    break;
                }
            }
        }
    }
    
    if(!coDocGiaTreHan) {
        cout << "Khong co doc gia nao tre han!" << endl;
    }
    
    cout << "Nhan Enter de tiep tuc...";
    cin.ignore();
}

