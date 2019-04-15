#include <stdio.h>
#include <string.h>
#include "c_tokenizer.h"
#include "SpookyV2.h"
#include <string>
//#include "proxysql.h"
//#include <iostream>
//using namespace std;


extern int mysql_thread___query_digests_max_query_length;

int main(int argc, char **argv)
{
    if(argc != 2) {
        printf("A SQL must be provided as a parameter! Exit 1.\n");
        printf("No \"\"  is allowed in SQL,please use '' instead! \n\n");
        return 1;
    }

    char buf[128];

    char *sql=argv[1];
    int l = strlen(sql);
    char *digest_text=mysql_query_digest_and_first_comment(sql,l,NULL,NULL);
    int digest_length=strnlen(digest_text,mysql_thread___query_digests_max_query_length);
    long long unsigned digest=SpookyHash::Hash64(digest_text,digest_length,0);

    sprintf(buf,"0x%016llX",digest);

    printf("digest:%s\n",buf);
    printf("digest_text:%s\n",digest_text);
    //cout<<"digest:"<<digest_str<<endl;
    //cout<<"digest_text:"<<digest_text<<endl;

    return 0;
}
