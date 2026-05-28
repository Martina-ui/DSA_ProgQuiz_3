#include <catch2/catch_test_macros.hpp>

#include <vector>

#include "interquartile_range.h"
using namespace std;

TEST_CASE("Test 1: Small Even List", "[iqr]") {
	vector<int> v = {1, 4, 7, 10};
	Node* head = nullptr;
	for (int i : v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 6.0f);

	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

TEST_CASE("Test 2: Odd Length List", "[iqr]") {
	vector<int> v = {1, 2, 10, 20, 40};
	Node* head = nullptr;
	for (int i : v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 28.5f);

	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

TEST_CASE("Test 3: Equal Values", "[iqr]") {
	vector<int> v = {5, 5, 5, 5, 5, 5};
	Node* head = nullptr;
	for (int i : v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 0.0f);

	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

TEST_CASE("Test 4: Negative Values", "[iqr]") {
	vector<int> v = {-10, -5, 0, 5, 10, 15, 20, 25};
	Node* head = nullptr;
	for (int i : v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 20.0f);

	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

TEST_CASE("Test 5: Duplicate Blocks", "[iqr]") {
	vector<int> v = {1, 1, 1, 1, 10, 10, 10, 10};
	Node* head = nullptr;
	for (int i : v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 9.0f);

	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}
