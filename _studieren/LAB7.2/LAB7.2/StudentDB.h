/*
 * 파일명 : StudentDB.h
 * 프로그램의 목적 및 기능 : StudentDB와 관련된 class를 선언한 헤더 파일입니다.
 * ==========================================================================================================
 * AUTHOR : 변정호
 * Program completion Date : 2026.04.17
 * ==========================================================================================================
*/

#ifndef CLASS_STUDENT_DB_H   // 중복 포함 방지
#define CLASS_STUDENT_DB_H

#include <iostream>
#include <string>
#include "Student.h"

using namespace std;


/* StudentDB Class 입니다.
* 구성 요소 :
*     - private :
*            - string db_name    : 학생 데이터베이스의 이름입니다.
*            - int num_entries   : 학생의 수를 저장하는 변수입니다.
*            - Student* students : Student 객체 배열을 가리키는 포인터입니다.
*     - public  :
*            - StudentDB()           : 기본 생성자 입니다.
*            - StudentDB(...)        : 매개변수 생성자 입니다.
*            - ~StudentDB()          : 소멸자 입니다.
*            - sortStudents()        : 학생 데이터를 정렬하는 함수입니다.
*     - friend :
*            - istream >> 연산자 : 파일로부터 데이터를 입력받는 함수입니다.
*            - ostream << 연산자 : 데이터를 출력하는 함수입니다.
*/
class StudentDB
{
    friend istream& operator>>(istream&, StudentDB&);
    friend ostream& operator<<(ostream&, StudentDB&);

public:
    /* 기본 생성자 입니다.
    * 기능 설명 : StudentDB 객체를 초기화합니다.
    */
    StudentDB();

    /* 매개변수 생성자 입니다.
    * 기능 설명 : 데이터베이스 이름과 학생 수를 설정합니다.
    */
    StudentDB(string db_name, int num_entries);

    /* 소멸자 입니다.
    * 기능 설명 : 동적 메모리를 해제합니다.
    */
    ~StudentDB() {}

    /* sortStudents 함수입니다.
    * 기능 설명 : 지정된 기준과 정렬 방식에 따라 학생들을 정렬합니다.
    * 매개 변수 :
    *   - ST_ATTR attr        : 정렬 기준 (이름, 학번, GPA 등)
    *   - SORT_ORDER order    : 정렬 방식 (오름차순, 내림차순)
    */
    void sortStudents(ST_ATTR attr, SORT_ORDER sort_order);

private:
    string db_name;       // 데이터베이스 이름
    int num_entries;      // 학생 수
    Student* students;    // 학생 객체 배열 포인터
};

#endif