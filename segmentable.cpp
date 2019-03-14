#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// To execute C++, please define "int main()"

class Segmentation {
private:
  set<string> dict;
  set<int> allSizes;
  int maxLen;
  int minLen;
public:
  Segmentation(set<string> words) {
    dict = words;
    for(auto itr=dict.begin(); itr!=dict.end(); itr++) {
      allSizes.emplace(itr->size());
      if(itr==dict.begin()) {
        maxLen = minLen = itr->size();
      }
      else {
        if(itr->size() > maxLen)
          maxLen = itr->size();
        if(itr->size() < minLen)
          minLen = itr->size();
      }
    }
  }

  vector<string> doSegment(string str) {
    vector<string> result;
    set<string> failed;

    if(!str.size()) return result;
    if(minLen > str.size()) return result;

    doSegmentCore(str, result, failed);
    return result;
  }

  bool doSegmentCore(string str, vector<string> &result, set<string> &failed) { 
    if(failed.find(str) != failed.end())
      return false;

    if(dict.find(str) !=dict.end()) {
      result.push_back(str);
      return true;
    }
  
    if(str.size() <= minLen) {
      failed.emplace(str);
      return false;
    }
  
    for(auto itr=allSizes.begin(); itr!=allSizes.end(); itr++) {

      int leftSize  = *itr;
      int rightSize = str.size() - *itr;

      if( (leftSize >=minLen) &&  (rightSize>=minLen) ) {
        string left = str.substr(0, *itr);
        string right = str.substr(*itr, str.size()-*itr);

        if( doSegmentCore(left, result, failed) && doSegmentCore(right, result, failed)) {
          return true;
        }
        else{
          result.clear();
          failed.emplace(str);
        }
      }
    }
    return false;
  }
};

int main() {
  set<string> words = {"jump", "jumped", "jumpedov", "over", "some", "thing", "something"};
  Segmentation sg(words);

  string input ="jumped oversomething";
  vector<string> res = sg.doSegment(input);

  cout <<"String:"<<input<<" can be segmented into words:";
  for(string str: res) {
    cout << str <<" ";
  }
  cout << endl;
  return 0;
}


/* 
Your previous Plain Text content is preserved below:

Given a string and a set of words, break the string into a list of words from the set. If the word can not be segmented fully, return an empty list.
Example:
Set: {"jump", "jumped", "jumpedov", "over", "some", "thing", "something"}
String: "jumpedoversomething", 
Can return [“jumped”, “over”, “something”] or  [ “jumped”, “over”, “some”, “thing”]

 */