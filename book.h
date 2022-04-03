//
// Created by RenJunXi on 2022/4/3.
//

#ifndef BOOK_BOOK_H
#define BOOK_BOOK_H
#include "api.h"
using namespace std;

string get_now_book()
{
    string _return;
    input(".book_config",_return);
    return _return;
}
inline void __reset()
{
    output(".book_config","book1");
}
inline void __set()
{
    string set_str;
    cin>>set_str;
    output(get_now_book(),set_str);
    cout<<"Book: "<<set_str<<" has been seted."<<endl;
}
inline void __cat()
{
    string cat_str;
    input(get_now_book(),cat_str);
    cout<<cat_str<<endl;
}
inline void __open()
{
    string shell_command=SHELL_ONE+get_now_book()+SHELL_TWO;
    system(shell_command.c_str());
    cout<<"Book: "<<get_now_book()<<" has been opened."<<endl;
}
inline void __flag()
{
    string other_flag;
    cin>>other_flag;
    ifstream ch_flag;
    ch_flag.open(other_flag,ios::in|ios::out);
    if(!ch_flag.is_open())
    {
        cerr<<"Reset Flag Error";
        exit(RESET_FLAG_ERR);
    };
    output(".book_config",other_flag);
    cout<<"Book "<<other_flag<<" has been the flag."<<endl;
}
inline void __normal()
{
    while(true)
        __set();
}

void find_way(string & argv)
{
    if(argv==NORMAL){
        __normal();
    }else if(argv==RESET){
        __reset();
    }else if (argv==SET_BOOK){
        __set();
    }else if (argv==CAT_BOOK){
        __cat();
    }else if (argv==OPEN){
        __open();
    }else if (argv==FLAG){
        __flag();
    }
}

#endif //BOOK_BOOK_H