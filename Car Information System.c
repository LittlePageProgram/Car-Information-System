#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<conio.h>

//Cars�ṹ��
struct CarsInfo{
	char OderNum[8];
	char IdentiNum[18];
	char LicenseNum[6];
	int fee;
};

//�˵�ѡ�
int menu(){
	int i;
	printf("\n\n\t*************������Ϣϵͳ****************\n");
	printf("\n\n\t*****************************************\n");
	printf("\t***         1.¼�뱣��               ****\n");
	printf("\t***         2.��ѯ����������Ϣ       ****\n");
	printf("\t***         3.��ʾȫ��������Ϣ       ****\n");
	printf("\t***         4.ɾ������������Ϣ       ****\n");
	printf("\t***         5.�޸ĳ�����Ϣ           ****\n");
	printf("\t***         6.ͳ��                   ****\n");
	printf("\t***         7.�˳�ϵͳ               ****\n");
	printf("\n\n\t*****************************************\n\n\n");

	printf("\t�������Ӧ�����֣�\n");
	scanf("%d",&i);
	return i;
}

struct CarsInfo save(){
	struct CarsInfo a;
	printf("������һ���µĶ�����:\n");
	scanf("%s",a.OderNum);
	printf("������һ���µ����֤��:\n");
	scanf("%s",a.IdentiNum);
	printf("������һ���µĳ��ƺ�:\n");
	scanf("%s",a.LicenseNum);
	printf("���������(����):\n");
	scanf("%d",&a.fee);
	system("cls");
	printf("¼��ɹ�");
	return a;
}

void showSingInfo(int i,struct CarsInfo all[]){
	int num=0;
	struct CarsInfo temp;
	printf("������һ����¼����(�Ѿ������0-100֮�������):\n");
	scanf("%d",&num);
	system("cls");
	if(num>=i||num<0)	printf("��Ч��¼");
	else{
		temp=all[num];
		printf("������:%s\t���֤��:%s\t���ƺ�:%s\t����:%d",temp.OderNum,temp.IdentiNum,temp.LicenseNum,temp.fee);
	}
};

void showAll(int i,struct CarsInfo all[]){
	int j;
	system("cls");
	for(j=0;j<i;j++){
		printf("������:%s\t���֤��:%s\t���ƺ�:%s\t����%d\n",all[j].OderNum,all[j].IdentiNum,all[j].LicenseNum,all[j].fee);
	}
};

int deleteCar(int i,struct CarsInfo all[]){
	int num=0,j=0;
	printf("������һ��Ҫɾ���ļ�¼����(�Ѿ������0-100֮�������):\n");
	scanf("%d",&num);
	system("cls");
	if(num>=i||num<0){
		printf("��Ч��¼");
		return 0;
	}
	else{
		printf("ɾ����%d����¼�ɹ�",num);
		for(j=num+1;j<i;j++){
			all[j-1]=all[j];
		}
		return 1;
	}
};

void modify(int i,struct CarsInfo all[]){
	int num,choose;
	printf("������һ��Ҫ�޸ĵļ�¼����(�Ѿ������0-100֮�������):\n");
	scanf("%d",&num);
	if(num>=i||num<0){
		printf("��Ч��¼");
		return;
	}
	printf("������һ��Ҫ�޸ĵ���Ϣ(�޸Ķ����Ű�0,�޸����֤�Ű�1,�޸ĳ��ƺŰ�2,�޸ķ��ð�3):\n");
	scanf("%d",&choose);
	switch(choose){
		case 0:
			printf("�����붩����:\n");
			scanf("%s",all[num].OderNum);
			break;
		
		case 1:
			printf("���������֤��:\n");
			scanf("%s",all[num].IdentiNum);
			break;

		
		case 2:
			printf("�����복�ƺ�:\n");
			scanf("%s",all[num].LicenseNum);
			break;

		
		case 3:
			printf("���������:\n");
			scanf("%d",&all[num].fee);
			break;
	}
	system("cls");
	printf("�޸ĳɹ�");
}

void caculate(int i){
	system("cls");
	printf("Ŀǰ��¼һ��%d��",i);
}


void main(){
	static int i;//i��ȫ����ָ�����ã���Ϊ��������洢
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