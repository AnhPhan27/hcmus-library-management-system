#include "muontra.h"

// Định nghĩa mảng toàn cục cho phiếu mượn/trả
string maPhieuMuon[MAX_PHIEU];
string maDocGiaMuon[MAX_PHIEU];
string ISBNMuon[MAX_PHIEU];
string ngayMuon[MAX_PHIEU];
string ngayTraDuKien[MAX_PHIEU];
string ngayTraThucTe[MAX_PHIEU];
int soLuongPhieu = 0;

void menuMuonTra() {
    int luaChon;
    do {
        system("clear");
        cout << "\n===== MUON TRA SACH =====" << endl;
        cout << "1. Muon sach" << endl;
        cout << "2. Tra sach" << endl;
        cout << "3. Xem danh sach phieu muon" << endl;
        cout << "0. Quay lai menu chinh" << endl;
        cout << "=========================" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();
        
        switch(luaChon) {
            case 1:
                muonSach();
                break;
            case 2:
                traSach();
                break;
            case 3:
                xemDanhSachPhieuMuon();
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

void muonSach() {
    system("clear");
    cout << "\n===== MUON SACH =====" << endl;
    
    if(soLuongPhieu >= MAX_PHIEU) {
        cout << "He thong da day!" << endl;
        cout << "Nhan Enter de tiep tuc...";
        cin.ignore();
        return;
    }
    
    string maDocGiaInput, isbnInput, ngayMuonInput;
    
    cout << "Nhap ma doc gia: ";
    getline(cin, maDocGiaInput);
    
    if(timViTriDocGia(maDocGiaInput) == -1) {
        cout << "Khong tim thay doc gia!" << endl;
        cout << "Nhan Enter de tiep tuc...";
        cin.ignore();
        return;
    }
    
    cout << "Nhap ISBN sach: ";
    getline(cin, isbnInput);
    
    if(!kiemTraSachCoSan(isbnInput)) {
        cout << "Sach khong co san!" << endl;
        cout << "Nhan Enter de tiep tuc...";
        cin.ignore();
        return;
    }
    
    cout << "Nhap ngay muon (dd/mm/yyyy): ";
    getline(cin, ngayMuonInput);
    
    string maPhieu = "PM" + to_string(soLuongPhieu + 1001);
    
    maPhieuMuon[soLuongPhieu] = maPhieu;
    maDocGiaMuon[soLuongPhieu] = maDocGiaInput;
    ISBNMuon[soLuongPhieu] = isbnInput;
    ngayMuon[soLuongPhieu] = ngayMuonInput;
    ngayTraDuKien[soLuongPhieu] = tinhNgayTraDuKien(ngayMuonInput);
    ngayTraThucTe[soLuongPhieu] = "";
    
    giamSoLuongSach(isbnInput);
    soLuongPhieu++;
    
    cout << "Muon sach thanh cong!" << endl;
    cout << "Ma phieu: " << maPhieu << endl;
    cout << "Nhan Enter de tiep tuc...";
    cin.ignore();
}

void traSach() {
    system("clear");
    cout << "\n===== TRA SACH =====" << endl;
    
    string maPhieu;
    cout << "Nhap ma phieu muon: ";
    getline(cin, maPhieu);
    
    int index = -1;
    for(int i = 0; i < soLuongPhieu; i++) {
        if(maPhieuMuon[i] == maPhieu && ngayTraThucTe[i].empty()) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        cout << "Khong tim thay phieu muon!" << endl;
        cout << "Nhan Enter de tiep tuc...";
        cin.ignore();
        return;
    }
    
    string ngayTraInput;
    cout << "Nhap ngay tra (dd/mm/yyyy): ";
    getline(cin, ngayTraInput);
    
    ngayTraThucTe[index] = ngayTraInput;
    tangSoLuongSach(ISBNMuon[index]);
    
    float tienPhat = tinhTienPhat(ngayTraDuKien[index], ngayTraInput);
    
    cout << "Tra sach thanh cong!" << endl;
    if(tienPhat > 0) {
        cout << "Tien phat: " << tienPhat << " VND" << endl;
    }
    cout << "Nhan Enter de tiep tuc...";
    cin.ignore();
}

void xemDanhSachPhieuMuon() {
    system("clear");
    cout << "\n===== DANH SACH PHIEU MUON =====" << endl;
    
    if(soLuongPhieu == 0) {
        cout << "Khong co phieu muon nao!" << endl;
    } else {
        for(int i = 0; i < soLuongPhieu; i++) {
            hienThiThongTinPhieuMuon(i);
        }
    }
    
    cout << "Nhan Enter de tiep tuc...";
    cin.ignore();
}

void timPhieuMuonTheoDocGia() {
    cout << "Chua thuc hien" << endl;
}

void xemSachQuaHan() {
    cout << "Chua thuc hien" << endl;
}

string tinhNgayTraDuKien(string ngayMuon) {
    return ngayMuon; // Đơn giản hóa
}

float tinhTienPhat(string ngayTraDuKien, string ngayTraThucTe) {
    return 0; // Đơn giản hóa
}

int soSanhNgay(string ngay1, string ngay2) {
    return 0; // Đơn giản hóa
}

void hienThiThongTinPhieuMuon(int index) {
    cout << "Ma phieu: " << maPhieuMuon[index] << endl;
    cout << "Ma doc gia: " << maDocGiaMuon[index] << endl;
    cout << "ISBN: " << ISBNMuon[index] << endl;
    cout << "Ngay muon: " << ngayMuon[index] << endl;
    cout << "Ngay tra du kien: " << ngayTraDuKien[index] << endl;
    cout << "Ngay tra thuc te: " << (ngayTraThucTe[index].empty() ? "Chua tra" : ngayTraThucTe[index]) << endl;
    cout << "--------------------------------" << endl;
}
