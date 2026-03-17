#include <iostream>
#include <string>
#include "student.hpp"

std::ostream& operator<<(std::ostream& out,const Student& student){
  return out<<student.ime_<<","<<student.prezime_<<","<<student.exam1_<<","<<student.exam2_<<","<<
    student.exam3_<<","<<student.exam4_<<","<<student.exam5_;
}

double Student::score() const {
  double ukupno=0.0;
  ukupno=exam1_*0.2 + exam2_*0.1 + exam3_*0.25 + exam4_*0.25 + exam5_*0.2;
  return ukupno;
}

int Student::failedExams() const {
  int brojac=0;
  if(exam1_<50) brojac++;
  if(exam2_<50) brojac++;
  if(exam3_<50) brojac++;
  if(exam4_<50) brojac++;
  if(exam5_<50) brojac++;

  return brojac;
}

std::string Student::finalGrade() const {
  if(failedExams()>=3)
    return "*";

  double total=score();
  if(total<54)
    return "nije polozio";
  else if(total<=63)
    return "6";

  else if(total<=73)
    return "7";
  
  else if(total<=83)
    return "8";

  else if(total<=93)
    return "9"; 

  else return "10";

}
