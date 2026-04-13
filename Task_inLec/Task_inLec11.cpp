#include <iostream>
#include <string>
#include <algorithm>
#include <map>        
#include <cctype> 

static bool notZero(char c) { return c != '0'; }
static char soundexEncode(char c) {
    static const std::map<char, char> encoding = {
        {'A','0'}, {'E','0'}, {'I','0'}, {'O','0'}, {'U','0'},
        {'H','0'}, {'W','0'}, {'Y','0'},   // 元音和HWY都是0
        {'B','1'}, {'F','1'}, {'P','1'}, {'V','1'},
        {'C','2'}, {'G','2'}, {'J','2'}, {'K','2'},
        {'Q','2'}, {'S','2'}, {'X','2'}, {'Z','2'},
        {'D','3'}, {'T','3'},
        {'L','4'},
        {'M','5'}, {'N','5'},
        {'R','6'}
    };
    return encoding.at(std::toupper(c));
}

// this is the code to implement soundex
std::string soundex(const std::string& s) {
    // 步骤1: 提取字母
    std::string letters;
    std::copy_if(s.begin(), s.end(), std::back_inserter(letters), ::isalpha);

    // （保存首字母，步骤4会用）
    char first_letter = letters[0];

    // 步骤2: 编码
    std::transform(letters.begin(), letters.end(), letters.begin(), soundexEncode);

    // 步骤3: 去相邻重复
    std::string unique;
    std::unique_copy(letters.begin(), letters.end(), std::back_inserter(unique));

    // 步骤4: 换首字母
    unique[0] = std::toupper(first_letter);

    // 步骤5: 去零
    std::string no_zeros;
    std::copy_if(unique.begin(), unique.end(), std::back_inserter(no_zeros), notZero);

    // 步骤6: 定长4位
    no_zeros += "0000";
    return no_zeros.substr(0, 4);
}