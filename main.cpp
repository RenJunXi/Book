#define LOCAL_DEBUG
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
