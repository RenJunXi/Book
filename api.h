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
#define FILE_IN_ERR 2
#define FILE_OUT_ERR 3
#define RESET_FLAG_ERR 4
#define NORMAL "normal"
#define RESET "reset"
#define SET_BOOK "set"
#define CAT_BOOK "cat"
#define OPEN "open"
#define FLAG "flag"
#define SHELL_ONE string("open $(cat ")
#define SHELL_TWO string(")")
using namespace std;
ifstream _istream(const string & open_name)
{
    ifstream _return;
    _return.open(open_name);
    if(!_return.is_open())
    {
        cerr<<"File Input Error";
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
        cerr<<"File Output Error";
        exit(FILE_OUT_ERR);
    }
    return _return;
}
void input(string open_name,string & input_str)
{
    ifstream stream=_istream(open_name);
    stream>>input_str;
    stream.close();
}
void output(string open_name,string output_str)
{
    ofstream stream=_ostream(open_name);
    stream<<output_str;
    stream.close();
}
#endif //BOOK_API_H
