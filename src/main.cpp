
/**
@mainpage COP 3330 Project 1

@Author James McAuley

The project has no special quirks, it should run when main is called and take in a string and analyze it.
I made a decision to not use dynamic memory allocation in my two arrays 'letters' and 'count'. When I 
tried to use dynamic memory allocation I kept getting memory leaks which I didn't know how to fix
and I also got segmentation faults which I didn't know how to fix. Plus the maximum number of characters 
possible is 128 (ASCII characters), which seemed like a reasonable size of array to carry. 

My partner dropped the class so I worked on this code alone.

The code is not very stable. There is a big bug which I cannot figure out... on longer strings the code
breaks down and give rubbish answers, even if the number of characters stays the same. Output will go 
from being completely correct to completely absurd based solely on the last few letters typed. I don't
understand how this is possible as none of the code depends on a single letter really. Below this I will 
paste a few examples of where the code fails.

mcauley@linprog4.cs.fsu.edu:~/HW_Template/bin> main
Please input a string: Sugar? I barely even know her! The nerve of some people. They think they can waltz on in here and
51

***Then with the same number of characters, note that ONLY the last 3 characters change***

mcauley@linprog4.cs.fsu.edu:~/HW_Template/bin> main
Please input a string: Sugar? I barely even know her! The nerve of some people. They think they can waltz on in here tim
14

(14 is the correct number of characters)
It also works with these final three characters:

mcauley@linprog4.cs.fsu.edu:~/HW_Template/bin> main
Please input a string: Sugar? I barely even know her! The nerve of some people. They think they can waltz on in here log
14

Although it can randomly blow up like this:

mcauley@linprog4.cs.fsu.edu:~/HW_Template/bin> main
Please input a string: Sugar? I barely even know her! The nerve of some people. They think they can waltz on in here and what? C
1853129890

And just so you can see the full sentence:

mcauley@linprog4.cs.fsu.edu:~/HW_Template/bin> main
Please input a string: Sugar? I barely even know her! The nerve of some people. They think they can waltz on in here and what? Create chaos?!
92

This bug I haven't noticed occur for shorter test cases, but it may... I don't understand why or how it's occurring and I really don't
understand its being a function of which letters are typed.

I found the project to be quite hard, but I think it's because I was working alone. I also don't really understand how the test cases should work. Thanks.
*/

#include <iostream>
#include <example.hpp>
#include <assert.h>
#include <string>

int get_max_count(std::string sinput){
  using namespace std;
  string dog=sinput ;
  //getline(cin, dog);
  //char *letters = new char(dog.size());
  //int *count = new int(dog.size());
  int uniques = 0; //Counts the number of unique non-whitespace characters found
  char letters[128];//Array which stores the unique non-whitespace characters found in the string
  int count[128];//Array which keeps track of the number of times a given non-whitespace character was found in the string
  bool found = false;//Boolean variable to track whether or not a given test character from the string is unique or redundant

  for (unsigned int i = 0; i< dog.size(); i++){
    found = false;
    if(isspace(dog[i])){  //Skips if character is a whitespace
      continue;
    }
    //Loop below is to determine uniqueness of letter
    int j = 0;
    while(j < uniques){
      if(dog[i]==letters[j]){ //if the tested character is found in the list of unique letter we set 'found' to true and add to that letter's counter
	found=true;
	count[j]++;
      }
      j++;
    }
    if(found==false){    //if no unique is found in the 'letters' array, then test character must be unique, and is added to 'letters' array
      letters[uniques]=dog[i];
      count[uniques]++;
      uniques++;
    }
    //Following for loop finds the maximum number of times a letter was found
  }
  int max =0;
  for(int k=0; k<uniques;k++){
    if(count[k]>max){
      max = count[k];
    }
  }

// cout << "the maximum number of times a character appears is: " << max << endl;
    return max;
}

int main(int argc, char *argv[]){
    using namespace std;
    
    if (argc >= 2){
        string test1("c++");
        assert(get_max_count(test1) == 2);
    } else {
        string line; 
        cout << "Please input a string: "; 
        getline(cin, line);
        cout << get_max_count(line) << endl;
    }

	return 0;

}
