from os import *
main_cpp='''
#include "book.h"
#include "api.h"
using namespace std;
string str_argv,final_argv;
int main(int argc,const char * argv[]) {
    if (argc > 0 and argc < 4) {
        if (argc == 2)
            str_argv = argv[1];
        if (argc == 1)
            str_argv = NORMAL;
        if (argc == 3) {
            str_argv = argv[1];
            final_argv = argv[2];
        }
    } else {
        cerr << "Arg Error";
        return ARG_ERR;
    }
#ifdef LOCAL_DEBUG
    while(true) {
        cin >> str_argv;
        cin >> final_argv;
        if(str_argv==QUIT)
        {
            cerr<<"Debug End.";
            exit(DEBUG_END);
        }
#endif
        find_way(str_argv, final_argv);
#ifdef LOCAL_DEBUG
    }
#endif
    return 0;
}
'''
book_h='''
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
        __set(argv);
    }
}

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
'''
api_h='''
//
// Created by RenJunXi on 2022/4/3.
//

#ifndef BOOK_API_H
#define BOOK_API_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#define ARG_ERR 1
#define BAD_ARG_ERR 2
#define FILE_IN_ERR 3
#define FILE_OUT_ERR 4
#define RESET_FLAG_ERR 5
#define DEBUG_END 6
#define NORMAL "normal"
#define RESET "reset"
#define SET_BOOK "set"
#define CAT_BOOK "cat"
#define OPEN "open"
#define FLAG "flag"
#define QUIT "quit"
#define SHELL_ONE string("open $(cat ")
#define SHELL_TWO string(")")
using namespace std;
ifstream _istream(const string & open_name)
{
    ifstream _return;
    _return.open(open_name);
    if(!_return.is_open())
    {
        cerr<<"Error:File Input Error.\\nError File: "<<open_name;
        exit(FILE_IN_ERR);
    }
    return _return;
}
ofstream _ostream(const string & open_name)
{
    ofstream _return;
    _return.open(open_name,ios::trunc|ios::out);
    if(!_return.is_open())
    {
        cerr<<"File Output Error\\nError File: "<<open_name;
        exit(FILE_OUT_ERR);
    }
    return _return;
}
void input(const string & open_name,string & input_str)
{
    ifstream stream=_istream(open_name);
    stream>>input_str;
    stream.close();
}
void output(const string & open_name,const string & output_str)
{
    ofstream stream=_ostream(open_name);
    stream<<output_str;
    stream.close();
}
#endif //BOOK_API_H
'''
book_fish='''
#By book
function bs
    ~/book set $argv
end
'''

main_cpp_file=open("~/Book_build/main.cpp", "w")
main_cpp_file.write(main_cpp)
main_cpp_file.close()
print("The main.cpp has been writed.")

main_cpp_file=open("~/Book_build/book.h", "w")
main_cpp_file.write(book_h)
main_cpp_file.close()
print("The book.h has been writed.")

main_cpp_file=open("~/Book_build/api.h", "w")
main_cpp_file.write(api_h)
main_cpp_file.close()
print("The api.h has been writed.")

main_cpp_file=open("~/.config/fish/config.fish", "a")
main_cpp_file.write(api_h)
main_cpp_file.close()
print("The book.fish has been writed.")

print("Building Book.")
system("g++ ~/main.cpp -o ~/book -O2")
print("Finished building Book.")
system("~/book reset")
print("Book has been installed!")

print("Clean Caches...")
system("rm -rf ~/Book_build")
