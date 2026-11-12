#include <iostream>
using namespace std;



bool try_lang(const string& word, char stage, size_t i, string output) {
    
    output+="->";
    output+=stage;

    if (i == word.length()) {
        bool accepted = stage == '9';
        cout << output << (accepted ? " (Accepted)" : " (Rejected)") << endl;
        return accepted;
    }
    const char digit = word[i];

    if (digit != '0' && digit != '1') {
        return false;
    }


    switch (stage) {
    case '1':
        if (digit == '0')
            return try_lang(word, '2', i + 1,output) | try_lang(word, '4', i + 1,output);
        return try_lang(word, '5', i + 1,output);
    case '2':
        if (digit == '0')
            return try_lang(word, '4', i + 1,output) | try_lang(word, '6', i + 1,output);
        return try_lang(word, '1', i + 1,output) | try_lang(word, '5', i + 1,output) |try_lang(word, '3', i + 1,output);
    case '3':
        if (digit == '0')
            return try_lang(word, '2', i + 1,output) | try_lang(word, '6', i + 1,output);
        return try_lang(word, '5', i + 1,output);
    case '4':
        if (digit == '0')
            return try_lang(word, '2', i + 1,output) | try_lang(word, '8', i + 1,output);
        return try_lang(word, '1', i + 1,output) | try_lang(word, '5', i + 1,output) |try_lang(word, '7', i + 1,output);
    case '5':
        if (digit == '0')
            return try_lang(word, '2', i + 1,output) | try_lang(word, '4', i + 1,output) |try_lang(word, '6', i + 1,output) | try_lang(word, '8', i + 1,output);
        return try_lang(word, '1', i + 1,output) | try_lang(word, '3', i + 1,output) |try_lang(word, '7', i + 1,output) | try_lang(word, '9', i + 1,output);
    case '6':
        if (digit == '0')
            return try_lang(word, '2', i + 1,output) | try_lang(word, '8', i + 1,output);
        return try_lang(word, '3', i + 1,output) | try_lang(word, '5', i + 1,output) |try_lang(word, '9', i + 1,output);
    case '7':
        if (digit == '0')
            return try_lang(word, '4', i + 1,output) | try_lang(word, '8', i + 1,output);
        return try_lang(word, '5', i + 1,output);
    case '8':
        if (digit == '0')
            return try_lang(word, '4', i + 1,output) | try_lang(word, '6', i + 1,output);
        return try_lang(word, '7', i + 1,output) | try_lang(word, '5', i + 1,output) | try_lang(word, '9', i + 1,output);
    case '9':
        if (digit == '0')
            return try_lang(word, '8', i + 1,output) | try_lang(word, '6', i + 1,output);
        return try_lang(word, '5', i + 1,output);
    default:
        return false;
    }
}

int main() {

    string word="0010011";

    cout << word <<'\n'<< (try_lang(word, '1', 0, "") ? "(Accepted)" : " (Rejected)") << endl;
    cout<<endl<<"Table of the language :"<<endl; 
    cout << R"(
    +------+-------+-------+
    |      |  0=R  |  1=B  |
    +------+-------+-------+
    | -> 1 |  2,4  |  5    |
    |    2 |  4,6  | 1,5,3 |
    |    3 |  2,6  |  5    |
    |    4 |  2,8  | 1,5,7 |
    |    5 |2,4,6,8|1,3,7,9|
    |    6 |  2,8  | 3,5,9 |
    |    7 |  4,8  |  5    |
    |    8 |  4,6  | 7,5,9 |
    |   *9 |  8,6  |  5    |
    +------+-------+-------+
    )" << endl;
    return 0;
}