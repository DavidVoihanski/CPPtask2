/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"
#include <cstdlib>
#include <ctime>
namespace randomChecker{
  bool inArr(int num , int arr[], int legthOfArr){
    for(int i=0; i<legthOfArr; i++){
      if(arr[i] == num) return true;
    }
    return false;
  } 
}
int main() {

  ariel::Tree emptytree;
  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  ariel::Tree mytree;  

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())
  .print();

  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
  badkan::TestCase tc2("EmptyTree");
  srand(time(0));
  int rand_ = rand()%200;
  tc2
    .CHECK_THROWS(emptytree.remove(rand_))
    .CHECK_EQUAL(emptytree.contains(rand_),false)
    .CHECK_THROWS(emptytree.left(rand_))
    .CHECK_THROWS(emptytree.right(rand_))
    .CHECK_THROWS(emptytree.parent(rand_))
    .CHECK_THROWS(emptytree.root())
    .CHECK_EQUAL(emptytree.size(),0)
    .CHECK_OK(emptytree.insert(rand_))
    .CHECK_EQUAL(emptytree.size(),1)
    .CHECK_EQUAL(emptytree.contains(rand_),true)
    .CHECK_OK(emptytree.remove(rand_))
    .CHECK_EQUAL(emptytree.contains(rand_),false)
    .CHECK_EQUAL(emptytree.size(),0)
    .print();

    cout << "Empty tree test: you got " << tc2.right() << "right answers and " << tc2.wrong() << " wrong answers. Your grade is " <<tc2.grade() << endl;

    int arr[10];
    ariel::Tree testRem;
    //creat an array of 10 unique numbers
    for(int i = 0; i<10; i++){
      rand_ = rand();
      while(randomChecker::inArr(rand_, arr, i)){
        rand_ = rand();
      }
      arr[i] = rand_;
      testRem.insert(rand_);
    }

    badkan::TestCase tc3("Test remove");
    tc3  
      .CHECK_EQUAL(testRem.contains(arr[0]),true)
      .CHECK_EQUAL(testRem.contains(arr[1]),true)
      .CHECK_EQUAL(testRem.contains(arr[2]),true)
      .CHECK_EQUAL(testRem.contains(arr[3]),true)
      .CHECK_EQUAL(testRem.contains(arr[4]),true)
      .CHECK_EQUAL(testRem.contains(arr[5]),true)
      .CHECK_EQUAL(testRem.contains(arr[6]),true)
      .CHECK_EQUAL(testRem.contains(arr[7]),true)
      .CHECK_EQUAL(testRem.contains(arr[8]),true)
      .CHECK_EQUAL(testRem.contains(arr[9]),true)
      .CHECK_EQUAL(testRem.size(),10)
      //starting to remove 1 by 1 
      .CHECK_OK(testRem.remove(arr[0]))
      .CHECK_EQUAL(testRem.contains(arr[0]),false)
      .CHECK_EQUAL(testRem.size(),9)
      //*******************************
      .CHECK_OK(testRem.remove(arr[1]))
      .CHECK_EQUAL(testRem.contains(arr[1]),false)
      .CHECK_EQUAL(testRem.size(),8)
      //*******************************
      .CHECK_OK(testRem.remove(arr[2]))
      .CHECK_EQUAL(testRem.contains(arr[2]),false)
      .CHECK_EQUAL(testRem.size(),7)
      //*******************************
      .CHECK_OK(testRem.remove(arr[3]))
      .CHECK_EQUAL(testRem.contains(arr[3]),false)
      .CHECK_EQUAL(testRem.size(),6)
      //*******************************
      .CHECK_OK(testRem.remove(arr[4]))
      .CHECK_EQUAL(testRem.contains(arr[4]),false)
      .CHECK_EQUAL(testRem.size(),5)
      //*******************************
      .CHECK_OK(testRem.remove(arr[5]))
      .CHECK_EQUAL(testRem.contains(arr[5]),false)
      .CHECK_EQUAL(testRem.size(),4)
      //*******************************
      .CHECK_OK(testRem.remove(arr[6]))
      .CHECK_EQUAL(testRem.contains(arr[6]),false)
      .CHECK_EQUAL(testRem.size(),3)
      //*******************************
      .CHECK_OK(testRem.remove(arr[7]))
      .CHECK_EQUAL(testRem.contains(arr[7]),false)
      .CHECK_EQUAL(testRem.size(),2)
      //*******************************
      .CHECK_OK(testRem.remove(arr[8]))
      .CHECK_EQUAL(testRem.contains(arr[8]),false)
      .CHECK_EQUAL(testRem.size(),1)
      //*******************************
      .CHECK_OK(testRem.remove(arr[9]))
      .CHECK_EQUAL(testRem.contains(arr[9]),false)
      .CHECK_EQUAL(testRem.size(),0)
      .print();

      cout << "Test remove: You got " << tc3.right() << "right answers and " << tc3.wrong() << " wrong answers. Your grade is: " << tc3.grade() << endl;
}

