
#define bool char


/**
The following two variables is the variables defined in ProxySQL
 *
 * mysql-query_digests_max_query_length
 * mysql-query_digests_lowercase
 *
 * You need to change them to the same values as they are in your ProxySQL
 *
*/
int mysql_thread___query_digests_max_query_length = 65000;
//false -- 0; none zero -->true
bool mysql_thread___query_digests_lowercase=1;
