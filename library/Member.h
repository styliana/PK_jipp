#include <string>

class Member {
private:
    std::string name;
    unsigned int booksBorrowed;

public:
    Member(std::string name);
    void borrowBook();
    void returnBook();
    std::string getName() const;
    void setName(std::string name);
    unsigned int getBooksBorrowed() const;
};
