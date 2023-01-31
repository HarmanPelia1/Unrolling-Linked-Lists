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

// CODEE

void ULListStr::push_back(const std::string& val)
{
if(empty()){
      Item* item1 = new Item();
      item1->val[0] = val;
      item1->last++;
      head_ = item1;
      tail_ = item1;
    }
  else if(tail_->last == ARRSIZE){
    Item* item1 = new Item();
    tail_->next = item1;
    item1->prev = tail_;
    tail_ = item1;
    item1->val[0] = val;
    item1->last++;
  }
  else{
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  size_++;
}

void ULListStr::pop_back()
{
  if(empty()){
    return;
  }
  if(tail_->last - tail_->first > 1){
        tail_->last--;
 
  }
  else{
    if(head_ == tail_){
      delete tail_;
      head_ = nullptr;
      tail_ = nullptr;
    } 
    else {
      Item* temp = tail_;
      tail_ = tail_->prev;
      tail_->next = nullptr;
      delete temp;
    }
  }
  size_--;
}

void ULListStr::push_front(const std::string& val)
{
  if(empty()){
    Item* new_item = new Item();
    new_item->val[0] = val;
    new_item->last++;
    head_ = new_item;
    tail_ = new_item;
  }
  else{
    if(head_->first == 0){
    Item* new_item = new Item();
    new_item->val[0] = val;
    new_item->last++;
    head_->prev = new_item;
    new_item->next = head_;
    head_ = new_item;
    }
    else{
      head_->val[head_->first - 1] = val;
      head_->first--;
    }
  }
  size_++;
}

void ULListStr::pop_front()
{
  if(empty()){
    return;
  }
 else if(head_->last - head_->first == 1){
    if(head_ == tail_){
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
  }
    else{
        Item* temp = head_;
        head_ = head_->next;
        head_->prev = nullptr;
        delete temp;
    }
  }
  else{
    head_->first++;
  }
  size_--;
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}



std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}



std::string* ULListStr::getValAtLoc(size_t loc) const
{
    Item* temp = head_;
          while(loc >= temp->last - temp->first){//check if this is right
            loc = loc - (temp->last - temp->first);
            temp = temp->next;
          }
    return &temp->val[temp->first + loc];
}


//STOPPPPPP


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
