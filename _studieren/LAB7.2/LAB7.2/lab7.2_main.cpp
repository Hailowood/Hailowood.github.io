/*
 * 파일명 : StudentDB_main.cpp
 * 프로그램의 목적 및 기능 :
 *  - 파일로부터 학생 데이터를 읽어옵니다.
 *  - StudentDB 객체에 데이터를 저장합니다.
 *  - 다양한 기준(NAME, GPA, STID)으로 정렬 후 출력합니다.
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


/* main 함수입니다.
* 기능 설명 : 프로그램의 시작점으로, 학생 데이터를 입력받고 정렬 및 출력합니다.
* 매개 변수 :
*   - 없음
* 지역 변수 :
*   - string input_data_file : 입력 파일 이름을 저장하는 변수입니다.
*   - ifstream fin          : 파일 입력 스트림입니다.
*   - ofstream fout         : (사용되지 않지만) 파일 출력 스트림입니다.
*   - StudentDB stDB        : 학생 데이터를 저장하는 객체입니다.
* 호출 함수 :
*   - open          : 파일을 엽니다.
*   - fail          : 파일 열기 실패 여부를 확인합니다.
*   - sortStudents  : 학생 데이터를 정렬합니다.
*   - operator>>    : 파일에서 데이터를 입력받습니다.
*   - operator<<    : 데이터를 출력합니다.
* 반환값 :
*   - int : 프로그램 종료 상태를 반환합니다.
*/
int main()
{
    string input_data_file = "student_DB.txt"; // 입력 파일 이름 설정
    ifstream fin;   // 입력 파일 스트림
    ofstream fout;  // 출력 파일 스트림 (사용 안됨)
    StudentDB stDB; // 학생 데이터 객체

    /* 입력 파일 열기 */
    fin.open(input_data_file);
    if (fin.fail()) {
        cout << "Fail to open input data file (" << input_data_file << ") !!!!" << endl;
        exit(1); // 파일 열기 실패 시 프로그램 종료
    }

    cout << "File input from " << input_data_file << " . . . ." << endl;

    /* 파일로부터 학생 데이터 입력 */
    fin >> stDB;

    /* 초기 상태 출력 */
    cout << endl << "Initial state of StudentDB : " << endl;
    cout << stDB;

    /* 이름 기준 오름차순 정렬 */
    cout << endl << "Sorted StudentDB (keyAttr = NAME, sort_order = INCR) : " << endl;
    stDB.sortStudents(NAME, INCR);
    cout << stDB;

    /* GPA 기준 내림차순 정렬 */
    cout << endl << "Sorted StudentDB (keyAttr = GPA, sort_order = DECR) : " << endl;
    stDB.sortStudents(STGPA, DECR);
    cout << stDB;

    /* 학번 기준 오름차순 정렬 */
    cout << endl << "Sorted StudentDB (keyAttr = STID, sort_order = INCR) : " << endl;
    stDB.sortStudents(STID, INCR);
    cout << stDB;

    /* 파일 닫기 */
    fin.close();

    return 0;
} // end main