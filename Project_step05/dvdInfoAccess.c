/* Name : dvdInfoAccess.c	ver	1.2
 * Content : DVD 정보 저장/참조 함수들의 정의
 * Implementation : YSW
 *
 * Last modified	2015/03/29
 */

#include "common.h"
#include "screenOut.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"

#define MAX_DVD	100
#define DVDINFOBKUP_FILE    "dvdinfo.dat"

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
	// pDVD->numOfRentCus = 0;
	
	dvdList[numOfDVD++] = pDVD;

    dvdStoreToFile();

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

/* 함 수 : int dvdLoadFromFile(void)
 * 기 능 : 저장된 파일로 부터 데이터 읽기
 * 반 환 : 성공하면 0, 실패하면 -1 반환
 *
 */
int dvdLoadFromFile(void)
{   
	dvdInfo *pDVD;
    FILE *fp;
    int i;

//  if (numOfCustomer >= MAX_CUSTOMER)
//  return -1;
    
    if ((fp = fopen(DVDINFOBKUP_FILE, "rb+")) == NULL)
    {
        fp = fopen(DVDINFOBKUP_FILE, "wb+");
        fclose(fp);
        return 0;
    }

    if (fp == NULL)
    {
        fprintf(stderr, "dvdinfo.dat error! \n");
        return -1;
    }

	
    fread(&numOfDVD, sizeof(int), 1, fp);
//  printf("read : numCus %d \n", numOfCustomer); 

    for (i = 0; i < numOfDVD; i++)
    {
	    pDVD = (dvdInfo *)malloc(sizeof(dvdInfo));
        fread((void *)pDVD, sizeof(dvdInfo), 1, fp);
        
    	dvdList[i] = pDVD;
    }
    
    fclose(fp);

	return 0;
}


/* 함 수 : int dvdStoreToFile(void)
 * 기 능 : 파일에 데이터 저장
 * 반 환 : 성공하면 0, 실패하면 -1 반환
 *
 */
int dvdStoreToFile(void)
{   
	dvdInfo *pDVD;
    FILE *fp;
    int i;

    if (numOfDVD >= MAX_DVD)
		return -1;
    
    if ((fp = fopen(DVDINFOBKUP_FILE, "rb+")) == NULL)
    {
        fp = fopen(DVDINFOBKUP_FILE, "wb+");
    }

    if (fp == NULL)
    {
        fprintf(stderr, "dvdinfo.dat error! \n");
        return -1;
    }

	
    fwrite(&numOfDVD, sizeof(int), 1, fp);
//  printf("read : numCus %d \n", numOfCustomer); 

    for (i = 0; i < numOfDVD; i++)
    {
        pDVD = dvdList[i]; 
        fwrite((void *) pDVD, sizeof(dvdInfo), 1, fp);
    }
    
    fclose(fp);

	return 0;
}






/* end fo file */
