/*
 * 파일명 : Mtrx.h
 * 프로그램의 목적 및 기능 : Mtrx와 관련된 class를 선언한 헤더 파일입니다.
 * ==========================================================================================================
 * AUTHOR : 변정호
 * Program completion Date : 2026.04.17
 * ==========================================================================================================
*/

#ifndef MTRX_H   // 중복 포함 방지
#define MTRX_H

#define MAX_SIZE 100

#include <iostream>
#include <string>

using namespace std;

class MtrxArray; // MtrxArray 클래스 전방 선언


/* Mtrx Class 입니다.
* 구성 요소 :
*     - private :
*            - string name : 행렬의 이름을 저장하는 변수입니다.
*            - int n_row   : 행(row)의 개수입니다.
*            - int n_col   : 열(column)의 개수입니다.
*            - double** dM : 2차원 동적 배열(행렬 데이터)을 가리키는 포인터입니다.
*     - public  :
*            - Mtrx()                  : 기본 생성자 입니다.
*            - Mtrx(...)               : 매개변수 생성자 입니다.
*            - ~Mtrx()                 : 소멸자 입니다.
*            - operator+               : 행렬 덧셈 연산자 입니다.
*            - operator-               : 행렬 뺄셈 연산자 입니다.
*            - operator*               : 행렬 곱셈 연산자 입니다.
*            - operator~               : 전치 행렬 연산자 입니다.
*            - operator=               : 대입 연산자 (깊은 복사) 입니다.
*            - operator==              : 행렬 비교 (같음) 연산자 입니다.
*            - operator!=              : 행렬 비교 (다름) 연산자 입니다.
*            - set_name()              : 행렬 이름을 설정하는 함수입니다.
*     - friend :
*            - ostream << 연산자 : 행렬을 출력하기 위한 friend 함수입니다.
*            - istream >> 연산자 : 행렬을 입력받기 위한 friend 함수입니다.
*            - MtrxArray         : 배열 클래스에서 접근 가능하도록 설정합니다.(friend)
*/
class Mtrx {
	friend ostream& operator<<(ostream&, const Mtrx&);
	friend istream& operator>>(istream&, Mtrx&);
	friend class MtrxArray;

public:
	/* 기본 생성자 입니다.
	* 기능 설명 : 행렬의 초기값을 설정합니다.
	*/
	Mtrx();

	/* 매개변수 생성자 입니다.
	* 기능 설명 : 외부 데이터로 행렬을 생성합니다.
	*/
	Mtrx(string nm, double* pA, int num_row, int num_col);

	/* 소멸자 입니다.
	* 기능 설명 : 동적 할당된 메모리를 해제합니다.
	*/
	~Mtrx();

	/* + 연산자 오버로딩 함수입니다.
	* 기능 설명 : 두 행렬의 덧셈을 수행합니다.
	*/
	const Mtrx operator+(const Mtrx&);

	/* - 연산자 오버로딩 함수입니다.
	* 기능 설명 : 두 행렬의 뺄셈을 수행합니다.
	*/
	const Mtrx operator-(const Mtrx&);

	/* * 연산자 오버로딩 함수입니다.
	* 기능 설명 : 두 행렬의 곱셈을 수행합니다.
	*/
	const Mtrx operator*(const Mtrx&);

	/* ~ 연산자 오버로딩 함수입니다.
	* 기능 설명 : 행렬의 전치(transpose)를 수행합니다.
	*/
	const Mtrx operator~();

	/* = 연산자 오버로딩 함수입니다.
	* 기능 설명 : 행렬을 깊은 복사합니다.
	*/
	const Mtrx& operator=(const Mtrx&);

	/* == 연산자 오버로딩 함수입니다.
	* 기능 설명 : 두 행렬이 같은지 비교합니다.
	*/
	bool operator==(const Mtrx&);

	/* != 연산자 오버로딩 함수입니다.
	* 기능 설명 : 두 행렬이 다른지 비교합니다.
	*/
	bool operator!=(const Mtrx&);

	/* set_name 함수입니다.
	* 기능 설명 : 행렬의 이름을 설정합니다.
	*/
	void set_name(string nm) { this->name = nm; }

private:
	string name;   // 행렬 이름
	int n_row;     // 행의 개수
	int n_col;     // 열의 개수
	double** dM;   // 2차원 동적 배열 포인터
};

#endif