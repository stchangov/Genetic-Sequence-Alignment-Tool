//  Copyright 2024 Stephan Tchangov
#pragma once

#include <string>
#include <vector>

class EDistance {
 public:
  EDistance(const std::string& s1, const std::string& s2);

  static int penalty(char a, char b);
  static int min3(int a, int b, int c);

  int optDistance();
  std::string alignment();

 private:
  std::string _sequence1;
  std::string _sequence2;
  std::vector<std::vector<int>> _dp;
};
