#include <iostream>
#include <map>
#include <vector>
#include <string>

// //#include "cafeteria.h"
// #include "csv_reader.h"
// #include "food.h"
// #include "menu.h"
#include "user.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

using namespace std;

void startConsole();
void memberConsole();
void nonmemberConsole();
void finishConsole();

void signin();
void signup();
void searchMenu();
bool check(string);
void recommendMenu();

void askOption(std::vector<std::string> prompt, map<int, void (*)()> actions) {
    void (*action)();
    while (1) { //종료시까지 실행
        cout << "Menu Recommendation Service For DGIST members"<<endl;
        // 화면에 출력될 텍스트들을 출력
        for (const string& line : prompt) {
            std::cout << line << std::endl;
        }

        // 사용자로 부터 선택지를 입력받음
        int option;
        std::cout << "원하시는 항목의 번호을 입력하세요.: ";
        std::cin >> option;

        // 사용자가 int형식으로 선택지를 입력했다고 가정하고(=type error가 없다고 가정) <-- 기본적인 프로그램을 완성하면 예외처리로 동작하도록 고려해봅시다 
        if (actions.find(option) == actions.end()) { // 유효하지 않은 선택
            /* 화면 초기화 처리
             * 운영체제(주로 Windows vs. Linux)에 따라 화면을 초기화(=빈화면으로 만드는)하는 방법이 다름
             * 프로그램이 돌아가는 운영체제를 찾는 방법을 모르기 때문에 일단 두 함수를 모두 실행하고
             * 예외 처리를 하거나 아니면 Windows에서만 실행된다고 가정하고 프로그램을 짜는 게 좋을 듯
            */

            // 경고 메세지 (좀 이상한것 같으면 고쳐도 됨)
            std::cout << "유효하지 않은 선택입니다!" << std::endl;
            std::cout << "화면에 나온 번호 중에 골라주세요!" << std::endl;

            continue;
        }
        else { // 유효한 선택
            action = actions[option]; // 선택에 맞는 함수를 찾음   
            action();
            cout << "아무 문자를 입력하면 전으로 돌아갑니다." << endl;
            string any;
            cin >> any;
        }
        system("cls");
    }
    action(); // 선택에 맞는 함수 실행
}

map<int, User> userMap = updateUser();;

User currentUser; //use in memberConsole

int main(int argc, char** argv) {
    cout << "Welcome" << endl;
    startConsole();

    return 0;
}

// 첫시작 콘솔
void startConsole(){
    system("cls");
    cout << "This is the first page" << endl;
  map<int, void (*)()> startFunctionMap;
  startFunctionMap.insert(make_pair(1, signin));
  startFunctionMap.insert(make_pair(2, nonmemberConsole));
  startFunctionMap.insert(make_pair(3, signup));
  startFunctionMap.insert(make_pair(4, finishConsole));
  std::vector<std::string> prompt = {"", "[1] Sign in", "[2] Search Menu", "[3] Sign up","[4] Exit"};
  askOption(prompt, startFunctionMap);
}

//회원용 콘솔
void memberConsole(){
  system("cls");
  cout << "This is for the member" << endl;
  cout << "User: " << currentUser.getId() << endl;
  map<int, void (*)()> memberFunctionMap;
  vector<string> prompt = {"[0] Back", "[1] Recommend Menu", "[2] Search Menu", "[3] Exit"};
  memberFunctionMap.insert(make_pair(1, recommendMenu));
  memberFunctionMap.insert(make_pair(2, searchMenu));
  memberFunctionMap.insert(make_pair(3, finishConsole));
  memberFunctionMap.insert(make_pair(0, startConsole)); //back
  askOption(prompt, memberFunctionMap);
}

//비회원용 콘솔
void nonmemberConsole() {
    system("cls");
    cout << "This is for the non-member" << endl;
    cout << "If you are a DGIST member, back to the page and log in." << endl;
    map<int, void (*)()> nonmemberFunctionMap;
    vector<string> prompt = { "[0] Back", "[1] Search Menu", "[2] Exit" };
    nonmemberFunctionMap.insert(make_pair(1, searchMenu));
    nonmemberFunctionMap.insert(make_pair(2, finishConsole));
    nonmemberFunctionMap.insert(make_pair(0, startConsole)); //back
    askOption(prompt, nonmemberFunctionMap);
}

void signin() { //로그인
    unsigned int ID;
    string password;
    cout << "ID:";
    cin >> ID;
    cout << '\n' << "Password:";
    cin >> password;
    if (userMap[ID].checkId(password)) {
        currentUser = userMap[ID];
        memberConsole();
    }
    else {
        cout << "It's wrong" << endl;
        cout << "아무 문자나 입력시 이전으로 돌아갑니다." << endl;
        startConsole();
    }
}

void signup() { //회원가입
  unsigned int newID;
  string password;
  cout << "ID:";
  cin >> newID;
  cout << '\n' << "Password:";
  cin >> password;
  userMap.insert(make_pair(newID,User(newID,password)));
}

void recommendMenu() { //메뉴추천
  //날짜 입력
  string date;
  cout<<"Input the date."<<"ex) 20201108"<<endl;
  cin>>date;
  while(check(date)==false){
    cout<<"No information for the date" << endl;
    cout<<"Input the date again." << endl;
    cin>>date;
  }
  //시간대 입력
  int time;
  cout<<"[1] Lunch [2] Dinner" << endl;
  cin>>time;
  while(time!=1 && time!=2){
    cout<<"It's the wrong input. Input again: " << endl;
    cin>>time;
  }
  //유저 칼로리 정보 확인
  if (currentUser.getCal() == 0) {
      //이전 칼로리 입력
      int lastCal;
      cout << "How many calories did you eat before?" << endl;
      cin >> lastCal;
      while (lastCal < 0) {
          cout << "It's the wrong input. Input again: " << endl;
          cin >> lastCal;
      }
  }  
  else{
    //칼로리 정보 입력유무
    int update;
    cout<<"Do you want to revise last eaten menu's calories?"<<endl;
    cout<<"[1] Yes [2] No"<<endl;
    cin>>update;
    if(update==1){
      //이전 칼로리 입력
      int lastCal;
      cout<<"How many calories did you eat before?";
      cin>>lastCal;
      while(lastCal<0){
        cout<<"It's the wrong input. Input again: ";
        cin>>lastCal;
      }
      currentUser.setCal(lastCal);
    }
  }
  cout << "menu recommend" << endl;
  
  //메뉴가져오기
  // for(auto cafeteria:cafeteriaMap){
  //   cout<<cafeteria.first<<endl;
  //   for(auto menulist:cafeteria.second.getMenutable(date,time,currentUser.getCal())){
  //     cout<<menulist.first<<endl;
  //     for(auto food:menulist.second.getFoodlist()){
  //       cout<<food<<endl;
  //     }
  //   }
  // }
}

void searchMenu() { //메뉴출력
//날짜 입력
    string date;
    cout << "Input the date." << "ex) 20201108" << endl;
    cin >> date;
    while (check(date) == false) {
        cout << "No information for the date" << endl;
        cout << "Input the date again." << endl;
        cin >> date;
    }
    //시간대 입력
    int time;
    cout << "[1] Lunch [2] Dinner" << endl;
    cin >> time;
    while (time != 1 && time != 2) {
        cout << "It's the wrong input. Input again: " << endl;
        cin >> time;
    }
    cout << "search menu" << endl;
// 메뉴 출력
// for(auto cafeteria:cafeteriaMap){
//   cout<<cafeteria.first<<endl; // 식당이름
//   for(auto menulist:cafeteria.second.getMenutable(day)){
//     cout<<menulist.first<<endl; // 메뉴 이름
//     for(auto menu:menulist.second){
//       cout<<menu<<endl; //음식 이름
//     }
//   }
// }
}

//종료
void finishConsole(){
  storeUser(userMap); // user 정보 저장
  exit(0); //콘솔 종료
}

//날짜 확인
bool check(string s) {
   string s1 = s.substr(0, 6);
   int s2 = stoi(s.substr(6, 2));
   if (s.length() != 8)
      return false;
   else if (s1 != "202011")
      return false;
   else if ((9 <= s2 && s2 <= 13) || (16 <= s2 && s2 <= 20))
      return true;
   else
      return false;
}