#include "muontra.h"
#include "utils.h"
#include <cstdio>



static int parseNgayThanhSoNgay(string ngayStr);

// Kiểm tra năm nhuận
static bool laNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

// Số ngày trong một tháng của năm
static int soNgayTrongThang(int nam, int thang) {
    static const int mdays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if(thang == 2) return laNamNhuan(nam) ? 29 : 28;
    if(thang >= 1 && thang <= 12) return mdays[thang-1];
    return 30; 
}

static string congNgay(int d, int m, int y, int cong) {
    int day = d, month = m, year = y;
    for(int i = 0; i < cong; ++i) {
        day += 1;
        int dim = soNgayTrongThang(year, month);
        if(day > dim) {
            day = 1;
            month += 1;
            if(month > 12) { month = 1; year += 1; }
        }
    }
    string dayStr = (day < 10) ? string("0") + to_string(day) : to_string(day);
    string monthStr = (month < 10) ? string("0") + to_string(month) : to_string(month);
    return dayStr + "/" + monthStr + "/" + to_string(year);
}

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
    discardLine();
        
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
                waitForEnter();
        }
    } while(luaChon != 0);
}

void muonSach() {
    system("clear");
    cout << "\n===== MUON SACH =====" << endl;
    
    if(soLuongPhieu >= MAX_PHIEU) {
        cout << "He thong da day!" << endl;
        waitForEnter();
        return;
    }
    
    string maDocGiaInput, isbnInput, ngayMuonInput;
    
    cout << "Nhap ma doc gia: ";
    getline(cin, maDocGiaInput);
    
    if(timViTriDocGia(maDocGiaInput) == -1) {
        cout << "Khong tim thay doc gia!" << endl;
        waitForEnter();
        return;
    }
    
    cout << "Nhap ISBN sach: ";
    getline(cin, isbnInput);
    
    if(!kiemTraSachCoSan(isbnInput)) {
        cout << "Sach khong co san!" << endl;
        waitForEnter();
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
    waitForEnter();
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
        {
            string _tmp;
            getline(cin, _tmp);
        }
        return;
    }
    
    // Hỏi người dùng xem là trả sách hay báo mất
    cout << "1. Tra sach thong thuong" << endl;
    cout << "2. Bao mat sach" << endl;
    cout << "Chon (1/2): ";
    int luaChonTra = 1;
    cin >> luaChonTra;
    discardLine();

    if(luaChonTra == 1) {
        // Trả sách bình thường
        string ngayTraInput;
        cout << "Nhap ngay tra (dd/mm/yyyy): ";
        getline(cin, ngayTraInput);
        ngayTraThucTe[index] = ngayTraInput;
        tangSoLuongSach(ISBNMuon[index]);

        float tienPhat = tinhTienPhat(ngayTraDuKien[index], ngayTraInput);

        // Tính số ngày trễ để hiển thị chi tiết
        int soNgayDuKien = parseNgayThanhSoNgay(ngayTraDuKien[index]);
        int soNgayThucTe = parseNgayThanhSoNgay(ngayTraInput);
        int soNgayTre = 0;
        if(soNgayThucTe > soNgayDuKien) soNgayTre = soNgayThucTe - soNgayDuKien;

        cout << "Tra sach thanh cong!" << endl;
        if(soNgayTre > 0) {
            cout << "So ngay tre: " << soNgayTre << " ngay" << endl;
            cout << "Tien phat: " << soNgayTre << " x 5000 VND = " << tienPhat << " VND" << endl;
        } else {
            cout << "Khong co tien phat." << endl;
        }
        waitForEnter();
    } else if(luaChonTra == 2) {
        // Báo mất sách: phạt 200% giá sách
        string ngayBaoMat;
        cout << "Nhap ngay bao mat (dd/mm/yyyy): ";
        getline(cin, ngayBaoMat);
        ngayTraThucTe[index] = ngayBaoMat; // lưu ngày báo mất

        int idxSach = timViTriSach(ISBNMuon[index]);
        float fine = 0.0f;
        if(idxSach != -1) {
            fine = 2.0f * giaSach[idxSach]; // 200% giá sách
        }

        int idxDocGia = timViTriDocGia(maDocGiaMuon[index]);
        if(idxDocGia != -1) {
            tienNo[idxDocGia] += fine;
        }

        // Không tăng lại số lượng sách vì sách mất
        cout << "Sach da duoc bao mat. Doc gia bi phat: " << fine << " VND (200% gia sach)" << endl;
        waitForEnter();
    } else {
        cout << "Lua chon khong hop le. Huy bo." << endl;
        waitForEnter();
    }
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
    
    waitForEnter();
}

// Tính ngày trả dự kiến = ngày mượn + 7 ngày
string tinhNgayTraDuKien(string ngayMuon) {
    int ngay = stoi(ngayMuon.substr(0, 2));
    int thang = stoi(ngayMuon.substr(3, 2));
    int nam = stoi(ngayMuon.substr(6, 4));

    return congNgay(ngay, thang, nam, 7);
}

// Tính tiền phạt dựa trên số ngày trễ hạn (5,000 VND/ngày)
float tinhTienPhat(string ngayTraDuKien, string ngayTraThucTe) {
    int soNgayDuKien = parseNgayThanhSoNgay(ngayTraDuKien);
    int soNgayThucTe = parseNgayThanhSoNgay(ngayTraThucTe);
    
    // Kiểm tra nếu trả đúng hạn hoặc sớm
    if(soNgayThucTe <= soNgayDuKien) {
        return 0; // Không phạt
    }
    
    // Tính số ngày trễ hạn
    int soNgayTre = soNgayThucTe - soNgayDuKien;

    // Phạt 5,000 VND/ngày trễ hạn
    float tienPhat = (float)(soNgayTre * 5000);
    
    return tienPhat;
}

static int parseNgayThanhSoNgay(string ngayStr) {
    int ngay = 0, thang = 0, nam = 0;
    const string &s = ngayStr;
    int i = 0, n = (int)s.size();

    auto docSo = [&](int &ketQua)->bool {
        if(i >= n || s[i] < '0' || s[i] > '9') return false;
        int v = 0;
        while(i < n && s[i] >= '0' && s[i] <= '9') { v = v*10 + (s[i]-'0'); ++i; }
        ketQua = v; return true;
    };

    if(!docSo(ngay)) return 0;
    if(i >= n || (s[i] != '/' && s[i] != '-')) return 0; ++i;
    if(!docSo(thang)) return 0;
    if(i >= n || (s[i] != '/' && s[i] != '-')) return 0; ++i;
    if(!docSo(nam)) return 0;

    if(thang < 1 || thang > 12) return 0;
    int dim = soNgayTrongThang(nam, thang);
    if(ngay < 1 || ngay > dim) return 0;

    // số ngày tích lũy trước mỗi tháng (năm không nhuận)
    static const int soNgayTichLuyTruocThang[] = {0,0,31,59,90,120,151,181,212,243,273,304,334};
    int ngayTrongNam = soNgayTichLuyTruocThang[thang] + ngay;
    if(laNamNhuan(nam) && thang > 2) ngayTrongNam += 1;

    int namTruoc = nam - 1;
    int soNamNhuan = namTruoc/4 - namTruoc/100 + namTruoc/400;
    int tongNgay = namTruoc * 365 + soNamNhuan + ngayTrongNam;
    return tongNgay;
}

// So sánh 2 ngày và trả về số ngày chênh lệch
int soSanhNgay(string ngay1, string ngay2) {
    if(ngay1 == ngay2) {
        return 0;
    }
    
    int soNgay1 = parseNgayThanhSoNgay(ngay1);
    int soNgay2 = parseNgayThanhSoNgay(ngay2);
    int diff = (soNgay1 >= soNgay2) ? (soNgay1 - soNgay2) : (soNgay2 - soNgay1);
    return diff;
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
