/* Name : cusInfoAccess.c	ver	1.2
 * Content : 고객 정보 저장 및 참조 함수들의 정의
 * Implementation : YSW
 *
 * Last modified	2015/04/05
 */

#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"

#define MAX_CUSTOMER	100
#define CUS_BACKUP_FILE "cusInfo.dat"

static cusInfo	*cusList[MAX_CUSTOMER];
static int numOfCustomer = 0;

/* 함 수 : int AddCusInfo (char *ID, char *name, char *num)
 * 기 능 : cusInfo 할당 및 저장
 * 반 환 : 성공 시 '등록된 정보의 개수', 실패시 0을 반환
 */
int AddCusInfo(char *ID, char *name, char *num)
{
	cusInfo *pCus;
	
	if (numOfCustomer >= MAX_CUSTOMER)
		return 0;

	pCus = (cusInfo *)malloc(sizeof(cusInfo));
	
	strcpy(pCus->ID, ID);
	strcpy(pCus->name, name);
	strcpy(pCus->phoneNum, num);
	
	cusList[numOfCustomer++] = pCus;

    StoreCusListToFile();

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

/* 함 수 : void StoreCusListToFile(void)
 * 기 능 : 고객 정보 파일에 저장
 * 반 환 : void
 *
 */
void StoreCusListToFile(void)
{
    int i;
    FILE *fp = fopen(CUS_BACKUP_FILE, "wb");
    if (fp == NULL)
        return;

    fwrite(&numOfCustomer, sizeof(int), 1, fp);

    for (i = 0; i < numOfCustomer; i++)
        fwrite(cusList[i], sizeof(cusInfo), 1, fp);

    fclose(fp);
}

/* 함 수 : void LoadCusListFromFile(void)
 * 기 능 : 고개 정보 파일로부터 복원
 * 반 환 : void
 *
 */
void LoadCusListFromFile(void)
{
    int i;
    FILE *fp = fopen(CUS_BACKUP_FILE, "rb");
    if (fp == NULL)
        return; 

    fread(&numOfCustomer, sizeof(int), 1, fp);

    for (i = 0; i < numOfCustomer; i++)
    {
        cusList[i] = (cusInfo *)malloc(sizeof(cusInfo));
        fread(cusList[i], sizeof(cusInfo), 1, fp);
    }

    fclose(fp);
}

/* end fo file */
