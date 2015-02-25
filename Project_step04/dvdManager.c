/* Name : dvdManager.c	ver 1.1
 * Content : DVD 관련 업무 처리 함수들의 정의
 * Implementation : YSW
 * 
 * Last modified 2015/01/09
 */
#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "rentInfo.h"
#include "rentInfoAccess.h"
#include "screenOut.h"

#include "cusInfoAccess.h"

/* 함 수 : void RegistDVD(void)
 * 기 능 : DVD 등록
 * 반 환 : void
 *
 */
void RegistDVD(void)
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int  genre;

	fputs("ISBN 입력 : ", stdout);
	gets(ISBN);

	if (IsRegistISBN(ISBN))
	{
		puts("해당 ISBN은  이미 등록되었습니다.");
		getchar();
		return;
	}
	
	fputs("제목 입력 : ", stdout);
	gets(title);

	fputs("쟝르 입력 (액션 1, 코믹 2, SF 3, 로맨틱 4) ", stdout);
	scanf("%d", &genre);
	while(getchar() != '\n');

	if (!AddDVDInfo(ISBN, title, genre)) 
	{
		puts("정상적인 데이터 저장에 실패하였습니다.");
		getchar();
		return;
	}

	puts("등록이 완료되었습니다.");
	getchar();
}

/* 함 수 : void SearchDVDInfo(void)
 * 기 능 : ISBN을 이용한 DVD 정보 검색
 * 반 환 : void
 *
 */
void SearchDVDInfo(void)
{
	char ISBN[ISBN_LEN];
	dvdInfo *dvdPtr;

	fputs("찾는 ISBN 입력 : ", stdout);
	gets(ISBN);

	dvdPtr = GetDVDPtrByISBN(ISBN);
	if (dvdPtr == 0)
	{
		puts("등록되지 않은 ISBN입니다.");
		getchar();
		return;
	}

	ShowDVDInfo(dvdPtr);
}

/* 함	수 : void RentDVD(void)
 * 기   능 : 고객이 DVD를 대여하는 과정 처리
 * 반   환 : void
 */
void RentDVD(void)
{
	char ISBN[ISBN_LEN];
	int registDVD;
	int registCus;
	int rentSte;

	char cusID[ID_LEN];
	unsigned int rentDay;

	fputs("대여 DVD ISBN 입력 : ", stdout);
	gets(ISBN);

	registDVD = IsRegistISBN(ISBN);
	if (registDVD == 0)
	{
		puts("등록되지 않은 ISBN 입니다.");
		getchar();
		return;
	}

	rentSte = GetDVDRentState(ISBN);
	if (rentSte == RENTED)
	{
		puts("대여 중이라 대여가 불가능 합니다.");
		getchar();
		return;
	}

	puts("대여가 가능 합니다. 대여 과정을 진행 합니다.");
	fputs("대여 고객 ID 입력 : ", stdout);
	gets(cusID);

	registCus = IsRegistID(cusID);
	if (registCus == 0)
	{
		puts("가입 고객이 아닙니다.");
		getchar();
		return;
	}

	fputs("대여 날짜 입력 : ", stdout);
	scanf("%u", &rentDay);
	while(getchar() != '\n');

	SetDVDRented(ISBN, cusID, rentDay);
	puts("대여가 완료 되었습니다.");
	getchar();
}

/* 함	수 : void ReturnDVD(void)
 * 기	능 : 고객이 DVD를 반납하는 과정 처리
 * 반   환 : void 
 *
 */
void ReturnDVD(void)
{
	char ISBN[ISBN_LEN];
	int registDVD;
	int rentSte;

	fputs("반납 DVD ISBN 입력 : ", stdout);
	gets(ISBN);

	registDVD = IsRegistISBN(ISBN);
	if (registDVD == 0)
	{
		puts("등록되지 않은 ISBN 입니다.");
		getchar();
		return;
	}

	rentSte = GetDVDRentState(ISBN);
	if (rentSte == RETURNED)
	{
		puts("대여되지 않은 DVD 입니다.");
		getchar();
		return;
	}

	SetDVDReturned(ISBN);
	getchar();
}

/* 함	수 : void ShowDVDRentAllCusInfo(void)
 * 기	능 : 특정 DVD 대여자 전체정보 출력
 * 반   환 : void
 * 
 */
void ShowDVDRentAllCusInfo(void)
{
	int i;
	char isbn[ISBN_LEN];

	dvdInfo *ptrDVDInfo;
	int rentCusNum;

	dvdRentInfo *ptrDVDRentInfo;
	cusInfo *ptrCusInfo;

	fputs("찾는 ISBN 입력 : ", stdout);
    gets(isbn);

	ptrDVDInfo = GetDVDPtrByISBN(isbn);
	if (ptrDVDInfo == 0)
	{
		puts("존재하지 않는 ISBN 입니다.");
		getchar();
		return;
	}

    PrintOutRentAllCusInfo((char *)isbn);
//	rentCusNum = ptrDVDInfo->numOfRentCus;
//	ptrDVDRentInfo = ptrDVDInfo->rentList;

//	for (i = 0; i < rentCusNum; i++)
//	{
//		printf("대여일 : %d \n", ptrDVDRentInfo[i].rentDay);
//		ptrCusInfo = GetCusPtrByID(ptrDVDRentInfo[i].cusID);
//		ShowCustomerInfoContinue(ptrCusInfo);
//	}

	puts("조회를 완료하였습니다.");
	getchar();
}

/* end of file */

