# C & C++ Learning Repository (UTC2 - 2024)

> Repository lưu trữ hành trình học tập ngôn ngữ lập trình **C** và **C++**, bao gồm các bài tập trên lớp, bài tập thực hành tại trường và các bài tự học mở rộng.

---

## Thông Tin Sinh Viên

* **Thời điểm thực hiện:** Tháng 12/2024 (Giai đoạn năm nhất Đại học)
* **Trường:** Phân hiệu Trường Đại học Giao thông Vận tải tại TP. Hồ Chí Minh (**UTC2**)
* **Mã số sinh viên (MSSV):** `6551071057`
* **Mục đích:** 
  - Hệ thống lại toàn bộ bài tập trên lớp, bài tập về nhà, bài tập thực hành môn Tin học đại cương / Kỹ thuật lập trình (ngôn ngữ C).
  - Tự nghiên cứu, rèn luyện tư duy thuật toán và lập trình với C và C++

---

## Cấu Trúc Repository

```text
C-program-utc2/
├── C/                          # Các bài học & bài tập ngôn ngữ C (Trên trường + Tự học)
│   ├── C ky1/                  # Học kỳ 1: Làm quen với cú pháp, cấu trúc điều khiển và bài tập cơ sở
│   │   ├── BTTT/               # Bài tập trên trường (Part 1 -> Part 5)
│   │   ├── BTVN/               # Bài tập về nhà theo từng ngày và đợt thực hành
│   │   ├── THDC/               # Tin học đại cương
│   │   ├── ThucHanh 1/         # Bài tập thực hành đợt 1
│   │   └── ThucHanh2/          # Bài tập thực hành đợt 2 & Thử thách (Challenge)
│   │
│   └── C ky2/                  # Học kỳ 2: Nâng cao kỹ năng xử lý mảng, con trỏ, struct, file I/O
│       ├── exercise/           # Các bài tập rèn luyện (Day 1 -> Day 5, quản lý sinh viên,...)
│       ├── school/             # Bài tập trên lớp & Lab (Lab01, Double Linked List, số phức,...)
│       └── TH/                 # Thực hành tổng hợp (Đọc ghi file, Quản lý thư viện - QLTV,...)
│
├── C++/                        # Tự học 100% ngôn ngữ C++
│   ├── basic/                  # C++ căn bản (Cú pháp, hàm, mảng, điều kiện, vòng lặp: Lesson 1 -> 8)
│   └── advance/                # C++ nâng cao & Cấu trúc dữ liệu giải thuật
│       ├── theory/             # Lý thuyết & Thư viện chuẩn STL (Vector, Set, Map, Pair & Tuple)
│       └── practice/           # Luyện tập thuật toán (Binary Search, bài toán tư duy: Lesson 1 -> 20)
│
└── README.md                   # Tài liệu giới thiệu repository
```

---

## Nội Dung & Kiến Thức Trọng Tâm

### 1. Ngôn ngữ C (Bài tập trường + Tự luyện)
- **Cơ bản:** Cú pháp, kiểu dữ liệu, toán tử, rẽ nhánh (`if-else`, `switch-case`), vòng lặp (`for`, `while`, `do-while`).
- **Nâng cao & Ứng dụng:**
  - Mảng 1 chiều, mảng 2 chiều và các thuật toán sắp xếp / tìm kiếm cơ bản.
  - Xử lý chuỗi ký tự (`string`).
  - Hàm (`function`), phạm vi biến và đệ quy.
  - Con trỏ (`pointer`) và cấp phát bộ nhớ động.
  - Kiểu cấu trúc (`struct`) để giải quyết bài toán thực tế (Quản lý sinh viên, Quản lý thư viện, số phức, hình học).
  - Cấu trúc dữ liệu tự tạo: Danh sách liên kết đôi (`Double Linked List`).
  - Thao tác tệp tin (`File I/O`): Đọc và ghi dữ liệu từ file text.

### 2. Ngôn ngữ C++ (Tự học)
- **Chuyển tiếp từ C sang C++:** Sử dụng `cin`, `cout`, thư viện chuẩn `<iostream>`, kiểu dữ liệu `string`.
- **Thư viện chuẩn C++ STL (Standard Template Library):**
  - `vector`: Mảng động linh hoạt.
  - `pair`, `tuple`: Ghép cặp và quản lý nhóm dữ liệu liên quan.
  - `set`, `map`: Cấu trúc dữ liệu tra cứu và lưu trữ theo key-value hiệu quả.
- **Tư duy thuật toán:**
  - Tìm kiếm nhị phân (`Binary Search`).
  - Các bài tập luyện tư duy logic thuật toán (20 lessons bài tập nâng cao).

---

## Hướng Dẫn Biên Dịch & Chạy Mã Nguồn

Có thể sử dụng trình biên dịch GCC/G++ (thông qua MinGW trên Windows hoặc GCC trên Linux/macOS):

### Đối với tệp C:
```bash
# Biên dịch
gcc "duong_dan_toi_file.c" -o chuongtrinh

# Chạy chương trình
./chuongtrinh        # Trên Linux / macOS / Git Bash
chuongtrinh.exe      # Trên Windows Command Prompt / PowerShell
```

### Đối với tệp C++:
```bash
# Biên dịch (hỗ trợ C++11 trở lên để dùng đầy đủ STL)
g++ -std=c++11 "duong_dan_toi_file.cpp" -o chuongtrinh

# Chạy chương trình
./chuongtrinh        # Trên Linux / macOS / Git Bash
chuongtrinh.exe      # Trên Windows Command Prompt / PowerShell
```