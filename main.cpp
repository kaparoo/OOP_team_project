#include <iostream>
#include <map>
#include <vector>
#include <string>

// //#include "cafeteria.h"
// #include "csv_reader.h"
// #include "food.h"
// #include "menu.h"
// #include "user.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

using namespace std;

// void signin();
// void signup();
// bool check(string);

// void startConsole();
// void nonmemberConsole();
// void memberConsole();
// void finishConsole();

// User currentUser; //use in memberConsole

// void recommendMenu();
// void searchMenu(); // get menu which the user want to see
// //system("cls"):콘솔화면 전부 지워줌.
// //system("clear"):linux 버전

// askOption함수의 예시를 위한 test코드들 (main함수에서 관련 부분 주석을 같이 지워야 사용가능)
void test1() {
    std::cout << "test1 함수를 선택하셨습니다." << std::endl;
}

void test2() {
    std::cout << "test2 함수를 선택하셨습니다." << std::endl;
    std::string text;
    std::cout << "텍스트를 입력하세요.(함수자체는 인자가 없어야 하지만 내부에서 입력받는건 상관없음을 보여주는 예제): ";
    std::cin >> text;
    std::cout << text;
}

// prompt: 화면에 출력될 메세지들(한줄씩 출력함), actions[i]: i번째 선택지에 맞는 함수(포인터)
// 함수(포인터): 인자와 반환값이 없는 미리 설정한 동작을 실행만 하는 함수에 대한 포인터, 함수내에서 cin이나 파일 입출력등을 하는것은 상관없음
void askOption(std::vector<std::string> prompt, map<int, void (*)()> actions) {
    void (*action)();
    while(1){ // 유효한 항목을 입력할 때까지 무한루프
        
        // 화면에 출력될 텍스트들을 출력
        for(const string& line : prompt) { 
            std::cout << line << std::endl;
        }

        // 사용자로 부터 선택지를 입력받음
        int option;
        std::cout << "원하시는 항목의 번호을 입력하세요.: ";
        std::cin >> option;
        
        // 사용자가 int형식으로 선택지를 입력했다고 가정하고(=type error가 없다고 가정) <-- 기본적인 프로그램을 완성하면 예외처리로 동작하도록 고려해봅시다 
        if(actions.find(option) == actions.end()) { // 유효하지 않은 선택
            /* 화면 초기화 처리
             * 운영체제(주로 Windows vs. Linux)에 따라 화면을 초기화(=빈화면으로 만드는)하는 방법이 다름
             * 프로그램이 돌아가는 운영체제를 찾는 방법을 모르기 때문에 일단 두 함수를 모두 실행하고
             * 예외 처리를 하거나 아니면 Windows에서만 실행된다고 가정하고 프로그램을 짜는 게 좋을 듯
            */
            
            // 경고 메세지 (좀 이상한것 같으면 고쳐도 됨)
            std::cout << "유효하지 않은 선택입니다!" << std::endl;
            std::cout << "화면에 나온 번호 중에 골라주세요!" << std::endl;

            continue;
        } else { // 유효한 선택
            action = actions[option]; // 선택에 맞는 함수를 찾음
            break; // 유효한 선택을 했으므로 선택지를 묻는 무한루프에서 나감
        }
    }
    action(); // 선택에 맞는 함수 실행
}

// map<int, User> userMap=updateUser();
// //map<string,Cafeteria> cafeteriaMap=updateCafeteria();

int main(int argc, char** argv) {
  cout<<"Welcome"<<endl;
  // startConsole();
  
  // 여기서부터 askOption함수 예제 (변수 이름은 중요하지 않음)
  std::vector<std::string> prompt = {"askOption 예제입니다.", "[1] test1함수", "[2] test2함수"};
  map<int, void(*)()> actions;
  actions.insert(make_pair(1, test1)); // 단, prompt에서 1번을 test1함수, 2번을 test2함수로 설정했으므로
  actions.insert(make_pair(2, test2)); // map에 함수를 insert할 때 순서를 반드시 지켜야 함
  askOption(prompt, actions);
  // 여기까지 askOption함수 예제 
  
  return 0;
}

// // 첫시작 콘솔
// void startConsole(){
//   map<int, void (*)()> startFunctionMap;
//   startFunctionMap.insert(make_pair(1, memberConsole));
//   startFunctionMap.insert(make_pair(2, nonmemberConsole));
//   startFunctionMap.insert(make_pair(3, signup));
//   startFunctionMap.insert(make_pair(4, finishConsole));
//   vector<string> prompt = {"None", "[1] 로그인", "[2] 메뉴검색", "[3] 회원가입","[4] 종료"};
//   askOption(prompt, startFunctionMap);
// }

// //비회원용 콘솔
// void nonmemberConsole(){
//   map<int, void (*)()> nonmemberFunctionMap;
//   vector<string> prompt = {"[0] 돌아가기", "[1] 메뉴검색", "[2] 종료"};
//   nonmemberFunctionMap.insert(make_pair(1, searchMenu));
//   nonmemberFunctionMap.insert(make_pair(2, finishConsole));
//   nonmemberFunctionMap.insert(make_pair(0, startConsole)); //back
//   askOption(prompt, nonmemberFunctionMap);
// }

// //회원용 콘솔
// void memberConsole(){
//   map<int, void (*)()> memberFunctionMap;
//   vector<string> prompt = {"[0] 돌아가기", "[1] 메뉴추천", "[2] 메뉴검색", "[3] 종료"};
//   memberFunctionMap.insert(make_pair(1, recommendMenu));
//   memberFunctionMap.insert(make_pair(2, searchMenu));
//   memberFunctionMap.insert(make_pair(3, finishConsole));
//   memberFunctionMap.insert(make_pair(0, startConsole)); //back
//   askOption(prompt, memberFunctionMap);
// }

// //종료
// void finishConsole(){
//   storeUser(userMap); // user 정보 저장
//   exit(0); //콘솔 종료
// }

// void signin() { //로그인
//   unsigned int id;
//   string password;
//   cout << "ID:";
//   cin >> id;
//   cout << '\n' << "Password:";
//   cin >> password;
//   if(userMap[id].checkId(password)){
//     currentUser=userMap[id];
//     memberConsole();
//   }
// }
// void signup() { //회원가입
//   unsigned int id;
//   string password;
//   cout << "ID:";
//   cin >> id;
//   cout << '\n' << "Password:";
//   cin >> password;
//   userMap.insert(make_pair(id,User(id,password)));
// }


// void recommendMenu(){ //메뉴추천
//   //날짜 입력
//   string date;
//   cout<<"날짜를 입력하세요.";
//   cout<<"ex) 20201108\n";
//   cin>>date;
//   while(check(date)==false){
//     cout<<"입력하신 정보는 없습니다.\n";
//     cout<<"날짜를 입력하세요.\n";
//     cin>>date;
//   }
//   //시간대 입력
//   int time;
//   cout<<"\n[1] 점심 [2] 저녁";
//   cin>>time;
//   while(time!=1 && time!=2){
//     cout<<"\n잘못된 입력입니다.\n 다시 입력하세요:";
//     cin>>time;
//   }
//   //유저 칼로리 정보 확인
//   if(currentUser.getCal());
//   else{
//     //칼로리 정보 입력유무
//     int update;
//     cout<<"칼로리 정보를 입력하시겠습니까?";
//     cout<<"\n[1] 네 [2] 아니오";
//     cin>>update;
//     if(update==1){
//       //이전 칼로리 입력
//       int lastCal;
//       cout<<"\n이전에 얼마나 드셨나요? ";
//       cin>>lastCal;
//       while(lastCal<0){
//         cout<<"\n잘못된 입력입니다.\n 다시 입력하세요:";
//         cin>>lastCal;
//       }
//       currentUser.setCal(lastCal);
//     }
//   }
  
  
//   //메뉴가져오기
//   // for(auto cafeteria:cafeteriaMap){
//   //   cout<<cafeteria.first<<endl;
//   //   for(auto menulist:cafeteria.second.getMenutable(date,time,currentUser.getCal())){
//   //     cout<<menulist.first<<endl;
//   //     for(auto food:menulist.second.getFoodlist()){
//   //       cout<<food<<endl;
//   //     }
//   //   }
//   // }
// }

// void searchMenu(){ //메뉴출력
//   string day;
//   cout<<"Input the day on which you want to see the menu.\n";
//   cout<<"ex) Mon, Tue, Wed, Thur, Fri\n";
//   cin>>day;
//   //날짜 입력
//   string date;
//   cout<<"날짜를 입력하세요.";
//   cout<<"ex) 20201108\n";
//   cin>>date;
//   while(check(date)==false){
//     cout<<"입력하신 정보는 없습니다.\n";
//     cout<<"날짜를 입력하세요.\n";
//     cin>>date;
//   }
//   //시간대 입력
//   int time;
//   cout<<"\n[1] 점심 [2] 저녁";
//   cin>>time;
//   while(time!=1 && time!=2){
//     cout<<"\n잘못된 입력입니다.\n 다시 입력하세요:";
//     cin>>time;
//   }
//   // 메뉴 출력
//   // for(auto cafeteria:cafeteriaMap){
//   //   cout<<cafeteria.first<<endl; // 식당이름
//   //   for(auto menulist:cafeteria.second.getMenutable(day)){
//   //     cout<<menulist.first<<endl; // 메뉴 이름
//   //     for(auto menu:menulist.second){
//   //       cout<<menu<<endl; //음식 이름
//   //     }
//   //   }
//   // }
// }

// bool check(string s) {
//    string s1 = s.substr(0, 6);
//    int s2 = stoi(s.substr(6, 2));
//    if (s.length() != 8)
//       return false;
//    else if (s1 != "202011")
//       return false;
//    else if ((9 <= s2 && s2 <= 13) || (16 <= s2 && s2 <= 20))
//       return true;
//    else
//       return false;
// }

// /*console 작업중 (goto문 if,while문으로 수정예정)
// void console(){
//   map<int, User> userMap=updateUser();
//   map<string, Food> foodMap=updateFood();
//   //map<string, Cafeteria> cafeteriaMap=updateCafeteria();
//   cout<<"Welcome:)"<<endl;
//   while(1){
//     cout<<"Select the number."<<endl;
//     cout<<"1. Sign in 2. Non-member 3. Sign up"<<endl;
//     int i;
//     cin>> i;
//     switch(i){
//     case 1:
//       return signIn();
//       signIn();
//       //메뉴 추천, 식단 보기 중에 선택
      
//       goto Member;
//       break;
//     case 2:
//       //식단보기
//       goto NonMember;
//       break;
//     case 3:
//       unsigned int ID;
//       string password;
//       cout << "ID:";
//       cin >> ID;
//       cout << '\n' << "Password:";
//       cin >> password;
//       userMap.insert(make_pair(ID, User(ID, password)))
//       goto First;
//       break;
//     default:
//       cout<<"Try again!";
//       goto First;
//     }
//   }
  
//   First:
//   cout<<"Select the number."<<endl;
//   cout<<"1. Sign in 2. Non-member 3. Sign up"<<endl;
//   int i;
//   cin>> i;
//   switch(i){
// 	case 1:
// 	  signIn();
// 	  //메뉴 추천, 식단 보기 중에 선택
// 	  goto Member;
// 	  break;
// 	case 2:
// 	  //식단보기
// 	  goto NonMember;
// 	  break;
// 	case 3:
// 	  signUp();
// 	  goto First;
// 	  break;
// 	default:
// 	  cout<<"Try again!";
// 	  goto First;
//   }
//   Member:
//   cout<<"Select the number."<<endl;
//   cout<<"1. Menu Recommendation 2. See Menu"<<endl;
//   cin>>i;
//   switch(i){
// 	case 1:
// 	  recommendMenu();
// 	  break;
// 	case 2:
// 	  break;
// 	default:
// 	  cout<<"Try again!";
// 	  goto Member;
//   }
//   NonMember:
//   cout<<"Input the date. ex)20191106"<<endl;
//   unsigned int date;
//   cin>>date;
//   //날짜에 해당하는 식단이 있을경우
//   printMenu();
//   //없을 경우
//   cout<<"Try again!";
//   goto NonMember;
// }
// */