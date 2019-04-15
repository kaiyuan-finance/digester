digester -- generate digest for a sql

When using proxysql, sometime you want to send a sql to the read group, but it's not easy to find the sql digest from table
`stats_mysql_query_digest`, so this tool can be used to generate digest for that sql.  

Build:
```
# yum install gcc,gcc-c++

g++ c_tokenizer.c c_tokenizer.h SpookyV2.cpp SpookyV2.h proxysql.h main.cpp -o digester

```
Example:
```
digester "select id,name from person where sex='F' and age > 33"
digest:0xBD3CCD01431FD8BF
digest_text:select id,name from person where sex=? and age > ?
```

