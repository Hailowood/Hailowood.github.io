/*
 * 파일명 : StudentDB.cpp
 * 프로그램의 목적 및 기능 : StudentDB.h에 선언된 class의 내부를 구현하는 파일입니다.
 * ==========================================================================================================
 * AUTHOR : 변정호
 * Program completion Date : 2026.04.17
 * ==========================================================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include "StudentDB.h"

using namespace std;


/* 기본 생성자 입니다.
* 기능 설명 : StudentDB 객체를 초기화합니다.
*/
StudentDB::StudentDB() {
    this->db_name = "";
    this->num_entries = 0;
    this->students = NULL;
}


/* 매개변수 생성자 입니다.
* 기능 설명 : 학생 수에 맞는 배열을 생성하고 초기화합니다.
*/
StudentDB::StudentDB(string db_name, int num_entries)
{
    this->db_name = db_name;
    this->num_entries = num_entries;
    this->students = new Student[num_entries]; // 
}


/* sortStudents 함수입니다.
* 기능 설명 : 삽입 정렬(insertion sort)을 이용하여 학생 데이터를 정렬합니다.
* 매개 변수 :
*   - ST_ATTR key_attr     : 정렬 기준
*   - SORT_ORDER sort_order: 정렬 방식
* 지역 변수 :
*   - Student keyST : 기준이 되는 학생 객체
*   - int j         : 비교 인덱스
*/
void StudentDB::sortStudents(ST_ATTR key_attr, SORT_ORDER sort_order)
{
    Student keyST;
    int j;

    for (int k = 1; k < this->num_entries; k++) {
        keyST = this->students[k];

        for (j = k; j > 0; j--) {
            if (this->students[j - 1].compareStudent(keyST, key_attr, sort_order) <= 0) // 오름차순으로 정렬되어있다면 break 합니다.
                break;
            else
                this->students[j] = this->students[j - 1]; // 내림차순으로 정렬되어있다면 j번째와 j-1번째를 swap합니다.
        }
        this->students[j] = keyST; // swap
    }
}


/* >> 연산자 오버로딩 함수입니다.
* 기능 설명 : 파일로부터 StudentDB 데이터를 입력받습니다.
* 매개 변수 :
*   - istream& fin   : 입력 스트림
*   - StudentDB& stDB: 데이터를 저장할 객체
* 지역 변수 :
*   - string db_name
*   - int num_students
*   - StudentDB* pStDB : 임시 객체 포인터
* 반환값 :
*   - istream& : 입력 스트림 반환
*/
istream& operator>>(istream& fin, StudentDB& stDB)
{
    string db_name;
    int num_students;
    StudentDB* pStDB;

    fin >> db_name >> num_students; // 파일로부터 값을 받습니다.

    cout << "File input : DB-name (" << db_name;
    cout << "), num_students (" << num_students << ")" << endl;

    pStDB = new StudentDB(db_name, num_students);

    for (int i = 0; i < num_students; i++) {
        fin >> pStDB->students[i]; // students[i]는 class Student를 사용하고 >>는 operator의 정의대로 동작합니다.
    }

    stDB = *pStDB; // 값 복사

    return fin; // 연쇄 할당을 위해 반환합니다.
}


/* << 연산자 오버로딩 함수입니다.
* 기능 설명 : StudentDB의 전체 데이터를 출력합니다.
* 매개 변수 :
*   - ostream& ostr : 출력 스트림
*   - StudentDB& st : 출력할 객체
* 반환값 :
*   - ostream& : 출력 스트림 반환
*/
ostream& operator<<(ostream& ostr, StudentDB& st)
{
    ostr << "StudentDB (" << st.db_name << ", num_students = ";
    ostr << st.num_entries << ")" << endl;

    for (int i = 0; i < st.num_entries; i++) {
        ostr << st.students[i] << endl;
    }

    return ostr;// 연쇄 할당을 위해 반환합니다.
}