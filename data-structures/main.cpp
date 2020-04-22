#include <iostream>
#include "./3#data-structures/linked_list.cpp"
#include "./3#data-structures/stack.cpp"
#include "./3#data-structures/tree.cpp"
#include "./3#data-structures/heap.cpp"
#include "./3#data-structures/hash_table.cpp"
#include "./3#data-structures/graph.cpp"
using namespace std;

int main() {
  printf("\x1B[31mLINKED LIST\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  lists();
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mSTACKS\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  stacks();
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mTREE\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  trees();
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mHEAP\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  heaps();
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mHASH TABLE\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  hash_tables();
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mGRAPH\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  graphs();
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  return 0;
};
