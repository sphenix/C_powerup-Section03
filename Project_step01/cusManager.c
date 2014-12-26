/* Name : cusManager.c	ver 1.1
 * Content : 고객 관련 업무 처리 함수들의 정의
 * Implementation : YSW
 * 
 * Last modified 2014/12/26
 */
#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
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
	char num[PHONE_LEN];

	fputs("ID 입력 : ", stdout);
	scanf("%s", ID);

	while (1)
	{
		if (IsRegistID(ID) == -1)
		{
			scanf("%s", ID);
		}
		else break;
	}
	
	fputs("이름 입력 : ", stdout);
	scanf("%s", name);

	fputs("전화번호 입력 : ", stdout);
	scanf("%s", num);
	
	if (!AddCusInfo(ID, name, num)) 
	{
		puts("등록에 실패 했습니다.");
		return;
	}

	puts("가입이 완료되었습니다.");
	while (getchar() != '\n');

	getchar();

	return;
}

/* 함 수 : void SearchCusInfo(void)
 * 기 능 : ID를 통한 회원 정보 검색
 * 반 환 : void
 *
 */
void SearchCusInfo(void)
{
	char ID[ID_LEN];
	cusInfo *pCus;

	fputs("찾을 ID 입력 : ", stdout);
	scanf("%s", ID);

	pCus = GetCusPtrByID(ID);
	if (pCus == NULL)
		puts("찾는 ID 가 존재하지 않습니다.");
	else
		ShowCustomerInfo(pCus);

	getchar();

	return;
}

/* end of file */

