// <Your name>
// Main file for Part2(a) of Homework 2.

#include "avl_tree_p2a.h"
#include "sequence_map.h"

#include <iostream>
#include <string>

#include <fstream>
#include <sstream>
using namespace std;

namespace {

// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &db_filename, TreeType &a_tree) {
  ifstream inFile(db_filename);
  //before reading any of the data we need to pass of the copyright info
  string copyright_Shit;
  for(int i{0}; i< 10; i++){
    getline(inFile, copyright_Shit);
  }
  //then we read the data
  string line{""};
  while(getline(inFile, line)){
    string enzyme_acronym{""}, recognition_sequence{""};
    stringstream splitOnSlash(line); //create a stream of line so we can use getline

    getline(splitOnSlash, enzyme_acronym, '/'); //get enzyme
    while(getline(splitOnSlash,recognition_sequence, '/')){ //get recognition sequence(s)
        SequenceMap sequence_map{recognition_sequence, enzyme_acronym}; 
        a_tree.insert(sequence_map);
    }
  }

}

}  // namespace

// int
// main(int argc, char **argv) {
//   if (argc != 2) {
//     cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
//     return 0;
//   }
//   const string db_filename(argv[1]);
//   cout << "Input filename is " << db_filename << endl;
  
//   AvlTree<SequenceMap> a_tree;
//   QueryTree(db_filename, a_tree);

//   string a{}, b{}, c{};
//   cin >> a >> b >> c;
//   a_tree.findAcronyms(a);
//   a_tree.findAcronyms(b);
//   a_tree.findAcronyms(c);

//   return 0;
// }
