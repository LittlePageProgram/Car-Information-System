#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<conio.h>

//Cars结构体
struct CarsInfo{
	char OderNum[8];
	char IdentiNum[18];
	char LicenseNum[6];
	int fee;
};

//菜单选项卡
int menu(){
	int i;
	printf("\n\n\t*************车辆信息系统****************\n");
	printf("\n\n\t*****************************************\n");
	printf("\t***         1.录入保存               ****\n");
	printf("\t***         2.查询单条车辆信息       ****\n");
	printf("\t***         3.显示全部车辆信息       ****\n");
	printf("\t***         4.删除单条车辆信息       ****\n");
	printf("\t***         5.修改车辆信息           ****\n");
	printf("\t***         6.统计                   ****\n");
	printf("\t***         7.退出系统               ****\n");
	printf("\n\n\t*****************************************\n\n\n");

	printf("\t请输入对应的数字：\n");
	scanf("%d",&i);
	return i;
}

struct CarsInfo save(){
	struct CarsInfo a;
	printf("请输入一个新的订单号:\n");
	scanf("%s",a.OderNum);
	printf("请输入一个新的身份证号:\n");
	scanf("%s",a.IdentiNum);
	printf("请输入一个新的车牌号:\n");
	scanf("%s",a.LicenseNum);
	printf("请输入费用(整数):\n");
	scanf("%d",&a.fee);
	system("cls");
	printf("录入成功");
	return a;
}

void showSingInfo(int i,struct CarsInfo all[]){
	int num=0;
	struct CarsInfo temp;
	printf("请输入一个记录号码(已经保存的0-100之间的数字):\n");
	scanf("%d",&num);
	system("cls");
	if(num>=i||num<0)	printf("无效记录");
	else{
		temp=all[num];
		printf("订单号:%s\t身份证号:%s\t车牌号:%s\t费用:%d",temp.OderNum,temp.IdentiNum,temp.LicenseNum,temp.fee);
	}
};

void showAll(int i,struct CarsInfo all[]){
	int j;
	system("cls");
	for(j=0;j<i;j++){
		printf("订单号:%s\t身份证号:%s\t车牌号:%s\t费用%d\n",all[j].OderNum,all[j].IdentiNum,all[j].LicenseNum,all[j].fee);
	}
};

int deleteCar(int i,struct CarsInfo all[]){
	int num=0,j=0;
	printf("请输入一个要删除的记录号码(已经保存的0-100之间的数字):\n");
	scanf("%d",&num);
	system("cls");
	if(num>=i||num<0){
		printf("无效记录");
		return 0;
	}
	else{
		printf("删除第%d条记录成功",num);
		for(j=num+1;j<i;j++){
			all[j-1]=all[j];
		}
		return 1;
	}
};

void modify(int i,struct CarsInfo all[]){
	int num,choose;
	printf("请输入一个要修改的记录号码(已经保存的0-100之间的数字):\n");
	scanf("%d",&num);
	if(num>=i||num<0){
		printf("无效记录");
		return;
	}
	printf("请输入一个要修改的信息(修改订单号按0,修改身份证号按1,修改车牌号按2,修改费用按3):\n");
	scanf("%d",&choose);
	switch(choose){
		case 0:
			printf("请输入订单号:\n");
			scanf("%s",all[num].OderNum);
			break;
		
		case 1:
			printf("请输入身份证号:\n");
			scanf("%s",all[num].IdentiNum);
			break;

		
		case 2:
			printf("请输入车牌号:\n");
			scanf("%s",all[num].LicenseNum);
			break;

		
		case 3:
			printf("请输入费用:\n");
			scanf("%d",&all[num].fee);
			break;
	}
	system("cls");
	printf("修改成功");
}

void caculate(int i){
	system("cls");
	printf("目前记录一共%d条",i);
}


void main(){
	static int i;//i在全局起指针作用，因为不用链表存储
	int fin;struct CarsInfo all[100];
	i=0;
	while(1){
		fin=menu();
		if(fin>7||fin<1) {system("cls");printf("data error");}
		switch(fin){
		case 1:
			all[i]=save();
			i++;
			break;
		case 2:
			showSingInfo(i,all);
			break;
		case 3:
			showAll(i,all);
			break;
		case 4:
			if(deleteCar(i,all)==1) i--;
			break;
		case 5:
			modify(i,all);
			break;
		case 6:
			caculate(i);
			break;
		case 7:
			exit(0);
		}
	}
	
}