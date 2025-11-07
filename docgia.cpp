#include "docgia.h"
#include "utils.h"

// Định nghĩa mảng toàn cục cho độc giả
string maDocGia[MAX_DOCGIA];
string hoTen[MAX_DOCGIA];
string cmnd[MAX_DOCGIA];
string ngaySinh[MAX_DOCGIA];
string gioiTinh[MAX_DOCGIA];
string email[MAX_DOCGIA];
string diaChi[MAX_DOCGIA];
string ngayLapThe[MAX_DOCGIA];
string ngayHetHan[MAX_DOCGIA];
int soLuongDocGia = 0;
// Khởi tạo mảng tiền nợ/phạt cho mỗi độc giả
float tienNo[MAX_DOCGIA];

void menuDocGia() {
    int luaChon;
    do {
        system("clear");
        cout << "\n===== QUAN LY DOC GIA =====" << endl;
        cout << "1. Xem danh sach doc gia" << endl;
        cout << "2. Them doc gia moi" << endl;
        cout << "3. Chinh sua thong tin doc gia" << endl;
        cout << "4. Xoa doc gia" << endl;
        cout << "5. Tim doc gia theo CMND" << endl;
        cout << "6. Tim doc gia theo ho ten" << endl;
        cout << "0. Quay lai menu chinh" << endl;
        cout << "==============================" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        discardLine();
        
        switch(luaChon) {
            case 1:
                xemDanhSachDocGia();
                break;
            case 2:
                themDocGia();
                break;
            case 3:
                chinhSuaDocGia();
                break;
            case 4:
                xoaDocGia();
                break;
            case 5:
                timDocGiaTheoCMND();
                break;
            case 6:
                timDocGiaTheoHoTen();
                break;
            case 0:
                cout << "Quay lai menu chinh..." << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                cout << "Nhan Enter de tiep tuc...";
                waitForEnter();
        }
    } while(luaChon != 0);
}

void xemDanhSachDocGia() {
    system("clear");
    cout << "\n===== DANH SACH DOC GIA =====" << endl;
    
    if(soLuongDocGia == 0) {
        cout << "Khong co doc gia nao trong he thong!" << endl;
    } else {
        cout << "Tong so doc gia: " << soLuongDocGia << endl;
        cout << "--------------------------------" << endl;
        
        for(int i = 0; i < soLuongDocGia; i++) {
            hienThiThongTinDocGia(i);
        }
    }
    
    waitForEnter();
}

void themDocGia() {
    system("clear");
    cout << "\n===== THEM DOC GIA MOI =====" << endl;
    
    if(soLuongDocGia >= MAX_DOCGIA) {
        cout << "He thong da day! Khong the them doc gia moi." << endl;
        cout << "Nhan Enter de tiep tuc...";
        waitForEnter();
        return;
    }
    
    string ma, ten, cmndInput, ngaySinhInput, gioiTinhInput, emailInput, diaChiInput, ngayLapInput;
    
    cout << "Nhap ma doc gia: ";
    getline(cin, ma);
    
    if(timViTriDocGia(ma) != -1) {
        cout << "Ma doc gia da ton tai!" << endl;
        cout << "Nhan Enter de tiep tuc...";
        waitForEnter();
        return;
    }
    
    cout << "Nhap ho ten: ";
    getline(cin, ten);
    
    cout << "Nhap CMND: ";
    getline(cin, cmndInput);
    
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, ngaySinhInput);
    
    cout << "Nhap gioi tinh (Nam/Nu): ";
    getline(cin, gioiTinhInput);
    
    cout << "Nhap email: ";
    getline(cin, emailInput);
    
    cout << "Nhap dia chi: ";
    getline(cin, diaChiInput);
    
    cout << "Nhap ngay lap the (dd/mm/yyyy): ";
    getline(cin, ngayLapInput);
    
    maDocGia[soLuongDocGia] = ma;
    hoTen[soLuongDocGia] = ten;
    cmnd[soLuongDocGia] = cmndInput;
    ngaySinh[soLuongDocGia] = ngaySinhInput;
    gioiTinh[soLuongDocGia] = gioiTinhInput;
    email[soLuongDocGia] = emailInput;
    diaChi[soLuongDocGia] = diaChiInput;
    ngayLapThe[soLuongDocGia] = ngayLapInput;
    ngayHetHan[soLuongDocGia] = tinhNgayHetHan(ngayLapInput);
    tienNo[soLuongDocGia] = 0.0f; // ban dau khong co no
    
    soLuongDocGia++;
    
    cout << "Them doc gia thanh cong!" << endl;
    waitForEnter();
}

void chinhSuaDocGia() {
    system("clear");
    cout << "\n===== CHINH SUA THONG TIN DOC GIA =====" << endl;
    
    string ma;
    cout << "Nhap ma doc gia can sua: ";
    getline(cin, ma);
    
    int index = timViTriDocGia(ma);
    if(index == -1) {
        cout << "Khong tim thay doc gia co ma: " << ma << endl;
        waitForEnter();
        return;
    }
    
    cout << "Thong tin hien tai cua doc gia:" << endl;
    hienThiThongTinDocGia(index);
    
    cout << "\nNhap thong tin moi (nhan Enter de giu nguyen):" << endl;
    
    string input;
    cout << "Ho ten moi: ";
    getline(cin, input);
    if(!input.empty()) hoTen[index] = input;
    
    cout << "CMND moi: ";
    getline(cin, input);
    if(!input.empty()) cmnd[index] = input;
    
    cout << "Ngay sinh moi: ";
    getline(cin, input);
    if(!input.empty()) ngaySinh[index] = input;
    
    cout << "Gioi tinh moi: ";
    getline(cin, input);
    if(!input.empty()) gioiTinh[index] = input;
    
    cout << "Email moi: ";
    getline(cin, input);
    if(!input.empty()) email[index] = input;
    
    cout << "Dia chi moi: ";
    getline(cin, input);
    if(!input.empty()) diaChi[index] = input;
    
    cout << "Cap nhat thong tin thanh cong!" << endl;
    waitForEnter();
}

void xoaDocGia() {
    system("clear");
    cout << "\n===== XOA DOC GIA =====" << endl;
    
    string ma;
    cout << "Nhap ma doc gia can xoa: ";
    getline(cin, ma);
    
    int index = timViTriDocGia(ma);
    if(index == -1) {
        cout << "Khong tim thay doc gia co ma: " << ma << endl;
        waitForEnter();
        return;
    }
    
    cout << "Thong tin doc gia can xoa:" << endl;
    hienThiThongTinDocGia(index);
    
    char xacNhan;
    cout << "Ban co chac chan muon xoa doc gia nay? (y/n): ";
    cin >> xacNhan;
    
    if(xacNhan == 'y' || xacNhan == 'Y') {
        for(int i = index; i < soLuongDocGia - 1; i++) {
            maDocGia[i] = maDocGia[i + 1];
            hoTen[i] = hoTen[i + 1];
            cmnd[i] = cmnd[i + 1];
            ngaySinh[i] = ngaySinh[i + 1];
            gioiTinh[i] = gioiTinh[i + 1];
            email[i] = email[i + 1];
            diaChi[i] = diaChi[i + 1];
            ngayLapThe[i] = ngayLapThe[i + 1];
            ngayHetHan[i] = ngayHetHan[i + 1];
            tienNo[i] = tienNo[i + 1];
        }
        soLuongDocGia--;
        cout << "Xoa doc gia thanh cong!" << endl;
    } else {
        cout << "Huy bo thao tac xoa." << endl;
    }
    
    waitForEnter();
}

void timDocGiaTheoCMND() {
    system("clear");
    cout << "\n===== TIM DOC GIA THEO CMND =====" << endl;
    
    string cmndTimKiem;
    cout << "Nhap CMND can tim: ";
    getline(cin, cmndTimKiem);
    
    bool timThay = false;
    for(int i = 0; i < soLuongDocGia; i++) {
        if(cmnd[i] == cmndTimKiem) {
            cout << "Tim thay doc gia:" << endl;
            hienThiThongTinDocGia(i);
            timThay = true;
            break;
        }
    }
    
    if(!timThay) {
        cout << "Khong tim thay doc gia co CMND: " << cmndTimKiem << endl;
    }
    
    waitForEnter();
}

void timDocGiaTheoHoTen() {
    system("clear");
    cout << "\n===== TIM DOC GIA THEO HO TEN =====" << endl;
    
    string tenTimKiem;
    cout << "Nhap ho ten can tim: ";
    getline(cin, tenTimKiem);
    
    bool timThay = false;
    cout << "Ket qua tim kiem:" << endl;
    
    for(int i = 0; i < soLuongDocGia; i++) {
        if(hoTen[i].find(tenTimKiem) != string::npos) {
            hienThiThongTinDocGia(i);
            timThay = true;
        }
    }
    
    if(!timThay) {
        cout << "Khong tim thay doc gia co ho ten chua: " << tenTimKiem << endl;
    }
    
    waitForEnter();
}

string tinhNgayHetHan(string ngayLap) {
    if(ngayLap.length() >= 10) {
        string nam = ngayLap.substr(6, 4);
        int namInt = stoi(nam) + 4;
        return ngayLap.substr(0, 6) + to_string(namInt);
    }
    return ngayLap;
}

int timViTriDocGia(string ma) {
    for(int i = 0; i < soLuongDocGia; i++) {
        if(maDocGia[i] == ma) {
            return i;
        }
    }
    return -1;
}

void hienThiThongTinDocGia(int index) {
    cout << "Ma doc gia: " << maDocGia[index] << endl;
    cout << "Ho ten: " << hoTen[index] << endl;
    cout << "CMND: " << cmnd[index] << endl;
    cout << "Ngay sinh: " << ngaySinh[index] << endl;
    cout << "Gioi tinh: " << gioiTinh[index] << endl;
    cout << "Email: " << email[index] << endl;
    cout << "Dia chi: " << diaChi[index] << endl;
    cout << "Ngay lap the: " << ngayLapThe[index] << endl;
    cout << "Ngay het han: " << ngayHetHan[index] << endl;
    cout << "--------------------------------" << endl;
}
