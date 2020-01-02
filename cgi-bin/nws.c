#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

typedef struct{
    int id;
    char *title;
    char *content;
    char *created_at;
}NEWS;

int insert(sqlite3 *db,NEWS *new){
    char *err;
    char sql[100];
    new->title = malloc(sizeof(char));
    new->content = malloc(sizeof(char));
    new->created_at = malloc(sizeof(char));
    printf("请输入标题:\n");
    scanf("%s",new->title);
    printf("请输入内容:\n");
    scanf("%s",new->content);
    printf("请输入创建时间:\n");
    scanf("%s",new->created_at);
    sprintf(sql,"INSERT INTO news(title,content,created_at) VALUES ('%s','%s','%s')",
    new->title,new->content,new->created_at);
  
    if(0 != sqlite3_exec(db,sql,NULL,NULL,&err)){
        printf("%s\n",err);
        exit(-1);
    };

    return 0;
}
int callback(void*para,int col_count,char **col_value,char **col_name){
     for(int i = 0; i < col_count; i++){
         printf("%s: %s \n",col_name[i],col_value[i]);
     }
     return 0;
}
int see (sqlite3 *db){
    char *err;
    char *sql = "SELECT * FROM news";
    if(0 != sqlite3_exec(db,sql,callback,NULL,&err)) {
        printf("%s\n",err);
        return -1;
    }
    return 0;
}
int update(sqlite3 *db,NEWS *new,int id){
    char *err;
    char sql[100];
    new->title = malloc(sizeof(char));
    new->content = malloc(sizeof(char));
    new->created_at = malloc(sizeof(char));
    //printf("请输入id号:\n");
    //scanf("%d",&new.id);
    printf("请输入标题:\n");
    scanf("%s",new->title);
    printf("请输入内容:\n");
    scanf("%s",new->content);
    printf("请输入创建时间:\n");
    scanf("%s",new->created_at);
    sprintf(sql,"UPDATE news SET title = '%s',content = '%s',created_at = '%s'WHERE id = %d",new->title,new->content,new->created_at,id);
    if(SQLITE_OK != sqlite3_exec(db,sql,NULL,NULL,&err)){
        printf("%s\n",err);
        exit(-1);
    }
    return 0;
}
int delete (sqlite3  *db,int id){
    char *err;
    char sql[100];
    sprintf(sql,"DELETE FROM news WHERE id = %d",id);
    if(0 != sqlite3_exec(db,sql,NULL,NULL,&err)){
        printf("%s\n",err);
        exit(-1);
    }
    return 0;
}
int main()
{
    sqlite3 *db = NULL;
    int res = sqlite3_open("cms.db",&db);
    if(res != 0){
        printf("open db fail\n");
        return -1;
    }
    NEWS users;
    int count;
    int i,c;
    int flag=1;
    while(flag)
    {
        printf("--------主菜单--------\n1.添加动漫百科\n2.查看动漫百科\n3.修改动漫百科\n4.删除动漫百科\n5.退出\n");
        scanf("%d",&i);
        switch(i){
            case 1:
            insert(db, &users);
            break;
            case 2:
            see(db);
            break;
            case 3:
            printf("要修改第几条动漫百科:\n");
            scanf("%d",&count);
            if(count>0){
                update(db, &users,count);
            } else{
                printf("请输入大于0的数");
            };
            break;
            case 4:malloc(sizeof(char));
             printf("要修改第几条动漫百科:\n");
            scanf("%d",&c);
            if(c > 0){
               delete(db,c); 
            } else{
                printf("请输入大于0的数");
            };
            break;
            case 5://结束
            flag=0;
            break;
        }
    }
    sqlite3_close(db);
    return 0;
}