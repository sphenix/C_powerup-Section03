/* Name : cusInfoAccess.c	ver	1.0
 * Content : 고객 정보 저장 및 참조 함수들의 정의
 * Implementation : YSW
 *
 * Last modified	2014/12/17
 */

#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER	100

static cusInfo	*cusList[MAX_CUSTOMER];
static int numOfCustomer = 0;

/* 함 수 : int AddCusInfo (char *ID, char *name, char *num)
 * 기 능 : cusInfo 할당 및 저장
 * 반 환 : 성공 시 '등록된 정보의 개수', 실패시 0을 반환
 */
int AddCusInfo(char *ID, char *name, char *num)
{
//작성 필요.
}

/* 함 수 : cusInfo *GetCusPtrByID(char *ID)
 * 기 능 : 해당 ID의 정보를 담고 있는 변수의 포인터 변환
 * 반 환 : 등록 안된 ID의 경우 NULL 포인터 반환
 *
 */
cusInfo *GetCusPtrByID(char *ID)
{
	//작성 필요.
}

/* 함 수 : int IsRegistID(char *ID)
 * 기 능 : 가입된 ID인지 확인
 * 반 환 : 가입 되었으면 1, 아니면 0 반환
 *
 */
int IsRegistID(char *ID)
{
	// 작성 필요.
}

/* end fo file */
