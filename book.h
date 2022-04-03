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
string get_now_book()
{
    string _return;
    (_istream(".book_config")>>_return).close();
    return _return;
}
void find_way(string & argv)
{
    if(argv==RESET)
    {
        (_ostream(".book_config")<<"book1").close();
    }
    else if (argv==SET_BOOK)
    {
        string set_str;
        cin>>set_str;
        (_ostream(get_now_book())<<set_str).close();
    }
    else if (argv==CAT_BOOK)
    {
        string cat_str;
        (_istream(get_now_book())>>cat_str).close();
        cout<<cat_str<<endl;
    }
    else if (argv==OPEN)
    {
        ;
    }
    else if (argv==NEW)
    {
        ;
    }
    else if (argv==FLAG)
    {
        ;
    }
}
/*
    常用的值如下：
　　ios::app：　　　以追加的方式打开文件
　　ios::ate：　　　文件打开后定位到文件尾，ios:app就包含有此属性
　　ios::binary：　以二进制方式打开文件，缺省的方式是文本方式。两种方式的区别见前文
　　ios::in：　　　 文件以输入方式打开(文件数据输入到内存)
　　ios::out：　　　文件以输出方式打开(内存数据输出到文件)
　　ios::nocreate： 不建立文件，所以文件不存在时打开失败
　　ios::noreplace：不覆盖文件，所以打开文件时如果文件存在失败
　　ios::trunc：　　如果文件存在，把文件长度设为0
　　打开文件的属性取值是：
　　0：普通文件，打开访问
　　1：只读文件
　　2：隐含文件
　　4：系统文件
*/