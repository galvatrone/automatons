#include <iostream>

using namespace std;



void Try_langur(string word){

    char state='A',digit;

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
            state = (digit=='0')?'B':'C';
            break;
        case 'B':
            state = (digit=='0')?'A':'D';
            break;
        case 'C':
            state = (digit=='0')?'D':'A';
            break;
        case 'D':
            state = (digit=='0')?'C':'B';
            break;
        
        default:
            break;
        }
        Newword+="->";
        Newword+=state;
    }


    if(state=='A'){
        cout<<Newword<<"  (Accepted)["<<word<<"]"<<endl;
    }
    else{
        Newword="";
    }
    
    // if(state=='A'){
    //     cout<<endl<<"Accepted";
    // }else{
    //     cout<<endl<<"Rejected";
    // }

}

string add1(string word ,int i){


    if (i < 0) {
        return "1" + word;
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


int main(){

    string word;


    word="0";

    for(int i=0;i<500;i++){


        Try_langur(word); 

        if(word[word.length()-1]=='0'){
            word[word.length()-1]='1';
        }
        else{
            word = add1(word, word.length() - 1);
        }
    }


    cout<<endl<<"Table of the language :"<<endl; 
    cout << R"(
    +------+-----+-----+
    |      |  0  |  1  |
    +------+-----+-----+
    | ->*A |  B  |  C  |
    |    B |  A  |  D  |
    |    C |  D  |  A  |
    |    D |  C  |  B  |
    +------+-----+-----+
    )" << endl;
    //getline(cin,word);

    

    return 0;
}