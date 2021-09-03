#include <mariadb/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    printf("%d\n", argc);
    MYSQL *con = mysql_init(NULL);
    MYSQL_RES *result;
    unsigned int col_num;
    MYSQL_ROW row;
    MYSQL_FIELD *field;
    
    
    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "user", "user",
            "testdb", 0, NULL, 0) == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    
    
    
    char query[] = "SELECT * FROM MyGuests";
    if (mysql_real_query(con, query, strlen(query)))
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    } else
    {
        result = mysql_use_result(con);
        col_num = mysql_field_count(con);
        while((row = mysql_fetch_row(result)) != NULL)
        {
            for(int i = 0; i < col_num; i++)
            {
                field = mysql_fetch_field_direct(result, i);
                printf("%s: %s\t", field->name, row[i]);
            }
            printf("\n");
        }
    }
    mysql_close(con);
    exit(0);
}
