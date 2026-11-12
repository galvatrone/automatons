#include <iostream>
using namespace std;



bool try_lang(const string& word, char stage, size_t i, string output) {
    
    output+="->";
    output+=stage;

    if (i == word.length() ) {
        if (stage == 'B')
            return try_lang(word, 'D', i, output);
        if (stage == 'E')
                return try_lang(word, 'B', i, output) | try_lang(word, 'C', i, output);
        bool accepted = stage == 'D';
        cout << output << (accepted ? " (Accepted)" : " (Rejected)") << endl;
        return accepted;
    }
    const char digit = word[i];

    if (digit != '0' && digit != '1') {
        return false;
    }


    switch (stage) {
    case 'A':
        if (digit == '0')
            return try_lang(word, 'E', i + 1,output);
        return try_lang(word, 'B', i + 1,output);
    case 'B':
        if (digit == '0')
            return  cout << output <<  " (Rejected)" << endl && false  | try_lang(word, 'D', i ,output);
        return try_lang(word, 'C', i + 1,output) | try_lang(word, 'D', i ,output);
    case 'C':
        if (digit == '0')
            return cout << output <<  " (Rejected)" << endl && false ;
        return try_lang(word, 'D', i + 1,output);
    case 'D':
        if (digit == '0')
            return cout << output <<  " (Rejected)" << endl && false ;
        return cout << output <<  " (Rejected)" << endl && false ;
    case 'E':
        if (digit == '0')
            return try_lang(word, 'F', i + 1,output) | try_lang(word, 'B', i ,output) | try_lang(word, 'C', i,output);
        return  try_lang(word, 'B', i,output) | try_lang(word, 'C', i,output);
    case 'F':
        if (digit == '0')
            return try_lang(word, 'D', i + 1,output);
        return cout << output <<  " (Rejected)" << endl && false ;
    default:
        return cout << output <<  " (Rejected)" << endl && false ;
    }
}

int main() {

    string word="111";
    cout << word <<'\n'<< (try_lang(word, 'A', 0, "") ? "(Accepted)" : " (Rejected)") << endl;

    word="11";
    cout << word <<'\n'<< (try_lang(word, 'A', 0, "") ? "(Accepted)" : " (Rejected)") << endl;
    word="011";
    cout << word <<'\n'<< (try_lang(word, 'A', 0, "") ? "(Accepted)" : " (Rejected)") << endl;
    word="000";
    cout << word <<'\n'<< (try_lang(word, 'A', 0, "") ? "(Accepted)" : " (Rejected)") << endl;
    word="0";
    cout << word <<'\n'<< (try_lang(word, 'A', 0, "") ? "(Accepted)" : " (Rejected)") << endl;
    word="01";
    cout << word <<'\n'<< (try_lang(word, 'A', 0, "") ? "(Accepted)" : " (Rejected)") << endl;
    word="1";
    cout << word <<'\n'<< (try_lang(word, 'A', 0, "") ? "(Accepted)" : " (Rejected)") << endl;
    word="010";
    cout << word <<'\n'<< (try_lang(word, 'A', 0, "") ? "(Accepted)" : " (Rejected)") << endl;

    cout<<endl<<"Table of the language :"<<endl; 
    cout << R"(
    +------+-------+-------+----+
    |      |  0=R  |  1=B  |  E |
    +------+-------+-------+----+
    | -> A |   E   |   B   |    |
    |    B |       |   C   |  D |
    |    C |       |   D   |    |
    |   *D |       |       |  D |
    |    E |   F   |       | B,C|
    |    F |   D   |       |    |
    +------+-------+-------+----+
    )" << endl;
    return 0;
}