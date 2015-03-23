/* Name : cusInfoAccess.c	ver	1.1
 * Content : 고객 정보 저장 및 참조 함수들의 정의
 * Implementation : YSW
 *
 * Last modified	2014/12/26
 */
#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER	100
#define CUSINFOBKUP_FILE    "cusinfo.dat"

static cusInfo	*cusList[MAX_CUSTOMER];
static int numOfCustomer = 0;

/* 함 수 : int AddCusInfo (char *ID, char *name, char *num)
 * 기 능 : cusInfo 할당 및 저장
 * 반 환 : 성공 시 '등록된 정보의 개수', 실패시 0을 반환
 */
int AddCusInfo(char *ID, char *name, char *num)
{
	cusInfo *pCus;
	FILE  *fp;

	if (numOfCustomer >= MAX_CUSTOMER)
		return 0;
    
    fp = fopen(CUSINFOBKUP_FILE, "rb+");


    if (fp == NULL)
    {
        fprintf(stderr, "cusinfo.dat error! \n");
        return -1;
    }

	pCus = (cusInfo *)malloc(sizeof(cusInfo));
	
	strcpy(pCus->ID, ID);
	strcpy(pCus->name, name);
	strcpy(pCus->phoneNum, num);
	
	cusList[numOfCustomer++] = pCus;
   
//    fseek(fp, 0L, SEEK_SET);
    printf("numofCustomer  : %d \n", numOfCustomer); 
    fwrite(&numOfCustomer, sizeof(int), 1, fp);
    //fcolse(fp);

    fseek(fp, 0L, SEEK_END);
    fwrite((void *)pCus, sizeof(cusInfo), 1, fp);
    fclose(fp);

	return numOfCustomer;
}

/* 함 수 : cusInfo *GetCusPtrByID(char *ID)
 * 기 능 : 해당 ID의 정보를 담고 있는 변수의 포인터 변환
 * 반 환 : 등록 안된 ID의 경우 NULL 포인터 반환
 *
 */
cusInfo *GetCusPtrByID(char *ID)
{
	int i;

	for (i = 0; i < numOfCustomer; i++)
	{
		if (!strcmp(cusList[i]->ID, ID))
		return cusList[i];
	}

	return (cusInfo *)0;
}

/* 함 수 : int IsRegistID(char *ID)
 * 기 능 : 가입된 ID인지 확인
 * 반 환 : 가입 되었으면 1, 아니면 0 반환
 *
 */
int IsRegistID(char *ID)
{
	cusInfo *pCus = GetCusPtrByID(ID);

	if (pCus==0)
		return 0;
	else
		return 1;
}

/* end fo file */
