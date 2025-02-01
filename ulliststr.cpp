#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

// adds an element to the back of the list
void ULListStr::push_back(const std::string& val){
  // if the list is empty create a new item
  if(empty()){
    head_ = new Item();
    head_->last++;
    head_->val[head_->first] = val;
    tail_ = head_;
  }
  // if there is space in the last item add the value
  else if(ARRSIZE > tail_->last){
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  // create a new item if the current item is tail is full
  else{
    Item *temp = new Item();
    temp->val[temp->first] = val;
    temp->last++;
    temp->prev = tail_;
    tail_->next = temp;
    tail_ = tail_->next;
  }
  size_++;
}

// removes the last element from the list
void ULListStr::pop_back(){

  if(empty()){
    return;
  }
  tail_->last--;
  // if the item becomes empty, delete it
  if(tail_->first == tail_->last){
    Item *temp = tail_;
    tail_ = tail_->prev;
    if(tail_ != nullptr){
      tail_->next = nullptr;
    }
    else{
      // list is empty
      head_ = nullptr;
    }
    delete temp;
  }
  size_--;
}

// adds an element to the front of the list
void ULListStr::push_front(const std::string& val){
  // create a new item if the list is empty
  if(empty()){
    head_ = new Item();
    head_->last++;
    head_->val[head_->first] = val;
    tail_ = head_;
  }
  // if there is space at the front of the first item add the value
  else if(head_->first > 0){
    head_->first--;
    head_->val[head_->first] = val;
  }
  // create a new item is the first item is full
  else{
    Item *temp = new Item();
    temp->val[ARRSIZE - 1] = val;
    temp->last = ARRSIZE;
    temp->first = ARRSIZE - 1;
    temp->prev = nullptr;
    temp->next = head_;
    head_->prev = temp;
    head_ = temp;
  }
  size_++;
}

// removes the first item from the list
void ULListStr::pop_front(){

  if(empty()){
    return;
  }

  head_->first++;
  // if the item becomes empty, delete it
  if(head_->first == head_->last){
    Item *temp = head_;
    head_ = head_->next;
    delete temp;
  }
  size_--;
}

// returns the last element in the list
std::string const & ULListStr::back() const{
  return tail_->val[tail_->last - 1];
}

// returns the first element in the list
std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

// returns a pointer to the value at the given location in the list
std::string* ULListStr::getValAtLoc(size_t loc) const{
  
  if(empty()){
    return NULL;
  }
  // location is out of bounds
  if(loc >= size_){
    return NULL;
  }

  Item *temp = head_;
  size_t index = 0;
  size_t item_size;

  while(temp != nullptr){
    item_size = temp->last - temp->first;
    if(index + item_size > loc){
      // found the correct item, now find the correct index
      return &temp->val[temp->first + (loc - index)];
    }
    // if not correct item, add item size to index
    index += item_size;
    // move to next node
    temp = temp->next;
  }
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
