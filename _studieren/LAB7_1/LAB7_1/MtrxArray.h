/*
 * 파일명 : MtrxArray.h
 * 프로그램의 목적 및 기능 : MtrxArray와 관련된 class를 선언한 헤더 파일입니다.
 * ==========================================================================================================
 * AUTHOR : 변정호
 * Program completion Date : 2026.04.17
 * ==========================================================================================================
*/

#ifndef MTRX_ARRAY_H   // 중복 포함 방지
#define MTRX_ARRAY_H

#include <iostream>
using namespace std;

class Mtrx; // Mtrx 클래스 전방 선언 (헤더 의존성 감소)


/* MtrxArray Class 입니다.
* 구성 요소 :
*     - private :
*            - Mtrx* pMtrx        : Mtrx 객체 배열을 가리키는 포인터입니다.
*            - int mtrxArrySize   : 배열의 크기를 저장하는 변수입니다.
*            - bool isValidIndex(): 인덱스 유효성을 검사하는 함수입니다.
*     - public  :
*            - MtrxArray()        : 생성자 입니다.
*            - ~MtrxArray()       : 소멸자 입니다.
*            - operator[]         : 배열처럼 접근하기 위한 연산자 오버로딩 함수입니다.
*/
class MtrxArray
{
public:
	/* 생성자 입니다.
	* 기능 설명 : 지정된 크기의 Mtrx 객체 배열을 생성합니다.
	*/
	MtrxArray(int array_size);

	/* 소멸자 입니다.
	* 기능 설명 : 동적 할당된 배열을 해제합니다.
	*/
	~MtrxArray();

	/* [] 연산자 오버로딩 함수입니다.
	* 기능 설명 : 배열처럼 인덱스를 통해 Mtrx 객체에 접근합니다.
	*/
	Mtrx& operator[](int);

private:
	Mtrx* pMtrx;          // Mtrx 객체 배열 포인터
	int mtrxArrySize;     // 배열 크기

	/* 인덱스 유효성 검사 함수입니다.
	* 기능 설명 : 주어진 인덱스가 배열 범위 내인지 확인합니다.
	*/
	bool isValidIndex(int index);
};

#endif