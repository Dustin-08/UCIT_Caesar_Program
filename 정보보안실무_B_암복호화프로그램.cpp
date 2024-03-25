/* 이 프로그램은 울산과학대학교 컴퓨터IT학부 IoT기술전공 정보보안실무 과목의 "Caesar(시저)" 암호 프로그램 입니다.
* 암호화/복호화가 가능합니다. (공백 포함) 
* Caear 암호란?: 뒤로 3글자씩 밀어서 치환하는 암호
* 컴파일러가 없다면: https://www.onlinegdb.com/online_c++_compiler 
*/

#include <iostream>
#include <string>

using namespace::std;

int main()
{
    // 1. 변수 선언
    int selectCrypto; // 암호화 or 복호화 결정
    string plainText; // 평문 저장 변수
    int shiftCnt; // 몇칸씩 밀지 저장하는 정수 변수
    int shiftDirection; // 어느 방향으로 밀지 저장하는 정수 변수 (1: 앞, 2: 뒤)
    string encryptText; // 암호화된 변수
    
    // 2. input으로 암호화할지 복호화할지 결정
    cout << "암호화 시킬지 복호화 시킬지 번호를 눌러 결정하시오." << "\n";
    cout << "암호화 == 1, 복호화 == 2, 종료 == 3: ";
    cin >> selectCrypto;
    
    cout << "================================================================================" << "\n";
    
    // 3. while문으로 무한 loop
    while(true){
        plainText = ""; // 암호화/복호화 진행 전에 plainText 초기화
        encryptText = ""; // 암호화/복호화 진행 전에 encryptText 초기화
        
        // 4. if 암호화
        if(selectCrypto == 1){
            // 4_1. input으로 암호화할 plainText 받기
            cout << "암호화 시킬 평문(plainText)를 입력하세요: ";
            cin.ignore(); // 이전 입력 버퍼 비우기
            getline(cin, plainText); // 공백 포함하여 한 줄을 입력받음
            //cin >> plainText;
            
            cout << "================================================================================" << "\n";
            
            // 4_2. input으로 어느 방향으로 밀지 받기
            cout << "어느 방향으로 밀지 번호를 눌러 결정하시오." << "\n";
            cout << "앞 == 1, 뒤 == 2: ";
            cin >> shiftDirection;
            
            cout << "================================================================================" << "\n";
            
            // 입력이 1 또는 2가 아닌 경우 다시 입력 안내
            while (shiftDirection != 1 && shiftDirection != 2) {
                cout << "올바른 번호를 입력하세요." << "\n";
                cout << "앞 == 1, 뒤 == 2: ";
                cin >> shiftDirection;
                cout << "================================================================================" << "\n";
            }
            
            // 4_3. input으로 몇칸으로 밀지 받기
            cout << "몇칸 밀지 번호를 눌러 결정하시오.: ";
            cin >> shiftCnt;
            
            cout << "================================================================================" << "\n";
            
            // 4_4. custom 암호화 시작
            for (int i = 0; i < plainText.length(); ++i) { // 입력받은 plainText의 길이를 세서 그만큼 for문 반복
                char ch = plainText[i]; // 현재 인덱스에 있는 문자를 ch 변수에 저장
        
                // 알파벳인 경우만 밀기 작업 수행
                if (isalpha(ch)) { // ch가 알파벳인 경우
                    // 대문자인 경우
                    if (isupper(ch)) { // upper, lower에 따라 대소문자 구분
                        ch = 'A' + (ch - 'A' + shiftCnt) % 26; // 밀기 작업 수행하여 대문자를 변환
                        /* 상세 설명: 'A'에서 시작하여 현재 문자 ch와 'A' 사이의 거리를 계산 <- 이를 통해 현재 문자가 알파벳 대문자 중에서 몇번째 위치에 있는지 파악
                        *  shiftCnt 값을 더하여 문자를 이동시킵니다.
                        * % 26을 통해 26(알파벳의 길이)으로 나눈 나머지를 취합니다. 이는 알파벳의 끝에 도달하면 다시 처음으로 돌아가기 위함.
                        * 마지막으로 'A'를 더하여, 다시 알파벳 대문자의 범위로 되돌아가게 합니다.
                        * 그래서 예를 들어 ch가 "H"라면 H와 A의 거리는 7입니다.(ABCDEFGH)
                        * 거기에 shiftCnt가 3일 경우 3칸 옮긴 K가 됩니다.
                        * 만약 Z 등 거의 끝에서 밀었을 경우에는 범위를 벗어나므로 다시 A부터 시작하게끔 합니다.
                        */
                    }
                    // 소문자인 경우
                    else {
                        ch = 'a' + (ch - 'a' + shiftCnt) % 26; // 밀기 작업 수행하여 소문자를 변환
                    }
                }
        
                encryptText += ch; // 암호화된 문자열에 추가
            }
            
            // 4_5 결과 출력
            cout << "암호화된 결과 ===> " << encryptText << "\n";
            cout << "================================================================================" << "\n";
            cout << "암호화 시킬지 복호화 시킬지 번호를 눌러 결정하시오." << "\n";
            cout << "암호화 == 1, 복호화 == 2, 종료 == 3: ";
            cin >> selectCrypto;
            cout << "================================================================================" << "\n";
        }// 5. if 복호화
        else if(selectCrypto == 2){
            // 5_1. input으로 복호화할 encryptText 받기
            cout << "복호화 시킬 암호문(encryptText)를 입력하세요: ";
            cin.ignore(); // 이전 입력 버퍼 비우기
            getline(cin, encryptText); // 공백 포함하여 한 줄을 입력받음
            //cin >> encryptText;
            
            cout << "================================================================================" << "\n";
            
            // 5_2. input으로 어느 방향으로 밀지 받기
            cout << "어느 방향으로 밀지 번호를 눌러 결정하시오." << "\n";
            cout << "앞 == 1, 뒤 == 2: ";
            cin >> shiftDirection;
            
            cout << "================================================================================" << "\n";
            
            // 입력이 1 또는 2가 아닌 경우 다시 입력 안내
            while (shiftDirection != 1 && shiftDirection != 2) {
                cout << "올바른 번호를 입력하세요." << "\n";
                cout << "앞 == 1, 뒤 == 2: ";
                cin >> shiftDirection;
                cout << "================================================================================" << "\n";
            }
            
            // 5_3. input으로 몇칸으로 밀지 받기
            cout << "몇칸 밀지 번호를 눌러 결정하시오.: ";
            cin >> shiftCnt;
            
            cout << "================================================================================" << "\n";
            
            // 5_4. custom 복호화 시작
            for (int i = 0; i < encryptText.length(); ++i) { // 입력받은 encryptText의 길이를 세서 그만큼 for문 반복
                char ch = encryptText[i]; // 현재 인덱스에 있는 문자를 ch 변수에 저장
                
                // 알파벳인 경우만 밀기 작업 수행
                if (isalpha(ch)) { // ch가 알파벳인 경우
                    // 대문자인 경우
                    if (isupper(ch)) { // 대문자인지 확인
                        ch = 'Z' - ('Z' - ch + shiftCnt) % 26; // 복호화 작업 수행하여 대문자를 변환
                    }
                    // 소문자인 경우
                    else {
                        ch = 'z' - ('z' - ch + shiftCnt) % 26; // 복호화 작업 수행하여 소문자를 변환
                    }
                }
                
                plainText += ch; // 복호화된 문자열에 변환된 문자를 추가
            }
            
            // 5_5. 결과 출력
            cout << "복호화된 결과 ===> " << plainText << "\n";
            cout << "================================================================================" << "\n";
            cout << "암호화 시킬지 복호화 시킬지 번호를 눌러 결정하시오." << "\n";
            cout << "암호화 == 1, 복호화 == 2, 종료 == 3: ";
            cin >> selectCrypto;
            cout << "================================================================================" << "\n";
        }// 6. 종료 입력시
        else if(selectCrypto == 3){
            cout << "프로그램이 종료됩니다. Developed by Seungwoo Choi." << "\n";
            cout << "================================================================================" << "\n";
            break;
        }// 7. 잘못된 값 입력시
        else{
            cout << "값이 올바르지 않습니다. 다시 시도해주세요" << "\n";
            cout << "================================================================================" << "\n";
            cout << "암호화 시킬지 복호화 시킬지 번호를 눌러 결정하시오." << "\n";
            cout << "암호화 == 1, 복호화 == 2, 종료 == 3: ";
            cin >> selectCrypto;
            cout << "================================================================================" << "\n";
        }
    }
}
