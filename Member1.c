#include<stdio.h>
typedef struct {
    char name[50];
    int age;
    int sex;
} User;
int add(int *q,User *u){//添加会员
    printf("请输入会员姓名:\n");
    scanf("%s",u->name);
    printf("请输入会员年龄:\n");
    scanf("%d",&u->age);
    printf("请输入会员性别:\n");
    scanf("%d",&u->sex);
    printf("--------添加成功--------\n");
    return 0;
}
int see(User*users){//查看会员
            printf("姓名:%s\n",users->name);
            printf("年龄:%d\n",users->age);
            printf("性别:%d\n",users->sex);
}
int modify(User*users){//修改会员
    printf("请输入会员姓名:\n");
    scanf("%s",users->name);
    printf("请输入会员年龄:\n");
    scanf("%d",&users->age);
    printf("请输入会员性别:\n");
    scanf("%d",&users->sex);
    printf("--------修改成功--------\n");
}
int delete(User*u1,User*u2){//删除会员
    *u1=*u2;
}
int main(){
    User users[10];
    int count=0;
    int i,q,w,x;
    int flag=1;
    while(flag)
    {
        printf("--------主菜单--------\n1.添加会员\n2.查看会员\n3.修改会员\n4.删除会员\n5.退出\n");
        scanf("%d",&i);
        switch(i){
            case 1://添加会员
            add(&count,&users[count]);
            count++;
            break;
            case 2://查看会员
            printf("--------菜单--------\n1.查看全部会员\n2查看某个会员\n");
            scanf("%d",&i);
            switch(i){
            case 1://查看全部会员
            for(int a=0;a<count;a++){
                see(&users[a]);
            };
            break;
            case 2://查看某个会员
            printf("请输入需要查询的编号:\n");
            scanf("%d",&q);
            if(q>0){
                see(&users[q-1]);
            } else{
            printf("请输入大于1的编号\n"); 
            };
        };
            break;
            case 3://修改会员
            printf("要修改第几个人:\n");
            scanf("%d",&w);
            modify(&users[w-1]);
            break;
            case 4://删除会员
            printf("请输入要删除的编号:");
            scanf("%d",&x);
            for(;x<count;x++){
					delete(&users[x],&users[x+1]);
				}
				count--;
            printf("--------删除成功--------\n");
            break;
            case 5://结束
            flag=0;
            break;
        }
    }
}