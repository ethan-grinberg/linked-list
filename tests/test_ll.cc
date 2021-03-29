// Copyright (c) 2020 [Your Name]. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cs126linkedlist/ll.h>


using cs126linkedlist::LinkedList;

// Read more on SECTIONs here:
// `https://github.com/catchorg/Catch2/tree/master/docs`
// in the "Test Cases and Sections" file.
TEST_CASE("Push Back", "[constructor][push_back][size][empty]") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("Push back one element") {
    list.push_back(1);
    REQUIRE(list.size() == 1);
  }

  SECTION("Push back two elements") {
    list.push_back(-1);
    list.push_back(10000);
    REQUIRE(list.size() == 2);
  }
}

TEST_CASE("Empty, size, front, and back") {
  SECTION("empty") {
    LinkedList<int> list;
    REQUIRE(list.empty());
  }
  SECTION("size") {
    std::vector<int> vector(5,6);
    LinkedList<int> list(vector);
    REQUIRE(list.size() == 5);
  }
  SECTION("size") {
    std::vector<int> vector = {1,2,3,4};
    LinkedList<int> list(vector);
    REQUIRE(list.back() == 4);
  }
}

TEST_CASE("Insertions") {
  SECTION("push_front") {
    LinkedList<int> list;
    list.push_front(5);
    REQUIRE(list.front() == 5);
  }
}

TEST_CASE("Big Five") {
  SECTION ("Copy constructor") {

  }
  SECTION ("Move constructor") {

  }

  SECTION("Copy assignment operator") {

  }

  SECTION("Move assignment operator") {

  }
}
