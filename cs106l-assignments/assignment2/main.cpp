/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <random>
#include <sstream>

std::string kYourName = "Jerry Xing"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  std::ifstream ifs(filename);
  std::set<std::string> nameset;
  if (ifs.is_open()){
    std::string name;
    while(std::getline(ifs,name)){
      nameset.insert(name);
    }
  }
  return nameset;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */

std::string initials(std::string name){
  std::stringstream ss(name);
  std::string first;
  std::string last;
  ss >> first >> last;
  std::string initial;
  initial += first[0];
  initial += ',';
  initial += last[0];
  return initial;
}

std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  std::string name_i;
  name_i = initials(name);
  std::queue<const std::string*> stu_que;
  std::string student_i;
  for(const auto& stu:students){
    student_i = initials(stu);
    if(student_i == name_i){
      stu_que.push(&stu);
    }
  }
  return stu_que;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  std::string theone;
  if (matches.empty()) {
        theone = "NO MATCHES FOUND.";
        return theone;
    }

    int n = matches.size();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, n - 1);

    int k = dist(gen);

    for (int i = 0; i < k; i++) {
        matches.pop();
    }

    theone = *matches.front();
    return theone;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
