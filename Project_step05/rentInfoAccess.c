/* Name : rentInfoAccess.c ver 1.2
 * Content : DVD 대여 정보 저장/참조 함수들의 정의
 * Implementation : YSW
 * 
 * Last modified 2015/04/02
 */
#include "common.h"
#include "rentInfo.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "rentInfoAccess.h"
#include "screenOut.h"

#define RENT_LEN    100
#define RENTINFOBKUP_FILE   "rentinfo.dat"

static dvdRentInfo rentList[RENT_LEN];
static int numOfRentCus = 0;

/* 함 수 : void AddRentList(char *ISBN, char *cusID, int rentDay)
 * 기 능 : 대여 정보를 저장
 * 반 환 : void
 *
 */
void AddRentList(char *ISBN, char *cusID, int rentDay)
{
    strcpy(rentList[numOfRentCus].ISBN, ISBN);
    strcpy(rentList[numOfRentCus].cusID, cusID);
    rentList[numOfRentCus].rentDay = rentDay;

    numOfRentCus++;

    rentStoreToFile();
}

/* 함 수 : void PrintOutRentAllCusInfo(char *ISBN)
 * 기 능 : 특정 ISBN의 DVD 대여 고객 정보 출력
 * 반 환 : void
 *
 */
void PrintOutRentAllCusInfo(char *ISBN)
{
    int i;
    cusInfo *ptrCusInfo;

    for (i = 0; i < numOfRentCus; i++)
    {
        if (!strcmp(rentList[i].ISBN, ISBN))
        {
            printf("대여일 : %d \n", rentList[i].rentDay);
            ptrCusInfo = GetCusPtrByID(rentList[i].cusID);
            ShowCustomerInfoContinue(ptrCusInfo);
        }
    }
}

/* 함 수 : void PrintOutCusAllRentInfo(char *, unsigneed int, unsigned int);
 * 기 능 : 일정 기간에 이뤄진 특정 고객의 DVD 대여 정보 출력
 * 반 환 : void
 *
 */
void PrintOutCusAllRentInfo(char *ID, unsigned int start, unsigned int end)
{
    int i;

    for (i = 0; i < numOfRentCus; i++)
    {
        if (!strcmp(rentList[i].cusID, ID))
        {
            if (start <= rentList[i].rentDay && rentList[i].rentDay <= end)
                ShowDVDRentInfo(rentList[i]);
        }
    }
}

/* 함 수 : int rentLoadFromFile(void)
 * 기 능 : 저장된 파일로 부터 데이터 읽기
 * 반 환 : 성공하면 0, 실패하면 -1 반환
 *
 */
int rentLoadFromFile(void)
{   
    FILE *fp;
    int i;

//  if (numOfCustomer >= MAX_CUSTOMER)
//  return -1;
    
    if ((fp = fopen(RENTINFOBKUP_FILE, "rb+")) == NULL)
    {
        fp = fopen(RENTINFOBKUP_FILE, "wb+");
        fclose(fp);
        return 0;
    }

    if (fp == NULL)
    {
        fprintf(stderr, "rentinfo.dat error! \n");
        return -1;
    }

	
    fread(&numOfRentCus, sizeof(int), 1, fp);
//  printf("read : numCus %d \n", numOfCustomer); 

    for (i = 0; i < numOfRentCus; i++)
    {
        fread((void *)(rentList+i), sizeof(dvdRentInfo), 1, fp);
        
    }
    
    fclose(fp);

	return 0;
}


/* 함 수 : int rentStoreToFile(void)
 * 기 능 : 파일에 데이터 저장
 * 반 환 : 성공하면 0, 실패하면 -1 반환
 *
 */
int rentStoreToFile(void)
{   
    FILE *fp;
    int i;

    if (numOfRentCus >= RENT_LEN)
		return -1;
    
    if ((fp = fopen(RENTINFOBKUP_FILE, "rb+")) == NULL)
    {
        fp = fopen(RENTINFOBKUP_FILE, "wb+");
    }

    if (fp == NULL)
    {
        fprintf(stderr, "rentinfo.dat error! \n");
        return -1;
    }

	
    fwrite(&numOfRentCus, sizeof(int), 1, fp);
//  printf("read : numCus %d \n", numOfCustomer); 

    for (i = 0; i < numOfRentCus; i++)
    {
        fwrite((void *)(rentList+i), sizeof(dvdRentInfo), 1, fp);
    }
    
    fclose(fp);

	return 0;
}




/* end of file */
