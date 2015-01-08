/* Name : cusManager	ver 1.2
 * Content : 고객 관련 업무 처리 함수들의 정의
 * Implementation : YSW
 * 
 * Last modified 2015/01/05
 */
#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"

/* 함 수 : void RegistCustomer(void)
 * 기 능 : 신규 회원 가입
 * 반 환 : void
 *
 */
void RegistCustomer(void)
{
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];

	fputs("ID 입력 : ", stdout);
	gets(ID);

	if (IsRegistID(ID))
	{
		puts("해당 ID는 사용 중에 있습니다. 다른 ID를 선택해 주세요");
		getchar();
		return;
	}
	
	fputs("이름 입력 : ", stdout);
	gets(name);

	fputs("전화번호 입력 : ", stdout);
	gets(phoneNum);
	
	if (!AddCusInfo(ID, name, phoneNum)) 
	{
		puts("정상적인 데이터 저장에 실패하였습니다.");
		getchar();
		return;
	}

	puts("가입이 완료되었습니다.");
	getchar();
}

/* 함 수 : void SearchCusInfo(void)
 * 기 능 : ID를 통한 회원 정보 검색
 * 반 환 : void
 *
 */
void SearchCusInfo(void)
{
	char ID[ID_LEN];
	cusInfo *cusPtr;

	fputs("찾을 ID 입력 : ", stdout);
	gets(ID);

	cusPtr = GetCusPtrByID(ID);
	if (cusPtr == 0)
	{
		puts("존재하지 않는 ID입니다.");
		getchar();
		return;
	}

	ShowCustomerInfo(cusPtr);
}

/* 함 수 : void RentDVD(void)
 * 기 능 : DVD 대여 실행.
 * 반 환 : void
 * 
 */
void RentDVD(void)
{
	char ISBN[ISBN_LEN];
	char ID[ID_LEN];
	cusInfo *cusPtr;
	// dvdInfo datadDVD;
	dvdInfo *pDVD;
	unsigned int rentDay;
	
	fputs("대여 DVD ISBN 입력 : ", stdout);
	gets(ISBN);
	
	if (!IsRegistISBN(ISBN))
	{
		puts("없는 DVD 입니다. 대여가 불가능 합니다.");
		getchar();
		return;
	}

	pDVD = GetDVDPtrByISBN(ISBN);	
	
	if ((pDVD->rentState) == RENTED)
	{
		puts("대여 중이라 대여가 불가능 합니다.");
		getchar();
		return;
	}
	
	puts("대여가 가능 합니다. 대여 과정을 진행 합니다.");

	fputs("대여 고객 ID 입력 : ", stdout);
	gets(ID);

	cusPtr = GetCusPtrByID(ID);
	if (cusPtr == 0)
	{
		puts("가입 고객이 아닙니다.");
		getchar();
		return;
	}
		
	fputs("대여 날짜 입력 : ", stdout);
	scanf("%u", &rentDay);
		
	strcpy(pDVD->rentList[pDVD->numOfRentCus].cusID,ID);
	pDVD->rentList[pDVD->numOfRentCus].rentDay = rentDay;
	pDVD->rentState = RENTED;

	while(getchar() != '\n');
		
	(pDVD->numOfRentCus)++;
		
	puts("대여가 완료되었습니다.");
	return;
}

/* 함 수 d ReturnDVD(void)
 * 기 능 : DVD 반납.
 * 반 환 : void
 *
 */
void ReturnDVD(void)
{

}
/* end of file */

