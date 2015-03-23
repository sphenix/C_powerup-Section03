/* Name : rentInfoAccess.c ver 1.1
 * Content : DVD 대여 정보 저장/참조 함수들의 정의
 * Implementation : YSW
 * 
 * Last modified 2015/02/25
 */
#include "common.h"
#include "rentInfo.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
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
/* end of file */
