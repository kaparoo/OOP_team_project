#ifndef __OOP_CSV_READER__
#define __OOP_CSV_READER__

#include <string>
#include <vector>

class CSVReader final {
private:
    std::string file_name;
public:
    CSVReader(const std::string&) noexcept;
    ~CSVReader() { };
    // void setDataTable();
    std::vector<std::vector<std::string>> getDataTable() const;
};

std::vector<std::string> splitLine(const std::string&, const char&);

inline bool isNumeric(const std::string& target_str) {
    for (int i = 0; i < target_str.length(); i++)
        if (isdigit(target_str[i]) == false) return false;
    return true;
}

#endif // !__OOP_CSV_READER__