// Copyright (c) 2020 CS126SP20. All rights reserved.

#include "ll.h"

#include <cassert>
#include <utility>
#include <vector>

namespace cs126linkedlist {

template <typename ElementType>
LinkedList<ElementType>::LinkedList() {
  start_node_ = nullptr;
  size_ = 0;
}

template <typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType>& values) {
  start_node_ = nullptr;
  for (int i = values.size() - 1; i >= 0; i--) {
    push_front(values.at(i));
  }
  size_ = values.size();
}

// Copy constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {
  start_node_ = nullptr;
  size_ = 0;
  for (const_iterator itr = source.begin(); itr != source.end(); ++itr) {
    push_back(*itr);
  }
}

// Move constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {

}

// Destructor
template <typename ElementType>
LinkedList<ElementType>::~LinkedList() {
  Node* current = start_node_;
  while (current != nullptr) {
    Node* next = current->next_;
    delete current;
    current = next;
  }
}

// Copy assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    const LinkedList<ElementType>& source) {
  if (*this == source) {
    return *this;
  }
  clear();
  for (ElementType element : source) {
    push_back(element);
  }
  return *this;
}

// Move assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    LinkedList<ElementType>&& source) noexcept {
}

template <typename ElementType>
void LinkedList<ElementType>::push_front(const ElementType& value) {
  start_node_ = new Node(value, start_node_);
  size_++;
}

template <typename ElementType>
void LinkedList<ElementType>::push_back(const ElementType& value) {
  if (size_ == 0) {
    start_node_ = new Node(value, start_node_);
  } else {
    Node* next_node = start_node_;
    for (size_t i = 0; i < size_ - 1; i++) {
      next_node = next_node->next_;
    }
    next_node->next_ = new Node(value, next_node->next_);
  }
  size_++;
}

template <typename ElementType>
ElementType LinkedList<ElementType>::front() const {
  if (size_ == 0) {
    throw std::invalid_argument("no elements");
  }
  return start_node_->value_;
}

template <typename ElementType>
ElementType LinkedList<ElementType>::back() const {
  if (size_ == 0) {
    throw std::invalid_argument("no elements");
  }
  Node* last_node = start_node_;
  for (size_t i = 0; i < size_ - 1; i++) {
    last_node = last_node->next_;
  }
  return last_node->value_;
}

template <typename ElementType>
void LinkedList<ElementType>::pop_front() {
  if (size_ == 0) {
    return;
  }
  Node* current_start = start_node_;
  start_node_ = start_node_->next_;
  delete current_start;
  size_--;
}

template <typename ElementType>
void LinkedList<ElementType>::pop_back() {
  if (size_ == 0) {
    return;
  }
  Node* second_to_last = start_node_;
  for (size_t i = 0; i < size_ - 2; i++) {
    second_to_last = second_to_last->next_;
  }
  Node* last_node = second_to_last->next_;
  second_to_last->next_ = second_to_last->next_->next_;
  delete last_node;
  size_--;
}

template <typename ElementType>
size_t LinkedList<ElementType>::size() const {
  return size_;
}

template <typename ElementType>
bool LinkedList<ElementType>::empty() const {
  if (size_ == 0) {
    return true;
  }
  return false;
}

template <typename ElementType>
void LinkedList<ElementType>::clear() {
  if (size_ == 0) {
    return;
  }
  Node* current = start_node_;
  while (current != nullptr) {
    Node* next = current->next_;
    delete current;
    current = next;
  }
  start_node_ = nullptr;
  size_ = 0;
}

template <typename ElementType>
std::ostream& operator<<(std::ostream& os,
                         const LinkedList<ElementType>& list) {
  //TODO finish implementing
  return os;
}

template <typename ElementType>
void LinkedList<ElementType>::RemoveNth(size_t n) {
  if (n == 0) {
    pop_front();
    return;
  }
  Node* previous_node = start_node_;
  for (size_t i = 0; i < n - 1; i++) {
    previous_node = previous_node->next_;
  }

  Node* del_node = previous_node->next_;
  previous_node->next_ = previous_node->next_->next_;
  delete del_node;
  size_--;
}

template <typename ElementType>
void LinkedList<ElementType>::RemoveOdd() {
  //TODO probably need to make a copy
  if (size_ == 0) {
    return;
  }
  size_t previous_size = size_;
  for (size_t i = 0; i < previous_size; i++) {
  }
}

template <typename ElementType>
bool LinkedList<ElementType>::operator==(
    const LinkedList<ElementType>& rhs) const {
  if (size_ != rhs.size()) {
    return false;
  }
  for (const_iterator itr1 = begin(), itr2 = rhs.begin();
       itr1 != end() && itr2 != rhs.end(); ++itr1, ++itr2) {
    if (*itr1 != *itr2) {
      return false;
    }
  }
  return true;
}

template <typename ElementType>
bool LinkedList<ElementType>::operator!=(
    const LinkedList<ElementType>& rhs) const {
  if (size_ != rhs.size()) {
    return true;
  }

  for (const_iterator itr1 = begin(), itr2 = rhs.begin();
       itr1 != end() && itr2 != rhs.end(); ++itr1, ++itr2) {
    if (*itr1 != *itr2) {
      return true;
    }
  }
  return false;
}

template <typename ElementType>
typename LinkedList<ElementType>::iterator& LinkedList<ElementType>::iterator::
operator++() {
  current_ = current_->next_;
  return *this;
}

template <typename ElementType>
ElementType& LinkedList<ElementType>::iterator::operator*() const {
  return this->current_->value_;
}

template <typename ElementType>
bool LinkedList<ElementType>::iterator::operator!=(
    const typename LinkedList<ElementType>::iterator& other) const {
  return current_ != other.current_;
}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {
  return iterator(start_node_);
}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {
  return nullptr;
}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator&
LinkedList<ElementType>::const_iterator::operator++() {
  current_ = current_->next_;
  return *this;
}

template <typename ElementType>
const ElementType& LinkedList<ElementType>::const_iterator::operator*() const {
  return this->current_->value_;
}

template <typename ElementType>
bool LinkedList<ElementType>::const_iterator::operator!=(
    const typename LinkedList<ElementType>::const_iterator& other) const {
  return current_ != other.current_;
}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator
LinkedList<ElementType>::begin() const {
  return const_iterator(start_node_);
}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end()
    const {
  return nullptr;
}

}  // namespace cs126linkedlist
