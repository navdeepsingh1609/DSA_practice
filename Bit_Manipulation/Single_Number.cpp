//TC: O(n)
//SC: O(1)

int Solution::singleNumber(const vector<int> &v) {
    int a= v[0];
    for(int i=1; i<v.size(); i++){
        a=a^v[i];
    }
    return a;
}

