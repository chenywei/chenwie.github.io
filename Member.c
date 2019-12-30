#include <stdio.h>
struct User{
    char name[30];
    int age;
    int sex;
};
struct User users[50];
int count=0,i;
int add()//增加会员
{
    printf("请输入会员姓名:\n");
    scanf("%s",users[count].name);
    printf("请输入会员年龄:\n");
    scanf("%d",&users[count].age);
    printf("请输入会员性别:\n");
    scanf("%d",&users[count].sex);
    printf("--------添加成功--------\n");
    printf("姓名:%s\n",users[count].name);
    printf("年龄:%d\n",users[count].age);
    printf("性别:%d\n",users[count].sex);
    count++;
    return 0;
}
int see()//查看会员
{
    int q;
    printf("--------菜单--------\n1.查看全部会员\n2查看某个会员\n");
    scanf("%d",&i);
    switch(i){
        case 1:
        for(int a=0;a<count;a++){
            printf("姓名:%s\n",users[a].name);
            printf("年龄:%d\n",users[a].age);
            printf("性别:%d\n",users[a].sex);
        };//查看所有会员
        break;
        case 2:
        printf("请输入需要查询的编号:\n");
        scanf("%d",&q);
        if(q>0){
            printf("姓名:%s\n",users[q-1].name);
            printf("年龄:%d\n",users[q-1].age);
            printf("性别:%d\n",users[q-1].sex);
        } else{
            printf("请输入大于1的编号\n");
        }//查看某个会员
        break;
    }
}
int modify(){ //修改会员
    int w;
    printf("要修改第几个人:\n");
    scanf("%d",&w);
    printf("请输入会员姓名:\n");
    scanf("%s",users[w-1].name);
    printf("请输入会员年龄:\n");
    scanf("%d",&users[w-1].age);
    printf("请输入会员性别:\n");
    scanf("%d",&users[w-1].sex);
    printf("--------修改成功--------\n");
}
int delete(){//删除会员
    int x;
    printf("请输入要删除的编号:");
    scanf("%d",&x);
    for(x;x<count;x++){
         users[x]=users[x+1];
         count--;
    } 
    printf("--------删除成功--------\n");  
}
int main()
{
    int flag=1;
    while(flag)
    {
        printf("--------主菜单--------\n1.添加会员\n2.查看会员\n3.修改会员\n4.删除会员\n5.退出\n");
        scanf("%d",&i);
        switch(i){
            case 1:
            add(); 
            break;
            case 2:
            see();
            break;
            case 3:
            modify();
            break;
            case 4:
            delete();
            break;
            case 5:
            flag=0;
            break;
        }
    }
}