## digester
This is a simple tool to generate digest for a given sql

When using proxysql, sometime you want to send a sql to the read group,you need to know the sql's degist, but it's not easy to find a sql digest in table
`stats_mysql_query_digest`, so this tool can be used to generate digest for that sql.  

## Build:
(Before building, please read file `proxysql.h` )
```shell
$ yum install gcc gcc-c++
$ make
```
## Example:
```
$ digester "select id,name from person where sex='F' and age > 33"
// output
digest:0xBD3CCD01431FD8BF
digest_text:select id,name from person where sex=? and age > ?
```
If your sql contains " or ` , you need to escape them using a \ .

