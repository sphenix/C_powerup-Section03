/* Name : dvdInfoAccess.c	ver	1.3
 * Content : DVD 정보 저장/참조 함수들의 정의
 * Implementation : YSW
 *
 * Last modified	2015/04/05
 */

#include "common.h"
#include "screenOut.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"

#define MAX_DVD	100
#define DVD_BACKUP_FILE "dvdInfo.dat"

static dvdInfo	*dvdList[MAX_DVD];
static int numOfDVD = 0;

/* 함 수 : int AddDVDInfo (char *ISBN, char *title, int genre)
 * 기 능 : dvdInfo 할당 및 저장
 * 반 환 : 성공 시 '등록된 정보의 개수', 실패시 0을 반환
 */
int AddDVDInfo(char *ISBN, char *title, int genre)
{
	dvdInfo *pDVD;
	
	if (numOfDVD >= MAX_DVD)
		return 0;

	pDVD = (dvdInfo *)malloc(sizeof(dvdInfo));
	
	strcpy(pDVD->ISBN, ISBN);
	strcpy(pDVD->title, title);
	pDVD->genre = genre;
	
	pDVD->rentState = RETURNED;
	dvdList[numOfDVD++] = pDVD;
	
    StoreDVDListToFile();
    
    return numOfDVD;
}

/* 함 수 : dvdInfo *GetDVDPtrByISBN(char *ISBN)
 * 기 능 : 해당 ISBN의 정보를 담고 있는 변수의 포인터 변환
 * 반 환 : 등록 안된 ISBN의 경우 NULL 포인터 반환
 *
 */
dvdInfo *GetDVDPtrByISBN(char *ISBN)
{
	int i;

	for (i = 0; i < numOfDVD; i++)
	{
		if (!strcmp(dvdList[i]->ISBN, ISBN))
		return dvdList[i];
	}

	return (dvdInfo *)0;
}

/* 함 수 : int IsRegistISBN(char *ISBN)
 * 기 능 : 등록된 ISBN인지 확인
 * 반 환 : 등록 되었으면 1, 아니면 0 반환
 *
 */
int IsRegistISBN(char *ISBN)
{
	dvdInfo *pDVD = GetDVDPtrByISBN(ISBN);

	if (pDVD==0)
		return 0;
	else
		return 1;
}

/* 함 	수 : int SetDVDRented(char * ISBN)
 * 기 	능 : 대여 상태로 변경
 * 반 	환 : 성공 1, 실패 0
 */
// int SetDVDRented(char *ISBN, char *cusID, int rentDay)
int SetDVDRented(char *ISBN)
{
	dvdInfo *pDVD = GetDVDPtrByISBN(ISBN);
	if (pDVD == 0)
		return 0;
	
    pDVD->rentState = RENTED;

    StoreDVDListToFile();
	return 1;
}

/* 함 	 수 : int SetDVDReturned(char *ISBN)
 * 기 	 능 : 대여 가능 상태로 변경
 * 반 	 환 : 성공 1, 실패 0
 * 특이사항 : 필자가 제공한 함수 
 */
int SetDVDReturned(char *ISBN)
{
	dvdInfo *pDVD = GetDVDPtrByISBN(ISBN);
	
	if (pDVD == 0)
		return 0;
	
	pDVD->rentState = RETURNED;
	
    StoreDVDListToFile();
    return 1;
}

/* 함 수 : int GetDVDRentState(char *ISBN)
 * 기 능 : 현재 대여 상태 반환
 * 반 환 : RETURNED, RENTED, 존재하지 않는 ISBN 의 경우 -1  반환
 */
int GetDVDRentState(char *ISBN)
{
	dvdInfo *pDVD = GetDVDPtrByISBN(ISBN);
	if (pDVD == 0)
		return -1;

	return pDVD->rentState;
}

/* 함 수: void StoreDVDListToFile(void)
 * 기 능: DVD 정보 파일에 저장
 * 반 환: void
 *
 */
void StoreDVDListToFile(void)
{
    int i;
    FILE *fp = fopen(DVD_BACKUP_FILE, "wb");
    if (fp == NULL)
        return;

    fwrite(&numOfDVD, sizeof(int), 1, fp);

    for (i = 0; i < numOfDVD; i++)
        fwrite(dvdList[i], sizeof(dvdInfo), 1, fp);

    fclose(fp);
}

/* 함 수 : void LoadDVDListFromFile(void)
 * 기 능 : DVD 정보 파일 부터 복원
 * 반 환 : void
 *
 */
void LoadDVDListFromFile(void)
{
    int i;
    FILE *fp = fopen(DVD_BACKUP_FILE, "rb");
    if (fp == NULL)
        return;

    fread(&numOfDVD, sizeof(int), 1, fp);

    for (i = 0; i < numOfDVD; i++)
    {
        dvdList[i] = (dvdInfo *)malloc(sizeof(dvdInfo));
        fread(dvdList[i], sizeof(dvdInfo), 1, fp);
    }

    fclose(fp);
}
/* end fo file */
