#include "main/big_proxy.hh"
#include <vector>
using std::string;

int
main(int argc,char ** argv) {
    if(argc!=3){
        std::cout<<"expect ip and length"<<std::endl;
        return 0;
    }
    string ip(argv[1]);
    string length(argv[2]);

    std::vector<string> create{
        "create database micro_db;",
        "use micro_db;",
        string("create table str_table(name varchar(")+length+"));"
    };
    big_proxy b("tdb",ip,"root","letmein",3306);
    for(auto item:create){
        b.go(item);
    }
    return 0;
}

