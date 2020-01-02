#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
int callback(void*para,int col_count,char **col_value,char **col_name){
     printf("<li><a href='news1.cgi?%s'>%s</a></li>\n",col_value[0],col_value[1]);
     return 0;
};
int see(sqlite3 *db){
    printf("<ul>");
    char *sql = "SELECT * FROM news";
    char *err;
    if (0  != sqlite3_exec(db,sql,callback,NULL,&err) ){
        printf("%s\n",err);
        exit(-1);
    }
    printf("</ul>");
    return 0;
}
int main(){
    printf("Content-Type: text/html\n\n");
    char  *header = "<!doctype.html>"\
                                "<html>" \
                                "<head>"\
                                "<meta charset='utf-8'>" \
                                "<title>动漫百科</title>" \
                                "</head>" \
                                "<body>";
    printf("%s\n",header);
    printf("<style> " \
                 "a{color: #CD7F32;text-decoration:none;} "\
                 "li{list-style:none;}" \
                 "</style>"
    );
    printf("<div style='line-height:50px;color:#CD7F32;background:#FFF0F5;text-align:center;'>动漫百科</div>");
    sqlite3 *db = NULL;
    int res = sqlite3_open("cms.db",&db);
    if(res !=0){
        printf("open db faile\n");
        return -1;
    };
    see(db);
    sqlite3_close(db);
    printf("</body></html>");
    return  0;                               
}