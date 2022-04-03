//
// Created by RenJunXi on 2022/4/3.
//

#include "api.h"
using namespace std;
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

#endif //BOOK_BOOK_H