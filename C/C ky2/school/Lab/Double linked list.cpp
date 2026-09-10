#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <set>

using namespace std;

// ### Cấu trúc dữ liệu

struct Date {
    int day, month, year;
};

struct Reader {
    string id;
    string name;
    string mssv;
    Date dob;
    string gender;
    Date cardCreationDate;
    Date cardExpiryDate;
};

struct Book {
    string isbn;
    string title;
    string author;
    int year;
    string genre;
    double price;
    int quantity;
};

struct BorrowRecord {
    string readerId;
    Date borrowDate;
    Date expectedReturnDate;
    Date actualReturnDate;
    vector<string> isbns;
    vector<int> statuses; // 0: chưa trả, 1: đã trả, 2: mất
};

// ### Hàm xử lý ngày tháng

Date getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return {ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900};
}

Date addDays(Date date, int days) {
    date.day += days;
    while (date.day > 30) {
        date.day -= 30;
        date.month++;
        if (date.month > 12) {
            date.month = 1;
            date.year++;
        }
    }
    return date;
}

Date addMonths(Date date, int months) {
    date.month += months;
    while (date.month > 12) {
        date.month -= 12;
        date.year++;
    }
    return date;
}

long long dateDiff(Date d1, Date d2) {
    // Tính xấp xỉ số ngày chênh lệch
    return (d2.year - d1.year) * 365 + (d2.month - d1.month) * 30 + (d2.day - d1.day);
}

// ### Hàm đọc/ghi file

vector<Reader> readReaders() {
    vector<Reader> readers;
    ifstream file("readers.txt");
    if (file.is_open()) {
        Reader r;
        while (file >> r.id >> r.name >> r.mssv >> r.dob.day >> r.dob.month >> r.dob.year 
               >> r.gender >> r.cardCreationDate.day >> r.cardCreationDate.month >> r.cardCreationDate.year
               >> r.cardExpiryDate.day >> r.cardExpiryDate.month >> r.cardExpiryDate.year) {
            readers.push_back(r);
        }
        file.close();
    }
    return readers;
}

void writeReaders(const vector<Reader>& readers) {
    ofstream file("readers.txt");
    if (file.is_open()) {
        for (const auto& r : readers) {
            file << r.id << " " << r.name << " " << r.mssv << " " 
                 << r.dob.day << " " << r.dob.month << " " << r.dob.year << " "
                 << r.gender << " "
                 << r.cardCreationDate.day << " " << r.cardCreationDate.month << " " << r.cardCreationDate.year << " "
                 << r.cardExpiryDate.day << " " << r.cardExpiryDate.month << " " << r.cardExpiryDate.year << "\n";
        }
        file.close();
    }
}

vector<Book> readBooks() {
    vector<Book> books;
    ifstream file("books.txt");
    if (file.is_open()) {
        Book b;
        while (file >> b.isbn >> b.title >> b.author >> b.year >> b.genre >> b.price >> b.quantity) {
            books.push_back(b);
        }
        file.close();
    }
    return books;
}

void writeBooks(const vector<Book>& books) {
    ofstream file("books.txt");
    if (file.is_open()) {
        for (const auto& b : books) {
            file << b.isbn << " " << b.title << " " << b.author << " " << b.year << " " 
                 << b.genre << " " << b.price << " " << b.quantity << "\n";
        }
        file.close();
    }
}

vector<BorrowRecord> readBorrowRecords() {
    vector<BorrowRecord> records;
    ifstream file("borrows.txt");
    if (file.is_open()) {
        BorrowRecord r;
        int numBooks;
        while (file >> r.readerId >> r.borrowDate.day >> r.borrowDate.month >> r.borrowDate.year
               >> r.expectedReturnDate.day >> r.expectedReturnDate.month >> r.expectedReturnDate.year
               >> r.actualReturnDate.day >> r.actualReturnDate.month >> r.actualReturnDate.year
               >> numBooks) {
            r.isbns.clear();
            r.statuses.clear();
            for (int i = 0; i < numBooks; i++) {
                string isbn;
                int status;
                file >> isbn >> status;
                r.isbns.push_back(isbn);
                r.statuses.push_back(status);
            }
            records.push_back(r);
        }
        file.close();
    }
    return records;
}

void writeBorrowRecords(const vector<BorrowRecord>& records) {
    ofstream file("borrows.txt");
    if (file.is_open()) {
        for (const auto& r : records) {
            file << r.readerId << " " 
                 << r.borrowDate.day << " " << r.borrowDate.month << " " << r.borrowDate.year << " "
                 << r.expectedReturnDate.day << " " << r.expectedReturnDate.month << " " << r.expectedReturnDate.year << " "
                 << r.actualReturnDate.day << " " << r.actualReturnDate.month << " " << r.actualReturnDate.year << " "
                 << r.isbns.size() << " ";
            for (size_t i = 0; i < r.isbns.size(); i++) {
                file << r.isbns[i] << " " << r.statuses[i] << " ";
            }
            file << "\n";
        }
        file.close();
    }
}

// ### Quản lý độc giả

void viewReaders() {
    auto readers = readReaders();
    for (const auto& r : readers) {
        cout << "ID: " << r.id << ", Name: " << r.name << ", MSSV: " << r.mssv
             << ", DOB: " << r.dob.day << "/" << r.dob.month << "/" << r.dob.year
             << ", Gender: " << r.gender
             << ", Card Created: " << r.cardCreationDate.day << "/" << r.cardCreationDate.month << "/" << r.cardCreationDate.year
             << ", Card Expires: " << r.cardExpiryDate.day << "/" << r.cardExpiryDate.month << "/" << r.cardExpiryDate.year << "\n";
    }
}

void addReader() {
    Reader r;
    cout << "Enter name: ";
    cin >> r.name;
    cout << "Enter MSSV: ";
    cin >> r.mssv;
    cout << "Enter DOB (day month year): ";
    cin >> r.dob.day >> r.dob.month >> r.dob.year;
    cout << "Enter gender: ";
    cin >> r.gender;
    // Tạo ID
    auto readers = readReaders();
    int maxId = 0;
    for (const auto& reader : readers) {
        int id = stoi(reader.id);
        if (id > maxId) maxId = id;
    }
    r.id = to_string(maxId + 1);
    // Đặt ngày tạo và hết hạn thẻ
    r.cardCreationDate = getCurrentDate();
    r.cardExpiryDate = addMonths(r.cardCreationDate, 48);
    readers.push_back(r);
    writeReaders(readers);
    cout << "Reader added successfully.\n";
}

void editReader() {
    string id;
    cout << "Enter reader ID to edit: ";
    cin >> id;
    auto readers = readReaders();
    for (auto& r : readers) {
        if (r.id == id) {
            cout << "Enter new name: ";
            cin >> r.name;
            cout << "Enter new MSSV: ";
            cin >> r.mssv;
            cout << "Enter new DOB (day month year): ";
            cin >> r.dob.day >> r.dob.month >> r.dob.year;
            cout << "Enter new gender: ";
            cin >> r.gender;
            writeReaders(readers);
            cout << "Reader updated successfully.\n";
            return;
        }
    }
    cout << "Reader not found.\n";
}

void searchReaderByMSSV() {
    string mssv;
    cout << "Enter MSSV to search: ";
    cin >> mssv;
    auto readers = readReaders();
    for (const auto& r : readers) {
        if (r.mssv == mssv) {
            cout << "ID: " << r.id << ", Name: " << r.name << ", MSSV: " << r.mssv
                 << ", DOB: " << r.dob.day << "/" << r.dob.month << "/" << r.dob.year
                 << ", Gender: " << r.gender
                 << ", Card Created: " << r.cardCreationDate.day << "/" << r.cardCreationDate.month << "/" << r.cardCreationDate.year
                 << ", Card Expires: " << r.cardExpiryDate.day << "/" << r.cardExpiryDate.month << "/" << r.cardExpiryDate.year << "\n";
            return;
        }
    }
    cout << "Reader not found.\n";
}

// ### Quản lý sách

void viewBooks() {
    auto books = readBooks();
    for (const auto& b : books) {
        cout << "ISBN: " << b.isbn << ", Title: " << b.title << ", Author: " << b.author
             << ", Year: " << b.year << ", Genre: " << b.genre << ", Price: " << b.price
             << ", Quantity: " << b.quantity << "\n";
    }
}

void searchBookByISBN() {
    string isbn;
    cout << "Enter ISBN to search: ";
    cin >> isbn;
    auto books = readBooks();
    for (const auto& b : books) {
        if (b.isbn == isbn) {
            cout << "ISBN: " << b.isbn << ", Title: " << b.title << ", Author: " << b.author
                 << ", Year: " << b.year << ", Genre: " << b.genre << ", Price: " << b.price
                 << ", Quantity: " << b.quantity << "\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void searchBookByTitle() {
    string title;
    cout << "Enter title to search: ";
    cin >> title;
    auto books = readBooks();
    for (const auto& b : books) {
        if (b.title == title) {
            cout << "ISBN: " << b.isbn << ", Title: " << b.title << ", Author: " << b.author
                 << ", Year: " << b.year << ", Genre: " << b.genre << ", Price: " << b.price
                 << ", Quantity: " << b.quantity << "\n";
        }
    }
}

void viewBooksByGenre() {
    string genre;
    cout << "Enter genre: ";
    cin >> genre;
    auto books = readBooks();
    for (const auto& b : books) {
        if (b.genre == genre) {
            cout << "ISBN: " << b.isbn << ", Title: " << b.title << ", Author: " << b.author
                 << ", Year: " << b.year << ", Genre: " << b.genre << ", Price: " << b.price
                 << ", Quantity: " << b.quantity << "\n";
        }
    }
}

// ### Quản lý mượn/trả sách

void borrowBooks() {
    string readerId;
    cout << "Enter reader ID: ";
    cin >> readerId;
    auto readers = readReaders();
    bool readerExists = false;
    for (const auto& r : readers) {
        if (r.id == readerId) {
            readerExists = true;
            break;
        }
    }
    if (!readerExists) {
        cout << "Reader not found.\n";
        return;
    }
    int numBooks;
    cout << "Enter number of books to borrow: ";
    cin >> numBooks;
    vector<string> isbns;
    for (int i = 0; i < numBooks; i++) {
        string isbn;
        cout << "Enter ISBN: ";
        cin >> isbn;
        isbns.push_back(isbn);
    }
    auto books = readBooks();
    for (const auto& isbn : isbns) {
        bool found = false;
        for (auto& b : books) {
            if (b.isbn == isbn) {
                found = true;
                if (b.quantity > 0) {
                    b.quantity--;
                } else {
                    cout << "Book " << isbn << " is not available.\n";
                    return;
                }
                break;
            }
        }
        if (!found) {
            cout << "Book " << isbn << " not found.\n";
            return;
        }
    }
    BorrowRecord br;
    br.readerId = readerId;
    br.borrowDate = getCurrentDate();
    br.expectedReturnDate = addDays(br.borrowDate, 7);
    br.actualReturnDate = {0, 0, 0};
    br.isbns = isbns;
    br.statuses = vector<int>(isbns.size(), 0);
    auto borrowRecords = readBorrowRecords();
    borrowRecords.push_back(br);
    writeBorrowRecords(borrowRecords);
    writeBooks(books);
    cout << "Books borrowed successfully.\n";
}

void returnBooks() {
    auto borrowRecords = readBorrowRecords();
    vector<int> unfinishedIndices;
    for (size_t i = 0; i < borrowRecords.size(); i++) {
        const auto& br = borrowRecords[i];
        bool hasUnfinished = false;
        for (int s : br.statuses) {
            if (s == 0) {
                hasUnfinished = true;
                break;
            }
        }
        if (hasUnfinished) {
            unfinishedIndices.push_back(i);
            cout << "Index: " << i << ", Reader ID: " << br.readerId
                 << ", Borrow Date: " << br.borrowDate.day << "/" << br.borrowDate.month << "/" << br.borrowDate.year
                 << ", Books: ";
            for (const auto& isbn : br.isbns) {
                cout << isbn << " ";
            }
            cout << "\n";
        }
    }
    if (unfinishedIndices.empty()) {
        cout << "No borrow records to return.\n";
        return;
    }
    int index;
    cout << "Enter index of borrow record to return: ";
    cin >> index;
    if (index < 0 || index >= borrowRecords.size() || find(unfinishedIndices.begin(), unfinishedIndices.end(), index) == unfinishedIndices.end()) {
        cout << "Invalid index.\n";
        return;
    }
    auto& br = borrowRecords[index];
    for (size_t i = 0; i < br.isbns.size(); i++) {
        if (br.statuses[i] == 0) {
            cout << "Book " << br.isbns[i] << ": 1. Returned, 2. Lost: ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                br.statuses[i] = 1;
            } else if (choice == 2) {
                br.statuses[i] = 2;
            } else {
                cout << "Invalid choice, assuming not returned.\n";
            }
        }
    }
    bool allFinalized = true;
    for (int s : br.statuses) {
        if (s == 0) {
            allFinalized = false;
            break;
        }
    }
    if (allFinalized) {
        br.actualReturnDate = getCurrentDate();
    }
    double totalFee = 0.0;
    auto books = readBooks();
    for (size_t i = 0; i < br.isbns.size(); i++) {
        if (br.statuses[i] == 1) {
            if (dateDiff(br.expectedReturnDate, br.actualReturnDate) > 0) {
                long long lateDays = dateDiff(br.expectedReturnDate, br.actualReturnDate);
                totalFee += lateDays * 5000;
            }
            for (auto& b : books) {
                if (b.isbn == br.isbns[i]) {
                    b.quantity++;
                    break;
                }
            }
        } else if (br.statuses[i] == 2) {
            for (const auto& b : books) {
                if (b.isbn == br.isbns[i]) {
                    totalFee += b.price * 2.0;
                    break;
                }
            }
        }
    }
    writeBorrowRecords(borrowRecords);
    writeBooks(books);
    cout << "Books returned/updated successfully. Total fee: " << totalFee << " VND\n";
}

// ### Thống kê

void totalBooks() {
    auto books = readBooks();
    int total = 0;
    for (const auto& b : books) {
        total += b.quantity;
    }
    cout << "Total number of books: " << total << "\n";
}

void totalReaders() {
    auto readers = readReaders();
    cout << "Total number of readers: " << readers.size() << "\n";
}

void booksBorrowed() {
    auto borrowRecords = readBorrowRecords();
    int count = 0;
    for (const auto& br : borrowRecords) {
        for (int s : br.statuses) {
            if (s == 0) count++;
        }
    }
    cout << "Number of books currently borrowed: " << count << "\n";
}

void overdueReaders() {
    auto borrowRecords = readBorrowRecords();
    Date currentDate = getCurrentDate();
    set<string> overdueReaderIds;
    for (const auto& br : borrowRecords) {
        bool hasOverdue = false;
        for (int s : br.statuses) {
            if (s == 0) {
                hasOverdue = true;
                break;
            }
        }
        if (hasOverdue && dateDiff(br.expectedReturnDate, currentDate) > 0) {
            overdueReaderIds.insert(br.readerId);
        }
    }
    auto readers = readReaders();
    for (const auto& id : overdueReaderIds) {
        for (const auto& r : readers) {
            if (r.id == id) {
                cout << "ID: " << r.id << ", Name: " << r.name << ", MSSV: " << r.mssv << "\n";
                break;
            }
        }
    }
}

// ### Menu

void readerMenu() {
    while (true) {
        cout << "1. View Readers\n";
        cout << "2. Add Reader\n";
        cout << "3. Edit Reader\n";
        cout << "4. Search Reader by MSSV\n";
        cout << "0. Back\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: viewReaders(); break;
            case 2: addReader(); break;
            case 3: editReader(); break;
            case 4: searchReaderByMSSV(); break;
            case 0: return;
            default: cout << "Invalid choice\n";
        }
    }
}

void bookMenu() {
    while (true) {
        cout << "1. View Books\n";
        cout << "2. Search Book by ISBN\n";
        cout << "3. Search Book by Title\n";
        cout << "4. View Books by Genre\n";
        cout << "0. Back\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: viewBooks(); break;
            case 2: searchBookByISBN(); break;
            case 3: searchBookByTitle(); break;
            case 4: viewBooksByGenre(); break;
            case 0: return;
            default: cout << "Invalid choice\n";
        }
    }
}

void statisticsMenu() {
    while (true) {
        cout << "1. Total Books\n";
        cout << "2. Total Readers\n";
        cout << "3. Books Borrowed\n";
        cout << "4. Overdue Readers\n";
        cout << "0. Back\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: totalBooks(); break;
            case 2: totalReaders(); break;
            case 3: booksBorrowed(); break;
            case 4: overdueReaders(); break;
            case 0: return;
            default: cout << "Invalid choice\n";
        }
    }
}

// ### Hàm chính

int main() {
    while (true) {
        cout << "1. Reader Management\n";
        cout << "2. Book Management\n";
        cout << "3. Borrow Books\n";
        cout << "4. Return Books\n";
        cout << "5. Statistics\n";
        cout << "0. Exit\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: readerMenu(); break;
            case 2: bookMenu(); break;
            case 3: borrowBooks(); break;
            case 4: returnBooks(); break;
            case 5: statisticsMenu(); break;
            case 0: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}