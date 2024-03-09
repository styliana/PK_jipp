#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;

public:
    Book() = default;

    Book(std::string title, std::string author, std::string isbn);
    ~Book();
    void getInfo() const;
    std::string getTitle() const;
    void setTitle(std::string title);
    std::string getAuthor() const;
    void setAuthor(std::string author);
    std::string getISBN() const;
    void setISBN(std::string isbn);
    bool isAvailable() const;
    void setAvailable(bool available);
};
