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
#define NORMAL_ARGV "normal"
#define RESET "reset"
#define SET_BOOK "set"
#define CAT_BOOK "cat"
#define OPEN "open"
#define NEW "new"
#define FLAG "flag"
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

#endif //BOOK_API_H
