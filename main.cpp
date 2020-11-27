#include <iostream>
#include "user.h"
#include "menu.h"
using namespace std;

void updateFood();
void updateUser();
void updateRestaurant();
void setup();
void printMenu();
Menu recommendMenu();

User signUp();

int main(int argc, char** argv) {
  
}

void setup(){
  updateFood();
  updateUser();
  updateRestaurant();
}
void signIn(){}
User signUp(){
  unsigned int ID; string password;
  cout<<"ID:";
  cin>>ID;
  cout<<'\n'<<"Password:";
  cin>>password;
  //return User(ID, password);
  return User();
}
/* console 작업중 (goto문 if,while문으로 수정예정)
  setup();
  cout<<"Welcome:)"<<endl;
  First:
  cout<<"Select the number."<<endl;
  cout<<"1. Sign in 2. Non-member 3. Sign up"<<endl;
  int i;
  cin>> i;
  switch(i){
    case 1:
      signIn();
      //메뉴 추천, 식단 보기 중에 선택
      goto Member;
      break;
    case 2:
      //식단보기
      goto NonMember;
      break;
    case 3:
      signUp();
      goto First;
      break;
    default:
      cout<<"Try again!";
      goto First;
  }
  Member:
  cout<<"Select the number."<<endl;
  cout<<"1. Menu Recommendation 2. See Menu"<<endl;
  cin>>i;
  switch(i){
    case 1:
      recommendMenu();
      break;
    case 2:
      break;
    default:
      cout<<"Try again!";
      goto Member;
  }
  NonMember:
  cout<<"Input the date. ex)20191106"<<endl;
  unsigned int date;
  cin>>date;
  //날짜에 해당하는 식단이 있을경우
  printMenu();
  //없을 경우
  cout<<"Try again!";
  goto NonMember;
*/