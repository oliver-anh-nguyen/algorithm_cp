#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class RandomizedSet {
    unordered_set<int>s;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (s.find(val) != s.end()) {
            return false;
        } else {
            s.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if (s.find(val) == s.end()) {
            return false;
        } else {
            s.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return *next(s.begin(), rand()%s.size());
    }
};


 // Your RandomizedSet object will be instantiated and called as such:
 RandomizedSet* obj = new RandomizedSet();
 bool param_1 = obj->insert(2);
 bool param_2 = obj->remove(2);
 int param_3 = obj->getRandom();
 
