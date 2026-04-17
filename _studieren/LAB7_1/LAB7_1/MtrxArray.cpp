/*
* 파일명 : MtrxArray.cpp
* 프로그램의 목적 및 기능 : MtrxArray.h에 선언된 class의 내부를 구현하는 파일입니다.
* ==========================================================================================================
* AUTHOR : 변정호
* Program completion Date : 2026.04.17
* ==========================================================================================================
*/

#include <iostream>
#include "MtrxArray.h"
#include "Mtrx.h"

using namespace std;


/* 생성자 입니다.
* 기능 설명 : Mtrx 객체 배열을 동적 할당합니다.
* 매개 변수 :
*   - int array_size : 생성할 행렬 배열의 크기입니다.
* 지역 변수 :
*   - 없음
* 호출 함수 :
*   - new : Mtrx 객체 배열을 동적 생성합니다.
*/
MtrxArray::MtrxArray(int array_size)
{
    mtrxArrySize = array_size;           // 배열 크기 설정
    pMtrx = new Mtrx[mtrxArrySize]();    // Mtrx 객체 배열 생성 및 초기화
}


/* 소멸자 입니다.
* 기능 설명 : 동적 할당된 Mtrx 객체 배열을 해제합니다.
* 호출 함수 :
*   - delete[] : 배열 전체 메모리를 해제합니다.
*/
MtrxArray::~MtrxArray()
{
    delete[] pMtrx;  // 배열 전체 해제
}


/* isValidIndex 함수입니다.
* 기능 설명 : 주어진 인덱스가 배열 범위 내에 있는지 검사합니다.
* 매개 변수 :
*   - int index : 검사할 인덱스 값입니다.
* 반환값 :
*   - true  : 유효한 인덱스인 경우
*   - false : 범위를 벗어난 경우
*/
bool MtrxArray::isValidIndex(int index)
{
    if (index >= 0 && index < mtrxArrySize) {
        return true;
    }
    else {
        return false;
    }
}


/* [] 연산자 오버로딩 함수입니다.
* 기능 설명 : 배열처럼 Mtrx 객체에 접근할 수 있도록 합니다.
* 매개 변수 :
*   - int index : 접근할 인덱스입니다.
* 지역 변수 :
*   - 없음
* 호출 함수 :
*   - isValidIndex : 인덱스 유효성을 검사합니다.
*   - exit        : 범위를 벗어나면 프로그램을 종료합니다.
* 반환값 :
*   - Mtrx& : 해당 인덱스의 행렬 객체를 참조로 반환합니다.
*/
Mtrx& MtrxArray::operator[](int index)
{
    if (!isValidIndex(index)) {
        cout << "Index out of range!" << endl;
        exit(1);
    }
    return pMtrx[index];
}