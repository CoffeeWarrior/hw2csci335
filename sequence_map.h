#ifndef SEQUENCE_MAP_H
#define SEQUENCE_MAP_H

#include <string>
#include <vector>

using namespace std;

class SequenceMap{
    public:
    
    //big 5 constructors
    SequenceMap() = default;
	~SequenceMap() = default;
	SequenceMap(const SequenceMap& rhs) = default;
	SequenceMap(SequenceMap&& rhs) = default;
	SequenceMap& operator=(SequenceMap&& rhs) = default; 
	SequenceMap& operator=(const SequenceMap& rhs) = default;

    //part 1 a, b, c, d

    //a
        SequenceMap(const string &a_rec_seq, const string &an_enz_acro):recognition_sequence_{a_rec_seq}, enzyme_acronyms_{an_enz_acro}{}
    //b
        bool operator< (const SequenceMap &rhs) const{
            return recognition_sequence_ < rhs.recognition_sequence_;
        }
    //c
        friend ostream &operator<<(ostream &output, const SequenceMap &rhs){
            output << rhs.recognition_sequence_;
            for(auto i:rhs.enzyme_acronyms_){
                output << i << " ";
            }
            output << endl;
            return output;
        }
    //d 
        void Merge(const SequenceMap &other_sequence){
            for(auto i:other_sequence.enzyme_acronyms_){
                enzyme_acronyms_.push_back(i);
            }
        }
    //list acronyms
        void displayAcronyms() {
			for (unsigned int i = 0; i < enzyme_acronyms_.size(); i++) {
				cout << enzyme_acronyms_[i] << " ";
			}
		}
    //will return sequence
        string getSequence(){
            return recognition_sequence_;
        }

    private: 
    string recognition_sequence_;
    vector<string> enzyme_acronyms_;
};

#endif