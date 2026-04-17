/*
 * 파일명 : Student.h
 * 프로그램의 목적 및 기능 : Student와 관련된 class 및 열거형을 선언한 헤더 파일입니다.
 * ==========================================================================================================
 * AUTHOR : 변정호
 * Program completion Date : 2026.04.17
 * ==========================================================================================================
*/

#ifndef CLASS_STUDENT_H   // 중복 포함 방지
#define CLASS_STUDENT_H

#include <iostream>
#include <string>

using namespace std;


/* ST_ATTR 열거형 입니다.
* 기능 설명 : 학생 정보를 정렬할 기준을 정의합니다.
*/
enum ST_ATTR { NAME, ADDR, STID, MAJOR, STGPA };

/* SORT_ORDER 열거형 입니다.
* 기능 설명 : 정렬 방식(오름차순, 내림차순)을 정의합니다.
*/
enum SORT_ORDER { INCR, DECR };


/* Student Class 입니다.
* 구성 요소 :
*     - private :
*            - string name  : 학생 이름입니다.
*            - string addr  : 학생 주소입니다.
*            - int stID     : 학번입니다.
*            - string major : 전공입니다.
*            - double GPA   : 평균 평점입니다.
*     - public  :
*            - Student()            : 기본 생성자 입니다.
*            - Student(...)         : 매개변수 생성자 입니다.
*            - ~Student()           : 소멸자 입니다.
*            - compareStudent()     : 두 학생을 비교하는 함수입니다.
*     - friend :
*            - istream >> 연산자 : 학생 데이터를 입력받는 함수입니다.
*            - ostream << 연산자 : 학생 데이터를 출력하는 함수입니다.
*/
class Student
{
    friend istream& operator>>(istream&, Student&);
    friend ostream& operator<<(ostream&, Student&);

public:
    /* 기본 생성자 입니다.
    * 기능 설명 : 학생 정보를 초기화합니다.
    */
    Student();

    /* 매개변수 생성자 입니다.
    * 기능 설명 : 학생의 정보를 설정합니다.
    */
    Student(string name, string addr, int StID, string major, double GPA);

    /* 소멸자 입니다.
    * 기능 설명 : 객체 소멸 시 호출됩니다.
    */
    ~Student();

    /* compareStudent 함수입니다.
    * 기능 설명 : 두 학생을 특정 기준과 정렬 방식에 따라 비교합니다.
    * 매개 변수 :
    *   - Student& other : 비교 대상 학생 객체입니다.
    *   - ST_ATTR stAttr : 비교 기준입니다.
    *   - SORT_ORDER order : 정렬 방식입니다.
    * 반환값 :
    *   - int : 비교 결과 (양수, 음수, 0)
    */
    int compareStudent(Student& other, ST_ATTR stAttr, SORT_ORDER order);

private:
    string name;   // 학생 이름
    string addr;   // 주소
    int stID;      // 학번
    string major;  // 전공
    double GPA;    // 평균 평점
};

#endif