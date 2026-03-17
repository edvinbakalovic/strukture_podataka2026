#pragma once
#include <iostream>
#include <vector>

class Student{
  private:
    std::string ime_;
    std::string prezime_;
    int exam1_,exam2_,exam3_,exam4_,exam5_;

  public:
  Student(std::string ime, std::string prezime, int exam1, int exam2, int exam3, int exam4, int exam5){
  ime_=ime;
  prezime_=prezime;
  exam1_=exam1;
  exam2_=exam2;
  exam3_=exam3;
  exam4_=exam4;
  exam5_=exam5;
  } 
    
  double score() const;
  int failedExams() const;
  std::string finalGrade() const;
  
  friend std::ostream& operator<<(std::ostream&,const Student&);

  const std::string& ime() const {return ime_;}
  const std::string& prezime() const {return prezime_;}
  int exam1() const {return exam1_;}
  int exam2() const {return exam2_;}
  int exam3() const {return exam3_;}
  int exam4() const {return exam4_;}
  int exam5() const {return exam5_;}

  void ime(const std::string& ime){ime_=ime;}
  void prezime(const std::string& prezime){prezime_=prezime;}
  void exam1(int exam1){exam1_=exam1;}
  void exam2(int exam2){exam2_=exam2;}
  void exam3(int exam3){exam3_=exam3;}
  void exam4(int exam4){exam4_=exam4;}
  void exam5(int exam5){exam5_=exam5;}
};

