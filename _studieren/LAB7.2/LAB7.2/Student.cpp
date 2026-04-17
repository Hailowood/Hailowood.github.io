/*
 * 파일명 : Student.cpp
 * 프로그램의 목적 및 기능 : Student.h에 선언된 class의 내부를 구현하는 파일입니다.
 * ==========================================================================================================
 * AUTHOR : 변정호
 * Program completion Date : 2026.04.17
 * ==========================================================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Student.h"

using namespace std;


/* 기본 생성자 입니다.
* 기능 설명 : 학생 객체의 멤버 변수를 초기화합니다.
*/
Student::Student() {
    this->name = "";
    this->addr = "";
    this->stID = 0;
    this->major = "";
    this->GPA = 0;
}


/* 매개변수 생성자 입니다.
* 기능 설명 : 전달받은 값으로 학생 정보를 초기화합니다.
*/
Student::Student(string name, string addr, int StID, string major, double GPA) {
    this->name = name;
    this->addr = addr;
    this->stID = StID;
    this->major = major;
    this->GPA = GPA;
}


/* 소멸자 입니다.
* 기능 설명 : 객체 소멸 시 호출됩니다.
*/
Student::~Student() {}


/* << 연산자 오버로딩 함수입니다.
* 기능 설명 : 학생 정보를 출력합니다.
* 매개 변수 :
*   - ostream& ostr : 출력 스트림
*   - Student& st   : 출력할 학생 객체
* 호출 함수 :
*   - setw : 출력 정렬을 위해 사용됩니다.
* 반환값 :
*   - ostream& : 출력 스트림을 반환합니다.
*/
ostream& operator<<(ostream& ostr, Student& st) {
    ostr << "Student(" << setw(10) << st.name;
    ostr << "," << setw(10) << st.addr;
    ostr << ", " << setw(5) << st.stID;
    ostr << ", " << setw(10) << st.major;
    ostr << ", " << setw(6) << st.GPA << ")";
    return ostr;
}


/* >> 연산자 오버로딩 함수입니다.
* 기능 설명 : 입력 스트림으로부터 학생 데이터를 읽어옵니다.
* 매개 변수 :
*   - istream& istr : 입력 스트림
*   - Student& st   : 데이터를 저장할 객체
* 반환값 :
*   - istream& : 입력 스트림을 반환합니다.
*/
istream& operator>>(istream& istr, Student& st) {
    istr >> st.name >> st.addr >> st.stID >> st.major >> st.GPA;
    return istr;
}


/* compareStudent 함수입니다.
* 기능 설명 : 두 학생 객체를 특정 기준에 따라 비교합니다.
* 매개 변수 :
*   - Student& other     : 비교 대상 학생 객체입니다.
*   - ST_ATTR stAttr     : 비교 기준 (이름, 주소, 학번 등)
*   - SORT_ORDER order   : 정렬 방식 (오름차순/내림차순)
* 지역 변수 :
*   - int cmp_res : 비교 결과를 저장하는 변수입니다.
* 반환값 :
*   - int : 비교 결과 (-1, 0, 1)
*/
int Student::compareStudent(Student& other, ST_ATTR stAttr, SORT_ORDER sort_order)
{
    int cmp_res;

    switch (stAttr) {
    case NAME: // 기준이 이름일때
        if (this->name < other.name) cmp_res = -1;
        else if (this->name > other.name) cmp_res = 1;
        else cmp_res = 0;
        break;

    case ADDR: // 기준이 주소일때
        if (this->addr < other.addr) cmp_res = -1;
        else if (this->addr > other.addr) cmp_res = 1;
        else cmp_res = 0;
        break;

    case STID: // 기준이 학번일때
        if (this->stID < other.stID) cmp_res = -1;
        else if (this->stID > other.stID) cmp_res = 1;
        else cmp_res = 0;
        break;

    case MAJOR: // 기준이 과목일때
        if (this->major < other.major) cmp_res = -1;
        else if (this->major > other.major) cmp_res = 1;
        else cmp_res = 0;
        break;

    case STGPA: // 기준이 학점일때 
        if (this->GPA < other.GPA) cmp_res = -1;
        else if (this->GPA > other.GPA) cmp_res = 1;
        else cmp_res = 0;
        break;
         
    default: // 기준 열거에 들어가지 않는 값일 때.
        cout << "Un-implemented attribute (" << stAttr;
        cout << ") in compareStudent() !!" << endl;
        exit(1);
    }

    // 내림차순일 경우 결과 반전
    if (sort_order == DECR)
        cmp_res = cmp_res * -1;

    return cmp_res; 
}