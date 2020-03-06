// <Your name>
// Main file for Part2(b) of Homework 2.

#include "avl_tree_p2b.h"
#include "sequence_map.h"

#include <iostream>
#include <string>

#include <fstream>
#include <sstream>
#include <cmath>
namespace {

// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree) {
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
//this function will perform recursive find and output the results
template <typename TreeType>  
void recursiveFind(const string &db_filename, const string &seq_filename, TreeType &a_tree){
  int successCounter = 0;
  int recursionCalls = 0;
  int queries = 0;
  string line;
  ifstream inFile(seq_filename);
  while(getline(inFile, line)){
    ++queries;
    successCounter += a_tree.find(line, recursionCalls);
  }
  cout << "4a: " << successCounter << endl;
  cout << "4b: " << recursionCalls/(float)queries << endl;
}

//this function will recursively remove and output the results
template <typename TreeType>  
void recursiveRemove(const string &db_filename, const string &seq_filename, TreeType &a_tree){
  string line;
  ifstream inFile(seq_filename);
  int total=0;
  int stringsRemoved=0;
  int avgrecursioncalls=0;
  while(getline(inFile, line)){
    ++total;
    if(total%2){
      SequenceMap a(line, "");
      if(a_tree.contains(a)){
        a_tree.remove(line, avgrecursioncalls);
        if(!a_tree.contains(a)){
          ++stringsRemoved;
        }      
      }
    }
  }
  cout << "5a: " << stringsRemoved << endl;
  cout << "5b: " << avgrecursioncalls/(float)stringsRemoved << endl;
}
} //namespace


// int
// main(int argc, char **argv) {
//   if (argc != 3) {
//     cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
//     return 0;
//   }
//   const string db_filename(argv[1]);
//   const string seq_filename(argv[2]);
//   cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
  
//   AvlTree<SequenceMap> a_tree;
//   TestTree(db_filename, seq_filename, a_tree);
//   float avgDepth = ((float)a_tree.pathLengthsAdded())/((float)a_tree.countNodes());
//   cout << "2: " << a_tree.countNodes() << endl;
//   cout << "3a: " << avgDepth << endl;
//   cout << "3b: " << avgDepth/log2(a_tree.countNodes()) << endl;
//   recursiveFind(db_filename, seq_filename, a_tree);
//   recursiveRemove(db_filename, seq_filename, a_tree);
//   cout << "6a: Not Done" << endl;
//   cout << "6b: Not Done" << endl;
//   cout << "6c: Not Done" << endl;
//   return 0;
// }
