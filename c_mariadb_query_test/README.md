If failed with:  
```Can't connect to local MySQL server through socket '/tmp/mysql.sock' (2)```  
create a symbolic link as below:  
```ln -s /var/run/mysqld/mysqld.sock /tmp/mysql.sock```
