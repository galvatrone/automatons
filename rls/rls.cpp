#include <iostream>
using namespace std;


/*
bool try_lang2(const string& word, char stage, size_t i, string output) {
    
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
            return try_lang2(word, '2', i + 1,output) | try_lang2(word, '4', i + 1,output);
        return try_lang2(word, '5', i + 1,output);
    case '2':
        if (digit == '0')
            return try_lang2(word, '4', i + 1,output) | try_lang2(word, '6', i + 1,output);
        return try_lang2(word, '1', i + 1,output) | try_lang2(word, '5', i + 1,output) |try_lang2(word, '3', i + 1,output);
    case '3':
        if (digit == '0')
            return try_lang2(word, '2', i + 1,output) | try_lang2(word, '6', i + 1,output);
        return try_lang2(word, '5', i + 1,output);
    case '4':
        if (digit == '0')
            return try_lang2(word, '2', i + 1,output) | try_lang2(word, '8', i + 1,output);
        return try_lang2(word, '1', i + 1,output) | try_lang2(word, '5', i + 1,output) |try_lang2(word, '7', i + 1,output);
    case '5':
        if (digit == '0')
            return try_lang2(word, '2', i + 1,output) | try_lang2(word, '4', i + 1,output) |try_lang2(word, '6', i + 1,output) | try_lang2(word, '8', i + 1,output);
        return try_lang2(word, '1', i + 1,output) | try_lang2(word, '3', i + 1,output) |try_lang2(word, '7', i + 1,output) | try_lang2(word, '9', i + 1,output);
    case '6':
        if (digit == '0')
            return try_lang2(word, '2', i + 1,output) | try_lang2(word, '8', i + 1,output);
        return try_lang2(word, '3', i + 1,output) | try_lang2(word, '5', i + 1,output) |try_lang2(word, '9', i + 1,output);
    case '7':
        if (digit == '0')
            return try_lang2(word, '4', i + 1,output) | try_lang2(word, '8', i + 1,output);
        return try_lang2(word, '5', i + 1,output);
    case '8':
        if (digit == '0')
            return try_lang2(word, '4', i + 1,output) | try_lang2(word, '6', i + 1,output);
        return try_lang2(word, '7', i + 1,output) | try_lang2(word, '5', i + 1,output) | try_lang2(word, '9', i + 1,output);
    case '9':
        if (digit == '0')
            return try_lang2(word, '8', i + 1,output) | try_lang2(word, '6', i + 1,output);
        return try_lang2(word, '5', i + 1,output);
    default:
        return false;
    }
}

int main() {

    string word="0010011";

    cout << word <<'\n'<< (try_lang2(word, '1', 0, "") ? "(Accepted)" : " (Rejected)") << endl;
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
*/




bool Try_langur(string word,char state) {

    char digit;

    string Newword="";
    //Newword+=state ;

    for (int i=0;i<word.length();i++){
        digit=word[i];

        //cout<<digit;

        if (digit !='0' && digit!='1'){
            cout<<"invaled simbvol"<<endl;
            break;
        }

        

        switch (state)
        {
        case 'A':
            state = (digit=='0')?'B':'F';
            break;
        case 'B':
            state = (digit=='0')?'G':'C';
            break;
        case 'C':
            state = (digit=='0')?'A':'C';
            break;
        case 'D':
            state = (digit=='0')?'C':'G';
            break;
        case 'E':
            state = (digit=='0')?'H':'F';
            break;
        case 'F':
            state = (digit=='0')?'C':'G';
            break;
        case 'G':
            state = (digit=='0')?'G':'E';
            break;
        case 'H':
            state = (digit=='0')?'G':'C';
            break;
        
        default:
            break;
        }
        Newword+="->";
        Newword+=state;
    }


    if(state=='C'){
        cout<<Newword<<"  (Accepted)["<<word<<"]"<<endl;
        return true;
    }
    else{
        Newword="";
        return false;
    }
    
    // if(state=='A'){
    //     cout<<endl<<"Accepted";
    // }else{
    //     cout<<endl<<"Rejected";
    // }

}

string add1(string word, int i) {
    if (i < 0) {
        return "0" + word;   // было "1" + word
    }

    if (word[i] == '0') {
        word[i] = '1';
        return word;
    }
    else {
        word[i] = '0';
        return add1(word, i - 1);
    }
}

void initT(char table[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            table[i][j] = 'x';  // Initialize all entries to 'x'
        }
    }
}

int main(){

    string word;
    char table[8][8];
    char table_state[8]= {'A','B','C','D','E','F','G','H'};


    initT(table);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((table_state[i] == 'C' || table_state[j] == 'C') || (table_state[i] == table_state[j] )) {
                table[i][j] = 'x';  // Mark pairs involving the accepting state as distinguishable
                continue;
            }
    
            bool distinguishable = false;
            word = "0";
    
            for (int k = 0; k <= 500; k++) {
                bool acceptedI = Try_langur(word, table_state[i]);
                bool acceptedJ = Try_langur(word, table_state[j]);
    
                if (acceptedI != acceptedJ) {
                    distinguishable = true;
                    break;
                }
    
                if (word.back() == '0') {
                    word.back() = '1';
                } else {
                    word = add1(word, static_cast<int>(word.length()) - 1);
                }
            }
    
            table[i][j] = distinguishable ? 'x' : 'o';
        }
    }


    cout<<endl<<"Table of the language :"<<endl; 

    cout<<endl;
    for(int i=0;i<8;i++){
        cout<<table_state[i];
        for(int j=0;j<8;j++){
            if(i>j)
                cout<<' '<<table[i][j]<<' ';
        }
        cout<<endl;
    }
    for(int i=0;i<8;i++){
     cout<<"  "<<table_state[i];
    }
    cout<<endl;
    /*
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            if(i>j)
                cout<<" * ";
        }
        cout<<endl;
    }
    */
    //getline(cin,word);

    

    return 0;
}