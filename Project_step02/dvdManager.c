/* Name : dvdManager.c	ver 1.0
 * Content : DVD 관련 업무 처리 함수들의 정의
 * Implementation : YSW
 * 
 * Last modified 2015/01/02
 */
#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"

/* 함 수 : void RegistDVD(void)
 * 기 능 : 신규 DVD 등록
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
 * 기 능 : ISBN을 통한 DVD 정보 검색
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
		puts("존재하지 않는 ISBN입니다.");
		getchar();
		return;
	}

	ShowDVDInfo(dvdPtr);
}

/* end of file */

