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
inline void __set(string & set_str)
{
    output(get_now_book(),set_str);
    cout<<"Book: "<<set_str<<" has been seted on "<<get_now_book()<<"."<<endl;
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
    cout<<"Book: "<<get_now_book()<<" on "<<get_now_book()<<" has been opened."<<endl;
}
inline void __flag(string other_argv)
{
    other_argv+=".book";
    fstream ch_flag;
    ch_flag.open(other_argv,ios::in);
    if(ch_flag.is_open())
        ch_flag.close();
    else
    {
        ch_flag.close();
        ch_flag.open(other_argv,ios::out);
    }
    if(!ch_flag.is_open())
    {
        cerr<<"Error:Reset Flag Error";
        exit(RESET_FLAG_ERR);
    }
    output(".book_config",other_argv);
    cout<<"Book "<<other_argv<<" has been the flag."<<endl;
}
void __normal()
{
    string argv;
    while(true) {
        cin>>argv;
        if(argv==QUIT)
            exit(0);
        __set(argv);
    }
}
//TODO:UPDATE
/* void __update()
{

}*/

void find_way(string & argv,string & final_argv)
{
    if(argv==NORMAL){
        __normal();
    }else if(argv==RESET){
        __reset();
    }else if (argv==SET_BOOK){
        __set(final_argv);
    }else if (argv==CAT_BOOK){
        __cat();
    }else if (argv==OPEN){
        __open();
    }else if (argv==FLAG){
        __flag(final_argv);
    }else{
        cerr<<"Bad Arg Error";
        exit(BAD_ARG_ERR);
    }
}

#endif //BOOK_BOOK_H