/*
Link to the "Flatten Nested List Iterator" Problem ==>> https://leetcode.com/problems/flatten-nested-list-iterator/?envType=daily-question&envId=2023-10-20
   
Link to the complete Explaination Video ==>> https://youtu.be/EU7vyl_O7wc

*/

class NestedIterator {
private:
    vector<int>v;
    int index;
public:
    void createList(vector<NestedInteger>&list){
        for(auto elem : list){
            if(elem.isInteger()){
                v.push_back(elem.getInteger());
            }
            else{
                createList(elem.getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        index = 0;
        createList(nestedList);
    }
    
    int next() {
        return v[index++];
    }
    
    bool hasNext() {
        return index<v.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */