/*
* 파일명 : Mtrx.cpp
* 프로그램의 목적 및 기능 : Mtrx.h에 선언된 class의 내부를 구현하는 파일입니다.
* ==========================================================================================================
* AUTHOR : 변정호
* Program completion Date : 2026.04.17
* ==========================================================================================================
*/

#include "Mtrx.h"
#include <iostream>
#include <iomanip>

using namespace std;


/* 기본 생성자 입니다.
* 기능 설명 : 행렬의 초기값을 설정합니다.
*             이름은 빈 문자열, 행과 열은 0, 데이터 포인터는 nullptr로 초기화합니다.
*/
Mtrx::Mtrx() {
    this->name = "";
    this->n_row = 0;
    this->n_col = 0;
    this->dM = nullptr;
}


/* 매개변수 생성자 입니다.
* 기능 설명 : 전달받은 배열 데이터를 이용하여 행렬을 생성합니다.
* 매개 변수 :
*   - string nm    : 행렬의 이름입니다.
*   - double* pA   : 행렬 데이터를 담고 있는 1차원 배열입니다.
*   - int num_row  : 행의 개수입니다.
*   - int num_col  : 열의 개수입니다.
* 지역 변수 :
*   - int i, j : 행과 열 인덱스입니다.
*   - int k    : 1차원 배열 접근을 위한 인덱스입니다.
*/
Mtrx::Mtrx(string nm, double* pA, int num_row, int num_col) {
    int i, j, k = 0;

    this->name = nm;
    this->n_row = num_row;
    this->n_col = num_col;

    this->dM = new double* [this->n_row](); // n_row크기의 double형 포인터 배열을 만듭니다.

    for (i = 0; i < this->n_row; i++) {
        this->dM[i] = new double[this->n_col]();
        for (j = 0; j < this->n_col; j++) {
            this->dM[i][j] = pA ? pA[k++] : 0.0; // pA가 존재하면 값 복사, 아니면 0 초기화
        }
    }
}


/* 소멸자 입니다.
* 기능 설명 : 동적 할당된 2차원 배열 메모리를 해제합니다.
*/
Mtrx::~Mtrx() {
    for (int i = 0; i < n_row; i++)
        delete[] dM[i];
    delete[] dM;
}


#define SETW 7 // 원소의 출력은 7칸으로 맞춥니다.


/* << 연산자 오버로딩 함수입니다.
* 기능 설명 : 행렬을 보기 좋은 형식으로 출력합니다.
* 매개 변수 :
*   - ostream& fout : 출력 스트림
*   - const Mtrx& m : 출력할 행렬 객체
* 지역 변수 :
*   - int i, j : 행과 열 인덱스
* 호출 함수 :
*   - setw : 출력 폭을 지정합니다.
* 반환값 :
*   - ostream& : 출력 스트림을 반환합니다.
*/
ostream& operator<<(ostream& fout, const Mtrx& m)
{
    fout << m.name << endl;

    fout.setf(ios::fixed); // 모든 수의 소수점을 나타냅니다.
    fout.precision(2); // 소수점 이하 2자리로 고정

    for (int i = 0; i < m.n_row; i++) {

        // 왼쪽 괄호 출력
        if (i == 0) {
            fout<<"┌";
        }
        else if (i == m.n_row - 1) {
            fout<<"└";
        }
        else {
            fout<<"│";
        }

        // 행렬 값 출력
        for (int j = 0; j < m.n_col; j++) {
            fout << setw(7) << m.dM[i][j];
        }

        // 오른쪽 괄호 출력 (정렬 맞추기 위해 공백 2칸)
        if (i == 0) {
            fout << "  ┐";
        }
        else if (i == m.n_row - 1) {
            fout << "  ┘";
        }
        else {
            fout << "  │";
        }

        fout << endl; // 줄을 바꿉니다.
    }
    return fout;
}


/* >> 연산자 오버로딩 함수입니다.
* 기능 설명 : 파일로부터 행렬 데이터를 입력받습니다.
* 매개 변수 :
*   - istream& fin : 입력 스트림
*   - Mtrx& m      : 입력받을 행렬 객체
* 지역 변수 :
*   - int num_row, num_col : 행과 열의 크기
*   - double d             : 입력받을 값
* 반환값 :
*   - istream& : 입력 스트림을 반환합니다.
*/
istream& operator>>(istream& fin, Mtrx& m)
{
     
    int num_row, num_col;
    double d;

    fin >> num_row >> num_col; // 파일로부터 받습니다.
    m.n_row = num_row;
    m.n_col = num_col; // 행과 열을 저장합니다.

    m.dM = new double* [num_row];

    for (int r = 0; r < num_row; r++) {
        m.dM[r] = new double[num_col];
        for (int c = 0; c < num_col; c++) {
            if (fin.eof())
                m.dM[r][c] = 0.0;
            else {
                fin >> d;
                m.dM[r][c] = d;
            }
        }
    }
    return fin;
}


/* + 연산자 오버로딩 함수입니다.
* 기능 설명 : 두 행렬의 덧셈을 수행합니다.
*/
const Mtrx Mtrx::operator+(const Mtrx& mA)
{
    Mtrx mR("mR", nullptr, this->n_row, this->n_col);

    for (int i = 0; i < this->n_row; i++) {
        for (int j = 0; j < this->n_col; j++) {
            mR.dM[i][j] = this->dM[i][j] + mA.dM[i][j];
        }
    }
    return mR;
}


/* - 연산자 오버로딩 함수입니다.
* 기능 설명 : 두 행렬의 뺄셈을 수행합니다.
*/
const Mtrx Mtrx::operator-(const Mtrx& mA)
{
    Mtrx mR("mR", nullptr, n_row, n_col);

    for (int i = 0; i < this->n_row; i++) {
        for (int j = 0; j < this->n_col; j++) {
            mR.dM[i][j] = this->dM[i][j] - mA.dM[i][j];
        }
    }
    return mR;
}


/* * 연산자 오버로딩 함수입니다.
* 기능 설명 : 두 행렬의 곱셈을 수행합니다.
*/
const Mtrx Mtrx::operator*(const Mtrx& mA)
{
    Mtrx mR("mR", nullptr, this->n_row, mA.n_col);

    for (int i = 0; i < this->n_row; i++) {
        for (int j = 0; j < mA.n_col; j++) {
            mR.dM[i][j] = 0.0;
            for (int k = 0; k < this->n_col; k++) {
                mR.dM[i][j] += this->dM[i][k] * mA.dM[k][j];
            }
        }
    }
    return mR; // 계산 결과를 돌려줍니다.
}


/* ~ 연산자 오버로딩 함수입니다.
* 기능 설명 : 행렬의 전치(transpose)를 수행합니다.
*/
const Mtrx Mtrx::operator~()
{
    Mtrx mR("mR", nullptr, this->n_col, this->n_row);

    for (int i = 0; i < this->n_row; i++) {
        for (int j = 0; j < this->n_col; j++) { // 행과 열을 바꿉니다.
            mR.dM[j][i] = this->dM[i][j];
        }
    }
    return mR; // 계산 결과를 돌려줍니다.
}


/* = 연산자 오버로딩 함수입니다.
* 기능 설명 : 행렬을 깊은 복사(deep copy)합니다.
*/
const Mtrx& Mtrx::operator=(const Mtrx& right)
{
    this->n_row = right.n_row;
    this->n_col = right.n_col;

    this->dM = new double* [this->n_row]; // n_row 크기의 double형 포인터 배열을 만듭니다.

    for (int r = 0; r < this->n_row; r++) {
        this->dM[r] = new double[this->n_col];
        for (int c = 0; c < this->n_col; c++) {
            this->dM[r][c] = right.dM[r][c]; // 원소들을 복사합니다.
        }
    }
    return *this; // 연쇄 할당을 위해 리턴합니다.
}


/* == 연산자 오버로딩 함수입니다.
* 기능 설명 : 두 행렬이 같은지 비교합니다.
*/
bool Mtrx::operator==(const Mtrx& mA)
{
    for (int i = 0; i < n_row; i++) { // 만일 일치하는 원소가 하나라도 없다면 false를 돌려줍니다.
        for (int j = 0; j < n_col; j++) {
            if (this->dM[i][j] != mA.dM[i][j])
                return false;
        }
    }
    return true; // 모두 일치한다면 true를 돌려줍니다.
}


/* != 연산자 오버로딩 함수입니다.
* 기능 설명 : 두 행렬이 다른지 비교합니다.
*/
bool Mtrx::operator!=(const Mtrx& mA)
{
    for (int i = 0; i < n_row; i++) { // 일차하는 원소가 하나라도 없다면  true를 돌려줍니다.
        for (int j = 0; j < n_col; j++) {
            if (this->dM[i][j] != mA.dM[i][j])
                return true;
        }
    }
    return false; //모두 일치한다면 false를 돌려줍니다.
}