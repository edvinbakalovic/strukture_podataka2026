#include <iostream>
#include "student.hpp"
#include <vector>
#include <fstream>
#include <algorithm>

std::vector<std::string> split(const std::string& temp, char delimiter){
  std::vector<std::string> rez;
  std::string trenutnaRijec;
  for(auto c:temp){
    if(c==delimiter){
        rez.push_back(trenutnaRijec);
        trenutnaRijec="";
    }
    else
      trenutnaRijec+=c;
  }
  rez.push_back(trenutnaRijec);
  return rez;
}

int main(){
  //Ucitati studente iz student.csv fajla
  std::ifstream in{"students.csv"};
  if (!in)
    return 0;

  std::vector<Student> studenti;
  std::string temp;
  std::getline(in,temp); // header linija

  while (getline(in,temp)) {
    auto vrijednost=split(temp,',');
    //std::cout<<vrijednost.size()<<std::endl;
    Student s(vrijednost[0],vrijednost[1],std::stoi(vrijednost[2]),std::stoi(vrijednost[3]),std::stoi(vrijednost[4]),std::stoi(vrijednost[5]),std::stoi(vrijednost[6]));
    studenti.push_back(s);
  }
  in.close();

  std::sort(studenti.begin(),studenti.end(),[](const Student& a, const Student& b){
        return a.score()>b.score();
      });

  //Ispis ocjena u ocjene.csv
  std::ofstream output{"ocjene.csv"};
  if (output) {
    output<<"First Name,Last Name,Exam1,Exam2,Exam3,Exam4,Exam5"<<std::endl;
    for(const auto& it:studenti){
      output<<it.ime()<<","<<it.prezime()<<","<<it.finalGrade()<<std::endl;
    }
  }
  output.close();
  
  for(auto& it : studenti){
    std::cout<<it<<std::endl;
  }
  
  return 0;
}
