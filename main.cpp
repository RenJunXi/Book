#define LOCAL_DEBUG
#include "book.h"
#include "api.h"
using namespace std;
string str_argv;
int main(int argc,const char * argv[]) {
    if(argc==1 or argc==0)
    {
#ifdef LOCAL_DEBUG
        cin>>str_argv;
#endif
        if(argc==1)
            str_argv=argv[0];
        if(argc==0)
            str_argv=NORMAL_ARGV;
        find_way(str_argv);
    }
    else {
        cerr<<"Arg Error";
        return ARG_ERR;
    }
    return 0;
}
