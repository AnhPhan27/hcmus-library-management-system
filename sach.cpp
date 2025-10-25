#include "sach.h"

// Định nghĩa mảng toàn cục cho sách
string ISBN[MAX_SACH];
string tenSach[MAX_SACH];
string tacGia[MAX_SACH];
string nhaXuatBan[MAX_SACH];
int namXuatBan[MAX_SACH];
string theLoai[MAX_SACH];
float giaSach[MAX_SACH];
int soQuyen[MAX_SACH];
int soLuongSach = 0;

void menuSach() {
    int luaChon;
    do {
        system("clear");
        cout << "\n===== QUAN LY SACH =====" << endl;
        cout << "1. Xem danh sach sach" << endl;
        cout << "2. Them sach moi" << endl;
        cout << "3. Chinh sua thong tin sach" << endl;
        cout << "4. Xoa sach" << endl;
        cout << "5. Tim sach theo ISBN" << endl;
        cout << "6. Tim sach theo ten" << endl;
        cout << "7. Tim sach theo tac gia" << endl;
        cout << "0. Quay lai menu chinh" << endl;
        cout << "=========================" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();
        
        switch(luaChon) {
            case 1:
                xemDanhSachSach();
                break;
            case 2:
                themSach();
                break;
            case 3:
                chinhSuaSach();
                break;
            case 4:
                xoaSach();
                break;
            case 5:
                timSachTheoISBN();
                break;
            case 6:
                timSachTheoTen();
                break;
            case 7:
                timSachTheoTacGia();
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

void xemDanhSachSach() {
    system("clear");
    cout << "\n===== DANH SACH SACH =====" << endl;
    
    if(soLuongSach == 0) {
        cout << "Khong co sach nao trong thu vien!" << endl;
    } else {
        cout << "Tong so sach: " << soLuongSach << endl;
        cout << "--------------------------------" << endl;
        
        for(int i = 0; i < soLuongSach; i++) {
            hienThiThongTinSach(i);
        }
    }
    
    cout << "Nhan Enter de tiep tuc...";
    cin.ignore();
}

void themSach() {
    system("clear");
    cout << "\n===== THEM SACH MOI =====" << endl;
    
    if(soLuongSach >= MAX_SACH) {
        cout << "Thu vien da day! Khong the them sach moi." << endl;
        cout << "Nhan Enter de tiep tuc...";
        cin.ignore();
        return;
    }
    
    string isbnInput, ten, tacGiaInput, nxb, theLoaiInput;
    int nam, soQuyenInput;
    float gia;
    
    cout << "Nhap ISBN: ";
    getline(cin, isbnInput);
    
    if(timViTriSach(isbnInput) != -1) {
        cout << "ISBN da ton tai!" << endl;
        cout << "Nhan Enter de tiep tuc...";
        cin.ignore();
        return;
    }
    
    cout << "Nhap ten sach: ";
    getline(cin, ten);
    
    cout << "Nhap tac gia: ";
    getline(cin, tacGiaInput);
    
    cout << "Nhap nha xuat ban: ";
    getline(cin, nxb);
    
    cout << "Nhap nam xuat ban: ";
    cin >> nam;
    cin.ignore();
    
    cout << "Nhap the loai: ";
    getline(cin, theLoaiInput);
    
    cout << "Nhap gia sach: ";
    cin >> gia;
    
    cout << "Nhap so quyen: ";
    cin >> soQuyenInput;
    
    ISBN[soLuongSach] = isbnInput;
    tenSach[soLuongSach] = ten;
    tacGia[soLuongSach] = tacGiaInput;
    nhaXuatBan[soLuongSach] = nxb;
    namXuatBan[soLuongSach] = nam;
    theLoai[soLuongSach] = theLoaiInput;
    giaSach[soLuongSach] = gia;
    soQuyen[soLuongSach] = soQuyenInput;
    
    soLuongSach++;
    
    cout << "Them sach thanh cong!" << endl;
    cout << "Nhan Enter de tiep tuc...";
    cin.ignore();
    cin.ignore();
}

void chinhSuaSach() {
    system("clear");
    cout << "\n===== CHINH SUA THONG TIN SACH =====" << endl;
    
    string isbnInput;
    cout << "Nhap ISBN sach can sua: ";
    getline(cin, isbnInput);
    
    int index = timViTriSach(isbnInput);
    if(index == -1) {
        cout << "Khong tim thay sach co ISBN: " << isbnInput << endl;
        cout << "Nhan Enter de tiep tuc...";
        cin.ignore();
        return;
    }
    
    cout << "Thong tin hien tai cua sach:" << endl;
    hienThiThongTinSach(index);
    
    cout << "\nNhap thong tin moi (nhan Enter de giu nguyen):" << endl;
    
    string input;
    cout << "Ten sach moi: ";
    getline(cin, input);
    if(!input.empty()) tenSach[index] = input;
    
    cout << "Tac gia moi: ";
    getline(cin, input);
    if(!input.empty()) tacGia[index] = input;
    
    cout << "Nha xuat ban moi: ";
    getline(cin, input);
    if(!input.empty()) nhaXuatBan[index] = input;
    
    cout << "Nam xuat ban moi: ";
    getline(cin, input);
    if(!input.empty()) namXuatBan[index] = stoi(input);
    
    cout << "The loai moi: ";
    getline(cin, input);
    if(!input.empty()) theLoai[index] = input;
    
    cout << "Gia sach moi: ";
    getline(cin, input);
    if(!input.empty()) giaSach[index] = stof(input);
    
    cout << "So quyen moi: ";
    getline(cin, input);
    if(!input.empty()) soQuyen[index] = stoi(input);
    
    cout << "Cap nhat thong tin thanh cong!" << endl;
    cout << "Nhan Enter de tiep tuc...";
    cin.ignore();
}

void xoaSach() {
    system("clear");
    cout << "\n===== XOA SACH =====" << endl;
    
    string isbnInput;
    cout << "Nhap ISBN sach can xoa: ";
    getline(cin, isbnInput);
    
    int index = timViTriSach(isbnInput);
    if(index == -1) {
        cout << "Khong tim thay sach co ISBN: " << isbnInput << endl;
        cout << "Nhan Enter de tiep tuc...";
        cin.ignore();
        return;
    }
    
    cout << "Thong tin sach can xoa:" << endl;
    hienThiThongTinSach(index);
    
    char xacNhan;
    cout << "Ban co chac chan muon xoa sach nay? (y/n): ";
    cin >> xacNhan;
    
    if(xacNhan == 'y' || xacNhan == 'Y') {
        for(int i = index; i < soLuongSach - 1; i++) {
            ISBN[i] = ISBN[i + 1];
            tenSach[i] = tenSach[i + 1];
            tacGia[i] = tacGia[i + 1];
            nhaXuatBan[i] = nhaXuatBan[i + 1];
            namXuatBan[i] = namXuatBan[i + 1];
            theLoai[i] = theLoai[i + 1];
            giaSach[i] = giaSach[i + 1];
            soQuyen[i] = soQuyen[i + 1];
        }
        soLuongSach--;
        cout << "Xoa sach thanh cong!" << endl;
    } else {
        cout << "Huy bo thao tac xoa." << endl;
    }
    
    cout << "Nhan Enter de tiep tuc...";
    cin.ignore();
    cin.ignore();
}

void timSachTheoISBN() {
    system("clear");
    cout << "\n===== TIM SACH THEO ISBN =====" << endl;
    
    string isbnTimKiem;
    cout << "Nhap ISBN can tim: ";
    getline(cin, isbnTimKiem);
    
    int index = timViTriSach(isbnTimKiem);
    if(index != -1) {
        cout << "Tim thay sach:" << endl;
        hienThiThongTinSach(index);
    } else {
        cout << "Khong tim thay sach co ISBN: " << isbnTimKiem << endl;
    }
    
    cout << "Nhan Enter de tiep tuc...";
    cin.ignore();
}

void timSachTheoTen() {
    system("clear");
    cout << "\n===== TIM SACH THEO TEN =====" << endl;
    
    string tenTimKiem;
    cout << "Nhap ten sach can tim: ";
    getline(cin, tenTimKiem);
    
    bool timThay = false;
    cout << "Ket qua tim kiem:" << endl;
    
    for(int i = 0; i < soLuongSach; i++) {
        if(tenSach[i].find(tenTimKiem) != string::npos) {
            hienThiThongTinSach(i);
            timThay = true;
        }
    }
    
    if(!timThay) {
        cout << "Khong tim thay sach co ten chua: " << tenTimKiem << endl;
    }
    
    cout << "Nhan Enter de tiep tuc...";
    cin.ignore();
}

void timSachTheoTacGia() {
    system("clear");
    cout << "\n===== TIM SACH THEO TAC GIA =====" << endl;
    
    string tacGiaTimKiem;
    cout << "Nhap ten tac gia can tim: ";
    getline(cin, tacGiaTimKiem);
    
    bool timThay = false;
    cout << "Ket qua tim kiem:" << endl;
    
    for(int i = 0; i < soLuongSach; i++) {
        if(tacGia[i].find(tacGiaTimKiem) != string::npos) {
            hienThiThongTinSach(i);
            timThay = true;
        }
    }
    
    if(!timThay) {
        cout << "Khong tim thay sach cua tac gia: " << tacGiaTimKiem << endl;
    }
    
    cout << "Nhan Enter de tiep tuc...";
    cin.ignore();
}

int timViTriSach(string isbnInput) {
    for(int i = 0; i < soLuongSach; i++) {
        if(ISBN[i] == isbnInput) {
            return i;
        }
    }
    return -1;
}

void hienThiThongTinSach(int index) {
    cout << "ISBN: " << ISBN[index] << endl;
    cout << "Ten sach: " << tenSach[index] << endl;
    cout << "Tac gia: " << tacGia[index] << endl;
    cout << "Nha xuat ban: " << nhaXuatBan[index] << endl;
    cout << "Nam xuat ban: " << namXuatBan[index] << endl;
    cout << "The loai: " << theLoai[index] << endl;
    cout << "Gia: " << giaSach[index] << " VND" << endl;
    cout << "So quyen: " << soQuyen[index] << endl;
    cout << "--------------------------------" << endl;
}

bool kiemTraSachCoSan(string isbnInput) {
    int index = timViTriSach(isbnInput);
    if(index != -1 && soQuyen[index] > 0) {
        return true;
    }
    return false;
}

void giamSoLuongSach(string isbnInput) {
    int index = timViTriSach(isbnInput);
    if(index != -1 && soQuyen[index] > 0) {
        soQuyen[index]--;
    }
}

void tangSoLuongSach(string isbnInput) {
    int index = timViTriSach(isbnInput);
    if(index != -1) {
        soQuyen[index]++;
    }
}

bool capNhatSoLuongSach(string isbn_input, int soLuongThayDoi) {
    int index = timViTriSach(isbn_input);
    if(index != -1) {
        soQuyen[index] += soLuongThayDoi;
        if(soQuyen[index] < 0) {
            soQuyen[index] = 0;
            return false;
        }
        return true;
    }
    return false;
}
