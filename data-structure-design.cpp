class RandomizedSet {
    int n;
    vector<int> elements;
    unordered_map<int, int> randomSet;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        n = 0;
        srand (time(NULL));
    
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(randomSet.find(val) != randomSet.end())
        {
            return false;
        }
        else
        {
             
            randomSet.insert(make_pair(val,n));
            elements.emplace_back(val);
           
            n++;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {

        if(randomSet.find(val) == randomSet.end())
        {
            return false;
        }
        else
        {
            int l = randomSet[val];
            randomSet.erase(val);
            elements[l] = elements[n-1];
            if(l != n-1)
            {
                randomSet[elements[l]] = l;
            }
            elements.pop_back();
            n--;
            return true;
        }
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if( n == 0)
            return -1;
        int randNumber = rand()%n;
        return elements[randNumber];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
