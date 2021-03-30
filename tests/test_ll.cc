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
    REQUIRE(list.back() == 10000);
  }
}

TEST_CASE("Empty, size, and back") {
  SECTION("empty") {
    LinkedList<int> list;
    REQUIRE(list.empty());
  }
  SECTION("size") {
    std::vector<int> vector(5,6);
    LinkedList<int> list(vector);
    REQUIRE(list.size() == 5);
  }
  SECTION("back") {
    std::vector<int> vector = {1,2,3,4};
    LinkedList<int> list(vector);
    REQUIRE(list.back() == 4);
  }
}

TEST_CASE("push_front") {
  SECTION("front()") {
    LinkedList<int> list;
    list.push_front(5);
    REQUIRE(list.front() == 5);
    REQUIRE(list.size() == 1);
  }
}

TEST_CASE("Big Five") {
  SECTION ("Copy constructor") {
    std::vector<int> vector(5,6);
    LinkedList<int> list(vector);
    REQUIRE(list.size() == 5);

    LinkedList<int> new_list(list);
    REQUIRE(new_list.size() == 5);

    for (LinkedList<int>::iterator itr = list.begin(); itr != list.end();
         ++itr) {
      REQUIRE(*itr == 6);
    }

  }
  SECTION ("Move constructor") {

  }

  SECTION("Copy assignment operator") {

  }

  SECTION("Move assignment operator") {

  }
}

TEST_CASE("Iterators") {
  SECTION("Non-const iterator") {
    std::vector<int> vector(4, 7);
    LinkedList<int> list(vector);
    for (LinkedList<int>::iterator itr = list.begin(); itr != list.end();
         ++itr) {
      REQUIRE(*itr == 7);
    }
  }
  SECTION("const iterator") {
    std::vector<int> vector(4, 7);
    const LinkedList<int> list(vector);
    for (LinkedList<int>::const_iterator itr = list.begin(); itr != list.end();
         ++itr) {
      REQUIRE(*itr == 7);
    }
  }
}

TEST_CASE("Equality") {
  SECTION("==") {
    std::vector<int> vector1 = {1,2,3,4};
    LinkedList<int> list1(vector1);
    std::vector<int> vector2 = {1,2,3,4};
    LinkedList<int> list2(vector2);
    REQUIRE(list1 == list2);
  }
  SECTION("!=") {
    std::vector<int> vector1 = {1,2,3,4};
    LinkedList<int> list1(vector1);
    std::vector<int> vector2 = {1,2,3,6};
    LinkedList<int> list2(vector2);
    REQUIRE(list1 != list2);
  }
  SECTION("Different size") {
    std::vector<int> vector1 = {1,2,3,4};
    LinkedList<int> list1(vector1);
    std::vector<int> vector2 = {1,2,3,4,5};
    LinkedList<int> list2(vector2);
    REQUIRE(list1 != list2);
  }
}

TEST_CASE("Clear") {
  std::vector<int> vector(4, 7);
  LinkedList<int> list(vector);
  list.clear();
  REQUIRE(list.size() == 0);
  list.push_back(10);
  list.push_front((5));
  REQUIRE(list.back() == 10);
  REQUIRE(list.front() == 5);
  REQUIRE(list.size() == 2);
}

TEST_CASE("Remove functions") {
  SECTION("pop_front") {
    std::vector<int> vector = {5, 6, 7, 8};
    LinkedList<int> list(vector);
    REQUIRE(list.size() == 4);
    REQUIRE(list.front() == 5);
    list.pop_front();
    REQUIRE(list.size() == 3);
    REQUIRE(list.front() == 6);
  }
  SECTION("pop_back") {
    std::vector<int> vector = {5, 6, 7, 8};
    LinkedList<int> list(vector);
    REQUIRE(list.size() == 4);
    REQUIRE(list.back() == 8);
    list.pop_back();
    REQUIRE(list.size() == 3);
    REQUIRE(list.back() == 7);
  }
  SECTION("remove n") {
    std::vector<int> vector = {5, 5, 7, 5};
    LinkedList<int> list(vector);
    REQUIRE(list.size() == 4);

    list.RemoveNth(2);
    REQUIRE(list.size() == 3);
    for (LinkedList<int>::iterator itr = list.begin(); itr != list.end();
         ++itr) {
      REQUIRE(*itr == 5);
    }
  }
  SECTION("remove odd") {
    std::vector<int> vector = {5, 9, 5, 7};
    LinkedList<int> list(vector);
    REQUIRE(list.size() == 4);

    list.RemoveOdd();
    REQUIRE(list.size() == 2);
    for (LinkedList<int>::iterator itr = list.begin(); itr != list.end();
         ++itr) {
      REQUIRE(*itr == 5);
    }
  }
}
